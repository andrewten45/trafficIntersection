#include <iostream>
#include <chrono>
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
    switch (lightState) {
    case 0:
        std::cout << "Green\n";
        break;
    case 1:
        std::cout << "Yellow\n";
        break;
    case 2:
        std::cout << "Red\n";
        break;
    }
}

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
