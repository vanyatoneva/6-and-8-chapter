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
	int line = 0;
	char line1[MAX];
	char line2[MAX];
	while (fgets(line1, MAX, f1) != feof && fgets(line2, MAX, f2) != feof) { /*if they are the same the loop doesn't stop!!!!*/
		line++;
		if (strcmp(line1, line2) != 0) {
			fprintf(stdout, "files are diferent in lines : %d\n%s\n%s\n", line, line1, line2);
			return 1;
		}
	}
	printf("Files are the same!");
	return 0;
}