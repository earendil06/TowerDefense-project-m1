#pragma once
class Actionable{

private:
	int nbTick = 0;
	int tickSleep = 1;

public:
	virtual ~Actionable() {}
	void tick() {
		set_nb_tick((nb_tick() + 1) % tickSleep);
		if (nb_tick() == 0) {
			act();
		}
	}

	virtual void act() = 0;


	void set_nb_tick(int nb_tick) { nbTick = nb_tick; }
	int nb_tick() const { return nbTick; }

	void setTickSleep(int newSleep) {
		tickSleep = newSleep;
	}
};

