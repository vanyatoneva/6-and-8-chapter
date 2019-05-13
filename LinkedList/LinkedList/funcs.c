#include<stdio.h>
#include"ll_func.h"

Listptr makeNode(int n) {
	Listptr head = (Listptr)malloc(sizeof(List));
	head->val = n;
	head->next = NULL;
	return head;
}

/*************************************************************************************************************/

void addAtEnd(int n, Listptr head) {
	Listptr cur = head;
	Listptr l = makeNode(n);   //make node with n value
	while (cur->next != NULL) {   //goes to the last node of list
		cur = cur->next;
	}
	cur->next = l;     //makes the last node to points at the new one
}

/*************************************************************************************************************/

void push(Listptr* headp, int n) {   //take reference to head pointer
	Listptr newNode = makeNode(n);
	newNode->next = *headp;   //the new node now point at the head(the value of headp)
	*headp = newNode;
}

/*************************************************************************************************************/

int pop(Listptr* head) {
	if (*head == NULL) {
		printf("The list is empty!\n");
		return -1;         //if using exit(), it will stop the program
	}
	else {
		Listptr temp = *head;   //save the element
		*head = temp->next;     //now head points to the next element
		int v = temp->val;       //keep the value to return
		free(temp);             //delete the element
		return v;
	}
}

/*************************************************************************************************************/

void insertNth(Listptr* head, int n, int value) {
	if (n < 0 || n > getLen(*head)) {  //check if enterted position is correct
		printf("Invalid position!\n");
	}
	else {
		Listptr cur = *head;
		while (n > 1) {    //need to save the previous element - at n-1 pos
			cur = cur->next;
			n--;
		}
		Listptr newNode = makeNode(value);   
		newNode->next = cur->next;
		cur->next = newNode;
	}

}


/*************************************************************************************************************/

int count(Listptr head, int num) {
	Listptr cur = head;
	int c = 0;                  
	while (cur != NULL) {    //goes through all nodes from first to last
		if (cur->val == num) {
			c++;
		}
		cur = cur->next;
	}
	return c;
}

/*************************************************************************************************************/

int getLen(Listptr head) {
	int len = 0;
	Listptr cur = head;
	while (cur != NULL) {
		len++;
		cur = cur->next;
	}
	return len;   //if list is empty getlen will return 0
}

/*************************************************************************************************************/

int GetNth(Listptr head, int n) {   /*returns value of n-th element in the list*/
	Listptr nth = head;
	int len = getLen(head);
	if (!len) {   //First check if list is not empty
		printf("The list is empty!\n");
		return -1;
	}
	if (n >= len) {      //if n is bigger than num of list elements, print message and exits
		printf("The list has only %d elements!\n", len);
		return -1;
	}
	while (n > 0) {
		nth = nth->next;
		n--;
	}
	return nth->val;
}

/*************************************************************************************************************/


void deleteList(Listptr* headp) {
	Listptr cur = *headp;   //gets the first element
	Listptr next;           
	while (cur != NULL) {  
		next = cur->next;   //keeps the next element
		free(cur);          //deletes the current
		cur = next;         //current goes to the next
	}
	*headp = NULL;        
}


/*************************************************************************************************************/


void sortedInsert(Listptr* head, Listptr node) {
	if (*head == NULL) {   //case : the list is empty, make the node head of list
		printf("List is empty! Made new list with head the node you did!\n");
		*head = node;
		return;  
	}
	Listptr cur = *head;

	if (node->val < cur->val) {    // case : the node value is less than head value make this node head of list
		node->next = cur;
		*head = node;
		return;
	}

	Listptr nextNode = cur->next;

	if (nextNode == NULL) { cur->next = node; return; }   //case : the list only contains one element - the head
	else {
		while (node->val > nextNode->val) {    // find the position to place - in cur keep the previous element, in nextNode the next;
			cur = nextNode;
			nextNode = nextNode->next;
			if (nextNode == NULL) { //if there isn't bigger value in list, node goes at the end
				cur->next = node;
				return;
			}
		}
		node->next = nextNode;
		cur->next = node;
	}
}

/*************************************************************************************************************/

void insertSort(Listptr* head) {
	Listptr first = makeNode(pop(head));       //make new node with value the first of head - pop returns this value, and deletes the first node of head
	while (*head != NULL) {                   
		Listptr nextel = makeNode(pop(head));  //makes new node -||-
		sortedInsert(&first, nextel);          //the new node is inserted to "first", but sorted
	}
	*head =first;   //after all operations value of head is null, and "first" is list with sorted values, so we make head points to first
	
}

/*************************************************************************************************************/
void append(Listptr* appTo, Listptr* toApp) {
	Listptr last = *appTo;     
	while (last->next != NULL) {     //go to the last element of first list
		last = last->next;
	}
	while (*toApp != NULL) {          //get the value of next element and deleting the el., make node with this value and append it to the end of first
		last->next = makeNode(pop(toApp));
		last = last->next;
	}
	//last->next = *toApp;        //append second to the first - in this case can't delete the second one
	//deleteList(toApp);
}

/*************************************************************************************************************/

void frontBackSplit(Listptr head, Listptr* front, Listptr* back) {
	int l = getLen(head);
	int m = l / 2;         //m is half of lentgh
	Listptr b, f;          //to keep the lists
	Listptr temp = makeNode(pop(&head));  //save the first element int temp and f points to it
	f = temp;
	if (l % 2 == 0) {                  //to the middle of list, use temp to store the element in f
		while (m > 1) {
			temp->next = makeNode(pop(&head));
			temp = temp->next;
			m--;
		}
	}
	else {
		while (m > 0) {
			temp->next = makeNode(pop(&head));
			temp = temp->next;
			m--;
		}
	} 
	temp = makeNode(pop(&head));  //then go to first element after the middle, and make b points to it
	b = temp;
	while (head != NULL) {
		temp->next = makeNode(pop(&head));
		temp = temp->next;
	}
	*front = f;     //now make front and back references to f and b, in the proccess head is deleted by pop func.
	*back = b;
}


/*************************************************************************************************************/

void printList(Listptr head) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	else {
		Listptr cur = head;
		while (cur->next != NULL) {
			printf("%d --> ", cur->val);
			cur = cur->next;
		} 
		printf("%d\n", cur->val);   //print the last element without --> 
	}
}