#include <iostream>
#include <string>
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

// function is refactoring string to Package struct
void SortPackages(string P, string W, int &n, Car &car)
{
    string *prices = new string[n];
    string *weights = new string[n];
    string temp;
    car.packagesToPack = static_cast<Package *>(malloc(sizeof(Package) * n));
    car.packagesNumber = n;
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
        car.packagesToPack[i].price = stoi(prices[i]);
        car.packagesToPack[i].weight = stoi(weights[i]);
    }
    delete[] prices;
    delete[] weights;
}

// void PackingPackages(int carsNumber, Car &car)
// {
//     int mostValuablePackage = 0;
//     int filledCapacity = 0;
//     // cost of car packing
//     int money = -20;
//     double mostValuableWeight = 0;
//     while (filledCapacity <= car.capacity)
//     {
//         mostValuableWeight = 0;
//         for (int i = 0; i < car.packagesNumber; i++)
//         {
//             double pricePerWeight = static_cast<double>(car.packagesToPack[i].price) * static_cast<double>(car.packagesToPack[i].weight);
//             if (pricePerWeight > mostValuableWeight)
//             {
//                 mostValuableWeight = pricePerWeight;
//                 mostValuablePackage = i;
//                 if (car.packagesToPack[i].price > car.packagesToPack[mostValuablePackage].price)
//                 {
//                     mostValuablePackage = i;
//                 }
//             }
//         }
//         if (car.packagesToPack[mostValuablePackage].weight > 100 &&
//             filledCapacity + car.packagesToPack[mostValuablePackage].weight <= car.capacity)
//         {
//             money -= 5;
//         }
//         if (filledCapacity + car.packagesToPack[mostValuablePackage].weight > car.capacity)
//         {
//             car.packagesToPack[mostValuablePackage].price = 0;
//         }
//         money += car.packagesToPack[mostValuablePackage].price;
//         filledCapacity += car.packagesToPack[mostValuablePackage].weight;
//         car.packagesToPack[mostValuablePackage].price = 0;
//         car.packagesToPack[mostValuablePackage].weight = 1;
//     }
//     if (money < 0)
//     {
//         money = 0;
//     }
//     cout << money << endl;
// }
int PackingPackages(Car &car)
{
    int money = -20;
    // sort by prices
    for (int i = 0; i < car.packagesNumber - 1; i++)
    {
        for (int j = 0; j < car.packagesNumber - i - 1; j++)
        {
            if (car.packagesToPack[j].price < car.packagesToPack[j + 1].price)
            {
                // Swap packages
                Package temp = car.packagesToPack[j];
                car.packagesToPack[j] = car.packagesToPack[j + 1];
                car.packagesToPack[j + 1] = temp;
            }
        }
    }
    int actualWeight = car.capacity;
    for (int i = 0; i < car.packagesNumber; i++)
    {
        if (car.packagesToPack[i].weight <= actualWeight)
        {
            money += car.packagesToPack[i].price;
            if (car.packagesToPack[i].weight > 100)
            {
                money -= 5;
            }
            actualWeight -= car.packagesToPack[i].weight;
        }
    }
    if (money < 0)
    {
        money = 0;
    }
    return money;
}

void ReadInput(int &carsNumber, int &n, string &P, string &W, int &maximumLoading, Car *&cars)
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
    Car *cars;
    ReadInput(carsNumber, n, P, W, maximumLoading, cars);
    for (int i = 0; i < carsNumber; i++)
    {
        cout << PackingPackages(cars[i]) << endl;
    }
    return 0;
}
