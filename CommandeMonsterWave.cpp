#include "CommandeMonsterWave.h"
#include "World.h"
#include "EnvironmentUtils.h"


CommandeMonsterWave::CommandeMonsterWave()
{
}

CommandeMonsterWave::CommandeMonsterWave(int t, std::vector<std::string> p) {
	tick = t;
	params = p;
}

CommandeMonsterWave::~CommandeMonsterWave()
{
}

void CommandeMonsterWave::execute() {
	EnvironmentUtils::generateMonster(IAFactory::ShortestPathIA);
}
