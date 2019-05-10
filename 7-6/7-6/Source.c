#include<stdio.h>
#include<string.h>
#define MAXPATHL 200

main() {

	FILE* f1;
	FILE* f2;
	char fpath[MAXPATHL];
	printf("Insert the directory of the first file : ");
	scanf("%s", fpath);
	f1 = fopen(fpath, "r");
	while (f1 == NULL) {                   /*check if the file exist - if no, reads input again while correct*/
		printf("The file can not be found! Please try again : ");
		scanf("%s", fpath);
		f1 = fopen(fpath, "r");
	}
	printf("Insert the directory of the second file : ");
	scanf("%s", fpath);
	f2 = fopen(fpath, "r");
	while (f2 == NULL) {
		printf("The file can not be found! Please try again : ");
		scanf("%s", fpath);
		f2 = fopen(fpath, "r");
	}
	compare_files(f1, f2);
	fclose(f1);
	fclose(f2);
}

#define MAXLINE 200
int compare_files(FILE* f1, FILE* f2) {
	int line = 0;     /*counts the lines*/
	char line1[MAXLINE];   /*keep the current lines from the files*/
	char line2[MAXLINE];
	while (fgets(line1, MAXLINE, f1) != NULL && fgets(line2, MAXLINE, f2) != NULL) { /*fgets returns pointer to string -> if the end of file is reached it will return NULL*/
		line++;
		if (strcmp(line1, line2) != 0) {   /*check if lines are different*/
			fprintf(stdout, "files are diferent in line : %d\nFirst file : %sSecond file : %s", line, line1, line2);
			return 1;
		}
	}

	/*                                *In case one file is shorter than the other, the while loop will stop when reaches it end.*
	If the first file to check is the longer:
	it first reads the next line and saves it in line1, and then stops,
	so we need to compare the two lines - in this case line1 will be the next, and line 2 will be the last from the second file.
	*********************
	If the second file is longer :
	In line1 will be saved the last line from first file, but the loop will not check the next from the second file,
	so need to check if there's next in it and if it's true, it will be saved in line2.
	(If it was the last line, it will not change)
									 *At the end compare them last time*
	*/

	fgets(line2, MAXLINE, f2);
	if (strcmp(line1, line2) != 0) {
		fprintf(stdout, "One of files has only %d lines. Till then they are the same.\n", line);
	}
	else {
		printf("Files are the same!");   /*if files dont have different lines, and none of them is longer than the other*/
	}
	return 0;
}