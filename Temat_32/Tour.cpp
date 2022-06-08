#include "Tour.h"

void Tour::fillTour()
{
    char tmp[100];
    cout << "�������� ����: ";
    cin.getline(tmp, 100);
    name.setMyString(tmp); // �������� � Name

    cout << "����������� (������, �����): ";
    cin.getline(tmp, 100);
    direction.setMyString(tmp); // �������� � Direction

    cout << "�������� �����: ";
    cin.getline(tmp, 100);
    hotel.setMyString(tmp);

    cout << "���� ������: ";
    arrive.fillDate();

    cout << "���-�� �����: ";
    cin >> nights;

    cout << "��������� 1 ���� (���.): ";
    cin >> pricePerNight; 
    
    cout << "��������� ������� (���.): ";
    cin >> pricePerRide;

    cout << "������ �� \"�������\" ���(%): ";
    cin >> hotSale;
    cout << endl;
}

void Tour::showTour()
{
    cout << "�������� ����: " << name.str << endl;
    
    cout << "����������� (������, �����): " << direction.str << endl;

    cout << "�������� �����: " << hotel.str << endl;

    cout << "���� ������: " << arrive.toString() << endl;
    Date finish = arrive;
    for (int i = 0; i < nights; i++)
    {
        finish.toNextDay();
    }
    cout << "���� ������: " << finish.toString() << endl;

    cout << "���-�� �����: " << nights << endl;

    cout << "��������� 1 ���� (���.): " << pricePerNight << endl;
    
    cout << "��������� ������� (���.): " << pricePerRide << endl;

    cout << "������ �� \"�������\" ���(%): " << hotSale << endl;
    cout << "-----------------------------------------------------------------\n\n";
}

bool Tour::isHot()
{
    Date now;
    now.getNowDate(); // 2022 04 27
    for (int i = 0; i < 5; i++)
    {
        now.toNextDay(); // +5 ���� => 2022 05 02
    }
    // now => 2022 05 02            ����� ��������� strcmp
    // ---------------------------------------------------
    // arrive => 2022 05 01 -> hot
    // arrive => 2022 04 29 -> hot
    // arrive => 2022 05 03 -> not hot

    Date acheck;
    acheck.getNowDate();
    //               "2022 05 01"       "2022 05 02"                            ��������� �����
    if (strcmp(arrive.toString(), now.toString()) <= 0 && strcmp(arrive.toString(), acheck.toString()) >= 0)
    {
        return true; // ���� ���� ������ ������ ������ �� ����, ����� �������� <=0
    }
    else return false;

    return false;
}

float Tour::calcTotalPrice()
{
    float sum = nights * pricePerNight + pricePerRide;
    if (isHot()) // ���� ��� ������� - ��������� ������
    {
        sum -= sum * hotSale / 100;
    }
    return sum;
}

void Tour::printCheck()
{   
    cout << "\n----------------------------------------------------------\n";
    cout << "-----------------���-����� �� ���-------------------------\n";
    cout << "----------------------------------------------------------\n";
    cout << "�������� ����: " << name.str << endl;
    cout << "����������� (������, �����): " << direction.str << endl;
    cout << "�������� �����: " << hotel.str << endl;
    cout << "���� ������: " << arrive.toString() << endl;
    Date finish = arrive;
    for (int i = 0; i < nights; i++)
    {
        finish.toNextDay();
    }
    cout << "���� ������: " << finish.toString() << endl;
    cout << "��������� ��������� ����: " << calcTotalPrice() << " ������.\n";
    cout << "----------------------------------------------------------\n";
    cout << "----------------------------------------------------------\n";
    cout << "----------------------------------------------------------\n\n";

}


//=================================================================================
//				������� ��� ������ � ��������
//=================================================================================



void addTour(Tour*& arr, int& size)
{
    cout << endl;
    // ������ ��������� ������ �� + 1 �������
    Tour* tmp = new Tour[++size];

    //��������� ������ �� ������� ������� � �����
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }

    // � ��������� ������� ��������� ���
    cout << "���������� � ����� ����:\n";
    tmp[size - 1].fillTour();

    //������� ������ ������
    if (arr != NULL) delete[] arr;

    // ��������������� ��������� �� ����� ������
    arr = tmp;
}

void printArrayOfTours(Tour* arr, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\t ��� #" << i + 1 << endl;
        arr[i].showTour();
    }
}

void printHotTours(Tour* arr, int size)
{
    int noHotTours = 0;
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].isHot())
        {
            cout << "��������: " << arr[i].name.str << endl;
            cout << "���� ������: " << arr[i].arrive.toString() << endl;
            cout << "������: " << arr[i].hotSale << "%\n";
            cout << "����� ���������: " << arr[i].calcTotalPrice() << " ���.\n\n";
            noHotTours++;
        }
    }
    if (noHotTours == 0) cout << "������� �� �������, ����� ����� �����������.\n\n";
}

void delTour(Tour*& arr, int& size, char* tourName)
{
    cout << endl;
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, tourName) == 0)
        {
            cout << tourName << " " << arr[i].direction.str << " " << arr[i].arrive.toString() << "\n�����: " << i + 1 << endl;
            id = 1;
        }
    }

    if (id == -1)
    {
        cout << "��� " << tourName << " �� ������.\n";
    }
    else
    {
        cout << "����� ���������� ����: ";
        cin >> id;

        Tour* tmp = new Tour[--size];

        for (int i = 0; i < size; i++)
        {
            if (i < id) tmp[i] = arr[i];
            else if (i >= id) tmp[i] = arr[i + 1];
        }

        if (arr != NULL) delete[] arr;
        arr = tmp;

        cout << "��� \"" << tourName << "\" �����.\n\n";
    }
}

void sortByDirection(Tour* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(arr[j + 1].direction.str, arr[j].direction.str) <= 0)
            {
                swap(arr[j + 1], arr[j]); //arrive.toString
            }
        }
    }
}

void sortByArrive(Tour* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (strcmp(arr[j + 1].arrive.toString(), arr[j].arrive.toString()) <= 0)
            {
                swap(arr[j + 1], arr[j]); //arrive.toString
            }
        }
    }
}

void findByDirection(Tour* arr, int size, char* direct)
{
    int no = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].direction.str, direct) == 0)
        {
            cout << "�������� ����: " << arr[i].name.str << endl;

            cout << "����������� (������, �����): " << arr[i].direction.str << endl;

            cout << "�������� �����: " << arr[i].hotel.str << endl;

            cout << "���� ������: " << arr[i].arrive.toString() << endl;
           
            cout << "���-�� �����: " << arr[i].nights << endl;

            cout << "��������� 1 ���� (���.): " << arr[i].pricePerNight << endl;

            cout << "��������� ������� (���.): " << arr[i].pricePerRide << endl;

            cout << "������ �� \"�������\" ���(%): " << arr[i].hotSale << endl;
            cout << "-----------------------------------------------------------------\n\n";
            no++;
        }
    }
    if (no == 0) cout << "��� ������ ����!\n\n";

}

void findByDate(Tour* arr, int size, char* date)
{
    int no = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].arrive.toString(), date) == 0)
        {
            cout << "�������� ����: " << arr[i].name.str << endl;

            cout << "����������� (������, �����): " << arr[i].direction.str << endl;

            cout << "�������� �����: " << arr[i].hotel.str << endl;

            cout << "���� ������: " << arr[i].arrive.toString() << endl;

            cout << "���-�� �����: " << arr[i].nights << endl;

            cout << "��������� 1 ���� (���.): " << arr[i].pricePerNight << endl;

            cout << "��������� ������� (���.): " << arr[i].pricePerRide << endl;

            cout << "������ �� \"�������\" ���(%): " << arr[i].hotSale << endl;
            cout << "-----------------------------------------------------------------\n\n";
        }
    }
    if (no == 0) cout << "��� ������ ����!\n\n";

}
