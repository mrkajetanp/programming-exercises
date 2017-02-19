#ifndef CAR_H
#define CAR_H

#include "CarInterface.h"
#include <memory>

class Engine : public IEngine {
public:
    Engine ();
    void Start ();
    void Stop ();
    void Consume (double liters);
    bool getIsRunning ();
};

class FuelTank : public IFuelTank {
    friend class Car;
public:
    FuelTank ();
    FuelTank (double liters);
    void Consume (double liters);
    void Refuel (double liters);
};

class FuelTankDisplay : public IFuelTankDisplay {
    friend class Car;
public:
    FuelTankDisplay ();
    double getFillLevel ();
    bool getIsComplete ();
    bool getIsOnReserve ();
};

class Car : public ICar {
private:
    std::unique_ptr<Engine> engine;
    std::unique_ptr<FuelTank> fuelTank;
public:
    std::unique_ptr<FuelTankDisplay> fuelTankDisplay;

    Car ();
    Car (double liters);
    void EngineStart ();
    void EngineStop ();
    void RunningIdle ();
    void Refuel (double liters);
    bool getEngineIsRunning ();
};

#endif


