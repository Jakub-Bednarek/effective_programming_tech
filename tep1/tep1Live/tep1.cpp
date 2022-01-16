#pragma once
#include "AllocFunctions.h"

int main()
{
	CTable ctable("test", 5, 10);

	ctable.vFillArray();

	std::cout << "\nTablica przed zmianami: \n";
	ctable.vPrintArray();

	ctable[1][2] = 55;
	ctable[15][20] = 30;
	ctable[35][40] = 70;
	ctable[2][4] = 6;

	std::cout << "\nTablica po zmianach:\n";
	ctable.vPrintArray();

	std::cout << "\nCTable[3][2]: " << ctable[3][2] << '\n';
	std::cout << "\nCTable[2][4]: " << ctable[2][4] << '\n';
	std::cout << "\nCTable[22][53]: " << ctable[22][53] << '\n';

	return 0;
}