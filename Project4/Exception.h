#pragma once
class Exception
{
public:
	//исключение, что в поле целого числа введены символы
	bool is_digit(int& digit, string text);

	bool diapazon(int digit, int left_border, int right_border);
};

