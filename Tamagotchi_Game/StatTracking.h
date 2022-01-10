#pragma once


#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

class StatTracking
{
	public:
		StatTracking();
		void record();
		void read();
		void reset();
		int getHealth();
		void setHealth(int value);
		int getFood();
		void setFood(int value);
		int getCleanliness();
		void setCleanliness(int value);
		bool fileIsEmpty();

	private:
		ofstream myFile;
		ifstream myReadFile;
		struct tm timerik = {0};
		string str;
		int healthLvl;
		int foodLvl;
		int cleanlinessLvl;

		vector <int> lines;
};