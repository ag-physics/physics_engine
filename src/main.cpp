#define GLEW_STATIC
#include "../include/GLEW/glew.h"
#include "../include/GLFW/glfw3.h"
// #include <main.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};


static ShaderProgramSource ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile" <<(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
        std::cout << message << std::endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    std::cout << "Hello world!" << std::endl;
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
};







//function which runs the physics simulation
// void simulation() {
//     std::cout << "placeholder";
// };

// int main()
// {
//     unsigned int program = glCreateProgram();
//     unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//     unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

//     glAttachShader(program, vs);
//     glAttachShader(program, fs);
//     glLinkProgram(program);
//     glValidateProgram(program);

//     glDeleteShader(vs);
//     glDeleteShader(fs);

//     return program;
//     int option = { 0 };
//     int subMenu = { 0 };

//     while (option != 5) {
//         system("clear");

//         //logo
//         std::cout << "  /$$$$$$                   /$$     /$$              \n /$$__  $$                 | $$    | $$              \n| $$  \\__/     /$$$$$$     | $$    | $$      /$$$$$$$\n| $$          /$$__  $$    | $$    | $$     /$$_____/\n| $$         | $$$$$$$$    | $$    | $$    |  $$$$$$ \n| $$    $$   | $$_____/    | $$    | $$     \\____  $$\n|  $$$$$$//$$|  $$$$$$$ /$$| $$ /$$| $$ /$$ /$$$$$$$/\n \\______/|__/ \\_______/|__/|__/|__/|__/|__/|_______/ \n                                                   ";
//         std::cout << "\n" << "_________________________________________________________________\n \n";

//         //switch case handeling what page you are on
//         switch (option)
//         {
//         case 0: //main menu
//             std::cout << "1: Start\n" 
//             << "2: Load memory\n" 
//             << "3: Eject memory\n" 
//             << "4: Settings\n" 
//             << "5: Exit\n";
//             std::cout << "\n Type Option: ";
//             std::cin >> option;
//             if(std::cin.fail()) {
//                 std::cin.clear();
//                 std::cin.ignore();
//                 option = 0;
//             }
//             break;

//         case 1: //starting simulation/game
//             std::cout << "1: Back\n" 
//             << "2: Simulation\n" 
//             << "3: Game\n";
//             std::cout << "\n Launch option: ";
//             std::cin >> subMenu;
//             if(std::cin.fail()) {
//                 std::cin.clear();
//                 std::cin.ignore();
//                 subMenu = 0;
//             }
//             if (subMenu == 1){
//                 subMenu = 0;
//                 option = 0;
//                 break;
//             }
//             if (subMenu == 2){
//                 simulation();
//                 pause();
//             }
//             if(subMenu == 3){
//                 pause();
//             };
//             subMenu = 0;
//             break;

//         case 2: //loading memory
//             std::cout << "1: Back\n" << "2: Localy\n";
//             std::cout << "\n Load from: ";
//             std::cin >> subMenu;
//             if(std::cin.fail()) {
//                 std::cin.clear();
//                 std::cin.ignore();
//                 subMenu = 0;
//             }
//             if(subMenu == 1) {
//                 subMenu = 0;
//                 option = 0;
//                 break;
//             }
//             break;

//         case 3: //ejecting memory to location
//             std::cout << "1: Back\n" << "2: Localy\n";
//             std::cout << "\n Store at: ";
//             std::cin >> subMenu;
//             if(std::cin.fail()) {
//                 std::cin.clear();
//                 std::cin.ignore();
//                 subMenu = 0;
//             }
//             if(subMenu == 1) {
//                 subMenu = 0;
//                 option = 0;
//                 break;
//             }
//             break;

//         case 4: //settings
//             option = 0;
//             break;

//         default:
//             option = 0;
//             break;
//         }
//     }
// 	return 0;
// }







int main(void)
{
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    if (glewInit() != GLEW_OK) std::cout << "Error!" << std::endl;


    float positions[] = {
        -0.5f, -0.5f, // 0
         0.5f, -0.5f, // 1
         0.5f,  0.5f, // 2
        -0.5f,  0.5f, // 3
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 *sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    ShaderProgramSource source = ParseShader("src/basic.shader");
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    glUniform4f(location, 0.8f, 0.3f, 0.8f, 1.0f);

    glBindVertexArray(0);
    glUseProgram(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    float r = 0.0f;
    float increment = 0.05f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glUniform4f(location, r, 0.3f, 0.8f, 1.0f);


        glBindVertexArray(vao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        if (r > 1.0f)
            increment = -0.05f;
        else if (r < 0.0f)
            increment = 0.05f;

        r += increment;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}