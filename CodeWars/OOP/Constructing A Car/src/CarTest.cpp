#include <iostream>
#include <cassert>
#include "car.h"

void TestMotorStartAndStop () {
    Car car;
    assert (car.getEngineIsRunning() == false);
    car.EngineStart ();
    assert (car.getEngineIsRunning() == true);
    car.EngineStop ();
    assert (car.getEngineIsRunning() == false);

}

void TestFuelConsumptionOnIdle () {
    Car car (1);
    car.EngineStart ();
    for (int i = 0 ; i < 3000 ; i++)
        car.RunningIdle ();
    assert (car.fuelTankDisplay->getFillLevel() == 0.10);
}

void TestFuelTankDisplayIsComplete () {
    Car car (60);
    assert (car.fuelTankDisplay->getIsComplete() == true);
}

void TestFuelTankDisplayIsOnReserve () {
    Car car (4);
    assert (car.fuelTankDisplay->getIsOnReserve() == true);
}

void TestRefuel () {
    Car car (5);
    car.Refuel (40);
    assert (car.fuelTankDisplay->getFillLevel() == 45);
}

void TestMotorDoesntStartWithEmptyFuelTank () {
    Car car (0);
    car.EngineStart ();
    assert (car.getEngineIsRunning() == false);
}

void TestEngineStopsCauseOfNoFuelExactly () {
    Car car (1);
    car.EngineStart ();
    for (int i = 0; i < 3400; i++)
        car.RunningIdle ();
    assert (car.getEngineIsRunning() == false);
}

void TestNoConsumptionWhenEngineNotRunning () {
    Car car (1);
    for (int i = 0; i < 3400; i++)
        car.RunningIdle ();
    assert (car.fuelTankDisplay->getFillLevel() == 1);
}

void TestNoNegativeFuelLevelAllowed () {
    Car car (-5);
    assert (car.fuelTankDisplay->getFillLevel() == 0);
}

int main () {
    TestMotorStartAndStop ();
    TestFuelConsumptionOnIdle ();
    TestFuelTankDisplayIsComplete ();
    TestFuelTankDisplayIsOnReserve ();
    TestRefuel ();
    TestMotorDoesntStartWithEmptyFuelTank ();
    TestEngineStopsCauseOfNoFuelExactly ();
    TestNoConsumptionWhenEngineNotRunning ();
    TestNoNegativeFuelLevelAllowed ();
    std::cout << std::endl << "All tests have passed!" << std::endl;

    return 0;
}
