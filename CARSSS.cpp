#include <iostream>
#include "windows.h"
#include "car.h"
#include "petrol.h"
#include "electricCar.h"
#include "diesel.h"
#include <vector>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int n = 3;
	vector<car*> allcars(n);

	try {
		electricCar* ElectricCar;
		ElectricCar = new electricCar("Tesla", 10000, 2019, 50000, EngineType::sinhronniy, 500);
		allcars[0] = ElectricCar;
		allcars[0]->writeToStream(cout);
		//	delete car1;
	}
	catch (exception) {
		cout << "Ошибки при создании электромобиля\n";
	}
	try {
		petrol* PetrolCar;
		PetrolCar = new petrol("Mersedes", 200000, 1993, 4000, Fuel::PREMIUM, 8);
		allcars[1] = PetrolCar;
		allcars[1]->writeToStream(cout);
		//cout << *car2 << endl;
		//delete car2;
	}
	catch (exception) {
		cout << "Ошибки при создании машины на бензине\n";
	}
	try {
		diesel* DieselCar;
		DieselCar = new diesel("Man", 30000, 2017, 20000, Dt::DTL, 2500);
		allcars[2] = DieselCar;
		allcars[2]->writeToStream(cout);
		//cout << *car3 << endl;
	//	delete car3;
	}
	catch (exception) {
		cout << "Ошибки при создании машины на дизельном топливе\n";
	}
}
