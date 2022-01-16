#include "FileNode.h"
#include <iostream>

#define S_DEFAULT_NAME "f"
#define S_DEFAULT_SPACE "   "

int FileNode::I_INSTANCES = 0;

FileNode::FileNode()
{
	m_name = S_DEFAULT_NAME + std::to_string(I_INSTANCES);
	I_INSTANCES++;
}

FileNode::FileNode(const std::string& a_name)
{
	m_name = a_name;
}

FileNode::~FileNode()
{
}

void FileNode::v_print_with_offset(int a_tabs_offset) const
{
	std::string out = "";
	for (int i = 0; i < a_tabs_offset; i++)
	{
		out.append(S_DEFAULT_SPACE);
	}

	std::cout << out << m_name << '\n';
}

const std::string& FileNode::s_get_name() const
{
	return m_name;
}
