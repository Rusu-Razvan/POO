#include "RangeRover.h"
#include "Weather.h"


void RangeRover::Set_fuel_capacity() {

	this->fuel_capacity = 55; // Liters
}

void RangeRover::Set_fuel_consumption(Weather weather) {
	switch (weather)
	{
	case Rain:
		this->fuel_consumption = 13;
		break;
	case Sunny:
		this->fuel_consumption = 12;
		break;
	case Snow:
		this->fuel_consumption = 15;
		break;
	default:
		break;
	}
}

void RangeRover::Set_average_speed(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		this->average_speed = 60;
		break;
	case Weather::Sunny:
		this->average_speed = 70;
		break;
	case Weather::Snow:
		this->average_speed = 55;
		break;
	default:
		break;
	}

}


RangeRover::RangeRover() {
	name = "RangeRover";
	Set_fuel_capacity();
}