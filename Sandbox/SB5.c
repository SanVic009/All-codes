#include <stdio.h>

int main(void) {
	int x, fact = 1;

     scanf("%d", &x);
     for (int i = 1; i < x+1; i++)
     {
          fact *= i;
     }

     printf("%d", fact);
     
	return 0;
}