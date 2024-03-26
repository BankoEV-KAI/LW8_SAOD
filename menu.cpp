#include "menu.h"
#include <iostream>


void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;
    switch (operation)
    {
    case 1:
        std::cout << std::endl
            << "1. �������� ���� ���������; " << std::endl
            << "2. ����� ��������; " << std::endl
            << "3. ���������� �������� � MainList;" << std::endl
            << "4. ���������� �������� SubList;" << std::endl
            << "5. �������� �������� �� MainList; " << std::endl
            << "6. �������� �������� �� SubList; " << std::endl
            << "7. �������� ���� ���������; " << std::endl
            << "0. ���������." << std::endl
            << std::endl;
        break;
    
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "������� ����� �� " << rangeStart << " �� " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������������ ����. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "������������ �����. ";
        }
    }
}