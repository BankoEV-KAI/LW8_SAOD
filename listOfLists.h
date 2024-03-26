
struct SubListNode {
    int data;
    SubListNode* nextSub;
    SubListNode* prevSub;
    //SubListNode(int value) : data(value), nextSub(nullptr), prevSub(nullptr){}
};

//������� ���������������� (������������) + ������� ��������� � ���� ���� � ��� ���� 

struct MainListNode {
    int keyMainList; //�������������� ����� ��������� ������ 
    SubListNode* sublistHeader;
    MainListNode* nextMain;
    MainListNode* prevMain;
    MainListNode() : sublistHeader(nullptr), nextMain(nullptr), prevMain(nullptr) {}
};

//����� ������� ����������  �� �������� (���������� � ��������� bef/aft, ��� ���������� ��������� ���������� + �������� ���� : (��� ����) +
//  �������� ������� �� ����� �� ���� ����� (� �������� ����� ��� �����) + 
// �������� �������� �� ��� ����� �� �����) 

extern int countMain;
extern int countSubLists;
extern MainListNode* MainHeader;

void initMainList();

void addToMainList();

bool searchInMain(int searchKey);

void deleteFromMainList();

void searchInMainDialog(int searchKey);

void printMainListWithSublists();

void addToSubList();

bool searchInSubList(int searchSubKey, int keyInMain);

void deleteFromSubList();

void searchInSubListDialog();

void searchInAllStructure();

void searchDialog();
