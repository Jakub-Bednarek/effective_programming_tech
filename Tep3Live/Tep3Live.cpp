// Tep3Live.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DirTree.h"

int main()
{
	DirTree* tree = new DirTree();
	auto res = tree->s_split_string("root/d1/d2/d3/d4/d5");

	tree->mk_dir("root/d1");
	tree->mk_dir("root/d1/d3");
	tree->mk_dir("root/d2");

	tree->v_list();

	delete tree;
}
