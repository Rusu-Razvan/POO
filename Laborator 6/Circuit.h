#pragma once
#include "Circuit.h"
#include "Car.h"
#include "BMW.h"
#include "Volvo.h"
#include <iostream>
#include "Weather.h"

class Circuit
{
	
	int length;
	Weather currentWeather;
	int numCars;
	Car** cars;

public:
	

	~Circuit();

	void SetLength(int length);  //done


	void SetWeather(Weather weather);   //done
	Weather GetCurrentWeather();		//done

	void AddCar(Car* car);		//done
	int GetNumCars();			//done	

	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

	
};

