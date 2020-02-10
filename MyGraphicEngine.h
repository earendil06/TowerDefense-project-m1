#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"


class MyGraphicEngine : public GraphicEngine {

public:
	virtual ~MyGraphicEngine() {}

	virtual void Draw();

};