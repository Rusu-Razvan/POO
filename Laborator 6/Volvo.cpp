#include "Volvo.h"
#include "Car.h"
#include "Weather.h"



void Volvo::Set_fuel_capacity() {

	this->fuel_capacity = 48; //Liters
}

void Volvo::Set_fuel_consumption(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		this->fuel_consumption = 11;
		break;
	case Weather::Sunny:
		this->fuel_consumption = 9;
		break;
	case Weather::Snow:
		this->fuel_consumption = 14;
		break;
	default:
		break;
	}
}

void Volvo::Set_average_speed(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		this->average_speed = 50;
		break;
	case Weather::Sunny:
		this->average_speed = 65;
		break;
	case Weather::Snow:
		this->average_speed = 42;
		break;
	default:
		break;
	}

}


Volvo::Volvo() {
	name = "Volvo";
	Set_fuel_capacity();
}

