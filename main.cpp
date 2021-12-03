#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int iloscElementow = 0;

int wpysanieLiczb(int array[]) {
    int wpysanaLiczba;
    for (int i = 0; i < 50; i++)
    {
        cout << "Podaj Liczbe: ";
        cin >> wpysanaLiczba;

        if(wpysanaLiczba == -1) {
            break;
        }

        iloscElementow++;
        array[i] = wpysanaLiczba;
    }

    return 0;
    
}

int wyswietlicLiczbe(int arr[]) {
    return iloscElementow;
}

float sredniaElementow(int array[]) {
    float suma;
    for (int i = 0; i < iloscElementow; i++)
    {
        suma += array[i];
    }

    return suma / iloscElementow;
    
}

float odchylenie(int array[]) {
    int srednia = sredniaElementow(array);
    float dodaj = 0.0;
    float odchylenie;

    for (int i = 0; i < iloscElementow; i++)
    {
        dodaj += (array[i] - srednia) * (array[i] - srednia);
    }

    odchylenie = sqrt(dodaj/iloscElementow);

    return odchylenie;
}

void dodatUjemnie(int array[]) {
    int temp;
    int mniej = 0, wiecej = 0;

    for (int i = 0; i < iloscElementow; i++)
    {
        temp = array[i];
        if(temp <= 0) {
            mniej++;
        } else {
            wiecej++;
        }
    }

    cout << "Mniej od 0: " << mniej << endl;
    cout << "Wiecej od 0: " << wiecej << endl;
    
}


void reverse(int array[]) {
    for(int i=(iloscElementow-1); i>=0; i--)
        cout<<array[i] + 5<<" ";
    cout << endl;
    
}


void szukaczLiczbe(int array[]) {
    int element;
    bool czyJest = false;
    int k = 0;
    int pozycji[50] = {};

    cout << "Proze podac liczbe: ";
    cin >> element;


    for (int i = 0; i < iloscElementow; i++)
    {
        if(array[i] == element) {
            cout << "Tak, taka liczba jest w tablice!" << endl;
            czyJest = true;
            break;
        }
    }
    if(czyJest) {
        for (int i = 0; i < iloscElementow; i++)
        {
            if(array[i] == element) {
                pozycji[k] = i;
                k++;
            }
        }

        cout << "Index/Indexes: ";

        for (int i = 0; i < k; i++)
        {
            cout << pozycji[i] << " ";
        }

        cout << endl;
        
        
    }
    else if(!czyJest) {
        cout << "Nie znalezono" << endl;
    }
    


}


void bubbleSorting(int array[]) {
    int temp;

    for(int i=0; i<(iloscElementow-1); i++)
    {
        for(int j=0; j<(iloscElementow-i-1); j++)
        {
            if(array[j]<array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < iloscElementow; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    
}



int main() {
    int opcja;
    int size;
    float srednia, odchylenieStand;
    int array[50] = {};
    wpysanieLiczb(array);


    while(true) {

    cout << "MENU" << endl;
    cout << "1. wyświetlic liczbę wprowadzonych danych oraz wczytane dane." << endl;
    cout << "2. wyświetlic średnią i odchylenie standardowe" << endl;
    cout << "3. wyświetlic liczbę wystąpień dla cyfr dodatnich i ujemnych" << endl;
    cout << "4. odwrócic kolejność elementów w tablicy oraz zwiększy każdy element o 5" << endl;
    cout << "5. Znalescz element." << endl;
    cout << "6. Posortowac elementy tablicy." << endl;
    cout << "7. Wyjsc" << endl;
    cout << "Co robimy: ";
    cin >> opcja;

    switch (opcja)
    {
    case 1:
        size = wyswietlicLiczbe(array);
        cout << "Ilosc elementow: " << size << endl;
        break;
    case 2:
        srednia = sredniaElementow(array);
        cout << "Srednia: " << srednia << endl;
        odchylenieStand = odchylenie(array);
        cout << "Odchylenie: " << odchylenieStand << endl;
        break;
    case 3:
        dodatUjemnie(array);
        break;
    case 4:
        reverse(array);
        break;
    case 5:
        szukaczLiczbe(array);
        break;
    case 6:
        bubbleSorting(array);
        break;
    case 7:
        exit(1);
    default:
        break;
    }
    }
}