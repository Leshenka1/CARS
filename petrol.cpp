#pragma once
#include "petrol.h"

using namespace std;

string toString(Fuel f) {
    return FUEL_NAMES[(int)f - 1];
}

ostream& operator<<(ostream& os, const petrol& eb)
{
    os << (const car&)eb << "| Fuel type: " << toString(eb.fuel) << "| Moment: " << eb.candels << "\n";
    return os;
}

petrol::petrol() :car()
{
    readSedFromConsole();
}

petrol::petrol(string aMark, int aDistination, int aRelease, int aPrice, Fuel aFuel, int aCandels) :
    car(aMark, aDistination, aRelease, aPrice)
{
    setFuel(aFuel);
    setCandels(aCandels);
}

void petrol::setFuel(Fuel aFuel)
{

    fuel = aFuel;
}

void petrol::setCandels(int aCandels)
{
    if (aCandels <= 0 || aCandels > 12)
        throw exception("setCandels: invalid candels amount!");
    candels = aCandels;
}

Fuel petrol::getFuel() const
{
    return fuel;
}

int petrol::getCandels() const
{
    return candels;
}
void petrol::readFromConsole()
{
    car::readFromConsole();
    readSedFromConsole();
}

void petrol::writeToStream(ostream& os)
{
    os << (const car&)*this << "| Fuel: " << toString(fuel) << "| Candels: " << candels << "\n";
}

void petrol::readSedFromConsole()
{
    cin.ignore();
    Fuel inputGear;
    int t;
    cout << "Выберите тип бензинового (" + FUEL_STRING + "): ";
    while (true) {
        cin >> t;
        if (!((t < 1) || (t > FUEL_COUNT)))
            break;
        cout << "Вы ошиблись, повторите ввод!\n";
    }
    inputGear = (Fuel)t;
    setFuel(inputGear);
    cout << "введите количество свечей накала:";
    while (true) {
        cin >> t;
        try {
            setCandels(t);
            break;
        }
        catch (...) {
            cout << "Вы ошиблись, повторите ввод!\n";
        }
    }
}