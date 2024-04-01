#pragma once
#include "Car.h"

class Seat : public Car
{
public:

	Seat();
	void Set_fuel_capacity() override;
	void Set_fuel_consumption(Weather weather) override;
	void Set_average_speed(Weather weather) override;
};

