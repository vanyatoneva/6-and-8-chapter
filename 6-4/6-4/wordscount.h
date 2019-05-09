#ifndef WORD
#define WORD

typedef struct word {
	int count;
	char* word;
	struct word* next;
}Word;
typedef Word* Wordptr;


Wordptr makeRoot(Wordptr root, char* word); /*makes root only*/
Wordptr sort(Wordptr root);                   /*sortes the list by counters*/
int searchWord(Wordptr root, char* word);     /*if word is in list, increases the counter and returns 1, else returns 0*/
void addWord(Wordptr root, char* word);       /*add new node to the list with the given word*/
void printWords(Wordptr root);                /*prints the list from root to last element*/
int findLen(Wordptr p);                       /*finds length of list*/

#endif