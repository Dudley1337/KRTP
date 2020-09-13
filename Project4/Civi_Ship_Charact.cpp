#include "Civi_Ship_Charact.h"

Civi_Ship_Charact::Civi_Ship_Charact()
{
	num_of_characteristics = 0;
	cout << "Вызвался конструктор Civilian_ships_characteristics" << endl << endl;
}

void Civi_Ship_Charact::set_name()
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
	cout << "Укажтие тип гражданского корабля: " << endl;
	cout << "1 - Баржа " << endl << "2 - Судно береговой охраны " << endl << "3 - Частное судно " << endl << "4 - Рыболовное судно " << endl << "5 - Пассажирское судно " << endl;

	do
	{
		cin >> swtch;
	} while (ex.diapazon(swtch, 1, 8));

	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "Баржа");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "Судно береговой охраны");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "Частное судно");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "Рыболовное судно");
		break;
	case 5:
		strcpy(name[num_of_characteristic], "Пассажирское судно");
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
		} while (ex.is_digit(tmp_digit, "Укажите длину в диапозоне от 25 до 415 метров "));
	} while (ex.diapazon(tmp_digit, 25, 415));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "Укажите ширину в диапозоне от 2 до 64 метров "));
	} while (ex.diapazon(tmp_digit, 2, 64));

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
		} while (ex.is_digit(tmp_digit, "Укажите количество пассажиров на судне от 0 до 6500 человек "));
	} while (ex.diapazon(tmp_digit, 0, 6500));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///8-ая характеристика

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "укажите максимальную скорость судна (предельная скорость 45 узлов) "));
	} while (ex.diapazon(tmp_digit, 0, 45));

	itoa(tmp_digit, name[num_of_characteristic], 10);
}

void Civi_Ship_Charact::put()
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
			cout << "Габариты судна: " << endl << "	Длина => ";
			break;
		case 3:
			cout << "	Ширина => ";
			break;
		case 4:
			cout << "Район плавания => ";
			break;
		case 5:
			cout << "Тип энергетической установки => ";
			break;
		case 6:
			cout << "Водоизмещение => ";
			break;
		case 7:
			cout << "Экипаж => ";
			break;
		case 8:
			cout << "Количество пассажиров => ";
			break;
		case 9:
			cout << "Скорость => ";
			break;
		default:
			break;
		}
		puts(name[i]);
	}
}

void Civi_Ship_Charact::save(ofstream& fout)
{
	fout << num_of_characteristics << "@";
	for (int i = 0; i < num_of_characteristics; i++)
	{
		fout << name[i] << "@";
	}
}

void Civi_Ship_Charact::load(ifstream& fin)
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

void Civi_Ship_Charact::info()
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

Civi_Ship_Charact::~Civi_Ship_Charact()
{
	cout << "Destructor_~Civilian_ships_characteristics" << endl;
	for (int i = 0; i < num_of_characteristics; ++i)
	{
		delete[] name[i];
	}
	delete name;
}