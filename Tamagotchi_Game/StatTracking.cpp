#include "StatTracking.h"


StatTracking::StatTracking()
{

	if (fileIsEmpty())
	{
		healthLvl = 100;
		foodLvl = 80;
		cleanlinessLvl = 80;
	}
	else
	{
		read();
	}

	record();

}



void StatTracking::record()
{
	myFile.open("stat.txt");
	myFile << time(nullptr) << ' '<< healthLvl<< ' ' << foodLvl << ' ' << cleanlinessLvl;
	myFile.close();
}

void StatTracking::read()
{
	myReadFile.open("stat.txt");

	int i = 0;

	while (getline(myReadFile, str, ' '))
	{
		lines.push_back(stoi(str));
		i++;
	}

	healthLvl = lines.at(1);
	foodLvl = lines.at(2);
	cleanlinessLvl = lines.at(3);

	int difTime = difftime(lines.at(0), time(nullptr));

	setHealth(difTime / 3600);

	myReadFile.close();

}

void StatTracking::reset()
{
	healthLvl = 100;
	foodLvl = 80;
	cleanlinessLvl = 80;
	record();
}


int StatTracking::getHealth()
{
	return healthLvl;
}

void StatTracking::setHealth(int value)
{
	healthLvl += value;
}

int StatTracking::getFood()
{
	return foodLvl;
}
void StatTracking::setFood(int value)
{
	foodLvl += value;
}
int StatTracking::getCleanliness()
{
	return cleanlinessLvl;
}
void StatTracking::setCleanliness(int value)
{
	cleanlinessLvl += value;
}

bool StatTracking::fileIsEmpty()
{
	myReadFile.open("stat.txt");
	if (myReadFile.peek() == EOF)
	{
		cout << "File is empty!" << endl;
		myReadFile.close();
		return true;
	}
	myReadFile.close();
	return false;
}
