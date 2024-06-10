#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ChangeCode(char c)
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

string thirteenCode = "0123456789abc";
vector<string> result;

void GenerateSubPalindromes(int length, string actual, vector<string> &result)
{

    if (length == 0)
    {
        result.push_back(actual);
        return;
    }
    for (int i = 0; i < thirteenCode.length(); i++)
    {
        char c = thirteenCode[i];
        GenerateSubPalindromes(length - 1, actual + c, result);
    }
}

vector<string> GeneratePalindromes(int length)
{
    vector<string> palindromList;
    if (length == 0)
    {
        return palindromList;
    }
    if (length == 1)
    {
        for (auto c : thirteenCode)
        {
            palindromList.push_back(string(1, c));
        }
        return palindromList;
    }
    int halfLength = length / 2;
    vector<string> subPalindromes;
    GenerateSubPalindromes(halfLength, "", subPalindromes);
    if (length % 2 == 0)
    {
        for (auto sub : subPalindromes)
        {
            string palindrom = sub + string(sub.rbegin(), sub.rend());
            palindromList.push_back(palindrom);
        }
    }
    else
    {
        for (auto sub : subPalindromes)
        {
            for (auto c : thirteenCode)
            {
                string palindrom = sub + c + string(sub.rbegin(), sub.rend());
                palindromList.push_back(palindrom);
            }
        }
    }
    return palindromList;
}

int main()
{
    int linesNumber;
    cin >> linesNumber;
    vector<int> stringLengthList;
    for (int i = 0; i < linesNumber; i++)
    {
        int n;
        cin >> n;
        stringLengthList.push_back(n);
    }
    for (auto i : stringLengthList)
    {
        vector<string> palindromList = GeneratePalindromes(i);
        for (auto palindrom : palindromList)
        {
            int sum = 0;
            for (auto c : palindrom)
            {
                sum += ChangeCode(c);
            }
            if (sum % 2 == 0)
            {
                cout << palindrom;
            }
        }
        cout << endl;
    }
    return 0;
}