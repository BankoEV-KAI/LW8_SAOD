#include "listOfLists.h"
#include <iostream>

int countMain{ 0 };

SublistNode* createSublistNode(int value) {
    return new SublistNode(value);
}

MainListNode* createMainListNode() {
    return new MainListNode();
}

void printStructure(MainListNode* mainList) {
    MainListNode* currentMain = mainList;
    int mainIndex = 1;
    while (currentMain != nullptr) {
        std::cout << "—писок " << mainIndex << ": [";
        SublistNode* currentSub = currentMain->sublist;
        int subIndex = 1;
        while (currentSub != nullptr) {
            std::cout << " " << currentSub->data;
            currentSub = currentSub->next;
            if (currentSub != nullptr) {
                std::cout << ",";
            }
            subIndex++;
        }
        std::cout << "]; ";
        currentMain = currentMain->next;
        mainIndex++;
    }
    std::cout << std::endl;
    std::cout << "количество подчиненных списков " << countMain << std::endl;
}

bool findElement(MainListNode* mainList, int value, int& mainIndex, int& subIndex) {
    MainListNode* currentMain = mainList;
    mainIndex = 1;

    while (currentMain != nullptr) {
        SublistNode* currentSub = currentMain->sublist;
        subIndex = 1;

        while (currentSub != nullptr) {
            if (currentSub->data == value) {
                return true;
            }
            currentSub = currentSub->next;
            subIndex++;
        }

        currentMain = currentMain->next;
        mainIndex++;
    }

    return false;
}
void addToEmptySublist(MainListNode* mainList, int mainIndex, int value) {
    MainListNode* currentMain = mainList;
    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain->next == nullptr) {
            currentMain->next = createMainListNode();
        }
        currentMain = currentMain->next;
    }
    currentMain->sublist = createSublistNode(value);
    countMain++;
}

void addToSublist(MainListNode* mainList, int mainIndex, int value) {
    MainListNode* currentMain = mainList;
    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain == nullptr) {
            std::cout << "»ндекс превышает размер структуры." << std::endl;
            return;
        }
        currentMain = currentMain->next;
    }

    if (currentMain->sublist == nullptr) {
        currentMain->sublist = createSublistNode(value);
    }
    else {
        SublistNode* currentSub = currentMain->sublist;
        while (currentSub->next != nullptr) {
            currentSub = currentSub->next;
        }
        currentSub->next = createSublistNode(value);
    }
}

void removeFromSublist(MainListNode*& mainList, int mainIndex, int value) {
    MainListNode* currentMain = mainList;
    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain == nullptr) {
            std::cout << "»ндекс превышает размер структуры." << std::endl;
            return;
        }
        currentMain = currentMain->next;
    }

    if (currentMain->sublist == nullptr) {
        std::cout << "ѕодчиненный список пуст." << std::endl;
        return;
    }

    SublistNode* currentSub = currentMain->sublist;
    SublistNode* prevSub = nullptr;

    while (currentSub != nullptr && currentSub->data != value) {
        prevSub = currentSub;
        currentSub = currentSub->next;
    }

    if (currentSub == nullptr) {
        std::cout << "Ёлемент не найден." << std::endl;
        return;
    }

    if (prevSub == nullptr) {
        currentMain->sublist = currentSub->next;
    }
    else {
        prevSub->next = currentSub->next;
    }

    delete currentSub;
}
void removeFromMainList(MainListNode*& mainList, int mainIndex) {
    MainListNode* currentMain = mainList;
    MainListNode* prevMain = nullptr;

    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain == nullptr) {
            std::cout << "»ндекс превышает размер структуры." << std::endl;
            return;
        }
        prevMain = currentMain;
        currentMain = currentMain->next;
    }

    if (prevMain == nullptr) {
        mainList = currentMain->next;
    }
    else {
        prevMain->next = currentMain->next;
    }

    delete currentMain;
    countMain--;
}

void addEmptySublistToMainList(MainListNode*& mainList, int mainIndex, int position) {
    if (position == 0) {
        MainListNode* currentMain = mainList;
        while (currentMain->next != nullptr) {
            currentMain = currentMain->next;
        }

        currentMain->next = createMainListNode();
    }
    else if (position == -1) {
        MainListNode* currentMain = mainList;
        MainListNode* prevMain = nullptr;

        for (int i = 0; i < mainIndex; ++i) {
            if (currentMain == nullptr) {
                std::cout << "»ндекс превышает размер структуры." << std::endl;
                return;
            }
            prevMain = currentMain;
            currentMain = currentMain->next;
        }

        MainListNode* newMainNode = createMainListNode();
        newMainNode->next = currentMain;

        if (prevMain == nullptr) {
            mainList = newMainNode;
        }
        else {
            prevMain->next = newMainNode;
        }
        
    }
    else if (position == 1) {
        MainListNode* currentMain = mainList;

        for (int i = 0; i < mainIndex; ++i) {
            if (currentMain == nullptr) {
                std::cout << "»ндекс превышает размер структуры." << std::endl;
                return;
            }
            currentMain = currentMain->next;
        }

        MainListNode* newMainNode = createMainListNode();
        newMainNode->next = currentMain->next;
        currentMain->next = newMainNode;
    }
    countMain++;
}


void addToSublistBefore(MainListNode* mainList, int mainIndex, int beforeValue, int value) {
    MainListNode* currentMain = mainList;
    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain == nullptr) {
            std::cout << "»ндекс превышает размер структуры." << std::endl;
            return;
        }
        currentMain = currentMain->next;
    }

    SublistNode* currentSub = currentMain->sublist;
    SublistNode* prevSub = nullptr;

    while (currentSub != nullptr && currentSub->data != beforeValue) {
        prevSub = currentSub;
        currentSub = currentSub->next;
    }
    
    if (currentSub == nullptr) {
        std::cout << "Ёлемент " << beforeValue << " не найден." << std::endl;
        return;
    } 

    SublistNode* newNode = createSublistNode(value);
    newNode->next = currentSub;

    if (prevSub == nullptr) {
        currentMain->sublist = newNode;
    }
    else {
        prevSub->next = newNode;
    }
}

void addToSublistAfter(MainListNode* mainList, int mainIndex, int afterValue, int value) {
    MainListNode* currentMain = mainList;
    for (int i = 0; i < mainIndex; ++i) {
        if (currentMain == nullptr) {
            std::cout << "»ндекс превышает размер структуры." << std::endl;
            return;
        }
        currentMain = currentMain->next;
    }

    SublistNode* currentSub = currentMain->sublist;

    while (currentSub != nullptr && currentSub->data != afterValue) {
        currentSub = currentSub->next;
    }

    if (currentSub == nullptr) {
        std::cout << "Ёлемент " << afterValue << " не найден." << std::endl;
        return;
    }

    SublistNode* newNode = createSublistNode(value);
    newNode->next = currentSub->next;
    currentSub->next = newNode;
}

void initExamles(MainListNode*& mainList) {
    for (int i = 0; i < rand()%5 + 1; i++) {
        addToEmptySublist(mainList, countMain, rand() % 100 + 1);
        for (int j = 1; j < rand()%5 + 1; j++) {
            addToSublist(mainList, i, rand() % 100 + 1);
        }
    }
    printStructure(mainList);
}