#pragma once
#include <iostream>
#include "CTable.h"

#define DEFAULT_ARRAY_SIZE 10
#define NUMBER_TO_ADD 5

void v_alloc_table_add_5(int iSize)
{
	if (iSize <= 0)
	{
		iSize = DEFAULT_ARRAY_SIZE;
	}

	int* piTable = new int[iSize];
	for (int i = 0; i < iSize; i++)
	{
		piTable[i] = i + NUMBER_TO_ADD;
	}

	for (int i = 0; i < iSize; i++)
	{
		std::printf("%d ", piTable[i]);
	}

	delete[] piTable;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX <= 0 || iSizeY <= 0)
	{
		return false;
	}

	*piTable = new int* [iSizeY];

	for (int i = 0; i < iSizeY; i++)
	{
		(*piTable)[i] = new int[iSizeX];
	}

	return true;
}

bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeY <= 0)
	{
		return false;
	}

	for (int i = 0; i < iSizeY; i++)
	{
		delete[](*piTable)[i];
	}

	delete[] * piTable;
	piTable = NULL;

	return true;
}

void vModTab(CTable* pcTab, int iNewSizeX, int iNewSizeY)
{
	pcTab->bSetNewSize(iNewSizeX, iNewSizeY);
}

void vModTab(CTable cTab, int iNewSizeX, int iNewSizeY)
{
	cTab.bSetNewSize(iNewSizeX, iNewSizeY);
}

void vPrintArray(int** piArray, int iSizeX, int iSizeY)
{
	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
			std::cout << piArray[i][j] << ' ';

		std::cout << '\n';
	}
}

void vFillArray(int** piArray, int iSizeX, int iSizeY)
{
	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
			piArray[i][j] = i + j;
	}
}