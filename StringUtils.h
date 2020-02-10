#pragma once
#include <vector>
#include <sstream>

class StringUtils {
private:
	StringUtils();
	~StringUtils();

public:
	static std::vector<std::string> StringUtils::split(std::string str, char separator) {
		std::vector<std::string> internal;
		std::stringstream ss(str);
		std::string tok;
		while (getline(ss, tok, separator)) {
			internal.push_back(tok);
		}
		return internal;
	}
};
