#include "Header.h"
#include "Exception.h"

bool Exception::is_digit(int& digit, string text)
{
	char _digit[10];
	try
	{
		printf("%s", text.c_str());
		cin >> _digit;
		for (int i = 0; i < strlen(_digit); i++)
			if (!isdigit(_digit[i]))
				throw 1641;
		digit = atoi(_digit);
		return false;
	}
	catch (const int& ex)
	{
		cout << "Ошибка при вводе данных!" << endl << "Код ошибки: #" << ex << endl << "Введите данные ещё раз:\t" << endl;
		return true;
	}
}

bool Exception::diapazon(int digit, int left_border, int right_border)
{
	try
	{
		if ((digit < left_border) || (digit > right_border))
			throw 222;
		return false;
	}
	catch (const int& ex)
	{
		cout << "Ошибка при вводе данных!" << endl << "Код ошибки: #" << ex << endl << "Введите данные ещё раз:\t" << endl;
		return true;
	}
}