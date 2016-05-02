#include "Organism.h"
#include "Zombie.h"
#include "Human.h"
#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdexcept>
#include <cassert>

Organism::Organism(){};
Organism::~Organism(){};

Organism::Organism(City *city, int width, int height)
{
	//getting demensions of the city grid
	this->city = city;
	this->width = width;
	this->height = height;
}

void Organism::setPosition( int x, int y ){
	this->x = x;
	this->y = y;
}

void Organism::setMoved(bool moved){
	this->moved = moved;	
}

bool Organism::getMoved(){
	return this->moved;
}

void Organism::setHasBred(bool hasBred){
	this->hasBred = hasBred;	
}

bool Organism::getHasBred(){
	return this->hasBred;
}

void Organism::setBreedCount(int breedCount){
	this->breedCount = breedCount;
}

int Organism::getBreedCount(){
	return this->breedCount;
}


ostream& operator<<( ostream &output, Organism *organism ){

	//color controls

	HANDLE  hColor;	
    hColor = GetStdHandle (STD_OUTPUT_HANDLE);

	//check which organism the grid square is and output accordingly
	if(dynamic_cast<human*>(organism) != NULL){
		SetConsoleTextAttribute(hColor, 2);
		output << "H";
		SetConsoleTextAttribute(hColor, 7);
	}else if(dynamic_cast<Zombie*>(organism) != NULL){
		SetConsoleTextAttribute(hColor, 5);
		output << "Z";
		SetConsoleTextAttribute(hColor, 7);
	}else{
		output << (char)254;

	}

	return output;
}