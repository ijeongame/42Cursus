#include <stdio.h>

int main(void)
{
	int a = 100;

	printf("%p끝\n",a);
	printf("%10p끝\n",a);
	printf("%-10p끝\n",a);
	printf("%010p끝\n",a);
	printf("%.10p끝\n",a);
	printf("%3.7p끝\n",a);
	printf("%10.5p끝\n",a);
}