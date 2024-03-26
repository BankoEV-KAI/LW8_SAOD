#include "listOfLists.h"
#include "menu.h"
#include <iostream>

int countMain = 0;
int countSubLists = 0;
int counter = 0, findKey = 0;
MainListNode* MainHeader = nullptr;

//���, ��� �������� ������ � �������� �������

void addToMainList() {
	int searchMainKey = -1;
	if (MainHeader == nullptr) {
		int newMainKey = 0;
		std::cout << "������ ����. ���������� ����� ����������� ���� ���. " << std::endl;
		std::cout << "�������������� ����� ������������ ����� >> ";
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
		
		std::cout << "������� ������ ��� ����. ������� � ������ " << newMainKey << " �������� � ����� (�� �� ������). " << std::endl;
		countMain++;
		std::cout << "����������� ������:" << std::endl;
		printMainListWithSublists();
		std::cout << std::endl;
		return;
	}

	std::cout << "���������� �������� � ������� ������" << std::endl;
	std::cout << "������������ ������ �������� ��������� >> ";
	enteringNumber(1, 100, searchMainKey);
	if (searchInMain(searchMainKey)) {
		int position; // 0 - before, 1 - after
		std::cout << "���������� �� = 0 ��� ����� = 1 ���������� >> ";
		enteringNumber(0, 1, position);

		int newMainKey = 0;
		std::cout << "�������������� ����� ����� >> ";
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

		std::cout << "������� " << newMainKey << " �������� "
			<< ((position == 0) ? "�����" : "�����") << " �������� " << searchMainKey
			<< ". ���������� ��������� � ������: " << countMain << std::endl;
	}
	else {
		std::cout << "������� � ������ " << searchMainKey << " �� ������ (������� ������)." << std::endl; return;
	}
	std::cout << "����������� ������:" << std::endl;
	printMainListWithSublists();
	std::cout << std::endl;
}

bool searchInMain(int searchKey) {
	counter = 0;
	if (MainHeader == nullptr) return false; // ������ 

	MainListNode* current = MainHeader;
	do {
		if (current->keyMainList == searchKey)
			return true;
		current = current->nextMain;
		counter++;
	} while (current != MainHeader);

	return false; //�� ������
}

void deleteFromMainList() {
	int searchMainKey = -1;
	std::cout << "�������� �������� �� �������� ������" << std::endl;
	std::cout << "���� �������� ��� �������� >> ";
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
		std::cout << "������� � ������ " << searchMainKey << " ������ �� �������� ������." << std::endl;
	}
	else {
		std::cout << "������� � ������ " << searchMainKey << " �� ������ � ������� ������." << std::endl;
	}
}

void searchInMainDialog(int searchKey) {
	if (searchInMain(searchKey)) {
		std::cout << "������ � ������ " << searchKey << " ������ � ������,  �� �����  " << counter << " � ������ ������" << std::endl;
		
		MainListNode* current = MainHeader;
		while (current->keyMainList != searchKey) {
			current = current->nextMain;
		}
		std::cout << "subList ������������� ����� �����: " << std::endl;
		SubListNode* subCurrent = current->sublistHeader;
		if (subCurrent == nullptr) std::cout << " ������ ���� " << std::endl;
		while (subCurrent != nullptr) {
			std::cout << subCurrent->data << " ";
			subCurrent = subCurrent->nextSub;
		}
		std::cout << std::endl;
	}
	else std::cout << "������� � ������ " << searchKey << " �� ������" << std::endl;
}

void printMainListWithSublists() {
	if (MainHeader == nullptr) {
		std::cout << "���������� �����." << std::endl;
		return;
	}
	
	std::cout << "������ ������ ���������: keyMain:[keySub keySub]" << std::endl;

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader) {
		std::cout  << current->keyMainList << ": [ ";
		if (current->sublistHeader == nullptr) {
			std::cout << "����� ]" << std::endl; 
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

//���, ��� �������� ������ � ��-���� ��������� ������ (������)

void addToSubList() {
	int keyInMain, newSubKey, searchSubKey, positionKey;

	if (MainHeader == nullptr) {
		std::cout << "������� ������ ����, ���������� �� ����� �����������" << std::endl;
		return;
	} 
	std::cout << "� ������ � ����� ������ ���������� >> ";
	enteringNumber(1, 100, keyInMain);
	if (!searchInMain(keyInMain)) {
		std::cout << "������� � ������ " << keyInMain << " �����������." << std::endl;
		return;
	}

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current->sublistHeader == nullptr) {
		std::cout << "������ ����. ���������� ����� ����������� � �����. " << std::endl;
		std::cout << "�������������� ����� ������������ ����� >> ";
		enteringNumber(1, 100, newSubKey);
		printMainListWithSublists();


		current->sublistHeader = new SubListNode;
		current->sublistHeader->data = newSubKey;
		current->sublistHeader->nextSub = current->sublistHeader;
		current->sublistHeader->prevSub = current->sublistHeader;


		std::cout << "������� ������ ��� ����. ������� � ������ " << newSubKey << " �������� � ����� (�� �� ������). " << std::endl;

		std::cout << "����������� ������:" << std::endl;
		printMainListWithSublists();
		std::cout << std::endl;
		return;
	}

	std::cout << "������������ ������ �������� ��������� >> ";
	enteringNumber(1, 100, searchSubKey);

	if (searchInSubList(searchSubKey, keyInMain)) {
		int position; // 0 - before, 1 - after
		std::cout << "���������� �� = 0 ��� ����� = 1 ���������� >> ";
		enteringNumber(0, 1, position);

		std::cout << "�������������� ����� ����� >> ";
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
		std::cout << "������� " << newSubKey << " �������� "
			<< ((position == 0) ? "�����" : "�����") << " �������� " << searchSubKey << std::endl;
	}
	else {
		std::cout << "������� � ������ " << searchSubKey << " �� ������ (������� ������)." << std::endl; return;
	}
	std::cout << "����������� ������:" << std::endl;
	printMainListWithSublists();
	std::cout << std::endl;
}

bool searchInSubList(int searchSubKey, int keyInMain) {
	counter = 0;
	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current->sublistHeader == nullptr) return false; //�����

	SubListNode* subCurrent = current->sublistHeader;
	do {
		if (subCurrent->data == searchSubKey)
			return true;
		subCurrent = subCurrent->nextSub;
		counter++;
	} while (subCurrent != current->sublistHeader);

	return false; //�� ������

}

void deleteFromSubList() {
	int keyInMain, searchSubKey;

	if (MainHeader == nullptr) {
		std::cout << "������� ������ ����." << std::endl;
		return;
	}

	std::cout << "�� ������ ������ ������� �������?" << std::endl;
	std::cout << "������� ���� �������� ��������� ������ >> ";
	enteringNumber(1, 100, keyInMain);

	MainListNode* current = MainHeader->nextMain;
	while (current != MainHeader && current->keyMainList != keyInMain) {
		current = current->nextMain;
	}

	if (current == MainHeader) {
		std::cout << "������� � ������ " << keyInMain << " �� ������ � ������� ������." << std::endl;
		return;
	}

	if (current->sublistHeader == nullptr) {
		std::cout << "��������� ���� ��� �������� � ������ " << keyInMain << "." << std::endl;
		return;
	}

	std::cout << "������� ���� ���������� �������� � ��������� >> ";
	enteringNumber(1, 100, searchSubKey);

	SubListNode* subCurrent = current->sublistHeader;
	SubListNode* prevSub = nullptr;

	while (subCurrent != nullptr && subCurrent->data != searchSubKey) {
		prevSub = subCurrent;
		subCurrent = subCurrent->nextSub;
	}

	if (subCurrent == nullptr) {
		std::cout << "������� � ������ " << searchSubKey << " �� ������ � ���������." << std::endl;
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

	std::cout << "������� � ������ " << searchSubKey << " ������ �� ��������� �������� � ������ " << keyInMain << "." << std::endl;
}

void searchInSubListDialog() {
	if (MainHeader == nullptr) {
		std::cout << "��������� ����� " << std::endl;
		return;
	}

	int keyInMain{ -1 }, searchData{ -1 };
	std::cout << "����� ���� � mainList ��� ������? " << std::endl;
	enteringNumber(1, 100, keyInMain);
	if (searchInMain(keyInMain)) {
		searchInMainDialog(keyInMain);
		std::cout << "����� ������� �����? " << std::endl;
		enteringNumber(1, 100, searchData);
		searchInSubList(searchData, keyInMain) ? std::cout << "������� ������� "<< searchData<< " ������ �� ������� "<< counter << std::endl:
			std::cout << "������� ������� " << searchData << " �� ������ " << std::endl;
		return;
	}
	else {
		std::cout << "������ � ������ " << keyInMain << " �� ������ " << std::endl;
		return;
	}
}

void searchInAllStructure() {
	if (MainHeader == nullptr) {
		std::cout << "������ ����. ����� ����������. " << std::endl; // ������ 
		return;
	}

	int counterInMain{ -1 }, counterInSub{ -1 };
	int searchKey{ -1 };
	std::cout << "����� ������� ����� �����? " << std::endl;
	enteringNumber(1, 100, searchKey);

	MainListNode* current = MainHeader;
	do {
		counterInMain++;
		if (current->keyMainList == searchKey) {
			std::cout << "������� ������� " << searchKey << " �������� ������ ������ � �������� " << counterInMain << " ";
			std::cout << "subList ������������� ����� �����: " << std::endl;
			SubListNode* subCurrent = current->sublistHeader;
			if (subCurrent == nullptr) std::cout << " ������ ���� " << std::endl;
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
					std::cout << "������� ������� " << searchKey << " �������� ��������� ������ � ������ " << current->keyMainList << " � ���������� �� ������� " << counterInSub << std::endl;
					return;
				}
				subCurrent = subCurrent->nextSub;
				counter++;
			} while (subCurrent != current->sublistHeader);
		}
		current = current->nextMain;
		counter++;
	} while (current != MainHeader);

	std::cout << "������� ������� �� ������. " << std::endl; //�� ������
}

void searchDialog() {
	int keySearch{ -1 };
	int searchData{ -1 };

	std::cout << "1. ����� �� ���� ��������� " << std::endl
		<< "2. ����� ����� ������ mainList" << std::endl
		<< "3. ����� � ������������ subList" << std::endl
		<< "0. �����" << std::endl;
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
			std::cout << "��������� ����� " << std::endl;
			return;
		}
		std::cout << "����� ������� ���������� �����? " << std::endl;
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