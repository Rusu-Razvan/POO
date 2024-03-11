#include<iostream>
#include "Math.h"
using namespace std;

int main() {

	cout << "Add: "<< Math::Add(1, 2) << ' ' << Math::Add(1, 2, 3) << ' ' << Math::Add(6.78, 5.7) << ' ' << Math::Add(4.3, 30.0, 4.5) << ' ' << Math::Add(4, 1, 2, 3, 4);
	cout << endl;
	cout << "Mul: "<< Math::Mul(1, 2) << ' ' << Math::Mul(1, 2, 3) << ' ' << Math::Mul(6.78, 5.7) << ' ' << Math::Mul(4.3, 30.0, 4.5);
	cout << endl;
	
	const char* str1 = "105"; //nullptr;
	const char* str2 = "4000"; 

	char*result = Math::Add(str1, str2);
	
	cout << "Add strings: ";

	if (result == nullptr) {
		cout << "One of the input strings is nullptr" << endl;
	}
	else {
		cout << result << endl;
		delete[] result;
	}

	return 0;
}