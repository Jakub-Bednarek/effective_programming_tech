#pragma once

#include <iostream>

#define DEFAULT_NAME "defaultName"
#define DEFAULT_TABLE_LENGTH 10

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLength);
	CTable(CTable& pcOther);
	CTable(CTable&& pcOther);
	~CTable();
	CTable& operator=(const CTable& pcOther);
	CTable& operator=(CTable&& pcOther);

	std::string s_get_name() const;
	int i_get_table_length() const;

	void v_print() const;
	void v_print(const std::string& sText) const;
	void v_set_value_at(int iOffset, int iNewVal);
	void v_set_name(std::string sNewName);
	void v_fill_random();
	bool b_set_new_size(int iNewTableLength);
	
	CTable* pcClone();

	CTable operator+(const CTable& pcOther);
	bool operator==(const CTable& pcOther);
private:
	std::string s_name;

	int* pi_table = nullptr;
	int i_table_length;
};

std::ostream& operator<<(std::ostream& os, const CTable& pcTable);