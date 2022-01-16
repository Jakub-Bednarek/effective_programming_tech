#include "CTable.h"

#include <random>

CTable::CTable()
{
	s_name = DEFAULT_NAME;
	i_table_length = DEFAULT_TABLE_LENGTH;
	pi_table = new int[i_table_length];

	std::cout << "bezp: " << s_name << '\n';
}

CTable::CTable(std::string sName, int iTableLength)
{
	i_table_length = iTableLength < 0 ? DEFAULT_TABLE_LENGTH : iTableLength;
	s_name = sName;
	pi_table = new int[i_table_length];

	std::cout << "parametr: " << s_name << '\n';
}

CTable::CTable(CTable& pcOther)
{
	*this = pcOther;
}

CTable::CTable(CTable&& pcOther)
{
	*this = std::move(pcOther);
	std::cout << "Move: " << s_name << '\n';
}

CTable::~CTable()
{
	if (pi_table != nullptr)
	{
		delete[] pi_table;
		pi_table = nullptr;
	}

	std::cout << "usuwam: " << s_name << '\n';
}

CTable& CTable::operator=(const CTable& pcOther)
{
	if (*this == pcOther)
	{
		return *this;
	}

	delete[] pi_table;

	s_name = pcOther.s_name;
	i_table_length = pcOther.i_table_length;
	pi_table = new int[i_table_length];

	if (pi_table != nullptr)
	{
		for (int i = 0; i < i_table_length; i++)
		{
			pi_table[i] = pcOther.pi_table[i];
		}
	}

	std::cout << "Copy: " << s_name << '\n';

	return *this;
}

CTable& CTable::operator=(CTable&& pcOther)
{
	if (*this == pcOther)
	{
		return *this;
	}

	delete[] pi_table;

	s_name = std::move(pcOther.s_name);
	i_table_length = std::move(pcOther.i_table_length);
	pi_table = pcOther.pi_table;

	pcOther.s_name = "";
	pcOther.i_table_length = 0;
	pcOther.pi_table = nullptr;

	return *this;
}

std::string CTable::s_get_name() const
{
	return s_name;
}

int CTable::i_get_table_length() const
{
	return i_table_length;
}

void CTable::v_print() const
{
	if (pi_table == nullptr)
	{
		std::cout << "pi_table is NULL\n";
		return;
	}

	if (pi_table != nullptr)
	{
		for (int i = 0; i < i_table_length; i++)
		{
			std::cout << pi_table[i] << ' ';
		}

		std::cout << '\n';
	}
}

void CTable::v_print(const std::string& sText) const
{
	std::cout << sText << '\n';
	v_print();
	std::cout << '\n';
}

void CTable::v_set_value_at(int iOffset, int iNewVal)
{
	if (iOffset < 0 || iOffset >= i_table_length)
	{
		std::cout << "Invalid arguments for function v_set_value_at.\n";
		return;
	}

	pi_table[iOffset] = iNewVal;
}

void CTable::v_set_name(std::string sNewName)
{
	s_name = sNewName;
}

void CTable::v_fill_random()
{
	if (pi_table == nullptr)
	{
		std::cout << "pi_table is NULL\n";
		return;
	}

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> dist(0, 1000);

	for (int i = 0; i < i_table_length; i++)
	{
		pi_table[i] = dist(generator);
	}
}

bool CTable::b_set_new_size(int iNewTableLength)
{
	if (iNewTableLength < 0)
	{
		return false;
	}

	int shorterSize = iNewTableLength < i_table_length ? iNewTableLength : i_table_length;
	int* piNewTable = new int[iNewTableLength];

	if (pi_table != nullptr)
	{
		for (int i = 0; i < shorterSize; i++)
		{
			piNewTable[i] = pi_table[i];
		}
	}

	delete[] pi_table;
	pi_table = piNewTable;
	i_table_length = iNewTableLength;

	return true;
}

CTable* CTable::pcClone()
{
	CTable* newTable = new CTable(s_name, i_table_length);

	for (int i = 0; i < i_table_length; i++)
	{
		newTable->pi_table[i] = pi_table[i];
	}

	return newTable;
}

CTable CTable::operator+(const CTable& pcOther)
{
	int iNewSize = i_table_length + pcOther.i_table_length;
	std::string sNewName = s_name + pcOther.s_name;
	int* pc_new_tab = new int[iNewSize];

	if (pcOther.pi_table != nullptr)
	{
		for (int i = 0; i < i_table_length; i++)
		{
			pc_new_tab[i] = pi_table[i];
		}

		for (int i = i_table_length; i < iNewSize; i++)
		{
			pc_new_tab[i] = pcOther.pi_table[i - i_table_length];
		}
	}

	CTable t(sNewName, iNewSize);
	delete[] t.pi_table;
	t.pi_table = pc_new_tab;

	return t;
}

bool CTable::operator==(const CTable& pcOther)
{
	return &pi_table == &(pcOther.pi_table);
}


std::ostream& operator<<(std::ostream& os, const CTable& cTable)
{
	return os;
}
