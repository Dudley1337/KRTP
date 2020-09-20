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
	PortCreater NewShip;
	MILITARY_SHIPS* MILITARY_factory;
	CIVILIAN_SHIPS* CIVILIAN_factory;
	int num_MILITARY_factory;
	int num_CIVILIAN_factory;
	int all_MILITARY;
	int all_CIVILIAN;
	int num_line_delete;
	int nem_line_now = 0;
	int num_in_list;
	ifstream fin;
	ofstream fout;
	string filename;
	string line;
	string line_file_text;
	int menu;

	while (true)
	{

		cout << "Выберите боевые или гражданские корабли: " << endl;
		cout << "1 - Боевые" << endl;
		cout << "2 - Гражданские" << endl;
		cout << "0 - EXIT" << endl;


		cin >> menu;
		switch (menu)
		{
		case 1:
			filename = "MILITARY_SHIPS.txt";
			cout << "Выберите действие: " << endl;
			cout << "1 - Создание кораблей" << endl;
			cout << "2 - Загрузка данных из файла" << endl;
			cout << "3 - Удаление базы данных" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << "Введите количество военных кораблей, которых хотите добавить: " << endl;
				cin >> num_MILITARY_factory;
				MILITARY_factory = new MILITARY_SHIPS[num_MILITARY_factory];

				for (int i = 0; i < num_MILITARY_factory; i++)
				{
					M = NewShip.createPort(MILITARY_factory[i]);
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
					buffer = NewShip.createPort(*MILITARY_factory);
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
				num_in_list = 0;
				try
				{
					fin.open("MILITARY_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_MILITARY_factory; i++)
					{
						num_in_list++;
						cout << "Номер корабля в списке: " << num_in_list << endl;
						M = NewShip.createPort(MILITARY_factory[i]);
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
				all_MILITARY = 0;
				try
				{
					fin.open("MILITARY_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					MILITARY_factory = new MILITARY_SHIPS;
					buffer = NewShip.createPort(*MILITARY_factory);
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
				num_in_list = 0;
				try
				{
					fin.open("MILITARY_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_MILITARY_factory; i++)
					{
						num_in_list++;
						cout << "Номер корабля в списке: " << num_in_list << endl;
						M = NewShip.createPort(MILITARY_factory[i]);
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

				cout << "Введите номер корабля, который нужно удалить:" << endl;
				cin >> num_line_delete;
				fin.open("MILITARY_SHIPS.txt");
				line_file_text = "";
				nem_line_now = 0;
				while (!fin.eof())
				{
					getline(fin, line, '\n');
					nem_line_now++;

					if (!(nem_line_now == num_line_delete))
					{
						line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
						/*добавить перенос на слудующую строку*/
						if (!(num_line_delete == num_in_list))
						{
							if ((nem_line_now == num_in_list)/* || (nem_line_now == (num_in_list - 1))*/) {}
							else
							{
								line_file_text.insert(line_file_text.size(), "\n");
							}
						}
						else if (!(nem_line_now == (num_in_list - 1)))
						{
							line_file_text.insert(line_file_text.size(), "\n");
						}
						
					}
				}
				fin.close();

				fout.open("MILITARY_SHIPS.txt"/*, ios::trunc | ios::binary*/); //открыть и обрезать
				//fout.clear();

				//записать

				fout.write(line_file_text.c_str(), line_file_text.size());
				fout.clear();
				fout.close();
				break;
			case 0:
				cout << "Назад";
				break;
			}
			break;
		case 2:
			filename = "CIVILIAN_SHIPS.txt";
			cout << "Выберите действие: " << endl;
			cout << "1 - Создание кораблей" << endl;
			cout << "2 - Загрузка данных из файла" << endl;
			cout << "3 - Удаление базы данных" << endl;
			cin >> menu;
			switch (menu)
			{
			case 1:
				cout << "Введите количество гражданских кораблей, которых хотите добавить: " << endl;
				cin >> num_CIVILIAN_factory;
				CIVILIAN_factory = new CIVILIAN_SHIPS[num_CIVILIAN_factory];

				for (int i = 0; i < num_CIVILIAN_factory; i++)
				{
					M = NewShip.createPort(CIVILIAN_factory[i]);
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
					buffer = NewShip.createPort(*CIVILIAN_factory);
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
				num_in_list = 0;
				try
				{
					fin.open("CIVILIAN_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_CIVILIAN_factory; i++)
					{
						num_in_list++;
						cout << "Номер корабля в списке: " << num_in_list << endl;
						M = NewShip.createPort(CIVILIAN_factory[i]);
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
				all_MILITARY = 0;
				try
				{
					fin.open("CIVILIAN_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					MILITARY_factory = new MILITARY_SHIPS;
					buffer = NewShip.createPort(*MILITARY_factory);
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
				num_in_list = 0;
				try
				{
					fin.open("CIVILIAN_SHIPS.txt");
					if (!fin.is_open()) {
						throw 111;
					}
					for (int i = 0; i < num_MILITARY_factory; i++)
					{
						num_in_list++;
						cout << "Номер корабля в списке: " << num_in_list << endl;
						M = NewShip.createPort(MILITARY_factory[i]);
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

				cout << "Введите номер корабля, который нужно удалить:" << endl;
				cin >> num_line_delete;
				fin.open("CIVILIAN_SHIPS.txt");
				line_file_text = "";
				nem_line_now = 0;
				while (!fin.eof())
				{
					getline(fin, line, '\n');
					nem_line_now++;

					if (!(nem_line_now == num_line_delete))
					{
						line_file_text.insert(line_file_text.size(), line); /*дабавить строку*/
						/*добавить перенос на слудующую строку*/
						if (!(num_line_delete == num_in_list))
						{
							if ((nem_line_now == num_in_list)/* || (nem_line_now == (num_in_list - 1))*/) {}
							else
							{
								line_file_text.insert(line_file_text.size(), "\n");
							}
						}
						else if (!(nem_line_now == (num_in_list - 1)))
						{
							line_file_text.insert(line_file_text.size(), "\n");
						}

					}
				}
				fin.close();

				fout.open("CIVILIAN_SHIPS.txt"/*, ios::trunc | ios::binary*/); //открыть и обрезать
				//fout.clear();

				//записать

				fout.write(line_file_text.c_str(), line_file_text.size());
				fout.clear();
				fout.close();
				break;
				break;
			case 0:
				cout << "Назад";
				break;
			}
			break;
		case 0:
			return 0;
		}
	}
	system("pause");
}