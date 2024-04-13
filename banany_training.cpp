#include <iostream>
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

int main()
{
    int n;
    cin >> n;
    int *w = new int[n];
    string *adjacencyMatrix = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> adjacencyMatrix[i];
    }
    for (int i = 0; i < n; i++)
    {
        int *nodes = NodesWithChildrenBeneath(w[i], adjacencyMatrix[i]);
        for (int j = 0; j < w[i]; j++)
        {
            cout << nodes[j] << " ";
        }
        cout << endl;
    }
    return 0;
}