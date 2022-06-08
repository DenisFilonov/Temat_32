#include "Tour.h"

void Tour::fillTour()
{
    char tmp[100];
    cout << "Название тура: ";
    cin.getline(tmp, 100);
    name.setMyString(tmp); // копируем в Name

    cout << "Направление (Страна, Город): ";
    cin.getline(tmp, 100);
    direction.setMyString(tmp); // копируем в Direction

    cout << "Название отеля: ";
    cin.getline(tmp, 100);
    hotel.setMyString(tmp);

    cout << "Дата заезда: ";
    arrive.fillDate();

    cout << "Кол-во ночей: ";
    cin >> nights;

    cout << "Стоимость 1 ночи (грн.): ";
    cin >> pricePerNight; 
    
    cout << "Стоимость проезда (грн.): ";
    cin >> pricePerRide;

    cout << "Скидка на \"горящий\" тур(%): ";
    cin >> hotSale;
    cout << endl;
}

void Tour::showTour()
{
    cout << "Название тура: " << name.str << endl;
    
    cout << "Направление (Страна, Город): " << direction.str << endl;

    cout << "Название отеля: " << hotel.str << endl;

    cout << "Дата заезда: " << arrive.toString() << endl;
    Date finish = arrive;
    for (int i = 0; i < nights; i++)
    {
        finish.toNextDay();
    }
    cout << "Дата выезда: " << finish.toString() << endl;

    cout << "Кол-во ночей: " << nights << endl;

    cout << "Стоимость 1 ночи (грн.): " << pricePerNight << endl;
    
    cout << "Стоимость проезда (грн.): " << pricePerRide << endl;

    cout << "Скидка на \"горящий\" тур(%): " << hotSale << endl;
    cout << "-----------------------------------------------------------------\n\n";
}

bool Tour::isHot()
{
    Date now;
    now.getNowDate(); // 2022 04 27
    for (int i = 0; i < 5; i++)
    {
        now.toNextDay(); // +5 дней => 2022 05 02
    }
    // now => 2022 05 02            будет сравнение strcmp
    // ---------------------------------------------------
    // arrive => 2022 05 01 -> hot
    // arrive => 2022 04 29 -> hot
    // arrive => 2022 05 03 -> not hot

    Date acheck;
    acheck.getNowDate();
    //               "2022 05 01"       "2022 05 02"                            настоящее время
    if (strcmp(arrive.toString(), now.toString()) <= 0 && strcmp(arrive.toString(), acheck.toString()) >= 0)
    {
        return true; // если одна строка меньше другой по коду, можем написать <=0
    }
    else return false;

    return false;
}

float Tour::calcTotalPrice()
{
    float sum = nights * pricePerNight + pricePerRide;
    if (isHot()) // Если тур горящий - применяем скидку
    {
        sum -= sum * hotSale / 100;
    }
    return sum;
}

void Tour::printCheck()
{   
    cout << "\n----------------------------------------------------------\n";
    cout << "-----------------ЧЕК-БИЛЕТ НА ТУР-------------------------\n";
    cout << "----------------------------------------------------------\n";
    cout << "Название тура: " << name.str << endl;
    cout << "Направление (Страна, Город): " << direction.str << endl;
    cout << "Название отеля: " << hotel.str << endl;
    cout << "Дата заезда: " << arrive.toString() << endl;
    Date finish = arrive;
    for (int i = 0; i < nights; i++)
    {
        finish.toNextDay();
    }
    cout << "Дата выезда: " << finish.toString() << endl;
    cout << "Суммарная стоимость тура: " << calcTotalPrice() << " гривен.\n";
    cout << "----------------------------------------------------------\n";
    cout << "----------------------------------------------------------\n";
    cout << "----------------------------------------------------------\n\n";

}


//=================================================================================
//				Функции для работы с массивом
//=================================================================================



void addTour(Tour*& arr, int& size)
{
    cout << endl;
    // Создаём временный массив на + 1 элемент
    Tour* tmp = new Tour[++size];

    //Переносим данные из старого массива в новый
    for (int i = 0; i < size - 1; i++)
    {
        tmp[i] = arr[i];
    }

    // В последний элемент добавляем Тур
    cout << "Информация о новом туре:\n";
    tmp[size - 1].fillTour();

    //Очищаем старый массив
    if (arr != NULL) delete[] arr;

    // Перепривязываем указатель на новую память
    arr = tmp;
}

void printArrayOfTours(Tour* arr, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\t Тур #" << i + 1 << endl;
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
            cout << "Название: " << arr[i].name.str << endl;
            cout << "Дата заезда: " << arr[i].arrive.toString() << endl;
            cout << "Скидка: " << arr[i].hotSale << "%\n";
            cout << "Общая стоимость: " << arr[i].calcTotalPrice() << " грн.\n\n";
            noHotTours++;
        }
    }
    if (noHotTours == 0) cout << "Таковых не имеется, ждите новых предложений.\n\n";
}

void delTour(Tour*& arr, int& size, char* tourName)
{
    cout << endl;
    int id = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name.str, tourName) == 0)
        {
            cout << tourName << " " << arr[i].direction.str << " " << arr[i].arrive.toString() << "\nНомер: " << i + 1 << endl;
            id = 1;
        }
    }

    if (id == -1)
    {
        cout << "Тур " << tourName << " не найден.\n";
    }
    else
    {
        cout << "Номер удаляемого тура: ";
        cin >> id;

        Tour* tmp = new Tour[--size];

        for (int i = 0; i < size; i++)
        {
            if (i < id) tmp[i] = arr[i];
            else if (i >= id) tmp[i] = arr[i + 1];
        }

        if (arr != NULL) delete[] arr;
        arr = tmp;

        cout << "Тур \"" << tourName << "\" удалён.\n\n";
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
            cout << "Название тура: " << arr[i].name.str << endl;

            cout << "Направление (Страна, Город): " << arr[i].direction.str << endl;

            cout << "Название отеля: " << arr[i].hotel.str << endl;

            cout << "Дата заезда: " << arr[i].arrive.toString() << endl;
           
            cout << "Кол-во ночей: " << arr[i].nights << endl;

            cout << "Стоимость 1 ночи (грн.): " << arr[i].pricePerNight << endl;

            cout << "Стоимость проезда (грн.): " << arr[i].pricePerRide << endl;

            cout << "Скидка на \"горящий\" тур(%): " << arr[i].hotSale << endl;
            cout << "-----------------------------------------------------------------\n\n";
            no++;
        }
    }
    if (no == 0) cout << "Нет такого тура!\n\n";

}

void findByDate(Tour* arr, int size, char* date)
{
    int no = 0;

    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].arrive.toString(), date) == 0)
        {
            cout << "Название тура: " << arr[i].name.str << endl;

            cout << "Направление (Страна, Город): " << arr[i].direction.str << endl;

            cout << "Название отеля: " << arr[i].hotel.str << endl;

            cout << "Дата заезда: " << arr[i].arrive.toString() << endl;

            cout << "Кол-во ночей: " << arr[i].nights << endl;

            cout << "Стоимость 1 ночи (грн.): " << arr[i].pricePerNight << endl;

            cout << "Стоимость проезда (грн.): " << arr[i].pricePerRide << endl;

            cout << "Скидка на \"горящий\" тур(%): " << arr[i].hotSale << endl;
            cout << "-----------------------------------------------------------------\n\n";
        }
    }
    if (no == 0) cout << "Нет такого тура!\n\n";

}
