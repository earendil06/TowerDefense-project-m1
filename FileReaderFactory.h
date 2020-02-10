#pragma once
#include <map>
#include <fstream>
#include <string>
#include <vector>
#include "StringUtils.h"


class FileReaderFactory
{
public:
	static std::map<std::string, std::string> fromFile(char*);

private:
	static const char SEPARATOR = '=';

	FileReaderFactory();
};

inline std::map<std::string, std::string> FileReaderFactory::fromFile(char* filename) {
	std::map<std::string, std::string> result;
	std::ifstream myfile(filename, std::ifstream::in);
	for (std::string line; getline(myfile, line); ) {
		std::vector<std::string> acc = StringUtils::split(line, SEPARATOR);
		std::string key = acc.at(0);
		std::string value = acc.at(1);
		result[key] = value;
	}
	myfile.close();
	return result;
}
