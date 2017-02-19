#ifndef CAR_INTERFACE_H
#define CAR_INTERFACE_H

class ICar {
public:
    virtual void EngineStart() = 0;
    virtual void EngineStop() = 0;
    virtual void Refuel(double liters) = 0;
    virtual void RunningIdle() = 0;
protected:
    bool engineIsRunning = false;
};

class IEngine {
public:
    virtual void Consume(double liters) = 0;
    virtual void Start() = 0;
    virtual void Stop() = 0;
protected:
    bool isRunning = false;
};

class IFuelTank {
public:
    virtual void Consume(double liters) = 0;
    virtual void Refuel(double liters) = 0;
protected:
    double fillLevel = 0.0;
    bool isOnReserve = false;
    bool isComplete = false;
};

class IFuelTankDisplay {
protected:
    double fillLevel = 0.0;
    bool isOnReserve = false;
    bool isComplete = false;
};

#endif

