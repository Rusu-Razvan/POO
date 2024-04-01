#pragma once
#include "Car.h"
class Volvo : public Car
{
public:

	Volvo();
	void Set_fuel_capacity() override;
	void Set_fuel_consumption(Weather weather) override;
	void Set_average_speed(Weather weather) override;
};

