#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cstdlib>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c) {
	return a + b  + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}

int Math::Mul(double a, double b, double c) {
	return a * b * c;
}

int Math::Add(int count, ...) {
	
	int i, sum = 0;

	va_list args;
	va_start(args, count);

	for ( i = 0; i < count; i++)
	{
		int arg = va_arg(args, int);
		sum += arg;
	}

	va_end(args);
	return sum;

}


char* Math::Add(const char* str1, const char* str2) {
	
	int number1 = 0, number2 = 0, p=1, i, result_number = 0, copy_result_number, digit_len=0;
	
	if (str1 == nullptr or str2 == nullptr)
		return nullptr;

	int len1 = strlen(str1);
	int len2 = strlen(str2);


	for (i = len1-1; i >=0; i--) {
		int digit = str1[i] - '0';
		number1 = number1 + digit * p;
			p *= 10;
	}

	p = 1;

	for (i = len2 - 1; i >= 0; i--) {
		int digit = str2[i] - '0';
		number2 = number2 + digit * p;
			p *= 10;
	}

	result_number = number1 + number2;
	copy_result_number = result_number;

	do {
		digit_len++;
		copy_result_number /= 10;
	}while(copy_result_number);

	char* result = new char[digit_len+1];

	_itoa(result_number, result, 10);

	
	return result;
	

}


