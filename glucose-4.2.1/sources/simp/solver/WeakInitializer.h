#ifndef WEAKINITIALIZER_H
#define WEAKINITIALIZER_H

#include "WeakPropagator.h"

class WeakInitializer
{
public:
    static WeakInitializer &getInstance()
    {
        static WeakInitializer instance;
        return instance;
    }

    ~WeakInitializer() {}

    void initialize();

    WeakPropagator *getWeakPropagator()
    {
        return weakPropagator;
    }

    void printStatus()
    {
        weakPropagator->printCurrentStatus();
    }

    int getBound()
    {
        return weakPropagator->getUpperBound();
    }

    void setBound(int bound)
    {
        weakPropagator->setUpperBound(bound);
    }

    int getSumPropagator() const { return weakPropagator->getActualSum(); }

    void enabledPropagator() { weakPropagator->enabledPropagator(); }

    void propagateAtLevelZero(Glucose::Solver* solver,Glucose::vec<Glucose::Lit>& propagation) { weakPropagator->propagateLevelZero(solver,propagation);}

private:
    WeakInitializer();
    WeakPropagator *weakPropagator;
};
#endif
