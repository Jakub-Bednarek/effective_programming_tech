#pragma once
#include <vector>

template<typename T>
class CTreeDynamic
{
public:
	class CNodeDynamic
	{
	public:
		CNodeDynamic(CNodeDynamic* pcParent);
		CNodeDynamic(const CNodeDynamic& pcOther);
		CNodeDynamic& operator=(const CNodeDynamic& pcOther);
		~CNodeDynamic();

		bool bDeleteChild(unsigned int iChildOffset);

		int iGetChildrenNumber();

		void vSetValue(T iNewVal);
		void vAddNewChild();
		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();
		void vSetParent(CNodeDynamic* pcParent);
		void vAddNewChild(CNodeDynamic* pcChild);

		CNodeDynamic* pcGetChild(unsigned int iChildOffset);
		CNodeDynamic* pcGetParent();
		CNodeDynamic* pcGetParent(unsigned int* piChildNumber);

		CTreeDynamic<T>* pcGetChildTree(unsigned int iChildOffset);
	private:
		static constexpr int I_DEFAULT_VALUE = 0;
		std::vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		T i_val;
	};
public:
	CTreeDynamic();
	CTreeDynamic(CNodeDynamic* pcRoot);
	~CTreeDynamic();

	CNodeDynamic* pcGetRoot() const;
	void vPrintTree() const;
	static bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
private:
	CNodeDynamic* pc_root;
};

#include "CTreeDynamic.tpp""