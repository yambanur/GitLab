// VLab2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <math.h>
#include <iomanip>

using namespace std;

void vvod(int **&a, int &n, int &m)                                                       //������� ���������� �������
{
	int j;
	if (a != NULL)
	{
		for (int i = 0; i < n; i++)
			delete[] a[i];
		delete[] a;
	}
	cout << "������� ������ �������\n";
	cin >> n >> m;
	a = new int*[n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	cout << "������� '1', ���� ������ ��������� ������ ���� ��� '2' � ��������� ������\n";
	cin >> j;
	while ((j != 1) && (j != 2))
	{
		cout << "������� ������������ ��������! ���������� �����\n";
		cin >> j;
	}
	if (j == 1)
	{
		cout << "������� �������� ��������� �������\n";
		for (int i = 0; i < n; i++)
			for (int f=0; f<m; f++)
		    {
			    cin >> a[i][f];                                         //���������� ������� �������������
		    }
	}
	else
	{
		
	}
	cout << "������\n";
}

void obrab(int m, int &ob)                                                      //������� ��������� �������
{	
	cout << "������\n";
}

void vyvod(int **&a,int n, int m, int ob)                                       //����� ������� �� �����
{
	if (m == 0) cout << "������! ������� ������� �������� �������\n";
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
	cout << "����:\n���� ��������� ������� - 1\n��������� ������� - 2\n����� ������� �� ����� - 3\n";
	cout << "������� ������ ������� - 4\n����� - 0\n���� ��������?\n";
	return 0;
}

int main()                                                      //���� ���������
{
	setlocale(LC_ALL, "Rus");
	int j = 0, f = 0, ob=0;
	int **a = NULL,m=0,n=0;
	menu();
	do
	{
		cin >> f;
		if ((f>4) || (f<0)) cout << "������� ������������ ��������! ���������� �����\n";
		else
		{
			switch (f)                                         //��������� ������ ������������
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

