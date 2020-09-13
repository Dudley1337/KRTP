#pragma once
#include "Ship_Charact.h"
#include "Exception.h"

class Civi_Ship_Charact :	public Ship_Charact
{
private:
	char** name;
	int num_of_characteristics;
public:
	Civi_Ship_Charact();

	void set_name();

	void put();

	void save(ofstream& fout);

	void load(ifstream& fin);

	void info();

	~Civi_Ship_Charact();
};