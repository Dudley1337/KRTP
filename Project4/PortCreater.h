#pragma once
#include "Ship.h"
#include "PortFactory.h"

class PortCreater
{
public:
	Ship* createPort(PortFactory& factory);
};