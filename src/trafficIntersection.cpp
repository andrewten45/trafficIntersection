#include <iostream>
#include <chrono>
#include <windows.h>
#include "trafficIntersection.h"

void trafficIntersection::AutoContinue() {
    std::string userIn;

    std::cout << "Enter 0 to break from the loop.\n";

    while (userIn != "0") {
        //GenerateLightColor();
        GetLightColor();
        std::cin >> userIn;
    }
}

void trafficIntersection::CycleLightColors(int userNum1, int userNum2) {
    lightState = 0;
    GetLightColor();
    _sleep(userNum1 * 1000);

    lightState = 1;
    GetLightColor();
    _sleep(userNum2 * 1000);

    lightState = 2;
    GetLightColor();
    _sleep(userNum1 * 1000);
}

void trafficIntersection::DetectionLightColors() {
    if (isVehicleDetected == true && lightState == 2) {
        lightState = 0;
        GetLightColor();
    }
    else {
        lightState = 2;
        GetLightColor();
    }
}

void trafficIntersection::GetLightColor() {
    //Test with Console Colors from windows.h
    //Note that output is formatted this way in the original source, an article by Tenry (Link: https://dev.to/tenry/terminal-colors-in-c-c-3dgc)
    //Despite my use of different formatting, the program still functions correctly. More testing may be needed, however.
    /*
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,
        FOREGROUND_RED);
    printf("red text\n");
    */

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    switch (lightState) {
    case 0:
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "Green\n";
        break;
    case 1:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
        std::cout << "Yellow\n";
        break;
    case 2:
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << "Red\n";
        break;
    }
}

//TODO: Function that calls to SetDetectTrue/False based on placeholder. Currently seemingly operates as if there are no cars.

void trafficIntersection::SetDetectTrue() {
    isVehicleDetected = true;
}

void trafficIntersection::SetDetectFalse() {
    isVehicleDetected = false;
}

void trafficIntersection::SetLightColor() {
    std::cout << "Enter light color, which can be either 0, 1, or 2.\n";
    std::cin >> lightState;
}
