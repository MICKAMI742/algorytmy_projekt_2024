#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> matrixes; // every index is string which shows one matrix
vector<int> nodeNumber;  // every index is int which shows number of nodes
vector<string> nodes;    // every index is string which shows one node neighbours
int n;                   // number of trees

void ReadInput(vector<string> &matrixes, vector<int> &nodeNumber)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int nN;    // number of nodes
        string aM; // adjacency matrix
        cin >> nN;
        cin >> aM;
        nodeNumber.push_back(nN);
        matrixes.push_back(aM);
    }
}

void ParseToRows(vector<string> &nodes, string matrix, int nN)
{
    int iterator = 0;
    string help = "";
    for (auto c : matrix)
    {
        help += c;
        iterator++;
        if (iterator == nN)
        {
            nodes.push_back(help);
            help = "";
            iterator = 0;
        }
    }
}

int StringSum(string row)
{
    int sum = 0;
    for (auto c : row)
    {
        sum += c - '0';
    }
    return sum;
}

bool HasNoTwoRoots(vector<int> bananaIndexes, vector<int> aboveIndexes)
{
    vector<string> finalLevel{};
    for (auto i : aboveIndexes)
    {
        finalLevel.push_back(nodes[i]);
    }
    for (auto &row : finalLevel)
    {
        for (auto index : bananaIndexes)
        {
            row[index] = '0';
        }
    }
    string lastRow = finalLevel[0];
    for (int i = 1; i < finalLevel.size(); i++)
    {
        if (finalLevel[i] != lastRow)
        {
            return false;
        }
    }
    return true;
}

bool IsBananaTree(int nN, vector<string> &nodes)
{
    vector<int> aboveBananas; // indexes of nodes above bananas
    vector<int> bananasIndexes;
    int bananaIndex = 0;
    for (auto row : nodes)
    {
        if (StringSum(row) == 1)
        {
            bananasIndexes.push_back(bananaIndex);
        }
        bananaIndex++;
    }
    for (auto row : nodes)
    {
        int index = 0;
        if (StringSum(row) == 1)
        {
            for (auto c : row)
            {
                if (c == '1')
                {
                    aboveBananas.push_back(index);
                    break;
                }
                index++;
            }
        }
    }
    int lastSum = StringSum(nodes[aboveBananas[0]]);
    for (int i = 1; i < aboveBananas.size(); i++)
    {
        if (StringSum(nodes[aboveBananas[i]]) != lastSum)
        {
            return false;
        }
    }
    if (HasNoTwoRoots(bananasIndexes, aboveBananas))
    {
        return true;
    }
    return false;
}

int NumberOfBananas(vector<string> &nodes, int nN)
{
    int sum = 0;
    for (auto row : nodes)
    {
        if (StringSum(row) == 1)
        {
            for (auto c : row)
            {
                if (c == '1')
                {
                    sum += 1;
                }
            }
        }
    }
    return sum;
}

int main()
{
    ReadInput(matrixes, nodeNumber);

    for (int i = 0; i < n; i++)
    {
        ParseToRows(nodes, matrixes[i], nodeNumber[i]);
        if (IsBananaTree(nodeNumber[i], nodes))
        {
            cout << NumberOfBananas(nodes, nodeNumber[i]) << " bananas :)" << endl;
        }
        else
        {
            cout << "0 bananas :(" << endl;
        }
        nodes.clear();
    }
    return 0;
}

// 1
// 6 010011101100010000010000100000100000