
struct SubListNode {
    int data;
    SubListNode* nextSub;
    SubListNode* prevSub;
    //SubListNode(int value) : data(value), nextSub(nullptr), prevSub(nullptr){}
};

//сделать двунаправленными (закольцевать) + бахнуть заголовки в мейн лист и саб лист 

struct MainListNode {
    int keyMainList; //информационная часть главнного списка 
    SubListNode* sublistHeader;
    MainListNode* nextMain;
    MainListNode* prevMain;
    MainListNode() : sublistHeader(nullptr), nextMain(nullptr), prevMain(nullptr) {}
};

//тогда функций становится  по минимуму (добавление с передачей bef/aft, что определяет положение добавление + просмотр ключ : (саб лист) +
//  удаление элмента по ключу из мейн листа (с удаление всего саб листа) + 
// удаление элемента из саб листа по ключу) 

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
