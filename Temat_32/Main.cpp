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
	//cout << "Горящий: " << (a.isHot() ? "Да." : "Нет.") << endl;
	//cout << "Общая стоимость: " << a.calcTotalPrice() << " грн." << endl;

	int sizeTours = 0; // кол-во туров => размерность массива
	Tour* arr = NULL; // указатель на динамический массив
	int menu = 0;
	int choise;
	int printtour = 0;

	do
	{
		cout << "0. Выход из меню.\n"
			<< "1. Добавить новый тур.\n"
			<< "2. Показать список всех туров.\n"
			<< "3. Показать список горящих туров.\n"
			<< "4. Удалить тур.\n"
			<< "5. Сортировка туров.\n"
			<< "6. Поиск тура по направлению (Страна или Город).\n"
			<< "7. Поиск тура по дате заезда.\n"
			<< "8. Печать чека-билета на тур.\n"
			<< "Выбор: ";
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
			cout << "Введите название тура для удаления:\n";
			cin.ignore();
			cin.get(s, 100);
			delTour(arr, sizeTours, s);
		case 5:
		{
			do
			{
				cout << "Как сортировать: 1 - по направлению, 2 - по дате заезда.\nВыбор: ";
				cin >> choise;
				if (choise == 0) break;

				switch (choise)
				{
				case 1: sortByDirection(arr, sizeTours);
					printArrayOfTours(arr, sizeTours); break;

				case 2: sortByArrive(arr, sizeTours);
					printArrayOfTours(arr, sizeTours); break;

				default: cout << "Выберите первый или второй вариант! Ноль - выход\n\n"; break;
				}
			} while (choise != 1 || choise != 2); break;
		}
		case 6: 
			char a[100];
			cout << "Введите название тура для поиска:\n";
			cin.ignore();
			cin.get(a, 100);
			findByDirection(arr, sizeTours, a);	break;
		case 7: 
			char b[100];
			cout << "Введите название тура для поиска:\n";
			cin.ignore();
			cin.get(b, 100);
			findByDate(arr, sizeTours, b);	break;

		case 8: 
			cout << "Тур #: ";
			cin >> printtour;
			arr[--printtour].printCheck(); break;

		default:
			cout << "Неверно выбран пункт, попробуйте снова.\n\n"; break;
		}

	} while (menu!=0);









	return 0;
	system("pause");
}