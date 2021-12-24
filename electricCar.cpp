#include "electricCar.h"

string toString(EngineType f) {
	return ENGINETYPE_NAMES[(int)f - 1];
}

ostream& operator<<(ostream& os, const electricCar& ab)
{
	os << (const car&)ab << "| Type of engine: " << toString(ab.engineType) << "| One charge distance: " << ab.ChargeDist << "\n";
	return os;
}

electricCar::electricCar() : car()
{
	readElectricFromConsole();
}

electricCar::electricCar(string aMark, int aDistination, int aRelease, int aPrice, EngineType aEnginType, int aChargeDist) :
	car(aMark, aDistination, aRelease, aPrice)
{
	setEngineType(aEnginType);
	setChargeDist(aChargeDist);
}

void electricCar::setEngineType(EngineType aEnginType)
{
	engineType = aEnginType;
}

void electricCar::setChargeDist(int aChargeDist)
{
	if (aChargeDist <= 0)
		throw exception("setTime: invalid one charge distance!");
	ChargeDist = aChargeDist;
}

EngineType electricCar::getEngineType() const
{
	return engineType;
}

int electricCar::getChargeDist() const
{
	return ChargeDist;
}

void electricCar::readFromConsole()
{
	car::readFromConsole();
	readElectricFromConsole();
}

void electricCar::writeToStream(ostream& os)
{
	os << (const car&)*this << "| Engnine type: " << toString(engineType) << "| One charge distance: " << ChargeDist << "\n";

}

void electricCar::readElectricFromConsole()
{
	cin.ignore();
	EngineType inputEngineType;
	int t;
	cout << "Выберите тип кпп (" + MENU_STRING2 + "): ";
	while (true) {
		cin >> t;
		if (!((t < 1) || (t > ENGINETYPE_COUNT)))
			break;
		cout << "Вы ошиблись, повторите ввод!\n";
	}
	inputEngineType = (EngineType)t;
	setEngineType(inputEngineType);
	cout << "Введите дальность хода на одном заряде (в километрах): ";
	while (true) {
		cin >> t;
		try {
			setChargeDist(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}

}