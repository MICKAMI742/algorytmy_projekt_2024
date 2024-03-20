#include <iostream>
#include <vector>

using namespace std;

struct Tree
{
    int w;
    vector<vector<string>> adjacencyMatrix; // adjacency matrix
};

void ReadInput(int &n, int &w, vector<Tree> &arrayOfTrees)
{
    cin >> n;
    arrayOfTrees.resize(n);
    string matrixAsOneString;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> matrixAsOneString;
        arrayOfTrees[i].w = w;
        while (matrixAsOneString.size() > 0)
        {
            vector<string> row;
            for (int j = 0; j < w; j++)
            {
                row.push_back(matrixAsOneString.substr(0, 1));
                matrixAsOneString.erase(0, 1);
            }
            arrayOfTrees[i].adjacencyMatrix.push_back(row);
        }
    }
}

int IsBanana(int &numberOfBananas, Tree tree)
{
    int numberOfNeighbours = 0;
    vector<int> neighbours;
    for (int i = 0; i < tree.w; i++)
    {
        numberOfNeighbours = 0;
        for (int j = 0; j < tree.w; j++)
        {
            if (tree.adjacencyMatrix[i][j] == "1")
            {
                numberOfNeighbours++;
            }
        }
        neighbours.push_back(numberOfNeighbours);
    }
    for (auto neighbour : neighbours)
    {
        if (neighbour == 1)
        {
            numberOfBananas++;
        }
    }

    return numberOfBananas;
}

int main()
{
    int n, w;                  // number of lines and number of graph vertices
    string matrixAsOneString;  // adjacency matrix as one string
    vector<Tree> arrayOfTrees; // array of trees
    int numberOfBananas = 0;   // number of bananas
    ReadInput(n, w, arrayOfTrees);
    for (auto tree : arrayOfTrees)
    {
        cout << IsBanana(numberOfBananas, tree) << " bananas" << endl;
        numberOfBananas = 0;
    }
    return 0;
}