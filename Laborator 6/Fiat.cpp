#include "Fiat.h"
#include "Weather.h"


void Fiat::Set_fuel_capacity() {

	this->fuel_capacity = 45; // Liters
}

void Fiat::Set_fuel_consumption(Weather weather) {
	switch (weather)
	{
	case Rain:
		this->fuel_consumption = 12;
		break;
	case Sunny:
		this->fuel_consumption = 9;
		break;
	case Snow:
		this->fuel_consumption = 14;
		break;
	default:
		break;
	}
}

void Fiat::Set_average_speed(Weather weather) {
	switch (weather)
	{
	case Weather::Rain:
		this->average_speed = 55;
		break;
	case Weather::Sunny:
		this->average_speed = 63;
		break;
	case Weather::Snow:
		this->average_speed = 44;
		break;
	default:
		break;
	}

}


Fiat::Fiat() {
	name = "Fiat";
	Set_fuel_capacity();
}