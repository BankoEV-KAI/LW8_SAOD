#include "listOfLists.h"
#include "menu.h"
#include <iostream>

//список списков 


int main() {
    srand(time(0));

    setlocale(LC_ALL, "Ru");


    int operation{ 0 }, newData{ 0 }, findData{ 0 };
    int mainIndex, subIndex, position;

    

    while (true)
    {
        printMenu(1);
        enteringNumber(0, 7, operation);
        switch (operation)
        {
        case 0:
            return -1;
        case 1:
            printMainListWithSublists();
            break;
        case 2:
            searchDialog();
            break;
        case 3:
            addToMainList();
            break; 
        case 4:
            addToSubList();
            break;
        case 5:
            deleteFromMainList();
            break;
        case 6:
            deleteFromSubList();
            break;
        case 7:
            printMainListWithSublists();
            break;
        default:
            break;
        }
    }

    //initExamles(mainList);

    /*
    while (true) {
        printMenu(1);
        enteringNumber(0, 6, operation);
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
            printStructure(mainList);
            break;
        case 2:
            enteringNumber(1, 100, findData);
            findElement(mainList, findData, mainIndex, subIndex) ?
                std::cout << "Элемент " << findData << " найден в списке " << mainIndex << ", позиция " << subIndex << "." << std::endl :
                std::cout << "Элемент " << findData << " не найден." << std::endl;
            break;
        case 3:
            std::cout << "До/после какого списка добавим >> ";
            if (countMain == 0) { std::cout << "empty " << std::endl; mainIndex = 0; }
            else {
                enteringNumber(1, countMain, mainIndex);
            }
            std::cout << "'-1' - до, '0' - в конец, '1' - после";
            enteringNumber(-1, 1, position);
            addEmptySublistToMainList(mainList, mainIndex-1, position);
            std::cout << "Создан пустой подчиненный список. " << std::endl;
            printStructure(mainList);
            break;
        case 4:
            printMenu(2);
            enteringNumber(0, 4, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                enteringNumber(1, 100, newData);
                addToEmptySublist(mainList, countMain, newData);
                break;
            case 2:
                if (countMain == 0) {
                    std::cout << "Главный список пуст" << std::endl;
                    break;
                }
                std::cout << "В какой подчиненный список добавим >> ";
                enteringNumber(1, countMain, mainIndex);
                std::cout << "До какого элемента добавить >> ";
                enteringNumber(1, 100, findData);
                std::cout << "Какой элемент добавить >> ";
                enteringNumber(1, 100, newData);
                addToSublistBefore(mainList, mainIndex-1, findData, newData);
                break;
            case 3:
                if (countMain == 0) {
                    std::cout << "Главный список пуст" << std::endl;
                    break;
                }
                std::cout << "В какой подчиненный список добавим >> ";
                enteringNumber(1, countMain, mainIndex);
                std::cout << "После какого элемента добавить >> ";
                enteringNumber(1, 100, findData);
                std::cout << "Какой элемент добавить >> ";
                enteringNumber(1, 100, newData);
                addToSublistAfter(mainList, mainIndex-1, findData, newData);
                break;
            case 4:
                if (countMain == 0) {
                    std::cout << "Главный список пуст" << std::endl;
                    break;
                }
                std::cout << "В какой подчиненный список добавим >> ";
                enteringNumber(1, countMain, mainIndex);
                enteringNumber(1, 100, newData);
                addToSublist(mainList, mainIndex-1, newData);
                break;
            default:
                break;
            }
            printStructure(mainList);
            break;
        case 5:
            if (countMain == 0) {
                std::cout << "Главный список пуст" << std::endl;
                break;
            }
            std::cout << "Из какого подчиненного списка удаление >> ";
            enteringNumber(1, countMain, mainIndex);
            enteringNumber(1, 100, findData);
            removeFromSublist(mainList, mainIndex - 1, findData);
            printStructure(mainList);
            break;
        case 6:
            if (countMain == 0) {
                std::cout << "Главный список пуст" << std::endl;
                break;
            }
            std::cout << "Какой подчиненный список удалить >> ";
            enteringNumber(1, countMain, mainIndex);
            removeFromMainList(mainList, mainIndex-1);
            printStructure(mainList);
            break;
        default:
            break;
        }
    }
    */
    return 0;
}
