#include<stdarg.h>
#include<stdio.h>
#include <fcntl.h>


void file_copy(int f1, int f2);


main(int argc, int* argv[]) {
	//char buf[BUFSIZ];
	//int n;
	//while ((n = read(0, buf, BUFSIZ)) > 0) {   /*n = num of read bytes; if 0 -> EOF reached*/
	//	write(1, buf, n);
	//}

	int f1, f2;
	if ((f1 = open("myfile.txt", O_RDONLY)) < 0 || ((f2 = open("copy.txt", O_WRONLY)) < 0)) {       /*perms are defined in fcntl.h*/
		fprintf(stderr, "Error : cant't open file!");      /*if some of files doesnt exist, exit the program*/
		exit(1);
	}
	else{
		file_copy(f1, f2);     
	}
	close(f1);
	close(f2);
}

void file_copy(int f1, int f2) {
	int n;
	char buf[BUFSIZ];     /*buf collects the info from the first file*/
	while ((n = read(f1, buf, BUFSIZ)) > 0) {    /*read n bytes from first file and put them in the second*/
		write(f2, buf, n);
	}
}


/*void error(char* fmt,...) {
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "Error : ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}*/