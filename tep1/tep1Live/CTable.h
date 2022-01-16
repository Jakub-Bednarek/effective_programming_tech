#pragma once
#include <string>

#define DEFAULT_NAME "defaultName"
#define DEFAULT_RETURN_VALUE -1

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iSizeX, int iSizeY);
	CTable(CTable& pcOther);
	~CTable();

	std::string sGetName() const;
	int iGetTableSizeX() const;
	int iGetTableSizeY() const;
	int iGetNumberAt(int iPosX, int iPosY);

	bool vSetNumberAt(int iPosX, int iPosY, int iNumber);
	bool bSetNewSize(int iNewSizeX, int iNewSizeY);

	void vSetName(std::string sNewName);
	void vFillArray();
	void vPrintArray();

	CTable* pcClone();

	class Proxy
	{
	public:
		Proxy(int* piInnerTable, int iSizeX, int* defaultReturn)
		{
			this->piInnerTable = piInnerTable;
			this->iSizeX = iSizeX;
			this->defaultReturn = defaultReturn;
			*defaultReturn = DEFAULT_RETURN_VALUE;
		}

		int& operator[](int iIndex)
		{
			if (iIndex >= iSizeX || iIndex < 0)
				return *defaultReturn;

			return piInnerTable[iIndex];
		}
	private:
		int* piInnerTable;
		int* defaultReturn;
		int iSizeX;
	};

	Proxy operator[](int iIndex);
private:
	void vAllocateTable();
private:
	static constexpr int DEFAULT_TABLE_LENGTH = 10;
	int* defaultReturn;

	std::string sName;
	int** piTable;
	int iSizeX;
	int iSizeY;
};


std::ostream& operator<<(std::ostream& os, const CTable& cTable);