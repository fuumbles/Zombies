#include "Zombie.h"
#include "Human.h"

Zombie::Zombie() {}
Zombie::~Zombie() {}

Zombie::Zombie(City *city, int width, int height) 
{
	this->city = city;
	this->width = width;
	this->height = height;
	this->starve = 0;
}

void Zombie::setStarve(int lastMeal)
{

	this->starve = lastMeal;
}

int Zombie::getStarve()
{
	return this->starve;
}

void Zombie::move()
{
	vector<int> validMoves;

	//checking for humans to eat
	//NORTH MOVE CHECK
	if((y - 1) >= 0 && city->getOrganism(x, y-1) != NULL)
	{
		validMoves.push_back(NORTH);
	}
	//SOUTH MOVE CHECK
	if((y + 1) <= height && city->getOrganism(x, y+1) != NULL)
	{
		validMoves.push_back(SOUTH);
	}
	//WEST MOVE CHECK
	if((x - 1) >= 0 && city->getOrganism(x, x-1) != NULL)
	{
		validMoves.push_back(WEST);
	}
	//EAST MOVE CHECK
	if((x + 1) <= width && city->getOrganism(x, x+1) != NULL)
	{
		validMoves.push_back(EAST);
	}
	//NORTH_WEST MOVE CHECK
	if((y - 1) >= 0 && (x - 1) >= 0 && city->getOrganism(x, y-1) != NULL)
	{
		validMoves.push_back(NORTH_WEST);
	}
	//SOUTH_EAST MOVE CHECK
	if((y + 1) <= height && (x + 1) > width && city->getOrganism(x, y+1) != NULL)
	{
		validMoves.push_back(SOUTH_EAST);
	}
	//SOUTH_WEST MOVE CHECK
	if((x - 1) >= 0 && (y + 1) > height && city->getOrganism(x, x-1) != NULL)
	{
		validMoves.push_back(SOUTH_WEST);
	}
	//NORTH_EAST MOVE CHECK
	if((y - 1) < 0 && (x + 1) <= width && city->getOrganism(x, x+1) != NULL)
	{
		validMoves.push_back(NORTH_EAST);
	}

	if(!validMoves.empty()){
		
		//Time since last meal is reset
		this->setStarve(0);
	}
	//if there are no humans in the 8 sqs around, do this
	else{
		//checking for moving as normal w/o human to eat


		int counter = getStarve();
		this->setStarve(counter+1);

		//delete zomzoms old position
		city->setOrganism(NULL,x,y);

		//check move positions
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
	}

	if(!validMoves.empty()){
		int ranNum = rand() % validMoves.size();
		int move = validMoves.at(ranNum);

		//delete zomzoms old position
		city->setOrganism(NULL,x,y);

		//get zomzoms new position
		if(move == NORTH){
			this->setPosition(x,y-1);
		}else if(move == SOUTH){
			this->setPosition(x,y+1);
		}else if(move == EAST){
			this->setPosition(x+1,y);
		}else if(move == WEST){
			this->setPosition(x-1,y);
		}else if(move == NORTH_EAST){
			this->setPosition(x+1,y-1);
		}else if(move == SOUTH_EAST){
			this->setPosition(x+1,y+1);
		}else if(move == NORTH_WEST){
			this->setPosition(x-1,y-1);
		}else if(move == SOUTH_WEST){
			this->setPosition(x-1,y+1);
		}

		
		//eat/set new position
		city->setOrganism(this,x,y);
	}	

	this->setMoved(true);

	this->starveZomZom();

}

//convert
void Zombie::breed()
{

}

void Zombie::starveZomZom()
{

	if(this->getStarve() > 3)
	{
		cout << "starve" << endl;
		/*Organism *pOrg =*/ 
		city->setOrganism(NULL, x, y);//retrieving zombie
		/*delete pOrg;*/
		
		human *newHuman = new human(city, x, y);//new human
		city->setOrganism(newHuman, x, y);//redefining zombie as human

		newHuman->setMoved(true);
		newHuman->setBreedCount(0);
		newHuman->setHasBred(true);
		
	}

}


