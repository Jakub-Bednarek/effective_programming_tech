#pragma once
#include <vector>

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

		bool bDeleteChild(int iChildOffset);
		void vSetValue(int iNewVal);
		void vAddNewChild();
		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();
		void vSetParent(CNodeDynamic* pcParent);
		void vAddNewChild(CNodeDynamic* pcChild);

		CNodeDynamic* pcGetChild(int iChildOffset);
		CNodeDynamic* pcGetParent();
		CNodeDynamic* pcGetParent(int* piChildNumber);
		CTreeDynamic* pcGetChildTree(int iChildOffset);
		int iGetChildrenNumber();
	private:
		static constexpr int I_DEFAULT_VALUE = 0;
		std::vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		int i_val;
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