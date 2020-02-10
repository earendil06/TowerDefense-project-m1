#pragma once
#include <vector>

class Commande {
protected:
	int tick;
	std::vector<std::string> params;

public:
	virtual ~Commande();

	virtual void execute() = 0;
	int getTick() const;
};

inline Commande::~Commande() {}
inline int Commande::getTick() const {
	return tick;
}

