// by ballypc
// Dec. 2013

#include <iostream>
#include <fstream>


#include "Arranger.h"


int main (void)
{
	std::ios_base::sync_with_stdio(false); // speed up cout

	std::streambuf* coutBuf = std::cout.rdbuf();
	std::ofstream of("out.txt");
	std::cout.rdbuf(of.rdbuf()); // redirect cout to filestream
/*
	for(int i=1;i<=m;++i) { // all boxes numbers form 1 to m
		std::cout<<i<<" boxes:"<<std::endl;
		Arranger(n,i).arrange_order_noempty();
		std::cout<<std::endl;
	}
*/

//	Arranger(10, 5).arrange();
//	Arranger(15, 10).arrange_noempty();	
	Arranger(30, 15).arrange_order();
//	Arranger(30, 10).arrange_order_noempty();

	std::cout.rdbuf(coutBuf);

	of.flush(); // write all answers form memory to file
	of.close();

	return 0;
}