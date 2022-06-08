#include"Date.h"
#include"MyString.h"


struct Tour
{
	//-------------------------------------------------
	MyString name; // ��� ����
	MyString direction; // ����������� (������, �����)
	MyString hotel; // �������� �����
	Date arrive; // ���� ������
	int nights = 1; // ���-�� �����
	float pricePerNight = 0; // ���� ����� ����
	float pricePerRide = 0; // ��������� �������
	float hotSale = 0; // ������ �� "�������" ���
	//-------------------------------------------------

	void fillTour(); // ���������� �������������
	void showTour(); // ����� ���������� �� �����
	bool isHot(); // ����������� �������� �� ��� ������� (5 ���� �� ������)
	float calcTotalPrice(); // ����� ��������� ����
	void printCheck();
};

//=================================================================================
//				������� ��� ������ � ��������
//=================================================================================
void addTour(Tour*& arr, int& size);
void printArrayOfTours(Tour* arr, int size);
void printHotTours(Tour* arr, int size);
void delTour(Tour*& arr, int& size, char* tourName);
void sortByDirection(Tour* arr, int size);
void sortByArrive(Tour* arr, int size);
void findByDirection(Tour* arr, int size, char* direct);
void findByDate(Tour* arr, int size, char* date);
