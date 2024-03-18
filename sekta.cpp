#include <iostream>
#include <vector>

using namespace std;
struct Problem
{
    int n; // number of people in the circle
    int k; // a person which will die k-th
};

// it will return the position of the person which will die k-th
// vector<int> WhosGonnaDieAtCurrentPos(vector<int> arrayOfPeople, int i, int k)
// {
//     if (i / 2 == k)
//     {
//         return arrayOfPeople;
//     }
//     arrayOfPeople.erase(arrayOfPeople.begin() + i);
//     return WhosGonnaDieAtCurrentPos(arrayOfPeople, i + 2, k);
// }

void WhosGonnaDieAtCurrentPos(vector<int> arrayOfPeople, int i, int k)
{
    int whichDies = 0;
    if (k < 0)
    {
        k = (arrayOfPeople.size() + 1) + k;
    }
    while (whichDies < k)
    {
        arrayOfPeople.push_back(arrayOfPeople[i]);
        i += 2;
        whichDies++;
    }
    cout << arrayOfPeople[i - 1] << endl;
}

void ReadInput(int number, vector<Problem> &array)
{
    for (int i = 0; i < number; i++)
    {
        int n, k;
        cin >> n >> k;
        array.push_back({n, k});
    }
}

int main()
{
    int linesNumber;
    cin >> linesNumber;
    vector<int> arrayOfPeople;
    vector<Problem> array;
    ReadInput(linesNumber, array);
    for (int i = 0; i < linesNumber; i++)
    {
        arrayOfPeople.clear();
        for (int j = 1; j <= array[i].n; j++)
        {
            arrayOfPeople.push_back(j);
        }
        WhosGonnaDieAtCurrentPos(arrayOfPeople, 0, array[i].k);
    }
    return 0;
}