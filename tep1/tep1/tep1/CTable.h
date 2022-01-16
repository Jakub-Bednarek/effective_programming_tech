#pragma once
#include <string>

#define DEFAULT_NAME "defaultName"
#define DEFAULT_TABLE_LENGTH 10

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();

	std::string sGetName() const;
	int iGetTableLength() const;

	void vPrint();
	void vSetValueAt(int iOffset, int iNewVal);
	void vSetName(std::string sNewName);
	bool bSetNewSize(int iNewTableLen);
	CTable* pcClone();

	void operator=(const CTable& pcOther);
	CTable operator+(const CTable& pcOther);
private:
	std::string sName;
	int* piTable;
	int iTableLength;
};


std::ostream& operator<<(std::ostream& os, const CTable& cTable);