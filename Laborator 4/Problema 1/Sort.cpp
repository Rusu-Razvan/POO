#include "Sort.h"
#include<iostream>
#include<vector>
#include<cstdarg>
#include<cstring>

Sort::Sort(int elem_count, int min, int max){
	arr.resize(elem_count);
	for (int i = 0; i < elem_count; i++)
		arr[i] = rand() % (max - min + 1) + min;
	
}

Sort::Sort(initializer_list<int> initList) : arr(initList) {}

Sort::Sort(const vector<int>& vec, int vecSize) {
	arr.resize(vecSize);
	for (int i = 0; i < vecSize; i++)
		arr[i] = vec[i];
}

Sort::Sort(int arg1, ...) {
	va_list args;
	va_start(args, arg1);

	int arg = arg1;
	while (arg != -1) {
		arr.push_back(arg);
		arg = va_arg(args, int);
	}

	va_end(args);
}

/*Sort::Sort(const char* s) {
	char* p;
	int number;
	p = strtok(s, ",");
	while (p) {
		number = atoi(p);
		arr.push_back(number);


		p = strtok(NULL, ",");
	}
}
*/

void Sort::InsertSort(bool ascendant) {
	int i, key, j;
	for (i = 1; i < arr.size(); i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && (ascendant ? arr[j] > key : arr[j] < key)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void Sort::QuickSort( int st, int dr, bool ascendent) {
	if (st < dr)
	{
		
		int m = (st + dr) / 2;
		int aux = arr[st];
		arr[st] = arr[m];
		arr[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if ((ascendent && arr[i] > arr[j]) || (!ascendent && arr[i] < arr[j])) 
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort( st, i - 1, ascendent);
		QuickSort( i + 1, dr, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent) {

	for (int i = 0; i < arr.size()-1; i++)
		for (int j = i + 1; j < arr.size(); j++)
			if (ascendent)
			{
				if (arr[j] < arr[i])
					swap(arr[i], arr[j]);
			}
			else {
				if (arr[j] > arr[i])
					swap(arr[i], arr[j]);
			}
}

void Sort::Print()
{
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << ' ';
	std::cout << endl;
}

int Sort::GetElementsCount() {
	return arr.size();
}

int Sort::GetElementFromIndex(int index) {
	return arr[index];
}