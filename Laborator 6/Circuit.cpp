#include "Circuit.h"
#include "Car.h"
#include <iostream>
#include "Weather.h"

void Circuit::SetLength(int length){
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	currentWeather = weather;
}

Weather Circuit::GetCurrentWeather()
 {
	return currentWeather;
}

void Circuit::AddCar(Car* car) {
    Car** temp = new Car * [numCars + 1];
    for (int i = 0; i < numCars; ++i) {
        temp[i] = cars[i];
    }
    temp[numCars++] = car;
    delete[] cars;
    cars = temp;
}

Circuit::~Circuit() {
    for (int i = 0; i < numCars; i++)
        delete cars[i];
    delete[]cars;
}

int Circuit::GetNumCars() {
	return numCars;
}

void Circuit::Race() {

    for (int i = 0; i < numCars; i++)
    {
        cars[i]->Set_average_speed(currentWeather);
        cars[i]->Set_fuel_consumption(currentWeather);

        float fuel_needed_to_finish = (length * 1.0f * cars[i]->fuel_consumption) / 100;

        if (fuel_needed_to_finish > cars[i]->fuel_capacity)
            cars[i]->race_time = -1; //cant finish the circuit
        else {
            cars[i]->race_time = length * 1.0f / cars[i]->average_speed;
        }
       // std::cout << "Fuel consumption: " << this->cars[i]->fuel_consumption;
       // std::cout <<" Fuel capacity: "<< this->cars[i]->fuel_capacity<< " Avg speed: " << this->cars[i]->average_speed << "; Time set: " << this->cars[i]->race_time << std::endl;
    }
    
    for (int i = 0; i < numCars-1; i++)
        for (int j = i + 1; j < numCars; j++)
        {
            if (cars[i]->race_time > cars[j]->race_time)
            {
                //swap(cars[i], cars[j]);
                Car* aux = cars[i];
                cars[i] = cars[j];
                cars[j] = aux;
            }
                
        }
   
}


void Circuit::ShowFinalRanks() {
    int rank = 1;
    for (int i = 0 ; i < numCars; i++) {
        if (cars[i]->race_time != -1)
            std::cout << "Rank " << rank++ << ":" << cars[i]->name << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish() {

    bool output = 0;

    
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->race_time == -1)
        {
            if (output == 0) {
                std::cout << " The cars that did not finish:" << std::endl;
            }
            std::cout << cars[i]->name << std::endl;
            output = 1;
        }
    }

    if (output == 0) {
        std::cout << "All the cars have finished!" << std::endl;
    }
}