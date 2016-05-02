#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include <Windows.h>

using namespace std;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class Organism;

class City
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	City();
	virtual ~City();

	Organism *getOrganism(int x, int y );
	void setOrganism(Organism *organism, int x, int y );

	int hCount();
	int zCount();

	void move();


	friend ostream& operator<<( ostream &output, City &city );

};

#endif

