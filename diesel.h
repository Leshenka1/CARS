#pragma once
#include "car.h"
#include <string>

using namespace std;

constexpr auto START_LINE3 = __LINE__;
enum class Dt {
    DTL = 1,
    DTZ,
    DTA
};
constexpr auto DT_COUNT = __LINE__ - START_LINE3 - 3;
const string DT_NAMES[] = { "ДТЛ", "ДТЗ", "ДТА" };
const string MENU_STRING3 = "Выберите тип дизельного топлива (1 - ДТЛ , 2 - ДТЗ, 3 - ДТА): ";

class diesel :
    public car
{
public:
    diesel();
    diesel(string aMark, int aDistination, int aRelease, int aPrice, Dt aDt, int aMoment);
    void setDt(Dt aDt);
    void setMoment(int aMoment);
    Dt getDt() const;
    int getMoment() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    Dt dt;
    int moment;
    void dummy() {};  // убираем абстрактность
    void readtrukFromConsole();

    friend ostream& operator << (ostream& os, const diesel& pb);
};

