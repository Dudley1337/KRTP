#pragma once
#include "Ship_Charact.h"

class PortFactory
{
public:
	virtual Ship_Charact* createShips_characteristics() = 0;
	virtual ~PortFactory() {}
};