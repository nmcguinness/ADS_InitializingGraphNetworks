#pragma once
#include <iostream>
using namespace std;

struct Bike {
public:
	string brand;
	double price;
	int gears;
	bool isFemale;
	bool fullSuspension;

	Bike(string brand, int gears, bool isFemale, bool fullSuspension, double price) {
		this->brand = brand;
		this->gears = gears;
		this->price = price;
		this->isFemale = isFemale;
		this->fullSuspension = fullSuspension;
	}

	friend ostream& operator<<(ostream& os, const Bike& bike) {
		os << "Brand: " << bike.brand;
		os << "\nGears: " << bike.gears;
		os << ", Price: " << bike.price;
		os << ", Gender: " << (bike.isFemale ? "Female" : "Male");
		os << ", Suspension: " << (bike.fullSuspension ? "Full" : "Rigid");
		return os;
	}
};