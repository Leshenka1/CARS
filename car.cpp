#include "car.h"

unsigned car::nextID = 0;

car::car(string aMark, int aDistination, int aRelease, int aPrice) : ID(nextID++)
{
	setMark(aMark);
	setDistination(aDistination);
	setYearRelease(aRelease);
	setPrice(aPrice);
}

void car::setMark(string aMark)
{
	Mark = aMark;
}

void car::setName(string aMark)
{
	Mark = aMark;
}

void car::setDistination(int aDistination)
{
	if (aDistination < 0)
		throw exception("setDistination: invalid creation year!");
	Distination = aDistination;
}



string car::getMark() const
{
	return Mark;
}

int car::getDistination() const
{

	return Distination;
}

car::car(const car& other) : ID(nextID++)
{
	clone(other);
}

void car::operator=(const car& other)
{
	clone(other);
}

car::car() :ID(nextID++)
{
	readFromConsole();
}

void car::setYearRelease(int aRelease)
{
	if (aRelease < 1886 || aRelease > 2021)
		throw exception("setYearRelease: invalid release year!");
	yearRelease = aRelease;
}

void car::setPrice(int aPrice)
{
	if (aPrice < 0)
		throw exception("setPrice: invalid car price");
	price = aPrice;
}

int car::getYearRelease() const
{
	return yearRelease;
}

int car::getPrice() const
{
	return price;
}

unsigned car::getID() const
{
	return ID;
}

void car::readFromConsole()
{
	int t;
	string s;

	cout << "Введите название марки машины: ";
	getline(cin, s);
	setName(s);
	cout << "Введите пробег машины (в километрах): ";
	while (true) {
		cin >> t;
		try {
			setDistination(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
	cout << "Введите год выпуска машины: ";
	while (true) {
		cin >> t;
		try {
			setYearRelease(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";
		}
	}
	cout << "Введите цену машины (в у.е.): ";
	while (true) {
		cin >> t;
		try {
			setPrice(t);
			break;
		}
		catch (...) {
			cout << "Вы ошиблись, повторите ввод!\n";

		}
	}
}

void car::writeToStream(ostream& os)
{
	os << "Car ID: " << ID << "| Mark: " << Mark <<
		"| travelled distance: " << Distination << "| Release year: " << yearRelease << "| Price: " << price << "\n";
}

void car::clone(const car& other)
{
	Mark = other.Mark;
	Distination = other.Distination;
	yearRelease = other.yearRelease;
	price = other.price;
}

ostream& operator<<(ostream& os, const car& b)
{
	os << "car ID: " << b.ID << "| Mark: " << b.Mark <<
		"| Travelled distance: " << b.Distination << "| Release year: " << b.yearRelease << "| Price: " << b.price << "\n";
	return os;
}