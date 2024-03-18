#include "Sort.h"
#include<iostream>
#include<vector>
using namespace std;

int main() {

	Sort arr1(6, 1, 11);     //construit cu valori aleatorii intre min max
	cout << "arr1: "; arr1.Print();
	arr1.InsertSort();
	cout << "arr1-InsertSort: "; arr1.Print();
	

	Sort arr2{ 2,6,7,1,9 };    // lista de initializare
	cout << "arr2: "; arr2.Print();
	arr2.QuickSort(0, arr2.GetElementsCount() - 1, false);
	cout << "arr2-QuickSort: "; arr2.Print();

	vector<int> vec = { 6, 1, 8, 17, 0 };   
	Sort arr3(vec, vec.size());    // un vector dat
	cout << "arr3: "; arr3.Print();
	arr3.BubbleSort(true);
	cout << "arr3-BubbleSort: "; arr3.Print();

	Sort arr4(1, 5, 6, 3, 45, 2, 9, -1);    // va_args
	arr4.Print();

	//Sort arr5("101,45,67,4,6,5");      // string
	//arr5.Print();



	return 0;
}