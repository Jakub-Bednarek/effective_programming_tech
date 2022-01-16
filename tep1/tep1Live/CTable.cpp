#include "CTable.h"
#include <iostream>

CTable::CTable()
{
	sName = DEFAULT_NAME;
	iSizeX = DEFAULT_TABLE_LENGTH;
	iSizeY = DEFAULT_TABLE_LENGTH;
	defaultReturn = new int(DEFAULT_RETURN_VALUE);
	
	vAllocateTable();

	std::cout << "bezp: " << sName << '\n';
}

CTable::CTable(std::string sName, int iSizeY, int iSizeX)
{
	this->sName = sName;
	this->iSizeX = iSizeX;
	this->iSizeY = iSizeY;
	this->piTable = new int*[iSizeY];
	defaultReturn = new int(DEFAULT_RETURN_VALUE);

	vAllocateTable();

	std::cout << "parametr: " << this->sName << '\n';
}

CTable::CTable(CTable& pcOther)
{
	this->sName = pcOther.sName + "_copy";
	this->iSizeX = pcOther.iSizeX;
	this->iSizeY = pcOther.iSizeY;
	this->piTable = new int*[iSizeY];
	defaultReturn = new int(DEFAULT_RETURN_VALUE);

	vAllocateTable();

	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
		{
			piTable[i][j] = pcOther.piTable[i][j];
		}
	}

	std::cout << "kopiuj: " << sName << '\n';
}

CTable::~CTable()
{
	for (int i = 0; i < iSizeY; i++)
	{
		delete[] piTable[i];
	}

	delete[] piTable;
	delete defaultReturn;

	std::cout << "usuwam: " << sName << '\n';
}

std::string CTable::sGetName() const
{
	return sName;
}

int CTable::iGetTableSizeX() const
{
	return iSizeX;
}

int CTable::iGetTableSizeY() const
{
	return iSizeY;
}

int CTable::iGetNumberAt(int iPosX, int iPosY)
{
	if (iPosX >= iSizeX || iPosY >= iSizeY)
	{
		return -1;
	}

	return piTable[iPosY][iPosX];
}

bool CTable::vSetNumberAt(int iPosX, int iPosY, int iNumber)
{
	if (iPosX >= iSizeX || iPosY >= iSizeY)
	{
		return false;
	}

	piTable[iPosY][iPosX] = iNumber;

	return true;
}

void CTable::vSetName(std::string sNewName)
{
	sName = sNewName;
}

void CTable::vFillArray()
{
	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
		{
			piTable[i][j] = i + j;
		}
	}
}

void CTable::vPrintArray()
{
	for (int i = 0; i < iSizeY; i++)
	{
		for (int j = 0; j < iSizeX; j++)
		{
			std::cout << piTable[i][j] << ' ';
		}

		std::cout << '\n';
	}
}

bool CTable::bSetNewSize(int iNewSizeX, int iNewSizeY)
{
	if (iNewSizeX <= 0 || iNewSizeY <= 0)
	{
		return false;
	}

	int shorterSizeX = 0;
	int shorterSizeY = 0;
	if (iNewSizeX < iSizeX)
	{
		shorterSizeX = iNewSizeX;
	}
	else
	{
		shorterSizeX = iSizeX;
	}

	if (iNewSizeY < iSizeY)
	{
		shorterSizeY = iNewSizeY;
	}
	else
	{
		shorterSizeY = iSizeY;
	}

	int** piNewTable = new int*[iSizeY];
	for(int i = 0; i < shorterSizeY; i++)
	{
		piNewTable[i] = new int[iNewSizeX];
	}

	for (int i = 0; i < shorterSizeY; i++)
	{
		for (int j = 0; j < shorterSizeX; j++)
		{
			piNewTable[i][j] = piTable[i][j];
		}
	}

	for (int i = 0; i < iSizeY; i++)
	{
		delete[] piTable[i];
	}

	delete[] piTable;
	piTable = piNewTable;
	iSizeX = iNewSizeX;
	iSizeY = iNewSizeY;

	return true;
}

CTable::Proxy CTable::operator[](int iIndex)
{
	if (iIndex >= iSizeY || iIndex < 0)
		return Proxy(piTable[iIndex], -1, defaultReturn);

	return Proxy(piTable[iIndex], iSizeX, defaultReturn);
}

CTable* CTable::pcClone()
{
	CTable* pNewCTable = new CTable(*this);

	return pNewCTable;
}

void CTable::vAllocateTable()
{
	for (int i = 0; i < iSizeY; i++)
	{
		piTable[i] = new int[iSizeX];
	}
}

std::ostream& operator<<(std::ostream& os, const CTable& cTable)
{
	return os << "[" << cTable.sGetName() << ", " << cTable.iGetTableSizeX() << cTable.iGetTableSizeY() << "]";
}
