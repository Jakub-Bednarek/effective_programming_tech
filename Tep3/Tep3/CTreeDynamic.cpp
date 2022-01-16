#include "CTreeDynamic.h"
#include <iostream>

CTreeDynamic::CTreeDynamic()
{
	std::cout << "Creating root.\n";
	pc_root = new CNodeDynamic(nullptr);
}

CTreeDynamic::CTreeDynamic(CNodeDynamic* pcRoot)
{
	pc_root = pcRoot;
}

CTreeDynamic::~CTreeDynamic()
{
	std::cout << "Deleting root\n";
	delete pc_root;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::pcGetRoot() const
{
	return pc_root;
}

void CTreeDynamic::vPrintTree() const
{
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	int iChildOffset = 0;
	CNodeDynamic* pcOldParent = pcNewChildNode->pcGetParent(&iChildOffset);

	if (!pcOldParent->bDeleteChild(iChildOffset))
	{
		return false;
	}

	pcNewChildNode->vSetParent(pcParentNode);
	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}

CTreeDynamic::CNodeDynamic::CNodeDynamic(CNodeDynamic* pcParent)
{
	i_val = I_DEFAULT_VALUE;
	pc_parent_node = pcParent;

	std::cout << "Creating new object\n";
}

CTreeDynamic::CNodeDynamic::CNodeDynamic(const CNodeDynamic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = new CNodeDynamic(pcOther.pc_parent_node);

	for (int i = 0; i < pcOther.v_children.size(); i++)
	{
		v_children.push_back(new CNodeDynamic(pcOther.v_children.at(i)));
	}
}

CTreeDynamic::CNodeDynamic& CTreeDynamic::CNodeDynamic::operator=(const CNodeDynamic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = pcOther.pc_parent_node;

	for (int i = 0; i < pcOther.v_children.size(); i++)
	{
		v_children.push_back(new CNodeDynamic(pcOther.v_children.at(i)));
	}

	return *this;
}

CTreeDynamic::CNodeDynamic::~CNodeDynamic()
{
	std::cout << "Deleting object\n";

	for (std::vector<CNodeDynamic*>::const_iterator it = v_children.begin(); it != v_children.end();)
	{
		delete* it;
		it = v_children.erase(it);
	}
}

bool CTreeDynamic::CNodeDynamic::bDeleteChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset > v_children.size())
	{
		return false;
	}

	std::vector<CNodeDynamic*>::const_iterator it = v_children.begin();
	it += iChildOffset;
	v_children.erase(it);

	return true;
}

void CTreeDynamic::CNodeDynamic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

void CTreeDynamic::CNodeDynamic::vAddNewChild()
{
	v_children.push_back(new CNodeDynamic(this));
}

void CTreeDynamic::CNodeDynamic::vPrint()
{
	std::cout << ' ' << i_val;
}

void CTreeDynamic::CNodeDynamic::vPrintAllBelow()
{
	vPrint();

	for (int i = 0; i < v_children.size(); i++)
	{
		v_children.at(i)->vPrintAllBelow();
	}
}

void CTreeDynamic::CNodeDynamic::vPrintUp()
{
	vPrint();

	if (pc_parent_node != nullptr)
	{
		pc_parent_node->vPrintUp();
	}
}

void CTreeDynamic::CNodeDynamic::vSetParent(CNodeDynamic* pcParent)
{
	pc_parent_node = pcParent;
}

void CTreeDynamic::CNodeDynamic::vAddNewChild(CNodeDynamic* pcChild)
{
	v_children.push_back(pcChild);
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset > v_children.size())
	{
		return nullptr;
	}

	return v_children.at(iChildOffset);
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetParent()
{
	return pc_parent_node;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetParent(int* piChildNumber)
{
	for (int i = 0; i < pc_parent_node->v_children.size(); i++)
	{
		if (v_children.at(i) == this)
		{
			*piChildNumber = i;
			return pc_parent_node;
		}
	}

	return pc_parent_node;
}

CTreeDynamic* CTreeDynamic::CNodeDynamic::pcGetChildTree(int iChildOffset)
{
	CNodeDynamic* node = pcGetChild(iChildOffset);

	if (node != nullptr)
	{
		CTreeDynamic* tree = new CTreeDynamic(node);
		return tree;
	}

	return nullptr;
}

int CTreeDynamic::CNodeDynamic::iGetChildrenNumber()
{
	return v_children.size();
}
