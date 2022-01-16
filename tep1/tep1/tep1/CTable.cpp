#include "CTable.h"
#include <iostream>

CTable::CTable()
{
	sName = DEFAULT_NAME;
	iTableLength = DEFAULT_TABLE_LENGTH;
	piTable = new int[iTableLength];

	std::cout << "bezp: " << sName << '\n';
}

CTable::CTable(std::string sName, int iTableLen)
{
	if (iTableLen < 0)
		iTableLen = DEFAULT_TABLE_LENGTH;

	this->sName = sName;
	this->iTableLength = iTableLen;
	this->piTable = new int[iTableLength];

	std::cout << "parametr: " << this->sName << '\n';
}

CTable::CTable(CTable& pcOther)
{
	this->sName = pcOther.sName + "_copy";
	this->iTableLength = pcOther.iTableLength;
	this->piTable = new int[iTableLength];

	for (int i = 0; i < iTableLength; i++)
	{
		piTable[i] = pcOther.piTable[i];
	}

	std::cout << "kopiuj: " << sName << '\n';
}

CTable::~CTable()
{
	delete[] piTable;

	std::cout << "usuwam: " << sName << '\n';
}

std::string CTable::sGetName() const
{
	return sName;
}

int CTable::iGetTableLength() const
{
	return iTableLength;
}

void CTable::vPrint()
{
	for (int i = 0; i < iTableLength; i++)
	{
		std::cout << piTable[i] << ' ';
	}
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset >= iTableLength || iOffset < 0)
		return;

	piTable[iOffset] = iNewVal;
}

void CTable::vSetName(std::string sNewName)
{
	sName = sNewName;
}

bool CTable::bSetNewSize(int iNewTableLen)
{
	if (iNewTableLen <= 0)
	{
		return false;
	}

	int shorterSize = 0;
	if (iNewTableLen < iTableLength)
	{
		shorterSize = iNewTableLen;
	}
	else
	{
		shorterSize = iTableLength;
	}

	int* piNewTable = new int[iNewTableLen];
	for(int i = 0; i < shorterSize; i++)
	{
		piNewTable[i] = piTable[i];
	}

	delete[] piTable;
	piTable = piNewTable;
	iTableLength = iNewTableLen;

	return true;
}

CTable* CTable::pcClone()
{
	CTable* pNewCTable = new CTable(sName, iTableLength);

	for (int i = 0; i < iTableLength; i++)
	{
		pNewCTable->piTable[i] = this->piTable[i];
	}

	return pNewCTable;
}

/*
void CTable::operator=(const CTable& pcOther)
{
	piTable = pcOther.piTable;
	iTableLength = pcOther.iTableLength;
}
*/

void CTable::operator=(const CTable& pcOther)
{
	delete[] piTable;

	sName = pcOther.sName;
	iTableLength = pcOther.iTableLength;
	piTable = new int[iTableLength];

	for (int i = 0; i < iTableLength; i++)
	{
		piTable[i] = pcOther.piTable[i];
	}
}

CTable CTable::operator+(const CTable& pcOther)
{
	int iNewSize = iTableLength + pcOther.iTableLength;
	std::string sNewName = sName + pcOther.sName;
	CTable result(sNewName, iNewSize);

	for (int i = 0; i < iTableLength; i++)
	{
		result.piTable[i] = piTable[i];
	}

	for (int i = iTableLength; i < iNewSize; i++)
	{
		result.piTable[i] = pcOther.piTable[i - iTableLength];
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const CTable& cTable)
{
	return os << "[" << cTable.sGetName() << ", " << cTable.iGetTableLength() << "]";
}
