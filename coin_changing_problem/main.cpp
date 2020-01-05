// Project: Coin_Change_Problem.cbp
// File   : Coin_Change_Problem.cpp

#include <iostream>
#include <vector>

using namespace std;

void MinimalChangeCoin(double changingNominal)
{
    // All denominations of Indian Currency
    double denom[] =
    {1.0, 2.0, 5.0, 10.0, 50.0, 100.0, 200.0, 500.0, 2000.0};
    int totalDenom = sizeof(denom) / sizeof(denom[0]);

    // Initialize result as a vector
    vector<double> result;

    // Traverse through all denomination
    for (int i = totalDenom - 1; i >= 0; --i)
    {
        // Find denominations
        while (changingNominal >= denom[i])
        {
            changingNominal -= denom[i];
            result.push_back(denom[i]);
        }

        // If there's no any denomination
        // that can be given just exit the loop
        if (changingNominal < denom[0])
            break;
    }

    // Print result
    for (int i = 0; i < result.size(); ++i)
        cout << result[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Coin Change Problem" << endl;

    // Initialize the change nominal
    double change = 999;

    // Getting the minimal
    cout << "Minimal number of change for ";
    cout << change << " is " << endl;
    MinimalChangeCoin(change);

    return 0;
}
