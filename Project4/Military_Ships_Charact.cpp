#include "Military_Ships_Charact.h"
//военные корабли

Military_Ships_Charact::Military_Ships_Charact()
{
	num_of_characteristics = 0;
	cout << "Вызвался конструктор Military_ships_characteristics" << endl << endl;
}

void Military_Ships_Charact::set_name()
{
	Exception ex;

	int num_of_characteristic = 0;
	int swtch;
	int tmp_digit;

	num_of_characteristics = 9;

	name = new char* [num_of_characteristics];
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		name[i] = new char[N];
	}

	///первая характеристика
	//написать исключения на повторение способов передвижения
	cout << "Укажтие тип военного корабля: " << endl;
	cout << "1 - Авианосец " << endl << "2 - Крейсер " << endl << "3 - Эсминец " << endl << "4 - Противолодочный " << endl << "5 - Десантный корабль " << endl;

	do
	{
		cin >> swtch; // исключение реализовать
	} 
	while (ex.diapazon(swtch, 1, 5));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "Авианосец");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "Крейсер");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "Эсминец");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "Противолодочный");
		break;
	case 5:
		strcpy(name[num_of_characteristic], "Десантный_корабль");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///Вторая характеристика

	cout << "Корабль идет на ремонт/реставрацию? " << endl;
	cout << "1 - ДА " << endl << "2 - НЕТ " << endl;

	do
	{
		cin >> swtch; // исключение реализовать
	} while (ex.diapazon(swtch, 1, 2));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "ДА");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "НЕТ");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///Третья характеристика

	cout << "Укажите габариты корабля " << endl;

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "Укажите длину в диапозоне от 15 до 500 метров "));
	} while (ex.diapazon(tmp_digit, 15, 500));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "Укажите ширину в диапозоне от 2 до 80 метров "));
	} while (ex.diapazon(tmp_digit, 2, 80));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///4-ая характеристика

	cout << "Укажтие район плавания корабля: " << endl;
	cout << "1 - Морской район А1 " << endl << "2 - Морской район А2 " << endl << "3 - Морской район А3 " << endl << "4 - Морской район А4 " << endl;

	do
	{
		cin >> swtch; // исключение реализовать
	} while (ex.diapazon(swtch, 1, 4));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "Морской район А1");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "Морской район А2");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "Морской район А3");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "Морской район А4");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///5-ая характеристика

	cout << "Тип энергетической установки корабля: " << endl;
	cout << "1 - Пароход " << endl << "2 - Дизельный двигатель " << endl << "3 - Электрическая " << endl << "4 - Атомная " << endl;

	do
	{
		cin >> swtch; // исключение реализовать
	} while (ex.diapazon(swtch, 1, 5));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "Пароход");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "Дизельный двигатель");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "Электрическая");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "Атомная");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///6-ая характеристика

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "Укажите экипаж корабля от 1 до 3000 человек "));
	} while (ex.diapazon(tmp_digit, 1, 3000));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///7-ая характеристика

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "Укажите количество пассажиров на судне от 0 до 6780 человек "));
	} while (ex.diapazon(tmp_digit, 0, 6780));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///8-ая характеристика

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "укажите максимальную скорость судна (предельная скорость 50 узлов) "));
	} while (ex.diapazon(tmp_digit, 0, 50));

	itoa(tmp_digit, name[num_of_characteristic], 10);

}

void Military_Ships_Charact::put()
{
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		switch (i)
		{
		case 0:
			cout << endl << "Тип судна => ";
			break;
		case 1:
			cout << "Корабль идет на ремонт/реставрацию? => ";
			break;
		case 2:
			cout << "Габариты судна: " << endl;
			cout << "Длина => ";
			cout.width(45);
			break;
		case 3:
			cout << "Ширина => ";
			break;
		case 4:
			cout << "Район плавания => ";
			break;
		case 5:
			cout << "Тип энергетической установки => ";
			break;
		case 6:
			cout << "Экипаж => ";
			break;
		case 7:
			cout << "Количество пассажиров => ";
			break;
		case 8:
			cout << "Скорость => ";
			break;
		default:
			break;
		}
		cout.setf(ios::left);
		cout.width(45);
		puts(name[i]);
	}
}

void Military_Ships_Charact::save(ofstream& fout)
{
	fout << num_of_characteristics << "@";
	for (int i = 0; i < num_of_characteristics; i++)
	{
		fout << name[i] << "@";
	}
}

void Military_Ships_Charact::load(ifstream& fin)
{


	for (int i = 0; i < num_of_characteristics; ++i)
	{
		delete[] name[i];
	}
	delete name;

	char ch;
	fin.get(ch);
	num_of_characteristics = atoi(&ch);
	fin.get(ch);

	name = new char* [num_of_characteristics];
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		name[i] = new char[N];
	}

	for (int i = 0; i < num_of_characteristics; i++)
	{
		fin.getline(name[i], N, '@');
	}
}

void Military_Ships_Charact::info()
{
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		switch (i)
		{
		case 0:
			cout << endl << "Тип судна => ";
			break;
		case 1:
			cout << "Корабль идет на ремонт/реставрацию? => ";
			break;
		case 2:
			cout << "Габариты судна: " << endl << "Длина => ";
			break;
		case 3:
			cout << "Ширина => ";
			break;
		case 4:
			cout << "Район плавания => ";
			break;
		case 5:
			cout << "Тип энергетической установки => ";
			break;
		case 6:
			cout << "Экипаж => ";
			break;
		case 7:
			cout << "Количество пассажиров => ";
			break;
		case 8:
			cout << "Скорость => ";
			break;
		default:
			break;
		}
		puts(name[i]);
	}
}

Military_Ships_Charact::~Military_Ships_Charact()
{
	cout << "Destructor_~Military_ships_characteristics" << endl;
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		delete[] name[i];
	}
	delete name;
}