#pragma once
#include <string>
#include <iostream>
using namespace std;

class car
{
public:
	car(string aMark, int aDistination, int aRelease, int aPrice);
	car(const car& other);
	void operator = (const car& other);
	car();
	void setYearRelease(int aRelease);
	void setPrice(int aPrice);
	void setMark(string aMark);
	void setName(string aName);
	void setDistination(int aDistination);
	string  getMark() const;
	int getDistination() const;
	int getYearRelease() const;
	int getPrice() const;
	unsigned getID() const;
	virtual void readFromConsole();
	virtual void writeToStream(ostream&);
private:
	unsigned ID;
	string Mark;
	int Distination;
	int yearRelease;
	int price;
	void clone(const car& other);
	virtual void dummy() = 0;   // для обеспечения абстрактности класса
	static unsigned nextID;  // для обеспечения уникальности ID

	friend ostream& operator << (ostream& os, const car& b);
};

