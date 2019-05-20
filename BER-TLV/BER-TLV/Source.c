

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>




#define MAX 40


#define CONSTRUCTED 1
#define IS_UNIVERSAL(n) !n      
#define IS_APPLICATION(n) !(n^1)
#define IS_CON_SPEC(n) !(n^2)
#define IS_PRIVATE(n) !(n^3) 

int getFirst3bits(unsigned int* n);
void printInf(unsigned int* n);
void checkTaginf(unsigned n);


main() {
	int n;
	unsigned int num[MAX];
	int i;
	for (i = 0; i < MAX; i++) {  
		if (scanf("%2x", &n)) {
			num[i] = n;
		}
		else { break; }
	};
	while (i < MAX) {
		num[i++] = 0x00;
	}
	printInf(num);
	
}

int getFirst3bits(unsigned int* n) {
	return *n >> 5;   // n is always 1 byte, so just shift is with 5 at left - > first 3 bits 
}


void printInf(unsigned int* n) {

	//base case !! if *n is 0;
	if (*n == 0) {
		return;
	}


	unsigned int tagInf = getFirst3bits(n);
	int tag = *n;
	//Now, get the value of tag to see if next byte is also part of it
	if (!((tagInf << 5 | 0x1f) ^ *n)) {   //will return true only if some bits are different, is false -> last 5 bits of n are set => next bit is part of tag
		tag = (tag << 8) | *++n;
		if ((*n << 7) & 1) {
			tag = (tag << 8) | *++n;
		}
	//check if next byte starts with 1 or 0 -> if 0, this is last byte, if not do again!
	}
	printf("Tag is : %x - ", tag);

	int len = *(++n); 
	if ((len >> 7) & 1) {   //checks if first bit is set
		if (len & 1) {
			len = *(++n);      //if set and the value is 1 - next byte keeps length
		}
		else if (len & 2) {
			len = (*(++n) << 8) | *(++n);     //is value is 2 - next 2 bytes are the length! 
		}
	}

	
	if (tagInf & CONSTRUCTED) {
		//constructed data object
		//see lentgh
		// then see ->next is tag 
		//need to pass all after the length, cause it's new tag
		checkTaginf(tagInf);
		printf(" template\n");
		printf("Length : %d\n", len);
		printInf(++n);

	}
	else {
		//primitive data object
		checkTaginf(tagInf);
		printf(" primitive\n");
		printf("Length : %d\n", len);

		if (!(tag^0x50)) {    //50 is application label - at this case print the char values 
			printf("Value is : ");
			while (len > 0) {
				printf("%c", *(++n));
				len--;
			}
			printf("\n");
		}
		else {

			printf("Value is : ");
			while(len > 0){
				printf("%.2X", *(++n));
				len--;
			}
			printf("\n");
		}
		printInf(++n); //see next tag

	}	
}


void checkTaginf(unsigned tag) {   //prints class of tag
	tag >>= 1;    //we need only 2 bits
	if (IS_UNIVERSAL(tag)) { 
		printf("universal ");
	}
	else if (IS_APPLICATION(tag)) {
		printf("application ");
	}
	else if (IS_CON_SPEC(tag)) {
		printf("context specific ");
	}
	else if(IS_PRIVATE(tag)){   
		printf("private ");
	}
}
