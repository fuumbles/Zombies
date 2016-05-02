#ifndef _ZOMBIE_H
#define _ZOMBIE_H
#include <vector>

#include "City.h"
#include "Organism.h"

class Zombie : public Organism
{

protected:
	int starve;

public:
	Zombie();
	Zombie( City *city, int width, int height );
	virtual ~Zombie();

	void move();
	void breed();
	void starveZomZom();
	void setStarve(int ate);
	int getStarve();
};

#endif
