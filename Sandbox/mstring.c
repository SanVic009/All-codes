#include <stdio.h>

int find_fact(int n);
int n;

int main()
{
	//code
}

int find_fact(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else 
		return n* find_fact(n-1);
}