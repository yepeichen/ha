#include<iostream>

long c (int n, int m)
{
	if (n==m || m==0) return 1;
	return c(n-1, m) + c(n-1, m-1);
}

int main (void)
{
	std::cout << c(30,15) << std::endl;
	return 0;
}