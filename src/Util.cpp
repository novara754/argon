#include "Util.h"

std::string ReplaceAll(std::string s, const std::string_view &old_val, const std::string_view &new_val)
{
	size_t start_pos = 0;
	while ((start_pos = s.find(old_val, start_pos)) != std::string::npos)
	{
		s.replace(start_pos, old_val.length(), new_val);
		start_pos += new_val.length();
	}
	return s;
}
