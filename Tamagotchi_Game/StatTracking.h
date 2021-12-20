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
		int healthLvl = 9999;
		int foodLvl = 9999;
		int cleanlinessLvl = 9999;

		vector <int> lines;
};