#include <iostream>
#include <fstream>
#include <main.hpp>

//function which runs the physics simulation
void simulation() {
    std::cout << "placeholder";
};

int main()
{
    int option = { 0 };
    int subMenu = { 0 };

    while (option != 5) {
        system("clear");

        //logo
        std::cout << "  /$$$$$$                   /$$     /$$              \n /$$__  $$                 | $$    | $$              \n| $$  \\__/     /$$$$$$     | $$    | $$      /$$$$$$$\n| $$          /$$__  $$    | $$    | $$     /$$_____/\n| $$         | $$$$$$$$    | $$    | $$    |  $$$$$$ \n| $$    $$   | $$_____/    | $$    | $$     \\____  $$\n|  $$$$$$//$$|  $$$$$$$ /$$| $$ /$$| $$ /$$ /$$$$$$$/\n \\______/|__/ \\_______/|__/|__/|__/|__/|__/|_______/ \n                                                   ";
        std::cout << "\n" << "_________________________________________________________________\n \n";

        //switch case handeling what page you are on
        switch (option)
        {
        case 0: //main menu
            std::cout << "1: Start\n" 
            << "2: Load memory\n" 
            << "3: Eject memory\n" 
            << "4: Settings\n" 
            << "5: Exit\n";
            std::cout << "\n Type Option: ";
            std::cin >> option;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                option = 0;
            }
            break;

        case 1: //starting simulation/game
            std::cout << "1: Back\n" 
            << "2: Simulation\n" 
            << "3: Game\n";
            std::cout << "\n Launch option: ";
            std::cin >> subMenu;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                subMenu = 0;
            }
            if (subMenu == 1){
                subMenu = 0;
                option = 0;
                break;
            }
            if (subMenu == 2){
                simulation();
                pause();
            }
            if(subMenu == 3){
                pause();
            };
            subMenu = 0;
            break;

        case 2: //loading memory
            std::cout << "1: Back\n" << "2: Localy\n";
            std::cout << "\n Load from: ";
            std::cin >> subMenu;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                subMenu = 0;
            }
            if(subMenu == 1) {
                subMenu = 0;
                option = 0;
                break;
            }
            break;

        case 3: //ejecting memory to location
            std::cout << "1: Back\n" << "2: Localy\n";
            std::cout << "\n Store at: ";
            std::cin >> subMenu;
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                subMenu = 0;
            }
            if(subMenu == 1) {
                subMenu = 0;
                option = 0;
                break;
            }
            break;

        case 4: //settings
            option = 0;
            break;

        default:
            option = 0;
            break;
        }
    }
	return 0;
}