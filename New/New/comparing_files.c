#include<stdio.h>



main() {
	
	FILE* f1;
	FILE* f2;
	f1 = fopen("myfile.txt", "r");
	f2 = fopen("newfile.txt", "r");
	compare_files(f1, f2);
	fclose(f1);
	fclose(f2);
}

#define MAX 100
int compare_files(FILE* f1, FILE* f2) {
	int line = 0;     /*counts the lines*/
	char line1[MAX];
	char line2[MAX];
	while (fgets(line1, MAX, f1) != NULL && fgets(line2, MAX, f2) != NULL) { /*fgets returns pointer to string -> if the end of file is reached it will return NULL*/
		line++;
		if (strcmp(line1, line2) != 0) {   /*check if lines are different*/
			fprintf(stdout, "files are diferent in lines : %d\n%s\n%s\n", line, line1, line2);
			return 1;
		}
	}
	if ((*line1 == '\n' && *line2 != '\n') || (*line2 == '\n' && *line1 != '\n')) {  /*if the loop doesn't find difference in files, but reaches the end of one of them, the last read line from it is '\n'*/
		fprintf(stdout, "One of files has only %d lines. Till then they are the same.\n", line);
	}
	else {
		printf("Files are the same!");   /*if files dont have different lines, and none of them is longer than the other*/
	}
	return 0;
}