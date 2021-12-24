#pragma once
#include "car.h"

using namespace std;

constexpr auto START_LINE = __LINE__;
enum class Fuel {
    REGULAR = 1,
    PREMIUM,
    SUPER,
    EKSTRA
};
constexpr auto FUEL_COUNT = __LINE__ - START_LINE - 3;
const string FUEL_NAMES[] = { "REGULAR", "PREMIUM", "SUPER", "EKSTRA" };
const string FUEL_STRING = "Выберите тип бензинового топлива (1 - АИ-92, 2 - АИ-95, 3 - АИ-95*, 4 - АИ-98): ";

class petrol :
    public car
{
public:
    petrol();
    petrol(string aMark, int aDistination, int aRelease, int aPrice, Fuel aFuel, int aCandels);
    void setFuel(Fuel aFuel);
    void setCandels(int aCandels);
    Fuel getFuel() const;
    int getCandels() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    Fuel fuel;
    int candels;
    void readSedFromConsole();
    void dummy() {};  // убираем абстрактность

    friend ostream& operator << (ostream& os, const petrol& eb);
};

