#include<stdio.h>
#include<stdlib.h>

void* my_calloc(unsigned n, unsigned size);

main() {
	double* p;
	int size;
	printf("Please enter size : ");
	scanf("%d", &size);
	p = (double*)my_calloc(size, sizeof p);
	int i;
	//int e = 158763;
	//p[4] = e;
	for (i = 0; i < size; i++) {
		printf("%lf, %p\n", *p++, p);     
	}

}

void* my_calloc(unsigned n, unsigned size) {
	unsigned i;
	char* p, * q; /*one to set values to 0*/
	/*we need space for n elements with size size*/
	p = q = malloc(n * size);
	if (!p) {
		return NULL;
	}
	memset(p, 0, n * size);  //memset sets the value 0, form p the next n*size bits
	return p;

	//for(i = 0; i <= n * size; i++){
	//	*p++ = 0;
	//}
	//return q;                 //q is still pointing at the begin, p now is pointing at the end
}


