#include"Date.h"
#include"MyString.h"


struct Tour
{
	//-------------------------------------------------
	MyString name; // Имя тура
	MyString direction; // Направление (Страна, город)
	MyString hotel; // Название отеля
	Date arrive; // Дата заезда
	int nights = 1; // Кол-во ночей
	float pricePerNight = 0; // Цена одной ночи
	float pricePerRide = 0; // Стоимость проезда
	float hotSale = 0; // Скидка на "горящий" тур
	//-------------------------------------------------

	void fillTour(); // Заполнение пользователем
	void showTour(); // Вывод информации на экран
	bool isHot(); // Определение является ли тур горящим (5 дней до заезда)
	float calcTotalPrice(); // Общая стоимость тура
	void printCheck();
};

//=================================================================================
//				Функции для работы с массивом
//=================================================================================
void addTour(Tour*& arr, int& size);
void printArrayOfTours(Tour* arr, int size);
void printHotTours(Tour* arr, int size);
void delTour(Tour*& arr, int& size, char* tourName);
void sortByDirection(Tour* arr, int size);
void sortByArrive(Tour* arr, int size);
void findByDirection(Tour* arr, int size, char* direct);
void findByDate(Tour* arr, int size, char* date);
