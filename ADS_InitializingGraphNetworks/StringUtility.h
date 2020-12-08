#pragma once
#include <string>
#include <algorithm>

/// @brief Provides common string manipulation and regex functions
class StringUtility
{
public:

	/// @brief converts string to lowercase
	/// @param str
	/// @return
	static std::string& to_lower(std::string& str)
	{
		std::transform(str.begin(), str.end(), str.begin(),
			[](unsigned char c) { return std::tolower(c); });

		return str;
	}

	/// @brief trim whitespace from the left hand side and right hand side of a string
	/// @param str
	/// @param chars
	/// @return string with no whitespace on LHS or RHS
	/// @see http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
	static std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		return ltrim(rtrim(str, chars), chars);
	}

	/// @brief trim whitespace from the left hand side of a string
	/// @param str
	/// @param chars
	/// @return string with no whitespace on LHS
	/// @see http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
	static std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		str.erase(0, str.find_first_not_of(chars));
		return str;
	}

	/// @brief trim whitespace from the right hand side of a string
	/// @param str
	/// @param chars
	/// @return string with no whitespace on RHS
	/// @see http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
	static std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
	{
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
};
