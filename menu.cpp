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
            << "3. ���������� ������� ������������(����������) ������;" << std::endl
            << "4. ���������� ������ �������� � ����������� ������;" << std::endl
            << "5. �������� �������� �� ������������ ������; " << std::endl
            << "6. �������� �������� �� �������� ������; " << std::endl
            << "0. ��������� � ������." << std::endl
            << std::endl;
        break;
    case 2:
        std::cout << std::endl
            << "1. � �������� ������ ������������ ������ � ����� ��������; " << std::endl
            << "2. � ������������ ������ �� ������������� ��������; " << std::endl
            << "3. � ������������ ������ ����� ������������� ��������; " << std::endl
            << "4. � ������������ ������ � �����; " << std::endl
            << "0. ��������� � ������." << std::endl
            << std::endl;
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