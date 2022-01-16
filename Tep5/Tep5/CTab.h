#pragma once

#include <string>

#define DEF_TAB_SIZE 10

class CTab
{
public:
	CTab();
	CTab(const CTab& cOther);
	CTab(CTab&& cOther);
	~CTab();
	CTab& operator=(const CTab& cOther);
	CTab& operator=(CTab&& cOther);

	bool operator==(const CTab& cOther);

	bool b_set_size(int iSize);
	int i_get_size() const;

	void v_print_tab() const;
	void v_print_tab(const std::string& sText) const;
	void v_fill_random();
private:
	void v_copy(const CTab& cOther);

	int* pi_table;
	int i_size;
};