#pragma once
#include "PortFactory.h"
#include "Military_Ships_Charact.h"

class MILITARY_SHIPS :
	public PortFactory
{
public:
	Ship_Charact* createShips_characteristics();
};

