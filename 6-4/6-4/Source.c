#include<stdio.h>
#include"wordscount.h"
#include<stdlib.h>

#define MAXWORD 100

static Wordptr root = NULL;

main() {
	
	char wordg[MAXWORD];
	char* word = wordg;
	scanf("%s", word);
	root = makeRoot(root, word);
	while (scanf("%s", word) != EOF) {
		int found = searchWord(root, word);
		if (found == 0) {
			addWord(root, word);
		}
	}
	root = sort(root);
	printWords(root);
}





