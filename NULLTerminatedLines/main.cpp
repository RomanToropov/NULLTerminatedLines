#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(char str[]);

void to_upper(char str[]);

void to_lower(char str[]);

void shrink(char str[]);

//bool is_palindrome(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H','e','l','l','o','\0'};
	//char str[] = "Hello";
	//cout << str << endl;
	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << str << endl;

	cout << StringLength(str) << endl;

	to_upper(str);
	cout << str << endl;

	to_lower(str);
	cout << str << endl;


	shrink(str);
	cout << str << endl;

	//is_palindrome(str);
	//cout << str << endl;
}
int StringLength(char str[])
{
	//cout << typeid(str).name() << endl;
	//return sizeof(str);
	int i = 0;
	for (; str[i]; i++);
		return i;
}

void to_upper(char str[])//Переводит строку в верхний регистр
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я')
			str[i] -= 32;
	}
}

void to_lower(char str[])//Переводит строку в нижний регистр

{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 32;
	}
}

void shrink(char str[])//Удаляет лишние пробелы из предложения
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			int cut = i + 1;
			i--;
			for (; cut < n; ++cut) str[cut] = str[cut + 1];
		}
	}
}

//bool is_palindrome(char str[])//Проверяет, явлвяется ли строка палиндромом
//{
	//bool palindrome = 1;
	//int n = StringLength(str);
	
//}