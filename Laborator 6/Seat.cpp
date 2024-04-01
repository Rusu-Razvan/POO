#include "Seat.h"
#include "Weather.h"


void Seat::Set_fuel_capacity() {

	this->fuel_capacity = 47; // Liters
}

void Seat::Set_fuel_consumption(Weather weather) {
	switch (weather)
	{
	case Rain:
		this->fuel_consumption = 12;
		break;
	case Sunny:
		this->fuel_consumption = 10;
		break;
	case Snow:
		this->fuel_consumption = 14;
		break;
	default:
		break;
	}
}

void Seat::Set_average_speed(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		this->average_speed = 56;
		break;
	case Weather::Sunny:
		this->average_speed = 65;
		break;
	case Weather::Snow:
		this->average_speed = 41;
		break;
	default:
		break;
	}

}


Seat::Seat() {
	name = "Seat";
	Set_fuel_capacity();
}

