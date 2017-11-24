// VLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <math.h>
#include <iomanip>

using namespace std;

void vvod(int **&a, int &n, int &m)                                                       //функция заполнения массива
{
	int j;
	if (a != NULL)
	{
		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
	}
	cout << "Введите размер массива\n";
	cin >> n >> m;
	a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	cout << "Нажмите '1', если хотите заполнить массив сами или '2' в противном случае\n";
	cin >> j;
	while ((j != 1) && (j != 2))
	{
		cout << "Выбрана некорректная операция! Попробуйте снова\n";
		cin >> j;
	}
	if (j == 1)
	{
		cout << "Введите значения элементов массива\n";
		for (int i = 0; i < n; i++)
			for (int f=0; f<m; f++)
		    {
			    cin >> a[i][f];                                         //заполнение массива пользователем
		    }
	}
	else
	{
		
	}
	cout << "Готово\n";
}

void obrab(int m, int &ob)                                                      //функция обработки массива
{	
	cout << "Готово\n";
}

void vyvod(int **&a,int n, int m, int ob)                                       //вывод массива на экран
{
	if (m == 0) cout << "Ошибка! Сначала задайте значение массива\n";
	else
	{
		if (ob == 0) 
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
					cout << a[i][j] << " ";
				cout << "\n";
			}
			cout << "\n";
		}
		else
		{
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					cout << a[j][i] << " ";
				cout << "\n";
			}
			cout << "\n";
		}
	}
}

int menu()
{
	cout << "Меню:\nВвод элементов массива - 1\nОбработка массива - 2\nВывод массива на экран - 3\n";
	cout << "Очистка экрана консоли - 4\nВыход - 0\nЧего изволите?\n";
	return 0;
}

int main()                                                      //тело программы
{
	setlocale(LC_ALL, "Rus");
	int j = 0, f = 0, ob=0;
	int **a = NULL,m=0,n=0;
	menu();
	do
	{
		cin >> f;
		if ((f>4) || (f<0)) cout << "Выбрана некорректная операция! Попробуйте снова\n";
		else
		{
			switch (f)                                         //обработка команд пользователя
			{
			case 1: {
						 vvod(a, n, m); 
						 break; 
			        }
			case 2: obrab(m,ob); break;
			case 3: vyvod(a,n,m,ob); break;
			case 4: system("cls"); menu(); break;
			}
		}
	} while (f != 0);
	return 0;
}

