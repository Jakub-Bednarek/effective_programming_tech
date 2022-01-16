#include <iostream>
#include "CTreeDynamic.h"

int main()
{
	CTreeDynamic<int>* c_tree = new CTreeDynamic<int>();

	c_tree->pcGetRoot()->vAddNewChild();
	c_tree->pcGetRoot()->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree->pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();


	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	auto newTree = c_tree->pcGetRoot()->pcGetChildTree(0);
	newTree->vPrintTree();

	c_tree->vPrintTree();
	std::cout << '\n';
	c_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	std::cout << '\n';

	CTreeDynamic<int>* c_tree2 = new CTreeDynamic<int>();

	c_tree2->pcGetRoot()->vAddNewChild();
	c_tree2->pcGetRoot()->pcGetChild(0)->vSetValue(5);

	c_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();


	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(13);
	c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(7);

	c_tree2->pcGetRoot()->vPrintAllBelow();
	std::cout << '\n';

	CTreeDynamic<int>::bMoveSubtree(c_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(1), c_tree->pcGetRoot()->pcGetChild(0));

	c_tree->pcGetRoot()->vPrintAllBelow();
	std::cout << '\n';

	c_tree2->pcGetRoot()->vPrintAllBelow();
	std::cout << '\n';

	delete c_tree;
	delete c_tree2;
}