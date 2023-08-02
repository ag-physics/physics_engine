g++ -c src/main.cpp -o out/main.o

g++ -o out/main.exe out/main.o lib/GLFW/libglfw3.a out/glew.o -lglfw3 -lopengl32  -lgdi32 