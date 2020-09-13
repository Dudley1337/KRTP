#pragma once
#include "Ship_Charact.h"
#include "Exception.h"

class Military_Ships_Charact :
	public Ship_Charact
{
private:
	char** name;
	int num_of_characteristics;
public:
	Military_Ships_Charact();

	void set_name();

	void put();

	void save(ofstream& fout);

	void load(ifstream& fin);

	void info();

	~Military_Ships_Charact();
};