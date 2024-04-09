#include<iostream>
float operator"" _Kelvin(unsigned long long int kelvin)
{
	float celsius = kelvin - 273.15;

	return celsius;
}

float operator"" _Fahrenheit(unsigned long long fahr) {

	float celsius = (fahr - 32) / 1.8;

	return celsius;

}

int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}