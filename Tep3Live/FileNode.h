#pragma once
#include <string>

class FileNode
{
public:
	FileNode();
	FileNode(const std::string& a_name);
	~FileNode();

	void v_print_with_offset(int a_tabs_offset) const;
	const std::string& s_get_name() const;
private:
	static int I_INSTANCES;
	std::string m_name;
};