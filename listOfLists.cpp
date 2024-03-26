#include "listOfLists.h"
#include "menu.h"
#include <iostream>

int countMain = 0;
int countSubLists = 0;
int counter = 0, findKey = 0;
MainListNode* MainHeader = nullptr;

//Все, что касается работы с основным списком

void addToMainList() {
	int searchMainKey = -1;
	if (MainHeader == nullptr) {
		int newMainKey = 0;
		std::cout << "Список пуст. Добавление будет произведено один раз. " << std::endl;
		std::cout << "Информационная часть добавляемого ключа >> ";
		enteringNumber(1, 100, newMainKey);

		MainHeader = new MainListNode;
		MainHeader->nextMain = MainHeader;
		MainHeader->prevMain = MainHeader;

		MainListNode* newNode = new MainListNode;
		newNode->keyMainList = newMainKey;
		newNode->nextMain = MainHeader;
		newNode->prevMain = MainHeader->prevMain;
		MainHeader->prevMain->nextMain = newNode;
		MainHeader->prevMain = newNode;
		
		std::cout << "Главный список был пуст. Элемент с ключом " << newMainKey << " добавлен в конец (он же начало). " << std::endl;
		countMain++;
		std::cout << "Обновленный список:" << std::endl;
		printMainListWithSublists();
		std::cout << std::endl;
		return;
	}

	std::cout << "Добавление элемента в главный список" << std::endl;
	std::cout << "Относительно какого элемента добавлени >> ";
	enteringNumber(1, 100, searchMainKey);
	if (searchInMain(searchMainKey)) {
		int position; // 0 - before, 1 - after
		std::cout << "Добавление до = 0 или после = 1 найденного >> ";
		enteringNumber(0, 1, position);

		int newMainKey = 0;
		std::cout << "Информационная часть ключа >> ";
		enteringNumber(1, 100, newMainKey);

		MainListNode* searchNode = MainHeader->nextMain;
		while (searchNode != MainHeader && searchNode->keyMainList != searchMainKey) {
			searchNode = searchNode->nextMain;
		}

		if (position == 0) { //before
			MainListNode* newNode = new MainListNode;
			newNode->keyMainList = newMainKey;
			newNode->nextMain = searchNode;
			newNode->prevMain = searchNode->prevMain;
			searchNode->prevMain->nextMain = newNode;
			searchNode->prevMain = newNode;
		}
		else if (position == 1) { //after
			MainListNode* newNode = new MainListNode;
			newNode->keyMainList = newMainKey;
			newNode->nextMain = searchNode->nextMain;
			newNode->prevMain = searchNode;
			searchNode->nextMain->prevMain = newNode;
			searchNode->nextMain = newNode;
		}
		countMain++;

		std::cout << "Элемент " << newMainKey << " вставлен "
			<< ((position == 0) ? "перед" : "после") << " элемента " << searchMainKey
			<< ". Количество элементов в списке: " << countMain << std::endl;
	}
	else {
		std::cout << "Элемент с ключом " << searchMainKey << " не найден (главный список)." << std::endl; return;
	}
	std::cout << "Обновленный список:" << std::endl;
	printMainListWithSublists();
	std::cout << std::endl;
}

bool searchInMain(int searchKey) {
	counter = 0;
	if (MainHeader == nullptr) return false; // пустой 

	MainListNode* current = MainHeader;
	do {
		if (current->keyMainList == searchKey)
			return true;
		current = current->nextMain;
		counter++;
	} while (current != MainHeader);

	return false; //не найден
}

void deleteFromMainList() {
	int searchMainKey = -1;
	std::cout << "Удаление элемента из главного списка" << std::endl;
	std::cout << "Ключ элемента для удаления >> ";
	enteringNumber(1, 100, searchMainKey);

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != searchMainKey) {
		current = current->nextMain;
	}

	if (current != MainHeader) {
		current->prevMain->nextMain = current->nextMain;
		current->nextMain->prevMain = current->prevMain;
		delete current;
		countMain--;
		std::cout << "Элемент с ключом " << searchMainKey << " удален из главного списка." << std::endl;
	}
	else {
		std::cout << "Элемент с ключом " << searchMainKey << " не найден в главном списке." << std::endl;
	}
}

void searchInMainDialog(int searchKey) {
	if (searchInMain(searchKey)) {
		std::cout << "Элмент с ключом " << searchKey << " найден в списке,  по счету  " << counter << " с начала списка" << std::endl;
		
		MainListNode* current = MainHeader;
		while (current->keyMainList != searchKey) {
			current = current->nextMain;
		}
		std::cout << "subList принадлежащий этому ключу: " << std::endl;
		SubListNode* subCurrent = current->sublistHeader;
		if (subCurrent == nullptr) std::cout << " список пуст " << std::endl;
		while (subCurrent != nullptr) {
			std::cout << subCurrent->data << " ";
			subCurrent = subCurrent->nextSub;
		}
		std::cout << std::endl;
	}
	else std::cout << "Элемент с ключом " << searchKey << " не найден" << std::endl;
}

void printMainListWithSublists() {
	if (MainHeader == nullptr) {
		std::cout << "Стуруктура пуста." << std::endl;
		return;
	}
	
	std::cout << "Формат выаода структуры: keyMain:[keySub keySub]" << std::endl;

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader) {
		std::cout  << current->keyMainList << ": [ ";
		if (current->sublistHeader == nullptr) {
			std::cout << "пусто ]" << std::endl; 
		}
		else {
			SubListNode* subCurrent = current->sublistHeader;
			SubListNode* temp = subCurrent; 
			do {
				std::cout << temp->data << " ";
				temp = temp->nextSub;
			} while (temp != current->sublistHeader); 
			std::cout << "]" << std::endl;
		}
		current = current->nextMain;
		
	}
}

//Все, что касается работы с эл-тами основного списка (списка)

void addToSubList() {
	int keyInMain, newSubKey, searchSubKey, positionKey;

	if (MainHeader == nullptr) {
		std::cout << "Главный список пуст, добавление не будет произведено" << std::endl;
		return;
	} 
	std::cout << "В список с каким ключом добавление >> ";
	enteringNumber(1, 100, keyInMain);
	if (!searchInMain(keyInMain)) {
		std::cout << "Элемент с ключом " << keyInMain << " отсутствует." << std::endl;
		return;
	}

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current->sublistHeader == nullptr) {
		std::cout << "Список пуст. Добавление будет произведено в конец. " << std::endl;
		std::cout << "Информационная часть добавляемого ключа >> ";
		enteringNumber(1, 100, newSubKey);
		printMainListWithSublists();


		current->sublistHeader = new SubListNode;
		current->sublistHeader->data = newSubKey;
		current->sublistHeader->nextSub = current->sublistHeader;
		current->sublistHeader->prevSub = current->sublistHeader;


		std::cout << "Главный список был пуст. Элемент с ключом " << newSubKey << " добавлен в конец (он же начало). " << std::endl;

		std::cout << "Обновленный список:" << std::endl;
		printMainListWithSublists();
		std::cout << std::endl;
		return;
	}

	std::cout << "Относительно какого элемента добавлени >> ";
	enteringNumber(1, 100, searchSubKey);

	if (searchInSubList(searchSubKey, keyInMain)) {
		int position; // 0 - before, 1 - after
		std::cout << "Добавление до = 0 или после = 1 найденного >> ";
		enteringNumber(0, 1, position);

		std::cout << "Информационная часть ключа >> ";
		enteringNumber(1, 100, newSubKey);

		SubListNode* searchNode = current->sublistHeader;
		while (searchNode != current->sublistHeader && searchNode->data != searchSubKey) {
			searchNode = searchNode->nextSub;
		}

		if (position == 0) {
			SubListNode* newNode = new SubListNode;
			newNode->data = newSubKey;
			newNode->nextSub = searchNode;
			newNode->prevSub = searchNode->prevSub;
			searchNode->prevSub->nextSub = newNode;
			searchNode->prevSub = newNode;

			if (searchNode == current->sublistHeader)
				current->sublistHeader = newNode;
		}
		else if (position == 1) {
			SubListNode* newNode = new SubListNode;
			newNode->data = newSubKey;
			newNode->nextSub = searchNode->nextSub;
			newNode->prevSub = searchNode;
			searchNode->nextSub->prevSub = newNode;
			searchNode->nextSub = newNode;
		}
		std::cout << "Элемент " << newSubKey << " вставлен "
			<< ((position == 0) ? "перед" : "после") << " элемента " << searchSubKey << std::endl;
	}
	else {
		std::cout << "Элемент с ключом " << searchSubKey << " не найден (главный список)." << std::endl; return;
	}
	std::cout << "Обновленный список:" << std::endl;
	printMainListWithSublists();
	std::cout << std::endl;
}

bool searchInSubList(int searchSubKey, int keyInMain) {
	counter = 0;
	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current->sublistHeader == nullptr) return false; //пусто

	SubListNode* subCurrent = current->sublistHeader;
	do {
		if (subCurrent->data == searchSubKey)
			return true;
		subCurrent = subCurrent->nextSub;
		counter++;
	} while (subCurrent != current->sublistHeader);

	return false; //не найден

}

void deleteFromSubList() {
	int keyInMain, searchSubKey;

	if (MainHeader == nullptr) {
		std::cout << "Главный список пуст." << std::endl;
		return;
	}

	std::cout << "Из какого списка удаляем элемент?" << std::endl;
	std::cout << "Введите ключ элемента основного списка >> ";
	enteringNumber(1, 100, keyInMain);

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current == MainHeader) {
		std::cout << "Элемент с ключом " << keyInMain << " не найден в главном списке." << std::endl;
		return;
	}

	if (current->sublistHeader == nullptr) {
		std::cout << "Подсписок пуст для элемента с ключом " << keyInMain << "." << std::endl;
		return;
	}

	std::cout << "Введите ключ удаляемого элемента в подсписке >> ";
	enteringNumber(1, 100, searchSubKey);

	SubListNode* subCurrent = current->sublistHeader;
	SubListNode* prevSub = nullptr;

	while (subCurrent != nullptr && subCurrent->data != searchSubKey) {
		prevSub = subCurrent;
		subCurrent = subCurrent->nextSub;
	}

	if (subCurrent == nullptr) {
		std::cout << "Элемент с ключом " << searchSubKey << " не найден в подсписке." << std::endl;
		return;
	}

	if (prevSub == nullptr) {
		if (subCurrent->nextSub == subCurrent) {
			delete subCurrent;
			current->sublistHeader = nullptr;
		}
		else {
			current->sublistHeader = subCurrent->nextSub;
			subCurrent->prevSub->nextSub = subCurrent->nextSub;
			subCurrent->nextSub->prevSub = subCurrent->prevSub;
			delete subCurrent;
		}
	}
	else {
		prevSub->nextSub = subCurrent->nextSub;
		subCurrent->nextSub->prevSub = prevSub;
		delete subCurrent;
	}

	std::cout << "Элемент с ключом " << searchSubKey << " удален из подсписка элемента с ключом " << keyInMain << "." << std::endl;
}

void searchInSubListDialog() {
	if (MainHeader == nullptr) {
		std::cout << "Структура пуста " << std::endl;
		return;
	}

	int keyInMain{ -1 }, searchData{ -1 };
	std::cout << "Какой ключ у mainList для поиска? " << std::endl;
	enteringNumber(1, 100, keyInMain);
	if (searchInMain(keyInMain)) {
		searchInMainDialog(keyInMain);
		std::cout << "Какой элемент найти? " << std::endl;
		enteringNumber(1, 100, searchData);
		searchInSubList(searchData, keyInMain) ? std::cout << "Искомый элемент "<< searchData<< " найден на позиции "<< counter << std::endl:
			std::cout << "Искомый элемент " << searchData << " НЕ найден " << std::endl;
		return;
	}
	else {
		std::cout << "Список с ключом " << keyInMain << " НЕ найден " << std::endl;
		return;
	}
}

void searchInAllStructure() {
	if (MainHeader == nullptr) {
		std::cout << "Список пуст. Поиск невозможен. " << std::endl; // пустой 
		return;
	}

	int counterInMain{ -1 }, counterInSub{ -1 };
	int searchKey{ -1 };
	std::cout << "Какой элемент нужно найти? " << std::endl;
	enteringNumber(1, 100, searchKey);

	MainListNode* current = MainHeader;
	do {
		counterInMain++;
		if (current->keyMainList == searchKey) {
			std::cout << "Искомый элемент " << searchKey << " является ключом списка с индексом " << counterInMain << " ";
			std::cout << "subList принадлежащий этому ключу: " << std::endl;
			SubListNode* subCurrent = current->sublistHeader;
			if (subCurrent == nullptr) std::cout << " список пуст " << std::endl;
			while (subCurrent != nullptr) {
				std::cout << subCurrent->data << " ";
				subCurrent = subCurrent->nextSub;
			}
			std::cout << std::endl;
			return;
		} else{
			counterInSub = -1;
			SubListNode* subCurrent = current->sublistHeader;
			do {
				counterInSub++;
				if (subCurrent->data == searchKey) {
					std::cout << "Искомый элемент " << searchKey << " является элементом списка с ключом " << current->keyMainList << " и расположен на позиции " << counterInSub << std::endl;
					return;
				}
				subCurrent = subCurrent->nextSub;
				counter++;
			} while (subCurrent != current->sublistHeader);
		}
		current = current->nextMain;
		counter++;
	} while (current != MainHeader);

	std::cout << "Искомый элемнет не найден. " << std::endl; //не найден
}

void searchDialog() {
	int keySearch{ -1 };
	int searchData{ -1 };

	std::cout << "1. Поиск по всей структуре " << std::endl
		<< "2. Поиск среди ключей mainList" << std::endl
		<< "3. Поиск в определенном subList" << std::endl
		<< "0. Назад" << std::endl;
	enteringNumber(0, 3, keySearch);
	switch (keySearch)
	{
	case 0:
		return;
	case 1:
		searchInAllStructure();
		break;
	case 2:
		if (MainHeader == nullptr) {
			std::cout << "Структура пуста " << std::endl;
			return;
		}
		std::cout << "Какой элемент необходимо найти? " << std::endl;
		enteringNumber(1, 100, searchData);
		searchInMainDialog(searchData);
		break;
	case 3:
		searchInSubListDialog();
		break;
	default:
		break;
	}
}