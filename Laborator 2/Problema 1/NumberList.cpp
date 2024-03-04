#include "NumberList.h"
#include<iostream>



void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count >= 10)
		return false;
	else
	   this->numbers[this->count++] = x;
	
}

void NumberList::Sort() {
	int i, j,aux;
	for (i = 0; i < this->count-1; i++)
		for ( j = i + 1; j < this->count; j++)
			if (this->numbers[i] > this->numbers[j])
			{
				aux = this->numbers[j];
				this->numbers[j] = this->numbers[i];
				this->numbers[i] = aux;
			}
}

void NumberList::Print() {
	for (int i = 0; i < this->count; i++)
	{
		printf("%d", this->numbers[i]);
		printf(" ");
	}
	
}
