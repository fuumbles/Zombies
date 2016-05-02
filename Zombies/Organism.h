#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class City;

class Organism
{
protected:
	int x;
	int y;
	int width;
	int height;
	int breedCount;
	bool moved;
	bool hasBred;
	City *city;

	enum { WEST, NORTH, EAST, SOUTH, NORTH_EAST, SOUTH_EAST, NORTH_WEST, SOUTH_WEST };

public:
	Organism();
	Organism( City *city, int width, int height );
	virtual ~Organism();

	virtual void move() = 0;	
	virtual void breed() = 0;

	void setPosition( int x, int y );

	bool getMoved();
	void setMoved(bool moved);

	bool getHasBred();
	void setHasBred(bool hasBred);
	void setBreedCount(int breedCount);
	int getBreedCount();

	friend ostream& operator<<( ostream &output, Organism *organism );
};

#endif
