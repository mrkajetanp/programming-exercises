#include "Car.h"
#include <memory>
#include <cmath>

/*********************************************************************
******************************* Car **********************************
*********************************************************************/

Car::Car () {
    engine.reset (new Engine);
    fuelTank.reset (new FuelTank);
    fuelTankDisplay.reset (new FuelTankDisplay);

    fuelTankDisplay->fillLevel = fuelTank->fillLevel;
}

Car::Car (double liters) {
    engine.reset (new Engine);
    fuelTank.reset (new FuelTank (liters));
    fuelTankDisplay.reset (new FuelTankDisplay);

    if (fuelTank->fillLevel >= 60) {
        fuelTank->fillLevel = 60;
        fuelTank->isComplete = true;
    }
    if (fuelTank->fillLevel < 5)
        fuelTank->isOnReserve = true;

    if (fuelTank->fillLevel < 0)
        fuelTank->fillLevel = 0;

    fuelTankDisplay->fillLevel = fuelTank->fillLevel;
    fuelTankDisplay->isComplete = fuelTank->isComplete;
    fuelTankDisplay->isOnReserve = fuelTank->isOnReserve;
}

bool Car::getEngineIsRunning () {
    return engineIsRunning;
}

void Car::EngineStart () {
    if (fuelTank->fillLevel > 0) {
        engine->Start ();
        engineIsRunning = true;
    }
}

void Car::EngineStop () {
    engine->Stop ();
    engineIsRunning = false;
}

void Car::RunningIdle () {
    if (getEngineIsRunning()) {
        fuelTank->Consume (0.0003);
        fuelTankDisplay->fillLevel = fuelTank->fillLevel;
        if (fuelTank->fillLevel < 5) {
            fuelTank->isOnReserve = true;
            fuelTankDisplay->isOnReserve = true;
        }
        if (fuelTank->fillLevel <= 0) {
            fuelTank->fillLevel = 0;
            EngineStop ();
        }
    }
  }

void Car::Refuel (double liters) {
    fuelTank->Refuel (liters);
    fuelTankDisplay->fillLevel = fuelTank->fillLevel;
    fuelTankDisplay->isComplete = fuelTank->isComplete;
}

/********************************************************************
**************************** Engine *********************************
********************************************************************/

Engine::Engine () { }

void Engine::Start () {
    isRunning = true;
}

void Engine::Stop () {
    isRunning = false;
}

bool Engine::getIsRunning () {
    return isRunning;
}

void Engine::Consume (double liters) {
    liters = 0;
}

/********************************************************************
**************************** Fuel Tank ******************************
********************************************************************/

FuelTank::FuelTank () {
    fillLevel = 20.0;
}

FuelTank::FuelTank (double liters) {
    fillLevel = liters;
}

void FuelTank::Consume (double liters) {
    fillLevel -= liters;
    if (fillLevel < 0.0)
        fillLevel = 0.0;
}

void FuelTank::Refuel (double liters) {
    fillLevel += liters;
    if (fillLevel >= 60) {
        fillLevel = 60;
        isComplete = true;
    }
}

/********************************************************************
************************ Fuel Tank Display **************************
********************************************************************/

FuelTankDisplay::FuelTankDisplay () {
}

double FuelTankDisplay::getFillLevel () {
    return std::floor (fillLevel*100+0.5)/100;
}

bool FuelTankDisplay::getIsComplete () {
    return isComplete;
}

bool FuelTankDisplay::getIsOnReserve () {
    return isOnReserve;
}


