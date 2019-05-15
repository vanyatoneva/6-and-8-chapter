#include<stdio.h>
#include"ll_func.h"

void otherfunc(Listptr f, Listptr s, Listptr t);


main() {
	Listptr f, s, t;
	f = s = t = NULL;
	char c;
	int p, n;
	printf("To make a list press 1\n");
	printf("To push node press 2\n");
	printf("To pop a press 3\n");
	printf("To delete list press 4\n");
	printf("To see length of list press 5\n");
	printf("To print the list press 6\n");
	printf("To insert element in n-th position press 7\n");
	printf("To get the element in n-th position, press 8\n");
	printf("For other actions press 9\n");
	printf("To add element in the end of the list press 0\n");
	printf("To exit the program press E\n");
	printf("\n\n");
	while ((c = getchar()) != 'E') {
		switch (c) {
		case '1':
			printf("Please choose a value for the node : ");
			if (f != NULL) {
				printf("This will delete the information of the list and make new\n");
			}
			scanf("%d", &n);
			f = makeNode(n);
			getchar();
			break;
		case '2':
			printf("Please choose a value for the node : ");
			scanf("%d", &n);
			push(&f, n);
			getchar();
			break;
		case '3':
			n = pop(&f);
			if (n != -1) {
				printf("The element you deleted has value : %d\n", n);
			}
			getchar();
			break;
		case '4':
			deleteList(&f);
			getchar();
			break;
		case '5':
			printf("The length of list is : %d\n", getLen(f));
			getchar();
			break;
		case '6':
			printf("The list is : ");
			printList(f);
			getchar();
			break;
		case '7':
			printf("Enter the value you want to insert : ");
			scanf("%d", &n);
			getchar();
			printf("Enter the position to insert it : ");
			scanf("%d", &p);
			getchar();
			insertNth(&f, p, n);
			break;
		case '8':
			printf("Enter the position you want to see : ");
			scanf("%d", &p);
			if (GetNth(f, p) != -1) {
				printf("The element in %dth position has value : %d\n", p, GetNth(f, p));
			}
			getchar();
			break;
		case '9':
			otherfunc(&f, &s, &t);
			getchar();
			break;
		case '0':
			printf("Enter the value you want to insert : ");
			scanf("%d", &n);
			getchar();
			addAtEnd(n, f);
			break;
		default:
			printf("Invalid input!\n");
			break;

		}
		printf("\n\nTo make a list press 1\n");
		printf("To push node press 2\n");
		printf("To pop a press 3\n");
		printf("To delete list press 4\n");
		printf("To see length of list press 5\n");
		printf("To print the list press 6\n");
		printf("To insert element in n-th position press 7\n");
		printf("To get the element in n-th position, press 8\n");
		printf("For other actions press 9\n");
		printf("To add element in the end of the list press 0\n");
		printf("To exit the program press E\n");
		printf("\n\n");
	}

}


void otherfunc(Listptr* f, Listptr* s, Listptr* t) {
	char c; 
	int num, num2;
	getchar();
	printf("\n\nTo sort the list press 0\n");
	printf("To insert element in sorted list press 1\n");
	printf("To append one list to another press 2\n");
	printf("To split a list at two halfs press 3\n");
	printf("To remove duplicates of the list press 4\n");
	printf("To split the elements alternating press 5\n");
	printf("To merge shufle two lists press 6\n");
	printf("To merge two sorted lists press 7\n");
	printf("To see the intersection of two lists press 8\n");
	printf("To reverse list press 9\n");
	printf("To pritn the list press P\n");
	printf("To return press R\n");
	printf("\n\n");
	while ((c = getchar()) != 'R') {
		switch (c) {
		case '0':
			printf("Choose a list to sort - 1 for the first, 2 for the second, 3 for thirth : ");
			scanf("%d", &num);
			if (num == 1) {
				insertSort(f);
			}
			else if (num == 2) {
				insertSort(s);
			}
			else if (num == 3) {
				mergeSort(t);
			}
			else{
				printf("Inavlid input!\n");
			}
			getchar();
			break;
		case '1':
			if (isSorted(f)) {
				printf("Enter value to insert : ");
				scanf("%d", &num);
				sortedInsert(f, makeNode(num));
			}
			else {
				printf("The list is not sorted!\n");
			}
			getchar();
			break;
		case '2':
			printf("Enter the list to append : ");
			scanf("%d", &num);
			getchar();
			printf("Enter from where : ");
			scanf("%d", &num2);
			if (num == 1) {
				if (num2 == 2) {
					append(f, s);
					//*s = NULL;
				}
				else if (num2 == 3) {
					append(f, t);
					//*t = NULL;
				}
				else {
					printf("Invalid second input! Can choose from 2 or 3!\n");
				}
			}
			else if (num == 2) {
				if (num2 == 1) {
					append(s, f);
					//*f = NULL;
				}
				else if (num2 == 3) {
					append(s, t);
					//*t = NULL;
				}
				else {
					printf("Invalid second input! Can choose from 1 or 3!\n");
				}
			}
			else if (num == 3) {
				if (num2 == 1) {
					append(t, f);
					//*f = NULL;
				}
				else if (num2 == 2) {
					append(t, s);
					//*s = NULL;
				}
				else {
					printf("Invalid second input! Can choose from 1 or 2!\n");
				}
			}
			else {
				printf("Invalid input! Choose from 1, 2 or 3\n");
			}
			getchar();
			break;
		case '3':
			frontBackSplit(*f, s, t);
			*f = NULL;
			getchar();
			break;
		case '4':
			printf("Choose list to remove duplicates from : ");
			scanf("%d", &num);
			getchar();
			if (num == 1) {
				removeDuplicates(f);
			}
			else if (num == 2) {
				removeDuplicates(s);
			}
			else if (num == 3) {
				removeDuplicates(t);
			}
			else {
				printf("Invalid input! Choose from 1, 2 or 3!");
			}
			break;
		case '5':
			printf("Choose list to split : ");
			scanf("%d", &num);
			getchar();
			if (num == 1) {
				alternatingSplit2(*f, s, t);
				*f = NULL;
			}
			else if (num == 2) {
				alternatingSplit2(*s, f, t);
				*s = NULL;
			}
			else if (num == 3) {
				alternatingSplit2(*t, f, s);
				*t = NULL;
			}
			else {
				printf("Invalid input! Choose from 1, 2 or 3!");
			}
			break;
		case '6':
			printf("Which lists to merge ? ");
			scanf("%d", &num);
			scanf("%d", &num2);
			if (num == 1) {
				if (num2 == 2) {
					*t = shuffleMerge(*f, *s);
				}
				else if (num2 == 3) {
					*s = shuffleMerge(*f, *t);
				}
				else {
					printf("Invalid input for second list!\n");
				}
			}
			else if (num == 2) {
				if (num2 == 1) {
					 *t = shuffleMerge(*s, *f);
				}
				else if (num2 == 3) {
					*f = shuffleMerge(*s, *t);
				}
				else {
					printf("Invalid input for second list!\n");
				}
			}
			else if (num == 3) {
				if (num2 == 1) {
					*s = shuffleMerge(*t, *f);
				}
				else if (num2 == 2) {
					*f = shuffleMerge(*t, *s);
				}
				else {
					printf("Invalid input for second list!\n");
				}
			}
			getchar();
			break;
		case '7':
			sortedMerge(*f, *s);
			getchar();
			break;
		case '8':
			*f = sortedIntersection(*s, *t);
			getchar();
			break;
		case '9':
			printf("To reverse recursively press 1, or 2 if not : ");
			scanf("%d", &num);
			if (num == 1) {
				reverseRec(f);
			}
			else if (num == 2) {
				reverse(f);
			}
			else {
				printf("Invalid input!");
			}
			getchar();
			break;
		case 'P':
			printf("Choose list to print : ");
			scanf("%d", &num);
			getchar();
			if (num == 1) {
				printList(*f);
			}
			else if (num == 2) {
				printList(*s);
			}
			else if (num == 3) {
				printList(*t);
			}
			else {
				printf("Invalid input! The lists are only 3!\n");
			}
			break;
		default:
			printf("Invalid input!\n");
			break;

		}
		printf("\n\n");
		printf("To sort the list press 0\n");
		printf("To insert element in sorted list press 1\n");
		printf("To append one list to another press 2\n");
		printf("To split a list at two halfs press 3\n");
		printf("To remove duplicates of the list press 4\n");
		printf("To split the elements alternating press 5\n");
		printf("To merge shufle two lists press 6\n");
		printf("To merge two sorted lists press 7\n");
		printf("To see the intersection of two lists press 8\n");
		printf("To reverse list press 9\n");
		printf("To return press R\n");
		printf("\n\n");
	}

	
}
