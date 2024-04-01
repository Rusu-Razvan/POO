#pragma once
#include "Car.h"

class BMW : public Car
{
public:
	BMW();
	void Set_fuel_capacity() override;
	void Set_fuel_consumption(Weather weather) override;
	void Set_average_speed(Weather weather) override;

};

