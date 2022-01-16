#pragma once

//Tree functions

template<typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	std::cout << "Creating root.\n";
	pc_root = new CNodeDynamic(nullptr);
}

template<typename T>
CTreeDynamic<T>::CTreeDynamic(CNodeDynamic* pcRoot)
{
	pc_root = pcRoot;
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	std::cout << "Deleting root\n";
	delete pc_root;
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::pcGetRoot() const
{
	return pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() const
{
	pc_root->vPrintAllBelow();
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	unsigned int iChildOffset = 0;
	CNodeDynamic* pcOldParent = pcNewChildNode->pcGetParent(&iChildOffset);

	if (!pcOldParent->bDeleteChild(iChildOffset))
	{
		return false;
	}

	pcNewChildNode->vSetParent(pcParentNode);
	pcParentNode->vAddNewChild(pcNewChildNode);

	return true;
}

//Node functions
template<typename T>
CTreeDynamic<T>::CNodeDynamic::CNodeDynamic(CNodeDynamic* pcParent)
{
	pc_parent_node = pcParent;
	std::cout << "Creating new object\n";
}

template<typename T>
CTreeDynamic<T>::CNodeDynamic::CNodeDynamic(const CNodeDynamic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = new CNodeDynamic(pcOther.pc_parent_node);

	for (int i = 0; i < pcOther.v_children.size(); i++)
	{
		v_children.push_back(new CNodeDynamic(pcOther.v_children.at(i)));
	}
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic& CTreeDynamic<T>::CNodeDynamic::operator=(const CNodeDynamic& pcOther)
{
	i_val = pcOther.i_val;
	pc_parent_node = pcOther.pc_parent_node;

	for (int i = 0; i < pcOther.v_children.size(); i++)
	{
		v_children.push_back(new CNodeDynamic(pcOther.v_children.at(i)));
	}

	return *this;
}

template<typename T>
CTreeDynamic<T>::CNodeDynamic::~CNodeDynamic()
{
	std::cout << "Deleting object\n";

	for (typename std::vector<CNodeDynamic*>::const_iterator it = v_children.begin(); it != v_children.end();)
	{
		delete* it;
		it = v_children.erase(it);
	}
}

template<typename T>
bool CTreeDynamic<T>::CNodeDynamic::bDeleteChild(unsigned int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset > v_children.size())
	{
		return false;
	}

	typename std::vector<CNodeDynamic*>::const_iterator it = v_children.begin();
	it += iChildOffset;
	v_children.erase(it);

	return true;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetValue(T iNewVal)
{
	i_val = iNewVal;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild()
{
	v_children.push_back(new CNodeDynamic(this));
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrint()
{
	std::cout << ' ' << i_val;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrintAllBelow()
{
	vPrint();

	for (size_t i = 0; i < v_children.size(); i++)
	{
		v_children.at(i)->vPrintAllBelow();
	}
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vPrintUp()
{
	vPrint();

	if (pc_parent_node != nullptr)
	{
		pc_parent_node->vPrintUp();
	}
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vSetParent(CNodeDynamic* pcParent)
{
	pc_parent_node = pcParent;
}

template<typename T>
void CTreeDynamic<T>::CNodeDynamic::vAddNewChild(CNodeDynamic* pcChild)
{
	v_children.push_back(pcChild);
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetChild(unsigned int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset > v_children.size())
	{
		return nullptr;
	}

	return v_children.at(iChildOffset);
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetParent()
{
	return pc_parent_node;
}

template<typename T>
typename CTreeDynamic<T>::CNodeDynamic* CTreeDynamic<T>::CNodeDynamic::pcGetParent(unsigned int* piChildNumber)
{
	for (unsigned int i = 0; i < pc_parent_node->v_children.size(); i++)
	{
		if (v_children.at(i) == this)
		{
			*piChildNumber = i;
			return pc_parent_node;
		}
	}

	return pc_parent_node;
}

template<typename T>
CTreeDynamic<T>* CTreeDynamic<T>::CNodeDynamic::pcGetChildTree(unsigned int iChildOffset)
{
			CNodeDynamic* node = pcGetChild(iChildOffset);

			if (node != nullptr)
			{
				CTreeDynamic* tree = new CTreeDynamic(node);
				return tree;
			}

			return nullptr;
}

template<typename T>
inline int CTreeDynamic<T>::CNodeDynamic::iGetChildrenNumber()
{
	return v_children.size();
}
