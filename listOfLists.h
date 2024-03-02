
struct SublistNode {
    int data;
    SublistNode* next;

    SublistNode(int value) : data(value), next(nullptr) {}
};


struct MainListNode {
    SublistNode* sublist;
    MainListNode* next;
    int countLists{ 0 };
    MainListNode() : sublist(nullptr), next(nullptr) {}
};

extern int countMain;


MainListNode* createMainListNode();
SublistNode* createSublistNode(int value);

void printStructure(MainListNode* mainList);
bool findElement(MainListNode* mainList, int value, int& mainIndex, int& subIndex);

void addToSublist(MainListNode* mainList, int mainIndex, int value);
void addToSublistAfter(MainListNode* mainList, int mainIndex, int afterValue, int value);
void addToSublistBefore(MainListNode* mainList, int mainIndex, int beforeValue, int value);
void removeFromSublist(MainListNode*& mainList, int mainIndex, int value);
void addToEmptySublist(MainListNode* mainList, int mainIndex, int value);

void removeFromMainList(MainListNode*& mainList, int mainIndex);
void addEmptySublistToMainList(MainListNode*& mainList, int mainIndex, int position);
