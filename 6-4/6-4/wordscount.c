#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"wordscount.h"




Wordptr makeRoot(Wordptr root, char* word) {            /*creates root of the list*/
	Wordptr temp = (Wordptr)malloc(sizeof(Word));
	if (root == NULL) {
		temp->word = (char*)malloc(sizeof(word));
		strcpy(temp->word, word);
		temp->count = 1;
		temp->next = NULL;
		root = temp;
	}
	else {
		printf("Root is already made\n");
	}
	return root;
}

int searchWord(Wordptr root, char* word) {   /*if the word is already in the list, increases the count and returns 1, otherwise returns 0(need to check if it did)*/
	Wordptr temp = root;
	if (root == NULL) {
		printf("There are no elements in list!\n");
	}
	while (temp != NULL) {
		if (strcmp(temp->word, word) == 0) {   /*if found the world, return 1 - there's no need to go to the end of list*/
			temp->count++;
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

void addWord(Wordptr root, char* word) {         /*if the word is new, makes new node*/
	if (root == NULL) {
		makeRoot(root, word);
	}
	Wordptr newWord = (Wordptr)malloc(sizeof(Word));
	newWord->count = 1;
	newWord->next = NULL;
	newWord->word = (char*)malloc(sizeof(word));
	strcpy(newWord->word, word);
	Wordptr temp = root;
	while (temp->next != NULL) {  /*goes to the end of list*/
		temp = temp->next;
	}
	temp->next = newWord;               /*and add the new word there*/

}


void printWords(Wordptr root) {    /*prints the words from root to the end*/
	Wordptr temp = root;
	if (root == NULL) {                 /*check if the list is empty*/
		printf("There are no words!\n");
	}
	else {
		while (temp != NULL) {
			printf("%d - %s\n", temp->count, temp->word);
			temp = temp->next;
		}
	}
}

Wordptr sort(Wordptr root) { 
	int len, l;
	//Wordptr temp = root;
	 l = len = findLen(root);
	while (len > 0) {
		
		if (root->count > root->next->count) {   /*if root counter is bigeer than next one*/
			Wordptr p = root->next;
			root->next = root->next->next;
			p->next = root;
			root = p;
		}
		Wordptr temp = root;
		for (int i = 0; i < l-2; i++) {    /*switch the next two elements if needed - check l-2 times(l is lenght of the list)*/
			Wordptr p = temp->next;          
			if (p->count > p->next->count) {
				Wordptr q = p->next;
				p->next = q->next;
				q->next = p;
				temp->next = q;
			}
			temp = temp->next;   /*go to the next element*/
		}
		len--;
		
	}
	return root;   /*returns the new root(if changed)*/
}



int findLen(Wordptr p) {  /*find lenght of list*/
	int len = 0;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}