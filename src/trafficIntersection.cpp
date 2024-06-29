#include <iostream>
#include <chrono>
#include <thread>
#include "trafficIntersection.h"
#include <string>

using namespace std;

void trafficIntersection::AutoContinue()
{
    string userIn;

    cout << "Enter 0 to break from the loop.\n";

    while (userIn != "0")
    {
        GetLightColor();
        cin >> userIn;
    }
}

void trafficIntersection::CycleLightColors(int userNum1, int userNum2)
{
    lightState = 0;
    GetLightColor();
    this_thread::sleep_for(chrono::seconds(userNum1));

    lightState = 1;
    GetLightColor();
    this_thread::sleep_for(chrono::seconds(userNum2));

    lightState = 2;
    GetLightColor();
    this_thread::sleep_for(chrono::seconds(userNum1));
}

void trafficIntersection::DetectionLightColors()
{
    if (isVehicleDetected && lightState == 2)
    {
        lightState = 0;
        GetLightColor();
    }
    else
    {
        lightState = 2;
        GetLightColor();
    }
}

void trafficIntersection::GetLightColor()
{
    switch (lightState)
    {
    case 0:
        cout << "Light is red.\n";
        break;
    case 1:
        cout << "Light is yellow.\n";
        break;
    case 2:
        cout << "Light is green.\n";
        break;
    }
}

// TODO: Function that calls to SetDetectTrue/False based on placeholder. Currently seemingly operates as if there are no cars.

void trafficIntersection::SetDetectTrue()
{
    isVehicleDetected = true;
}

void trafficIntersection::SetDetectFalse()
{
    isVehicleDetected = false;
}

void trafficIntersection::SetLightColor()
{
    cout << "Enter light color, which can be either 0, 1, or 2.\n";
    cin >> lightState;
}
