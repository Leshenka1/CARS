#pragma once
#include "car.h"

constexpr auto START_LINE2 = __LINE__;
enum class EngineType {
    sinhronniy = 1,
    asinhronniy,
    koleso
};
constexpr auto ENGINETYPE_COUNT = __LINE__ - START_LINE2 - 3;
const string ENGINETYPE_NAMES[] = { "����������", "�����������", "�����-������" };
const string MENU_STRING2 = "�������� ��� ��������� (1 - ����������, 2 - �����������, 3 - �����-������): ";


class electricCar :
    public car
{
public:
    electricCar();
    electricCar(string aMark, int aDistination, int aRelease, int aPrice, EngineType aEnginType, int aChargeDist);
    void setEngineType(EngineType aEngineType);
    void setChargeDist(int aChargeDist);
    EngineType getEngineType() const;
    int getChargeDist() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    EngineType engineType;
    int ChargeDist;
    void dummy() {};  // ������� �������������
    void readElectricFromConsole();
    friend ostream& operator << (ostream& os, const electricCar& ab);
};

