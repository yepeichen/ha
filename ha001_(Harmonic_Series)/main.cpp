#include<iostream>

int main (void)
{
	double sum = 0.0;
	for (int i=2; i<2014; ++i) {
		sum+=1.0 / double(i);
	}
	std::cout << sum << std::endl;
}