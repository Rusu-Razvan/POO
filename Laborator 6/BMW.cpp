#include "BMW.h"
#include "Weather.h"


void BMW::Set_fuel_capacity() {
	
	this->fuel_capacity = 50; // Liters
}

void BMW::Set_fuel_consumption(Weather weather) {
	switch (weather)
	{
	case Rain:
		this->fuel_consumption = 15;
		break;
	case Sunny:
		this->fuel_consumption = 13;
		break;
	case Snow:
		this->fuel_consumption = 17;
		break;
	default:
		break;
	}
}

void BMW::Set_average_speed(Weather weather) {
	switch(weather)
	{
	case Weather::Rain:
		this->average_speed = 62;
		break;
	case Weather::Sunny:
		this->average_speed = 74;
		break;
	case Weather::Snow:
		this->average_speed = 44;
		break;
	default:
		break;
	}
	
}


BMW::BMW() {
	name = "BMW";
	Set_fuel_capacity();
}

