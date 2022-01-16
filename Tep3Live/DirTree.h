#pragma once
#include <vector>
#include <string>
#include "FileNode.h"

class DirTree
{
private:
	class DirNode
	{
	public:
		DirNode();
		DirNode(const std::string& a_name);
		~DirNode();

		void v_print_with_offset(int a_tabs_offset) const;
		const std::string& s_get_name() const;
		bool b_add_folder(const std::vector<std::string>& a_dirs, int i_offset);
		bool b_add_file(const std::vector<std::string>& a_dirs, int i_offset, std::string a_name);
	private:
		std::vector<DirNode*> m_folders;;
		std::vector<FileNode*> m_files;

		std::string m_name;
		static int I_INSTANCES;
	};

public:
	DirTree();
	~DirTree();

	DirNode* pc_get_root() const;

	void v_list() const;

	int mk_dir(const std::string& a_path);
	int mk_file(const std::string& a_path);

	bool is_file() const;
	bool is_dir() const;
	std::vector<std::string> s_split_string(std::string a_path);
private:
private:
	DirNode* m_root;
};