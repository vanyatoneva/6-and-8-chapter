#ifndef  LINLIST
#define LINLIST

typedef struct list{
	int val;
	struct list* next;
}List;

typedef List* Listptr;

Listptr makeNode(int n);                //makes node with n value and null pointer
void addAtEnd(int n, Listptr head);     // adds new node at the end of list
void printList(Listptr head);           //prints the list from first to last element
int count(Listptr head, int num);  //returns how many times num is in the list
int GetNth(Listptr head, int n);   //returns the value of n-th element in list
int getLen(Listptr head);           //returns lenght of list
void push(Listptr* headp, int n);   //push element to the begin of list
int pop(Listptr* head);             //deletes the first element
void deleteList(Listptr* head);     //deletes all nodes of list
void insertNth(Listptr* head, int n, int value);    //insert element in nth position
void sortedInsert(Listptr* head, Listptr node);    //inserts the node in the correct position in increasing sorted list
void insertSort(Listptr* head);                    //sorts the list in icreasing order
void append(Listptr* appTo, Listptr* toApp);  //Appends the secpond to first, then deletes the second
void frontBackSplit(Listptr head, Listptr* front, Listptr* back);   //splits the list at half : at front keep the first, at back second

#endif // ! LINLIST

