#include<iostream>
#include "NumberList.h"

int main()
{
	NumberList v;
	
	v.Init();
	
	v.Add(7);
	v.Add(9);
	v.Add(3);
	v.Add(24);

	v.Sort();

	v.Print();

	return 0;
}