#include <iostream>
#include <cmath>
#include <cstdint>


using namespace std;

int64_t nat_pow(int64_t a, int64_t b)
{
    int64_t output = 1;
    for (int i = 0; i < b; i++)
    {
        output *= a;
    }
    return output;
}

int main()
{
    // pomysl jest taki - na zmiane w zakończeniach kolejnych wierszy/kolumn są potęgi kolejnych liczb naturalnych (2, 4, 9, 16...)
    // Będziemy patrzeć w który fragmencie to jest.

    // Interesuje nas większa z 2 podanych liczb - ona okresli nasz zakres
    // np 4 2 --- największe jest 4, interesować nas będą liczby od 9 do 16

    // x y

    // WIĘKSZA LICZBA PARZYSTA
    // 4 2 --- w tym wypadku bierzemy potęge x, dodajemy 1, odejmujemy y, mamy wynik (14)
    // 2 4 --- w tym wypadku bierzemy potęgę (y-1), dodajemy x, mamy wynik (11)

    // WIĘKSZA LICZBA NIEPARZYSTA
    // 5 2 --- w tym wypadku bierzemy potęge (x-1), dodajemy y, mamy wynik (18)
    // 2 5 --- w tym wypadku bierzemy potęgę y, dodajemy 1, odejmujemy x, mamy wynik (24)

    int32_t n;
    cin >> n;

    int64_t x, y;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;

        // Wieksza liczba parzysta
        if (max(x, y) % 2 == 0)
        {
            if (x > y)
            {
                cout << nat_pow(x, 2) + 1 - y << endl;
            }
            else
            {
                cout << nat_pow(y - 1, 2) + x << endl;
            }
        }
        // Wieksza liczba nieparzysta
        else
        {
            if (x > y)
            {
                cout << nat_pow(x - 1, 2) + y << endl;
            }
            else
            {
                cout << nat_pow(y, 2) + 1 - x << endl;
            }
        }
    }

    cin >> x >> y;

    // Wieksza liczba parzysta
    if (max(x, y) % 2 == 0)
    {
        if (x > y)
        {
            cout << nat_pow(x, 2) + 1 - y << endl;
        }
        else
        {
            cout << nat_pow(y - 1, 2) + x << endl;
        }
    }
    // Wieksza liczba nieparzysta
    else
    {
        if (x > y)
        {
            cout << nat_pow(x - 1, 2) + y << endl;
        }
        else
        {
            cout << nat_pow(y, 2) + 1 - x << endl;
        }
    }
}