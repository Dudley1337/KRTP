#pragma once
#include "Header.h"

class Ship_Charact 
{
public:
	virtual void set_name() = 0;

	virtual void save(ofstream& fout) = 0;

	virtual void load(ifstream& fin) = 0;

	virtual void info() = 0;
};