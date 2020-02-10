
#include "MyControlEngine.h"
#include "World.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		double frameWidth = glutGet(GLUT_WINDOW_WIDTH) / World::getMatrix()->getNbColumns();
		double frameHeight = glutGet(GLUT_WINDOW_HEIGHT) / World::getMatrix()->getNbLines();
		int i = std::div(y, frameHeight).quot;
		int j = std::div(x, frameWidth).quot;
		LandFrame* frame = static_cast<LandFrame*>(World::getMatrix()->getValue(i, j));
		if(frame->ok_for_tower()) {
			frame->set_ok_for_tower(false);
			World::getTowers()->push_back(new AbstractTower(frame));
		}
		
	}
}
