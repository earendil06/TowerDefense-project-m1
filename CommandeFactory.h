#pragma once
#include <map>
#include <vector>
#include "Commande.h"
#include "StringUtils.h"
#include "CommandeMonsterWave.h"

class CommandeFactory {
private:
	static const char SEPARATOR = '/';
	CommandeFactory();
	~CommandeFactory();

	static std::map<std::string, char> dict;

public:
	static Commande* getCommande(std::string str);
};

inline CommandeFactory::~CommandeFactory() {}

inline Commande* CommandeFactory::getCommande(std::string str) {
	std::vector<std::string> inputs = StringUtils::split(str, SEPARATOR);
	int tick = atoi(inputs[0].c_str());
	char type = dict[inputs[1]];
	std::vector<std::string> params;
	for (int i = 2; i < inputs.size(); i++) {
		params.push_back(inputs[i]);
	}

	switch(type) {
	case 'G': 
		return new CommandeMonsterWave(tick, params);
	default: 
		return nullptr;
	}
}

std::map<std::string, char> CommandeFactory::dict = {
	{"genMonster", 'G'}
};
