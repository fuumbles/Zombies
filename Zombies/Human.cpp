#include "Human.h"

human::human() {}
human::~human() {}

human::human( City *city, int width, int height )
{
	this->city = city;
	this->width = width;
	this->height = height;	
}


void human::move() {

	vector<int> validMoves;	//used for keeping track of the valid moves after all checks are done


	//NORTH MOVE CHECK
	if((y - 1) >= 0 && city->getOrganism(x, y-1) == NULL)
	{
		validMoves.push_back(NORTH);
	}
	//SOUTH MOVE CHECK
	if((y + 1) < height && city->getOrganism(x, y+1) == NULL)
	{
		validMoves.push_back(SOUTH);
	}
	//WEST MOVE CHECK
	if((x - 1) >= 0 && city->getOrganism(x-1, y) == NULL)
	{
		validMoves.push_back(WEST);
	}
	//EAST MOVE CHECK
	if((x + 1) < width && city->getOrganism(x+1, y) == NULL)
	{
		validMoves.push_back(EAST);
	}

	//random move from valid vector moves
	if(!validMoves.empty()){
		int ranNum = rand() % validMoves.size();
		int move = validMoves.at(ranNum);

		//delete humans old position
		city->setOrganism(NULL,x,y);

		//get humans new position
		if(move == NORTH){
			this->setPosition(x,y-1);
		}else if(move == SOUTH){
			this->setPosition(x,y+1);
		}else if(move == WEST){
			this->setPosition(x-1,y);
		}else if(move == EAST){
			this->setPosition(x+1,y);
		}
		//move human
		city->setOrganism(this,x,y);
	}
	
	this->setMoved(true);

}

//recruit
void human::breed() {

	if(this->getBreedCount() == 3){		
		vector<int> validSpots;	//used for keeping track of the valid moves after all checks are done


		//NORTH BREED CHECK
		if((y - 1) >= 0 && city->getOrganism(x, y-1) == NULL)
		{
			validSpots.push_back(NORTH);
		}
		//SOUTH BREED CHECK
		if((y + 1) < height && city->getOrganism(x, y+1) == NULL)
		{
			validSpots.push_back(SOUTH);
		}
		//WEST BREED CHECK
		if((x - 1) >= 0 && city->getOrganism(x-1, y) == NULL)
		{
			validSpots.push_back(WEST);
		}
		//EAST BREED CHECK
		if((x + 1) < width && city->getOrganism(x+1, y) == NULL)
		{
			validSpots.push_back(EAST);
		}

		//random move from valid vector moves
		if(!validSpots.empty()){
			int ranNum = rand() % validSpots.size();
			int move = validSpots.at(ranNum);

			human *newHuman = new human(city, GRID_WIDTH, GRID_HEIGHT);

			//get human new position
			if(move == NORTH){
				newHuman->setPosition(x,y-1);
			}else if(move == SOUTH){
				newHuman->setPosition(x,y+1);
			}else if(move == WEST){
				newHuman->setPosition(x-1,y);
			}else if(move == EAST){
				newHuman->setPosition(x+1,y);
			}

			city->setOrganism(newHuman, newHuman->x, newHuman->y);

			newHuman->setMoved(true);
			newHuman->setBreedCount(0);
			newHuman->setHasBred(true);

		}

		this->setBreedCount(0);
	}
	else{

		//increase counter
		int count = this->getBreedCount();
		this->setBreedCount(count+1);
	
	}
}