#pragma once

#include "Engine.h"

class MyGameEngine : public GameEngine {

private:
	int ticks;
public:
	virtual ~MyGameEngine() {}

	void idle() override;

	int getNbTicks() const;
};
