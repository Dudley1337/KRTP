#pragma once
#include "PortFactory.h"
#include "Civi_Ship_Charact.h"

class CIVILIAN_SHIPS :
	public PortFactory
{
public:
	Ship_Charact* createShips_characteristics();
};