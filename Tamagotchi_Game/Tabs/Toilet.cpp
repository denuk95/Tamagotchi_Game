#include "Toilet.h"


Toilet::Toilet(RenderWindow* temp1Window)
	: Tab(temp1Window, "assets/toilet.png")
{

}

void Toilet::action(StatTracking& stat)
{
	stat.setHealth(25);
	cout << "did action TOILET!" << endl;
}

