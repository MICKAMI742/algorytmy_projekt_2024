#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getNumberFromChar(char c)
{
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'a':
        return 10;
    case 'b':
        return 11;
    case 'c':
        return 12;
    default:
        return -1;
    }
}

string codeDigits = "0123456789abc";

string generateEvenPalindromes(int actualN, int n, string modifablePalindrome)
{
    if (actualN >= n)
    {
        int sum = 0;
        string help;
        for (auto c : modifablePalindrome)
        {
            sum += getNumberFromChar(c);
            help += c;
            if (sum % 2 == 0 && help.length() == n)
            {
                cout << help;
                help = "";
            }
        }
        return "";
    }

    if (n == 2)
    {
        for (int i = 0; i < codeDigits.length(); i++)
        {
            cout << string(1, codeDigits[i]) + string(1, codeDigits[i]);
        }
        return "";
    }
    else
    {
        int digitsNumber = codeDigits.length();
        for (int i = 0; i < digitsNumber; i++)
        {
            generateEvenPalindromes(actualN + 2, n, (modifablePalindrome + codeDigits[i] + modifablePalindrome));
        }
        return "";
    }
}

int main()
{
    int linesNumber;
    cin >> linesNumber;
    int *stringLengthList = new int[linesNumber];
    for (int i = 0; i < linesNumber; i++)
    {
        int n;
        cin >> n;
        stringLengthList[i] = n;
    }

    for (int i = 0; i < linesNumber; i++)
    {
        for (int j = 0; j < codeDigits.length(); j++)
        {
            generateEvenPalindromes(1, stringLengthList[i], string(1, codeDigits[j]));
            if (stringLengthList[i] == 2)
            {
                break;
            }
        }
        cout << endl;
    }
    delete[] stringLengthList;
    return 0;
}