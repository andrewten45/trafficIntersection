//Traffic intersection by Andrew T, which simulates a traffic light.
//This app represents a hypothetical traffic light; more research is needed on actual light behavior to more fully simulate scenarios.
#include <iostream>
#include <chrono>
#include "trafficIntersection.h"

void menuOutput(int menuNum) {
    switch (menuNum) {
    case 0:
        std::cout << "==================||==========================\n";
        std::cout << "Welcome to traffic intersection simulator.\n";
        menuOutput(1);
        break;
    case 1:
        std::cout << "--------------------------------------------------------\n";
        break;
    case 2:
        std::cout << "Enter 0 to quit.\n";
        std::cout << "Enter 1 to operate at a fixed interval of your choosing.\n";
        std::cout << "Enter 2 to operate based on traffic detection.\n";
        std::cout << "Enter 3 to operate based on pseudo-random prediction.\n";
        menuOutput(1);
        break;
    }
}

int main()
{
    std::string userOption = "";
    trafficIntersection userIntersection;
    menuOutput(0);
    menuOutput(2);

    getline(std::cin, userOption);

    if (userOption == "1") {
        int numCycles = 0;
        int userNum1 = 0;
        int userNum2 = 0;

        std::cout << "Enter the number of cycles:\n";
        std::cin >> numCycles;
        std::cout << "Enter duration of red/green lights:\n";
        std::cin >> userNum1;
        std::cout << "Enter duration of yellow light:\n";
        std::cin >> userNum2;

        for (int i = 0; i < numCycles; ++i) {
            userIntersection.CycleLightColors(userNum1, userNum2);
        }
    }
    else if (userOption == "2") {
        std::string userIn = "";

        std::cout << "Defaults to NORTH SOUTH. Enter \"detected\" to simulate cars being detected; enter \"nocars\" to simulate no cars being present.\n";
        std::cin >> userIn;

        if (userIn == "detected") {
            userIntersection.SetDetectTrue();
        }
        else if (userIn == "nocars") {
            userIntersection.SetDetectFalse();
        }

        userIntersection.DetectionLightColors();
    }
    else if (userOption == "3") {
        int numCycles = 0;
        int numCarsHere = 0;
        int numCarsThere = 0;
        int num1;

        std::cout << "How many cycles?\n";
        std::cin >> numCycles;
        std::cout << "How many cars go across this intersection?\n";
        std::cin >> numCarsHere;
        std::cout << "How many cars go across the adjoining intersection?\n";
        std::cin >> numCarsThere;

        std::cout << "The ratio of cars going across the intersection is: " << (0.1 - 0.1 + numCarsHere) / (numCarsHere + numCarsThere) << std::endl;

        numCarsThere = numCarsThere * -1;

        for (int i = 0; i < numCycles; ++i) {
            num1 = rand() % (numCarsHere - numCarsThere + 1) + numCarsThere;
            if (num1 >= 0) {
                std::cout << "Green/yellow.\n";
            }
            else if (num1 < 0) {
                std::cout << "Red.\n";
            }
        }
    }

    return 0;
}
