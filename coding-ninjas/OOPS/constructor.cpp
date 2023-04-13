#include <bits/stdc++.h>
using namespace std;

class Vehicle {
	string color;
	int maxSpeed;
public:
	Vehicle() {
		cout << "Vehicle constructor" << endl;
	}
	Vehicle(string c) {
		cout << "Parameter constructor vehicle" << endl;
		color = c;
	}
};

class Car: public Vehicle {
	string name;
public:
	// Car() {
	// 	Vehicle("red");
	// 	cout << "Cars constructor" << endl;
	// }
	Car() : Vehicle("red") {
		cout << "Car something" << endl;
	}
};

int main() {
	Car v;
	return 0;
}