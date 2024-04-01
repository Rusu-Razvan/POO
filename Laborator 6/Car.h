#pragma once
#include "Weather.h"


class Car {
public:
	//protected:
	int fuel_capacity;
	int fuel_consumption;
	int average_speed;
	float race_time; //in hours
	const char* name;
	
	virtual void Set_fuel_capacity() = 0;
	virtual void Set_fuel_consumption(Weather weather) = 0;
	virtual void Set_average_speed(Weather weather) = 0;

};