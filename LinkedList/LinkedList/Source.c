#include<stdio.h>
#include"ll_func.h"



main() {
	Listptr head = makeNode(5);    //make  list
	addAtEnd(1, head);
	addAtEnd(5, head);
	addAtEnd(3, head);
	addAtEnd(7, head);
	push(&head, 10);
	printf("The element with value %d was pushed to list\n", pop(&head));
	insertNth(&head, 3, 8); 
	
	int nth = GetNth(head, 3);
	if (nth != -1) {   // getnth return -1 if n is bigger than length of list, or the list is empty and the function prints the error message
		printf("%dth element is %d\n", 3, nth);
	}

	printf("5 is %d times in the list\n", count(head, 5));	

	insertSort(&head);   //sort the list
	printList(head);


	//deleteList(&head);  
	//pop(&head);
	//printf("Length of list is %d\n", getLen(head));
	//Listptr n = makeNode(2);  
	//sortedInsert(&head, n);  
	//printList(head);



	Listptr nodeToAdd = makeNode(7);
	Listptr head2 = makeNode(11);
	push(&head2, 9); push(&head2, 8); push(&head2, 5); push(&head2, 3); push(&head2, 2); //new list made
	sortedInsert(&head2, nodeToAdd);  //insert element in right position in sorted list
	Listptr bigger = makeNode(13);
	sortedInsert(&head2, bigger);
	Listptr one = makeNode(1);
	sortedInsert(&head2, one);
	printList(head2);


	append(&head, &head2);   //append second to first list
	printList(head);
	printList(head2);

	Listptr head1;   //new list
	deleteList(&head);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	frontBackSplit(head, &head1, &head2);
	printList(head1);
	printList(head2);
}