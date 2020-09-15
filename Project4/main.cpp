#include "Header.h"
#include "Ship.h"
#include "PortCreater.h"
#include "MILITARY.h"
#include "CIVILIAN.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Ship* M;
	Ship* D;

	Ship* buffer;

	PortCreater game;
	MILITARY_SHIPS* MILITARY_factory;
	CIVILIAN_SHIPS* CIVILIAN_factory;
	int num_MILITARY_factory;
	int num_CIVILIAN_factory;

	int all_MILITARY;
	int all_CIVILIAN;

	ifstream fin;
	ofstream fout;

	string filename;

	int swtch;
	while (true)
	{

		cout << "Выберите боевые или гражданские корабли: " << endl;
		cout << "1 - Боевые" << endl;
		cout << "2 - Гражданские" << endl;
		cout << "0 - EXIT" << endl;


		cin >> swtch;
		switch (swtch)
		{
		case 1:
			filename = "MILITARY_SHIPS.txt";
			cout << "Выберите действие: " << endl;
			cout << "1 - Создание кораблей" << endl;
			cout << "2 - Загрузка данных из файла" << endl;
			cout << "3 - Удаление базы данных" << endl;
			cin >> swtch;
			switch (swtch)
			{
			case 1:
				cout << "Введите количество военных кораблей, которых хотите добавить: " << endl;
				cin >> num_MILITARY_factory;
				MILITARY_factory = new MILITARY_SHIPS[num_MILITARY_factory];

				for (int i = 0; i < num_MILITARY_factory; i++)
				{
					M = game.createPort(MILITARY_factory[i]);
					M->set();
					M->save(filename);
				}

				delete[] MILITARY_factory;
				break;
			case 2:
				all_MILITARY = 0;
				try
				{
					fin.open("MILITARY_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					MILITARY_factory = new MILITARY_SHIPS;
					buffer = game.createPort(*MILITARY_factory);
					while (!fin.eof())
					{
						all_MILITARY++;
						buffer->load(fin);
					}
					delete MILITARY_factory;
					fin.close();
				}
				catch (const int ex)
				{
					cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
				}

				MILITARY_factory = new MILITARY_SHIPS[all_MILITARY];
				num_MILITARY_factory = all_MILITARY;
				try
				{
					fin.open("MILITARY_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_MILITARY_factory; i++)
					{
						M = game.createPort(MILITARY_factory[i]);
						M->load(fin);
						M->info();
						cout << endl;
					}
					fin.close();
				}
				catch (const int ex)
				{
					cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
				}
				break;
			case 3:
				fout.open("MILITARY_SHIPS.txt");
				fout.close();
				break;
			default:
				break;
			}
			break;
		case 2:
			filename = "CIVILIAN_SHIPS.txt";
			cout << "Выберите действие: " << endl;
			cout << "1 - Создание кораблей" << endl;
			cout << "2 - Загрузка данных из файла" << endl;
			cout << "3 - Удаление базы данных" << endl;
			cin >> swtch;
			switch (swtch)
			{
			case 1:
				cout << "Введите количество гражданских кораблей, которых хотите добавить: " << endl;
				cin >> num_CIVILIAN_factory;
				CIVILIAN_factory = new CIVILIAN_SHIPS[num_CIVILIAN_factory];

				for (int i = 0; i < num_CIVILIAN_factory; i++)
				{
					M = game.createPort(CIVILIAN_factory[i]);
					M->set();
					M->save(filename);
				}

				delete[] CIVILIAN_factory;
				break;
			case 2:
				all_CIVILIAN = 0;
				try
				{
					fin.open("CIVILIAN_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					CIVILIAN_factory = new CIVILIAN_SHIPS;
					buffer = game.createPort(*CIVILIAN_factory);
					while (!fin.eof())
					{
						all_CIVILIAN++;
						buffer->load(fin);
					}
					delete CIVILIAN_factory;
					fin.close();
				}
				catch (const int ex)
				{
					cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
				}

				CIVILIAN_factory = new CIVILIAN_SHIPS[all_CIVILIAN];
				num_CIVILIAN_factory = all_CIVILIAN;
				try
				{
					fin.open("CIVILIAN_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_CIVILIAN_factory; i++)
					{
						M = game.createPort(CIVILIAN_factory[i]);
						M->load(fin);
						M->info();
						cout << endl;
					}
					fin.close();
				}
				catch (const int ex)
				{
					cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
				}
				break;
			case 3:
				fout.open("CIVILIAN_SHIPS.txt");
				fout.close();
				break;
			default:
				break;
			}
			break;
		case 0:
			return 0;
		}
	}
	system("pause");
}