#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"

#include "Matrix.h"
#include "World.h"
#include "AbstractFrame.h"
#include "FrameFactory.h"
#include <map>
#include "FileReaderFactory.h"
#include <ctime>
#include <queue>
#include "Commande.h"
#include "CommandeFactory.h"


Matrix<AbstractFrame*>* initMatrix(int n, int m, std::string data) {
	Matrix<AbstractFrame*>* matrix = new Matrix<AbstractFrame*>(n, m);
	AbstractFrame* frame;
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			float width = 2.0 / m;
			float height = 2.0 / n;
			float ancX = -1.0f + j * width;
			float ancY = 1.0f - (i + 1) * height;
			char c = data.at(i * m + j);
			frame = FrameFactory::fromChar(i, j, c, ancX, ancY, width, height);
			matrix->setValue(i, j, frame);
		}
	}
	return matrix;
}


std::queue<Commande*>* initChronologie(std::string chrono) {
	std::queue<Commande*>* result = new std::queue<Commande*>();
	std::vector<std::string> lstStrs = StringUtils::split(chrono, ';');
	for (std::string str : lstStrs) {
		Commande* commande = CommandeFactory::getCommande(str);
		result->push(commande);
	}
	return result;
}

int main(int argc, char * argv[]){
	srand(static_cast<int>(time(nullptr)));
	//initialisations
	char* filename = "./levels/level1.txt";
	std::map<std::string, std::string> hash = FileReaderFactory::fromFile(filename);

	Matrix<AbstractFrame*>* matrix = initMatrix(atoi(hash.at("n").c_str()), atoi(hash.at("m").c_str()), hash.at("data"));
	std::queue<Commande*>* chronologie = initChronologie(hash.at("chrono").c_str());


	//configurations
	World::configureMatrix(matrix);
	World::configureChronologie(chronologie);
	

    Engine e(argc, argv);
    GraphicEngine* ge = new MyGraphicEngine();
    GameEngine* gme = new MyGameEngine();
    ControlEngine* ce = new MyControlEngine();
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();
    return 0;
}
