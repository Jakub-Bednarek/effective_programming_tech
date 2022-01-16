#include "DirTree.h"
#include <iostream>

#define S_DEFAULT_NAME "D"
#define S_DEFAULT_SPACE "   "

int DirTree::DirNode::I_INSTANCES = 0;

DirTree::DirNode::DirNode()
{
	m_name = S_DEFAULT_NAME + std::to_string(I_INSTANCES);
	I_INSTANCES++;
}

DirTree::DirNode::DirNode(const std::string& a_name)
{
	m_name = a_name;
}

DirTree::DirNode::~DirNode()
{
	std::vector<DirNode*>::const_iterator it_folders = m_folders.begin();
	for (int i = 0; i < m_folders.size(); i++)
	{
		delete* it_folders;
		it_folders = m_folders.erase(it_folders);
	}

	std::vector<FileNode*>::const_iterator it_files = m_files.begin();
	for (int i = 0; i < m_files.size(); i++)
	{
		delete* it_files;
		it_files = m_files.erase(it_files);
	}
}

void DirTree::DirNode::v_print_with_offset(int a_tabs_offset) const
{
	std::string out = "";
	for (int i = 0; i < a_tabs_offset; i++)
	{
		out.append(S_DEFAULT_SPACE);
	}

	std::cout << out << m_name << '\n';

	for (int i = 0; i < m_folders.size(); i++)
	{
		m_folders.at(i)->v_print_with_offset(a_tabs_offset + 1);
	}

	for (int i = 0; i < m_files.size(); i++)
	{
		m_files.at(i)->v_print_with_offset(a_tabs_offset + 1);
	}
}

const std::string& DirTree::DirNode::s_get_name() const
{
	return m_name;
}

bool DirTree::DirNode::b_add_folder(const std::vector<std::string>& a_dirs, int i_offset)
{
	if ((a_dirs.size() - 1) == i_offset)
	{
		m_folders.push_back(new DirNode(a_dirs.at(i_offset)));
		return true;
	}

	for (int i = 0; i < m_folders.size(); i++)
	{
		if (a_dirs.at(i_offset) == m_folders.at(i)->s_get_name())
		{
			return m_folders.at(i)->b_add_folder(a_dirs, i_offset + 1);
		}
	}

	return false;
}

bool DirTree::DirNode::b_add_file(const std::vector<std::string>& a_dirs, int i_offset, std::string a_name)
{
	if (a_dirs.size() - 1 == i_offset) 
	{
		m_files.push_back(new FileNode(a_name));
	}

	return true;
}

DirTree::DirTree()
{
	m_root = new DirNode("root");
}

DirTree::~DirTree()
{
	delete m_root;
}

DirTree::DirNode* DirTree::pc_get_root() const
{
	return m_root;
}

void DirTree::v_list() const
{
	m_root->v_print_with_offset(0);
}

int DirTree::mk_dir(const std::string& a_path)
{
	std::vector<std::string> a_dirs = s_split_string(a_path);

	if (m_root != nullptr)
	{
		if (m_root->s_get_name() == a_dirs.at(0))
		{
			return m_root->b_add_folder(a_dirs, 1);
		}
	}
	else if (a_dirs.size() == 1)
	{
		m_root = new DirNode(a_dirs.at(0));
		return true;
	}

	return false;
}

int DirTree::mk_file(const std::string& a_path)
{
	std::vector<std::string> a_dirs = s_split_string(a_path);

	if (m_root != nullptr)
	{
		if (m_root->s_get_name() == a_dirs.at(0))
		{
				return m_root->b_add_file(a_dirs, 1, "f");
		}
	}
	else if (a_dirs.size() == 1)
	{
		m_root = new DirNode(a_dirs.at(0));
		return true;
	}

	return false;
}

bool DirTree::is_file() const
{
	return false;
}

bool DirTree::is_dir() const
{
	return false;
}

std::vector<std::string> DirTree::s_split_string(std::string a_path)
{
	std::vector<std::string> a_dirs;
	int pos;
	while ((pos = a_path.find("/")) != std::string::npos) 
	{
		std::string name = a_path.substr(0, pos);
		if (name != "")
		{
			a_dirs.push_back(name);
		}
		a_path = a_path.substr(pos + 1);
	}
	if (a_path != "")
	{
		a_dirs.push_back(a_path);
	}

	return a_dirs;
}
