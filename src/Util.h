#pragma once

#include <string>
#include <string_view>

std::string ReplaceAll(std::string s, const std::string_view &old_val, const std::string_view &new_val);
