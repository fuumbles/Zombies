#define _WIN32_WINNT 0x0500

#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <Windows.h>

#include "Organism.h"
#include "Human.h"
#include "Zombie.h"
#include "City.h"
using namespace std;

//prototypes
void timer();// working
void CityBuilder();

void main()	{
	
	string input = "";

	//keeping track of number of objects
	int humanCount = 0;
	int zomzomCount = 0;

	//iterations count
	int iteration = 0;

	//color output
	HANDLE  hColor;	
    hColor = GetStdHandle (STD_OUTPUT_HANDLE);

	//random generator
	srand (time(NULL));

	City *city = new City();

	//do
	//{
	//	int ranX = rand() % GRID_WIDTH;
	//	int ranY = rand() % GRID_HEIGHT;
	//	int ranBreed = rand() % 4;
	//	//random placement generation

	//	if(city->getOrganism(ranX, ranY) == NULL)
	//	{
	//		human *newMan = new human(city, GRID_WIDTH, GRID_HEIGHT);
	//		newMan->setPosition(ranX, ranY);
	//		newMan->setBreedCount(0);
	//		city->setOrganism(newMan, ranX, ranY);
	//		humanCount++;

	//	}
	//}
	//while(humanCount != 0);

	do
	{
		int ranX = rand() % GRID_WIDTH;
		int ranY = rand() % GRID_HEIGHT;
		int ranBreed = rand() % 4;
		//random placement generation

		if(city->getOrganism(ranX, ranY) == NULL)
		{
			Zombie *ZomZom = new Zombie(city, GRID_WIDTH, GRID_HEIGHT);
			ZomZom->setPosition(ranX, ranY);
			ZomZom->setBreedCount(0);
			city->setOrganism(ZomZom, ranX, ranY) ;
			zomzomCount++;

		}
	}
	while(zomzomCount < 5);

	while (zomzomCount>0){	//humanCount>0 && 
	
		//move one turn
		city->move();
		//city->zmove();
		//city->hmove();
		humanCount = city->hCount();
		zomzomCount = city->zCount();
		iteration++;

		_getch();
		cout << *city;
		cout << "  Turn: " << iteration;
		SetConsoleTextAttribute(hColor, 2);
		cout << "     Humans: ";
		SetConsoleTextAttribute(hColor, 7);
		cout << humanCount;
		SetConsoleTextAttribute(hColor, 5);
		cout << "      Zombies: ";
		SetConsoleTextAttribute(hColor, 7);
		cout << zomzomCount << "       " << endl;	
	}


	_getch();
}








