#include <stdio.h>
#include <stdlib.h>

void echange (int *x, int *y) {
	int z;
	z=*x;*x=*y;*y=z;
}
int main() 
{
	int a;
	int b;
	int *pa;
	int **p;
	a=8;
	pa=&a;
	p=&pa;
	**p=281;
	b=3;
	echange(&a,&b);
	return 0;
} 
