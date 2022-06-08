#include<iostream>
#include "Tour.h"


using namespace std;

int main()
{
	setlocale(0, "");

	//Tour a;
	//a.fillTour();
	//cout << "-------------------------------------\n";
	//a.showTOur();
	//cout << "-------------------------------------\n";
	//cout << "�������: " << (a.isHot() ? "��." : "���.") << endl;
	//cout << "����� ���������: " << a.calcTotalPrice() << " ���." << endl;

	int sizeTours = 0; // ���-�� ����� => ����������� �������
	Tour* arr = NULL; // ��������� �� ������������ ������
	int menu = 0;
	int choise;
	int printtour = 0;

	do
	{
		cout << "0. ����� �� ����.\n"
			<< "1. �������� ����� ���.\n"
			<< "2. �������� ������ ���� �����.\n"
			<< "3. �������� ������ ������� �����.\n"
			<< "4. ������� ���.\n"
			<< "5. ���������� �����.\n"
			<< "6. ����� ���� �� ����������� (������ ��� �����).\n"
			<< "7. ����� ���� �� ���� ������.\n"
			<< "8. ������ ����-������ �� ���.\n"
			<< "�����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin.ignore();
			addTour(arr, sizeTours); break;
		case 2:
			printArrayOfTours(arr, sizeTours); break;
		case 3:
			printHotTours(arr, sizeTours); break;
		case 4:
			char s[100];
			cout << "������� �������� ���� ��� ��������:\n";
			cin.ignore();
			cin.get(s, 100);
			delTour(arr, sizeTours, s);
		case 5:
		{
			do
			{
				cout << "��� �����������: 1 - �� �����������, 2 - �� ���� ������.\n�����: ";
				cin >> choise;
				if (choise == 0) break;

				switch (choise)
				{
				case 1: sortByDirection(arr, sizeTours);
					printArrayOfTours(arr, sizeTours); break;

				case 2: sortByArrive(arr, sizeTours);
					printArrayOfTours(arr, sizeTours); break;

				default: cout << "�������� ������ ��� ������ �������! ���� - �����\n\n"; break;
				}
			} while (choise != 1 || choise != 2); break;
		}
		case 6: 
			char a[100];
			cout << "������� �������� ���� ��� ������:\n";
			cin.ignore();
			cin.get(a, 100);
			findByDirection(arr, sizeTours, a);	break;
		case 7: 
			char b[100];
			cout << "������� �������� ���� ��� ������:\n";
			cin.ignore();
			cin.get(b, 100);
			findByDate(arr, sizeTours, b);	break;

		case 8: 
			cout << "��� #: ";
			cin >> printtour;
			arr[--printtour].printCheck(); break;

		default:
			cout << "������� ������ �����, ���������� �����.\n\n"; break;
		}

	} while (menu!=0);









	return 0;
	system("pause");
}