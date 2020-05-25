#include <iostream>
#include <chrono>
#include "trafficIntersection.h"
using namespace std;

void trafficIntersection::AutoContinue() {
    string userIn;

    cout << "Enter 0 to break from the loop.\n";

    while(userIn != "0") {
        //GenerateLightColor();
        GetLightColor();
        cin >> userIn;
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
    if(isVehicleDetected == true && lightState == 2) {
        lightState = 0;
        GetLightColor();
    }
    else {
        lightState = 2;
        GetLightColor();
    }
}

void trafficIntersection::GetLightColor() {
    switch(lightState) {
    case 0:
        cout << "Green\n";
        break;
    case 1:
        cout << "Yellow\n";
        break;
    case 2:
        cout << "Red\n";
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
    cout << "Enter light color, which can be either 0, 1, or 2.\n";
    cin >> lightState;
}
