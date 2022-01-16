#include "CTab.h"

#include <cstring>
#include <utility>
#include <random>
#include <iostream>

CTab::CTab()
{
	i_size = DEF_TAB_SIZE;
	pi_table = new int[i_size];
}

CTab::CTab(const CTab& cOther)
{
	*this = cOther;
}

CTab::CTab(CTab&& cOther)
{
	*this = std::move(cOther);
}

CTab& CTab::operator=(const CTab& cOther)
{
	if (*this == cOther)
	{
		return *this;
	}

	v_copy(cOther);

	return *this;
}

CTab& CTab::operator=(CTab&& cOther)
{
	if (*this == cOther)
	{
		return *this;
	}

	if (pi_table != nullptr)
	{
		delete[] pi_table;
	}

	i_size = std::move(cOther.i_size);
	pi_table = std::move(cOther.pi_table);
	cOther.pi_table = nullptr;
	cOther.i_size = 0;

	return *this;
}

CTab::~CTab()
{
	if (pi_table != nullptr)
	{
		delete[] pi_table;
		pi_table = nullptr;
	}
}

bool CTab::operator==(const CTab& cOther)
{
	return &pi_table == &cOther.pi_table;
}

bool CTab::b_set_size(int iSize)
{
	if (iSize < 0)
	{
		return false;
	}

	int* new_tab = new int[iSize];

	std::memcpy(new_tab, pi_table, iSize * sizeof(int));

	delete[] pi_table;
	pi_table = new_tab;
	i_size = iSize;

	return true;
}

void CTab::v_print_tab() const
{
	if (pi_table == nullptr)
	{
		std::cout << "Tab is null!\n";
		return;
	}

	for (int i = 0; i < i_size; i++)
	{
		std::cout << pi_table[i] << ' ';
	}

	std::cout << '\n';
}

void CTab::v_print_tab(const std::string& sText) const
{
	std::cout << sText << '\n';
	v_print_tab();
	std::cout << '\n';
}

int CTab::i_get_size() const
{
	return i_size;
}

void CTab::v_copy(const CTab& cOther)
{
	if (pi_table != nullptr)
	{
		delete[] pi_table;
	}

	int* new_tab = new int[cOther.i_size];
	i_size = cOther.i_size;

	std::memcpy(new_tab, cOther.pi_table, i_size * sizeof(int));

	pi_table = new_tab;
}

void CTab::v_fill_random()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> dist(0, 1000);

	for (int i = 0; i < i_size; i++)
	{
		pi_table[i] = dist(generator);
	}
}
