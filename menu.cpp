#include "menu.h"
#include <iostream>


void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;
    switch (operation)
    {
    case 1:
        std::cout << std::endl
            << "1. Просмотр всей структуры; " << std::endl
            << "2. Поиск элемента; " << std::endl
            << "3. Добавление элемента в MainList;" << std::endl
            << "4. Добавление элемента SubList;" << std::endl
            << "5. Удаление элемента из MainList; " << std::endl
            << "6. Удаление элемента из SubList; " << std::endl
            << "7. Просмотр всей структуры; " << std::endl
            << "0. Завершить." << std::endl
            << std::endl;
        break;
    
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}