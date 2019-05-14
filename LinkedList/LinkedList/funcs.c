#include<stdio.h>
#include<stdlib.h>
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
	if (headp == NULL || *headp == NULL) {
		printf("List is empty!\n");
		return;
	}
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

void removeDuplicates(Listptr* head) {
	if (head == NULL) {
		printf("List is empty!\n");
		return;
	}
	Listptr temp = *head;
	while (temp->next != NULL) {   
		if (temp->val == temp->next->val) {
			Listptr todel = temp->next;    
			temp->next = todel->next;
			free(todel);
		}
		else {       //if temp was the same like next one, check again - this value can be in the list more than two times, only if different go to next
			temp = temp->next;
		}
	}
}

/*************************************************************************************************************/

void moveNode(Listptr* to, Listptr* from) {
	int n = (*from)->val;   //get the value of first elem of sec list
	push(to, n);           //push if to the first one
	pop(from);              //remove the first elem of second list
}

/*************************************************************************************************************/

void alternatingSplit(Listptr head, Listptr* first, Listptr* sec) { //using movenode function => the new lists are reversed
	int i, l = getLen(head);
	for (i = 0; i < l; i++) {
		if (i % 2 == 0) {  //if even elem. move to first, otherwise in second
			moveNode(first, &head);
		}
		else {
			moveNode(sec, &head);
		}
	}

}

/*************************************************************************************************************/

void alternatingSplit2(Listptr head, Listptr* first, Listptr* sec) {  //after the function head still keeps last values???
	int i, l = getLen(head);
	moveNode(first, &head);  //getting the first two element of the list
	moveNode(sec, &head);
		for (i = 2; i < l; i++) {  //from 3th element to the end, move if even - to the end of the first, odd => to the end of second
			if(i%2 == 0){
				int n = pop(&head);    
				addAtEnd(n, *first);
			}
			else {
				int n = pop(&head);
				addAtEnd(n, *sec);
			}
	}
		deleteList(&head);
}


/*************************************************************************************************************/

Listptr shuffleMerge(Listptr f, Listptr s) {
	Listptr merged = makeNode(pop(&f));    //make new list - begins with first elem of the first
	while (f != NULL && s != NULL) {       //while there are elem. in the two
		addAtEnd(pop(&s), merged);         //first get from second one(started with the first)
		addAtEnd(pop(&f), merged);         //than from first
	}
	if (f == NULL && s != NULL) {         //if reached the end of first, but there are more element in the second, get them
		while (s != NULL) {
			addAtEnd(pop(&s), merged);
		}
	}
	else if (f != NULL && s == NULL) {     // -||-
		while (f != NULL) {
			addAtEnd(pop(&f), merged);
		}
	}
	return merged;
}

/*************************************************************************************************************/

Listptr sortedMerge(Listptr f, Listptr s) {
	if (f == NULL || s == NULL) {            //checking if lists have elements, if one is empty return null instead of coping the other one
		printf("One of lists is empty!\n");
		return NULL;
	}
	else {
		int fe = f->val < s->val ? pop(&f) : pop(&s);    //sets the smaller element for first  
		Listptr merged = makeNode(fe);
		while (f != NULL && s != NULL) {                //while two list have elements, add the smaller of them
			int min = f->val < s->val ? pop(&f) : pop(&s);
			addAtEnd(min, merged);
		}
		if (f == NULL && s != NULL) {     //if end of one of list is reached, get the elements of other(they are already sorteD)
			while (s != NULL) {
				addAtEnd(pop(&s), merged);
			}
		}
		else if (f != NULL && s == NULL) {
			while (f != NULL) {
				addAtEnd(pop(&f), merged);
			}
		}
		return merged;
	}

}

/*************************************************************************************************************/

void mergeSort(Listptr* head) {
	if (*head == NULL || (*head)->next == NULL) {   //if last element reached, return
		return;
	}
	else {
		Listptr f, b;     
		frontBackSplit(*head, &f, &b);  
		mergeSort(&f);                  
		mergeSort(&b);                  
		*head = sortedMerge(f, b);      
	}
	
}


/*************************************************************************************************************/

Listptr sortedIntersection(Listptr f, Listptr s) {
	Listptr intersect = NULL;  //create new list
	Listptr firstL = f;         //make new pointers to check elements of lists, without changing them 
	Listptr secL = s;
	while (firstL != NULL && secL != NULL) { 
		if (firstL->val > secL->val) {   //if the value of first list is bigger than the second, check the next element of second(they may be same)
			secL = secL->next;
		}
		else if (secL->val > firstL->val) {  //also if the second value is bigger than first
			firstL = firstL->next;
		}
		else {  //if elements are with same value
			if (intersect == NULL) {    //if there are no elements, make new 
				intersect = makeNode(firstL->val);
			}
			else {                          //or if there are elements, add it to the end of the list and move to the next elements of the lists
				addAtEnd(firstL->val, intersect);
			}
			firstL = firstL->next;  
			secL = secL->next;
		}
	}
	return intersect;
}

/*************************************************************************************************************/

void reverse(Listptr* head) {
	int l = getLen((*head));
	int i , mid = l/2;
	i = 0;
	Listptr first, last, cur;
	while (i < mid) {
		cur = first = *head;
		last = cur->next;
		int j = i;
		while (j > 0) {
			first = first->next;
		}
		int k = 0;
		while (k < l) {
			cur = cur->next;
			last = last->next;
		}
		if (i == 0) {
			last->next = first->next;
			cur->next = first;
			first->next = NULL;
			*head = last;
		}
		else {

		}
		l--;
		i++;
	}
}

/*************************************************************************************************************/

void reverseRec(Listptr* head) {
	if (*head == NULL || (*head)->next == NULL) {  //if no elements or only one - return
		return;
	}
	else {
		Listptr f, l;
		frontBackSplit(*head, &f, &l);    
		reverseRec(&f);                   
		reverseRec(&l);
		append(&l, &f);
		*head = l;
	}
	
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