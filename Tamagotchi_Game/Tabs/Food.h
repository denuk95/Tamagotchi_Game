#pragma once

#include "Tab.h"
#include "../RenderWindow.h"

class Food : public Tab
{
	public:
		Food(){};
		Food(RenderWindow* temp1Window);
	protected:


	private:
		void action(StatTracking& stat);


};