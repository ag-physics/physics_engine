#include <iostream>
#include <fstream>

int main()
{
    int option = { 0 };
    int location = { 0 };

    while (option != 5) {
        system("clear");
        std::cout << "  /$$$$$$                   /$$     /$$              \n /$$__  $$                 | $$    | $$              \n| $$  \\__/     /$$$$$$     | $$    | $$      /$$$$$$$\n| $$          /$$__  $$    | $$    | $$     /$$_____/\n| $$         | $$$$$$$$    | $$    | $$    |  $$$$$$ \n| $$    $$   | $$_____/    | $$    | $$     \\____  $$\n|  $$$$$$//$$|  $$$$$$$ /$$| $$ /$$| $$ /$$ /$$$$$$$/\n \\______/|__/ \\_______/|__/|__/|__/|__/|__/|_______/ \n                                                   ";
        std::cout << "\n" << "_________________________________________________________________\n \n";

        switch (option)
        {
        case 0:
            std::cout << "1: Start simulation\n" << "2: Load memory\n" << "3: Eject memory\n" << "4: Settings\n" << "5: Exit\n";
            std::cout << "\nType Option: ";
            std::cin >> option;
            break;

        case 1:
            option = 0;
            break;

        case 2:
            std::cout << "1: back\n" << "2: localy\n";
            std::cout << "\n Load from: ";
            std::cin >> location;
            option = 0;
            break;

        case 3:
            std::cout << "1: back\n" << "2: localy\n";
            std::cout << "Store at: ";
            std::cin >> location;
            option = 0;
            break;

        case 4:
            option = 0;
            break;

        default:
            option = 0;
            break;
        }
    }
	return 0;
}