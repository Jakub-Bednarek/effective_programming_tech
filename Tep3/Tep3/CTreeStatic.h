#pragma once
#include <vector>

class CNodeStatic;

class CTreeStatic
{
private:
	class CNodeStatic
	{
	public:
		CNodeStatic();
		CNodeStatic(CNodeStatic* pcParent);
		CNodeStatic(const CNodeStatic& pcOther);
		CNodeStatic& operator=(const CNodeStatic& pcOther);
		~CNodeStatic();

		void vSetValue(int iNewVal);
		void vAddNewChild();
		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();

		int iGetChildrenNumber();

		CNodeStatic* pcGetChild(int iChildOffset);
	private:
		static constexpr int I_DEFAULT_VALUE = 0;
		std::vector<CNodeStatic> v_children;
		CNodeStatic* pc_parent_node;
		int i_val;
	};
public:
	CTreeStatic();
	~CTreeStatic();

	CNodeStatic* pcGetRoot();
private:
	CNodeStatic c_root;
};