#include "AllocFunctions.h"

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
		return 0;
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

void v_mod_tab(CTable* piTable, int iNewSize)
{
	piTable->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable piTable, int iNewSize)
{
	piTable.bSetNewSize(iNewSize);
}

void v_fill_array(int** piArray, int iSizeX, int iSizeY)
{
	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
			piArray[i][j] = i + j;
	}
}