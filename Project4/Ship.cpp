#include "Ship.h"

Ship::Ship()
{
	Ñharacteristic = nullptr;
}

void Ship::save(string filename)
{
	ofstream fout;
	fout.open(/*"MILITARY_SHIPS.txt"*/filename, ios::app);
	fout << name << "@";
	Ñharacteristic->save(fout);
	fout << endl;
	fout.close();
}

void Ship::load(ifstream& fin)
{
	char ch;
	fin.getline(name, N, '@');
	Ñharacteristic->load(fin);
	fin.get(ch);
}

void Ship::set()
{
	cout << "Ââåäèòå íàçâàíèå ñóäíà: ";
	cin >> name;
	Ñharacteristic->set_name();
}

void Ship::info()
{
	cout << "Ñóäíî: " << name << endl;
	Ñharacteristic->info();
}