#include<stdio.h>
#include"ll_func.h"



main() {
	/*Listptr head = makeNode(5);    //make  list
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
	//printList(head);
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

	Listptr head1 = makeNode(81);   //new list
	deleteList(&head);
	//push(&head, 2);
	//push(&head, 3);
	//push(&head, 4);
	//push(&head, 5);
	//frontBackSplit(head, &head1, &head2);
	//printList(head1);
	//printList(head2);
	for (int i = 20; i > 6; i--) {
		if (i == 8) {
			for (int j = 0; j < 4; j++) {
				push(&head, i);
			}
		}
		push(&head, i);
	}
	for (int i = 14; i > 3; i--) {
		push(&head1, i);
	}
	printf("First list : \n");
	printList(head);
	printf("Second list : \n");
	printList(head1);
	//moveNode(&head, &head1);
	//printList(head);
	//printList(head1);
	append(&head, &head1);
	printf("Now the first list is : \n");
	printList(head);
	insertSort(&head);
	printList(head);
	removeDuplicates(&head);
	printList(head);
	//printf("And the second : \n");
	//printList(head1);
	//frontBackSplit(head, &head1, &head2);
	//printf("First : \n");
	//printList(head1);
	//printf("Second : \n");
	//printList(head2);
	deleteList(head2);
	printf("********************************splitting********************************\n");
	alternatingSplit2(head, &head1, &head2);
	printList(head1);
	addAtEnd(44, head2);
	addAtEnd(45, head2);
	printList(head2);
	head = shuffleMerge(head1, head2);
	printf("after shuffle merge : \n");
	printList(head);
	

	

	Listptr h, h1, h2;
	h2 = NULL;
	h1 = makeNode(81);
	push(&h1, 44);
	push(&h1, 21);
	push(&h1, 12);
	push(&h1, 2);
	push(&h1, 1);
	h = sortedMerge(h1, h2);
	printList(h);
	h2 = makeNode(64);
	push(&h2, 63);
	push(&h2, 8);
	push(&h2, 4);
	printList(h1);
	printList(h2);
	h = shuffleMerge(h1, h2);
	printList(h);
	mergeSort(&h);
	printList(h); */


	Listptr a, b;
	a = makeNode(20); b = makeNode(18);
	push(&a, 17);  push(&a, 16); push(&a, 14);  push(&a, 13); push(&a, 12); push(&a, 10); push(&a, 8); push(&a, 6); push(&a, 3);
	push(&b, 19);  push(&b, 17); push(&b, 15); push(&b, 10); push(&b, 9); push(&b, 7); push(&b, 5); push(&b, 3);
	printList(a);
	printList(b);
	Listptr c = sortedIntersection(a, b);
	printList(c);
	reverseRec(&a);
	printList(a);
}