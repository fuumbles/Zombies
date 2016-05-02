#include "City.h"
#include "Organism.h"
#include "Human.h"
#include "Zombie.h"

City::City() 
{
	//create empty 'city' grid
	for(int i=0;i<GRID_HEIGHT;i++){
		for(int j=0;j<GRID_WIDTH;j++){
			grid[j][i] = NULL;
		}
	}
}
City::~City() {}

//returning the grid layout for the organism positions around
Organism* City::getOrganism(int x, int y)
{
	return this->grid[x][y];
}

//placing the organism
void City::setOrganism(Organism *organism, int x, int y)
{
	grid[x][y] = organism;
}


void City::move()
{
	//reset moved to false for all orgs
	for (int i = 0; i<GRID_HEIGHT; i++){
		for (int j = 0; j<GRID_WIDTH; j++){
			if (grid[j][i] != NULL){
				grid[j][i]->setMoved(false);
				grid[j][i]->setHasBred(false);
			}
		}
	}

	// move
	for (int i = 0; i<GRID_HEIGHT; i++){
		for (int j = 0; j<GRID_WIDTH; j++){
			if (grid[j][i] != NULL) {
				if (grid[j][i]->getMoved() == false){
					grid[j][i]->move();
				}
			}
		}
	}
}



//void City::hmove()
//{
	////human move
	//for (int i = 0; i<GRID_HEIGHT; i++){
	//	for (int j = 0; j<GRID_WIDTH; j++){
	//		if ((dynamic_cast<human*>(City::getOrganism(j, i)) != NULL)) {
	//			if (grid[j][i]->getMoved() == false){
	//				grid[j][i]->move();
	//			}
	//		}
	//	}
	//}

	////human recruit
	//for (int i = 0; i<GRID_HEIGHT; i++){
	//	for (int j = 0; j<GRID_WIDTH; j++){
	//		if ((dynamic_cast<human*>(City::getOrganism(j, i)) != NULL)) {
	//			if (grid[j][i]->getHasBred() == false){
	//				grid[j][i]->breed();
	//			}
	//		}
	//	}
	//}
//}	


int City::hCount() {

	int count = 0;

	for(int i=0;i<GRID_HEIGHT;i++){
		for(int j=0;j<GRID_WIDTH;j++){
			if(dynamic_cast<human*>(grid[j][i]) != NULL){
				count++;				
			}
		}
	}

	return count;
}

int City::zCount() {

	int count = 0;

		for(int i=0;i<GRID_HEIGHT;i++){
		for(int j=0;j<GRID_WIDTH;j++){
			if(dynamic_cast<Zombie*>(grid[j][i]) != NULL){
				count++;
			}
		}
	}

	return count;
}

ostream& operator<<( ostream &output, City &city ){
	
	//redraw grid without clearing screen
	COORD coord = {0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

	//controls
	HANDLE  hColor;	
    hColor = GetStdHandle (STD_OUTPUT_HANDLE);

	//delay
	int seconds = 50;

	SetConsoleTextAttribute(hColor, 7);//light gray

	//draw grid
	for(int i=0;i<GRID_HEIGHT;i++){
		for(int j=0;j<GRID_WIDTH;j++){

			output << city.grid[j][i];
		}
		output << endl;
	}

	return output;

}