#include "diesel.h"
using namespace std;

string toString(Dt f) {
	return DT_NAMES[(int)f - 1];
}

diesel::diesel() : car()
{
	readtrukFromConsole();
}

diesel::diesel(string aMark, int aDistination, int aRelease, int aPrice, Dt aDt, int aMoment) :
	car(aMark, aDistination, aRelease, aPrice)
{
	setDt(aDt);
	setMoment(aMoment);
}

void diesel::setDt(Dt aDt)
{
	dt = aDt;
}

void diesel::setMoment(int aMoment)
{
	if (aMoment <= 0)
		throw exception("setMoment: invalid moment number!");
	moment = aMoment;
}

Dt diesel::getDt() const
{

	return dt;
}

int diesel::getMoment() const
{
	return moment;
}

ostream& operator<<(ostream& os, const diesel& pb)
{
	os << (const car&)pb << "| Type of cargo: " << toString(pb.dt) << "| Weight power: " << pb.moment << "\n";
	return os;
}
void diesel::readFromConsole()
{
	car::readFromConsole();
	readtrukFromConsole();
}

void diesel::writeToStream(ostream& os)
{
	os << (const car&)*this << "| Type of diesel: " << toString(dt) << "| Moment number: " << moment << "\n";
}

void diesel::readtrukFromConsole()
{
	cin.ignore();
	Dt inputCargo;
	int s;
	cout << "Выберите тип дизельного топлива (" + MENU_STRING3 + "): ";
	while (true) {
		cin >> s;
		if (!((s < 1) || (s > DT_COUNT)))
			break;
		cout << "Вы ошиблись, повторите ввод!\n";
	}
	inputCargo = (Dt)s;
	setDt(inputCargo);
	cout << "Введите количесвто крутящего момента (в Н/м): ";
	while (true) {
		cin >> s;
		try {
			setMoment(s);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
}