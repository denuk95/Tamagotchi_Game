#pragma once

#include "Tab.h"
#include "../RenderWindow.h"

class Toilet : public Tab
{
public:
	Toilet() {};
	Toilet(RenderWindow* temp1Window);
protected:


private:
	void action(StatTracking& stat);


};