#include "CTreeStatic.h"
#include <iostream>


CTreeStatic::CTreeStatic()
{
	std::cout << "Creating stack object\n";
}

CTreeStatic::~CTreeStatic()
{
	std::cout << "Deleting stack object\n";
}

CTreeStatic::CNodeStatic* CTreeStatic::pcGetRoot()
{
	return &c_root;
}

CTreeStatic::CNodeStatic::CNodeStatic()
{
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = nullptr;
}

CTreeStatic::CNodeStatic::CNodeStatic(CNodeStatic* pcParent)
{
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = pcParent;

	std::cout << "New object" << '\n';
}

CTreeStatic::CNodeStatic::CNodeStatic(const CNodeStatic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = pcOther.pc_parent_node;
	v_children = pcOther.v_children;
}

CTreeStatic::CNodeStatic& CTreeStatic::CNodeStatic::operator=(const CNodeStatic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = pcOther.pc_parent_node;
	v_children = pcOther.v_children;

	return *this;
}

CTreeStatic::CNodeStatic::~CNodeStatic()
{
	std::cout << "Deleting stack node\n";
}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

void CTreeStatic::CNodeStatic::vAddNewChild()
{
	v_children.push_back(CNodeStatic(this));
}

void CTreeStatic::CNodeStatic::vPrint()
{
	std::cout << " " << i_val;
}

void CTreeStatic::CNodeStatic::vPrintAllBelow()
{
	vPrint();

	for (size_t i = 0; i < v_children.size(); i++)
	{
		v_children.at(i).vPrintAllBelow();
	}
}

void CTreeStatic::CNodeStatic::vPrintUp()
{
	vPrint();

	if (pc_parent_node != nullptr)
	{
		pc_parent_node->vPrintUp();
	}
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber()
{
	return v_children.size();
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset > v_children.size())
	{
		return nullptr;
	}

	return &v_children.at(iChildOffset);
}