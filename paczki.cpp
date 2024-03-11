#include <iostream>
using namespace std;
struct Package
{
    int price;
    int weight;
};

struct Car
{
    int packagesNumber;
    int capacity;
    Package *packagesToPack;
};

Car *cars;
Package *packages;

// function is refactoring string to Package struct
void SortPackages(string P, string W, int &n, Car &car)
{
    packages = new Package[n];
    string *prices = new string[n];
    string *weights = new string[n];
    string temp;
    car.packagesToPack = static_cast<Package *>(malloc(sizeof(Package) * n));
    int iterator = 0;
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i] != ' ')
        {
            temp += P[i];
        }
        else
        {
            prices[iterator] = temp;
            iterator++;
            temp = "";
        }
    }
    temp = "";
    iterator = 0;
    for (int i = 0; i < W.size(); i++)
    {
        if (W[i] != ' ')
        {
            temp += W[i];
        }
        else
        {
            weights[iterator] = temp;
            iterator++;
            temp = "";
        }
    }
    for (int i = 0; i < n; i++)
    {
        // packages[i].price = stoi(prices[i]);
        // packages[i].weight = stoi(weights[i]);
        car.packagesNumber = n;
        car.packagesToPack[i].price = stoi(prices[i]);
        car.packagesToPack[i].weight = stoi(weights[i]);
    }
}

void ReadInput(int &carsNumber, int &n, string &P, string &W, int &maximumLoading)
{
    string line;
    // reads car number
    getline(std::cin, line);
    carsNumber = std::stoi(line);
    // initialazing cars list
    cars = new Car[carsNumber];
    // initialazing packages list
    for (int i = 0; i < carsNumber; i++)
    {
        Car car;
        // reading number of packages
        getline(cin, line);
        n = stoi(line);

        // reading packages prices
        getline(cin, line);
        P = line + " ";

        // reading packages weights
        getline(cin, line);
        W = line + " ";

        SortPackages(P, W, n, car);

        // reading maximal loading
        getline(cin, line);
        maximumLoading = stoi(line);
        car.capacity = maximumLoading;
        // putting cars with data to the list
        cars[i] = car;
    }
}

int main()
{
    int carsNumber;
    int n;
    string P;
    string W;
    int maximumLoading;
    ReadInput(carsNumber, n, P, W, maximumLoading);
    for (int i = 0; i < carsNumber; i++)
    {
        Car car = cars[i];
        int size = car.packagesNumber;
        for (int j = 0; j < size; j++)
        {
            cout << car.capacity << " " << car.packagesToPack[j].price << " " << car.packagesToPack[j].weight << endl;
        }
    }

    return 0;
}
