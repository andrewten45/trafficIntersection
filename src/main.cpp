// Traffic intersection by Andrew T, which simulates an embedded traffic light.
// This app represents a hypothetical traffic light; more research is needed on actual light behavior to more fully simulate scenarios.
#include <iostream>
#include <chrono>
#include "trafficIntersection.h"

using namespace std;

void printMessage(const string &message)
{
    cout << message << endl;
}

void menuOutput(int menuNum)
{
    switch (menuNum)
    {
    case 0:
        cout << "==================||==========================\n";
        cout << "Welcome to traffic intersection simulator.\n";
        menuOutput(1);
        break;
    case 1:
        cout << "--------------------------------------------------------\n";
        break;
    case 2:
        cout << "Enter 0 to quit.\n";
        cout << "Enter 1 to operate at a fixed interval of your choosing.\n";
        cout << "Enter 2 to operate based on traffic detection.\n";
        cout << "Enter 3 to operate based on pseudo-random prediction.\n";
        menuOutput(1);
        break;
    }
}

int main()
{
    string userOption = "";
    trafficIntersection userIntersection;
    menuOutput(0);
    menuOutput(2);

    getline(cin, userOption);

    if (userOption == "1")
    {
        int numCycles = 0;
        int userNum1 = 0;
        int userNum2 = 0;

        cout << "Enter the number of cycles:\n";
        cin >> numCycles;
        cout << "Enter duration in seconds of red/green lights:\n";
        cin >> userNum1;
        cout << "Enter duration of yellow light:\n";
        cin >> userNum2;

        for (int i = 0; i < numCycles; ++i)
        {
            userIntersection.CycleLightColors(userNum1, userNum2);
        }
    }
    else if (userOption == "2")
    {
        string userIn = "";

        cout << "Defaults to NORTH SOUTH. Enter \"detected\" to simulate cars being detected; enter \"nocars\" to simulate no cars being present.\n";
        cin >> userIn;

        if (userIn == "detected")
        {
            userIntersection.SetDetectTrue();
        }
        else if (userIn == "nocars")
        {
            userIntersection.SetDetectFalse();
        }

        userIntersection.DetectionLightColors();
    }
    else if (userOption == "3")
    {
        int numCycles = 0;
        int numCarsHere = 0;
        int numCarsThere = 0;
        int num1;

        cout << "How many cycles?\n";
        cin >> numCycles;
        cout << "How many cars go across this intersection?\n";
        cin >> numCarsHere;
        cout << "How many cars go across the adjoining intersection?\n";
        cin >> numCarsThere;

        cout << "The ratio of cars going across the intersection is: " << (0.1 - 0.1 + numCarsHere) / (numCarsHere + numCarsThere) << endl;

        numCarsThere = numCarsThere * -1;

        for (int i = 0; i < numCycles; ++i)
        {
            num1 = rand() % (numCarsHere - numCarsThere + 1) + numCarsThere;
            if (num1 >= 0)
            {
                cout << "Green/yellow.\n";
            }
            else if (num1 < 0)
            {
                cout << "Red.\n";
            }
        }
    }

    return 0;
}
