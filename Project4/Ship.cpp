#include "Ship.h"

Ship::Ship()
{
	�haracteristic = nullptr;
}

void Ship::save(string filename)
{
	ofstream fout;
	fout.open(/*"MILITARY_SHIPS.txt"*/filename, ios::app);
	fout << name << "@";
	�haracteristic->save(fout);
	fout << endl;
	fout.close();
}

void Ship::load(ifstream& fin)
{
	char ch;
	fin.getline(name, N, '@');
	�haracteristic->load(fin);
	fin.get(ch);
}

void Ship::set()
{
	cout << "������� �������� �����: ";
	cin >> name;
	�haracteristic->set_name();
}

void Ship::info()
{
	cout << "�����: " << name << endl;
	�haracteristic->info();
}