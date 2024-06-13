#include <iostream>
using namespace std;

int s;   // ilosc samochodow
int *n;  // ilosc przedmiotow
int **p; // tablica cen
int **w; // tablica wag
int *bp; // tablica najlepszych cen
int *c;  // pojemnosc samochodu
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// wczytywanie danych
void ReadInput()
{
    cin >> s;
    p = new int *[s]; // alokacja wierszy
    w = new int *[s]; // alokacja wierszy
    n = new int[s];
    c = new int[s];
    for (int i = 0; i < s; i++)
    {
        cin >> n[i];
        p[i] = new int[n[i]]; // alokacja kolumn
        for (int j = 0; j < n[i]; j++)
        {
            cin >> p[i][j];
        }
        w[i] = new int[n[i]]; // alokacja kolumn
        for (int j = 0; j < n[i]; j++)
        {
            cin >> w[i][j];
        }
        cin >> c[i];
    }
}

// obliczanie najlepszych cen
void BestPrice()
{
    for (int i = 0; i < s; i++)
    {
        bp = new int[c[i] + 1];
        for (int j = 0; j <= c[i]; j++)
        {
            bp[j] = -20; // wypelnienie tablicy kosztami przewozu
        }
        for (int j = 0; j < n[i]; j++)
        {
            for (int k = c[i]; k >= w[i][j]; --k)
            {
                if (w[i][j] > 100)
                {
                    bp[k] = max(bp[k], bp[k - w[i][j]] + p[i][j] - 5); // odliczanie 5 za kazdy przedmiot o wadze > 100
                }
                else
                {
                    bp[k] = max(bp[k], bp[k - w[i][j]] + p[i][j]);
                }
            }
        }
        if (bp[c[i]] < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bp[c[i]] << endl;
        }
        delete[] bp;
    }
}

int main()
{
    ReadInput();
    BestPrice();
    // zwalnianie pamieci
    delete[] n;
    delete[] p;
    delete[] w;
    return 0;
}