#include "Food.h"


Food::Food(RenderWindow* temp1Window)
: Tab(temp1Window, "assets/food.png")
{

}

void Food::action(StatTracking& stat)
{
	cout<<"did action FOOD!"<<endl;
}

