#include "Military_Ships_Charact.h"
//������� �������

Military_Ships_Charact::Military_Ships_Charact()
{
	num_of_characteristics = 0;
	cout << "�������� ����������� Military_ships_characteristics" << endl << endl;
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

	///������ ��������������
	//�������� ���������� �� ���������� �������� ������������
	cout << "������� ��� �������� �������: " << endl;
	cout << "1 - ��������� " << endl << "2 - ������� " << endl << "3 - ������� " << endl << "4 - ��������������� " << endl << "5 - ��������� ������� " << endl;

	do
	{
		cin >> swtch; // ���������� �����������
	} 
	while (ex.diapazon(swtch, 1, 5));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "���������");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "�������");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "�������");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "���������������");
		break;
	case 5:
		strcpy(name[num_of_characteristic], "���������_�������");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///������ ��������������

	cout << "������� ���� �� ������/�����������? " << endl;
	cout << "1 - �� " << endl << "2 - ��� " << endl;

	do
	{
		cin >> swtch; // ���������� �����������
	} while (ex.diapazon(swtch, 1, 2));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "��");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "���");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///������ ��������������

	cout << "������� �������� ������� " << endl;

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "������� ����� � ��������� �� 15 �� 500 ������ "));
	} while (ex.diapazon(tmp_digit, 15, 500));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "������� ������ � ��������� �� 2 �� 80 ������ "));
	} while (ex.diapazon(tmp_digit, 2, 80));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///4-�� ��������������

	cout << "������� ����� �������� �������: " << endl;
	cout << "1 - ������� ����� �1 " << endl << "2 - ������� ����� �2 " << endl << "3 - ������� ����� �3 " << endl << "4 - ������� ����� �4 " << endl;

	do
	{
		cin >> swtch; // ���������� �����������
	} while (ex.diapazon(swtch, 1, 4));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "������� ����� �1");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "������� ����� �2");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "������� ����� �3");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "������� ����� �4");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///5-�� ��������������

	cout << "��� �������������� ��������� �������: " << endl;
	cout << "1 - ������� " << endl << "2 - ��������� ��������� " << endl << "3 - ������������� " << endl << "4 - ������� " << endl;

	do
	{
		cin >> swtch; // ���������� �����������
	} while (ex.diapazon(swtch, 1, 5));
	switch (swtch)
	{
	case 1:
		strcpy(name[num_of_characteristic], "�������");
		break;
	case 2:
		strcpy(name[num_of_characteristic], "��������� ���������");
		break;
	case 3:
		strcpy(name[num_of_characteristic], "�������������");
		break;
	case 4:
		strcpy(name[num_of_characteristic], "�������");
		break;
	default:
		break;
	}

	num_of_characteristic++;

	///6-�� ��������������

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "������� ������ ������� �� 1 �� 3000 ������� "));
	} while (ex.diapazon(tmp_digit, 1, 3000));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///7-�� ��������������

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "������� ���������� ���������� �� ����� �� 0 �� 6780 ������� "));
	} while (ex.diapazon(tmp_digit, 0, 6780));

	itoa(tmp_digit, name[num_of_characteristic], 10);

	num_of_characteristic++;

	///8-�� ��������������

	do
	{
		do
		{
		} while (ex.is_digit(tmp_digit, "������� ������������ �������� ����� (���������� �������� 50 �����) "));
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
			cout << endl << "��� ����� => ";
			break;
		case 1:
			cout << "������� ���� �� ������/�����������? => ";
			break;
		case 2:
			cout << "�������� �����: " << endl;
			cout << "����� => ";
			cout.width(45);
			break;
		case 3:
			cout << "������ => ";
			break;
		case 4:
			cout << "����� �������� => ";
			break;
		case 5:
			cout << "��� �������������� ��������� => ";
			break;
		case 6:
			cout << "������ => ";
			break;
		case 7:
			cout << "���������� ���������� => ";
			break;
		case 8:
			cout << "�������� => ";
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
			cout << endl << "��� ����� => ";
			break;
		case 1:
			cout << "������� ���� �� ������/�����������? => ";
			break;
		case 2:
			cout << "�������� �����: " << endl << "����� => ";
			break;
		case 3:
			cout << "������ => ";
			break;
		case 4:
			cout << "����� �������� => ";
			break;
		case 5:
			cout << "��� �������������� ��������� => ";
			break;
		case 6:
			cout << "������ => ";
			break;
		case 7:
			cout << "���������� ���������� => ";
			break;
		case 8:
			cout << "�������� => ";
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