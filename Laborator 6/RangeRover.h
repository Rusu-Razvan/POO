#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	void Set_fuel_capacity() override;
	void Set_fuel_consumption(Weather weather) override;
	void Set_average_speed(Weather weather) override;
};

