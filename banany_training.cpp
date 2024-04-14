#include <iostream>
#include <string>
using namespace std;

int *NodesWithChildrenBeneath(int w, string charList)
{
    int *nodes = new int[w];
    for (int i = 0; i < w; i++)
    {
        nodes[i] = 0;
    }
    int iterator = 0;
    int numOfOnes = 0;
    int indexOfLastOne = 0;
    for (int i = 0; i < charList.length(); i++)
    {
        if (charList[i] == '1' && iterator < w)
        {
            numOfOnes++;
            indexOfLastOne = iterator;
        }
        if (numOfOnes == 1 && iterator == w - 1)
        {
            nodes[indexOfLastOne] += 1;
        }
        iterator++;
        if (iterator == w)
        {
            numOfOnes = 0;
            iterator = 0;
        }
    }
    return nodes;
}

bool isBranch(string charList, string output, int w)
{
    string positionsCharList = "";
    string positionsOutput = "";
    for (int i = 0; i < w; i++)
    {
        if (output[i] != '0')
        {
            positionsOutput += to_string(i);
        }
    }
    int iterator = 0;
    int multiplier = 0;
    for (int i = 0; i < charList.length(); i++)
    {
        if (charList[i] == '1')
        {
            if (i >= w)
            {
                positionsCharList += to_string(i - (w * multiplier));
            }
            else
            {
                positionsCharList += to_string(i);
            }
        }
        if (iterator == w)
        {
            if (positionsCharList == positionsOutput)
            {
                for (int j = 1; j < positionsCharList.length(); j++)
                {
                    int posPrev = static_cast<int>(positionsCharList[j - 1]) - 48;
                    int posCurr = static_cast<int>(positionsCharList[j]) - 48;
                    if (output[posPrev] != output[posCurr])
                    {
                        return false;
                    }
                    return true;
                }
            }
            positionsCharList = "";
            iterator = 0;
            multiplier++;
        }
        iterator++;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    string *adjacencyMatrix = new string[n];
    int *nodes;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> adjacencyMatrix[i];
    }
    for (int i = 0; i < n; i++)
    {
        string output = "";
        nodes = NodesWithChildrenBeneath(w[i], adjacencyMatrix[i]);
        for (int j = 0; j < w[i]; j++)
        {
            output += to_string(nodes[j]);
        }
        bool isBranching = isBranch(adjacencyMatrix[i], output, w[i]);
        int sumOfBananas = 0;
        if (isBranching)
        {
            for (int j = 0; j < w[i]; j++)
            {
                sumOfBananas += nodes[j];
            }
            cout << sumOfBananas << " bananas :)";
        }
        else
        {
            cout << "0 bananas :(";
        }
        cout << endl;
    }
    return 0;
}