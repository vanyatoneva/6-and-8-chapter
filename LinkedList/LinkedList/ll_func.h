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
void append(Listptr* appTo, Listptr* toApp);  //Appends the second to first, then deletes the second
void frontBackSplit(Listptr head, Listptr* front, Listptr* back);   //splits the list at half : at front keep the first, at back second
void removeDuplicates(Listptr* head);          //removes duplicates in sorted linked list
void moveNode(Listptr* to, Listptr* from);     // move the first node from second list to the begin of the first
void alternatingSplit(Listptr head, Listptr* first, Listptr* sec); //even elem. goes to the first, odd in the second - new lists are reversed !!
void alternatingSplit2(Listptr head, Listptr* first, Listptr* sec); // this one makes the lists in the same order like the orig.
Listptr shuffleMerge(Listptr f, Listptr s); //takes the two lists and makes it one - 0th of(1), 0th of(2), 1st of(1), 1st of(2) - in this order
Listptr sortedMerge(Listptr f, Listptr s);   // takes two sorted lists, and make them one sorted list
void mergeSort(Listptr* head);     //sort recursively
Listptr sortedIntersection(Listptr f, Listptr s); //makes new list, representing the intersection of the two given. Given lists must be in increasing order
void reverse(Listptr* head); //reverses list
void reverseRec(Listptr* head); //reverses list recursively
int isSorted(Listptr* head);    //returns 1 if list is sorted, 0 if not

#endif // ! LINLIST

