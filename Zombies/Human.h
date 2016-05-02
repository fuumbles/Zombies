#ifndef _Human_H
#define _Human_H
#include <vector>

#include "City.h"
#include "Organism.h"

class human : public Organism
{
public:
	human(); 
	human( City *city, int width, int height );
	virtual ~human();

	void move();
	void breed();
};

#endif
