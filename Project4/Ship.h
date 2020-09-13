#pragma once
#include "Header.h"
#include "Ship_Charact.h"

class Ship
{
public:
	friend class PortCreater;
private:
	char name[N];
	Ship_Charact* Ñharacteristic;

public:

	Ship();

	void save(string filename);

	void load(ifstream& fin);

	void set();

	void info();
};