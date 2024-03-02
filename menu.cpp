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
            << "3. Добавление пустого подчиненного(вложенного) списка;" << std::endl
            << "4. Добавление нового элемента в подчиненный список;" << std::endl
            << "5. Удаление элемента из подчиненного списка; " << std::endl
            << "6. Удаление элемента из главного списка; " << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 2:
        std::cout << std::endl
            << "1. С создание нового подчиненного списка в КОНЦЕ главного; " << std::endl
            << "2. В существующий список ДО существующего элемента; " << std::endl
            << "3. В существующий список ПОСЛЕ существующего элемента; " << std::endl
            << "4. В существующий список в КОНЕЦ; " << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
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