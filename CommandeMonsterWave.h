#pragma once
#include "Commande.h"
#include <string>
#include <vector>

class CommandeMonsterWave :public Commande
{

public:
	CommandeMonsterWave();
	CommandeMonsterWave(int, std::vector<std::string>);
	~CommandeMonsterWave();
	void execute() override;
};

