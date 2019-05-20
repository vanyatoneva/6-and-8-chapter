

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
	for (i = 0; i < MAX; i++) {   //!!!!only stops ir reads letter, which is not in hex - if reads space, new line or tab doesn't 
		if (scanf("%2x", &n)) {
			num[i] = n;
		}
		else { break; }
	};
	while (i < MAX) {
		num[i++] = 0x00;
	}
	//int* numptr = num;
	//printf("%d", getFirst3bits(numptr));
	int* numptr = num;
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
	//Now, get the value of tag to see if next byte is also part of it!
	if (!((tagInf << 5 | 0x1f) ^ *n)) {   //will return true only if some bits are different, is false -> last 5 bits of n are set => next bit is part of tag
		tag = (tag << 8) | *++n;
		if ((*n << 7) & 1) {
			tag = (tag << 8) | *++n;
		}
	//!!!!!!!!Need to check if next byte starts with 1 or 0 -> if 0, this is last byte, if not do again!
	}
	printf("Tag is : %x - ", tag);

	int len = *(++n); 
	if ((len >> 7) & 1) {   //checks if first bit is set
		if (len & 1) {
			len = *(++n);      //if set and the value is 1 - next byte keeps length
			printf("Len is %x = %d\n", len, len);
		}
		else if (len & 2) {
			len = (*(++n) << 8) | *(++n);     //is value is 2 - next 2 bytes are the length! 
			printf("Len is %x = %d\n", len, len);
		}
	}

	//!!!!!! If len first bit is 1, check the value of len to see - if 1 next byte is length, if 2 - next two bytes are length!!!!!


	
	if (tagInf & CONSTRUCTED) {
		//constructed data object
		//see lentgh
		// then see ->next is tag 
		//need to pass all after the length, cause it new tag
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
		char* b = (char*)malloc(1);     //to save next byte
		char* val = (char*)malloc(len*2);   //need extra space, because of adding '0' in the case 0x0000 xxxx !!! 


		if (tag == 0x50) {
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
			/*itoa(*++n, b, 16);    //convert to char
			if (strlen(b) == 1) {
				strcpy(val, "0");
				strcat(val, b);
			}
			else {
				strcpy(val, b); //save the first in value
			}
			while (len > 1) {
				itoa(*++n, b, 16);    //copy to val len num of ints
				if (strlen(b) == 1) {   //if num is 0000 xxxx - b will not have the zeroes, need to add them
					strcat(val, "0");
				}
				strcat(val, b);
				len--;*/
			}
			printf("\n");
		}
		//printf("Value is : %s\n\n", val);
		printInf(++n);

	}	
}


void checkTaginf(unsigned tag) {   //prints class of tag
	tag >>= 1;    //we need only 2 bits
	if (IS_UNIVERSAL(tag)) {  //case two bits are 0
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
