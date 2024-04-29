#include<iostream>
#include "Map.h"
using namespace std;

int main() {

	Map<int, const char*> m;
	printf("Map m:\n");
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";
	for (auto [key, value, index] : m)
	{
		printf("Index: %d, Key: %d, Value: %s\n", index, key, value);
	}
	printf("\n");
	
	m[20] = "result";
	for (auto [key, value, index] : m)
	{
		printf("Index: %d, Key: %d, Value: %s\n", index, key, value);
	}
	printf("\n");

	Map<int, const char*> m2;
	
	m2[10] = "C++";
	m2[43] = "I";
	m2[20] = "love";
	m2[34] = "POO";

	printf("Map m2:\n");
	for (auto [key, value, index] : m2)
	{
		printf("Index: %d, Key: %d, Value: %s\n", index, key, value);
	}
	printf("\n");

	const char* value = nullptr;
	m2.Get(43, value);
	printf("Variable 'value' has the value from key 43 : %s\n", value);
	printf("\n");

	m2.Delete(43);
	printf("Map m2 after deleting key 43:\n");

	for (auto [key, value, index] : m2)
	{
		printf("Index: %d, Key: %d, Value: %s\n", index, key, value);
	}
	printf("\n");

	m2.Clear();

	m2[69] = "nice";

	printf("Map m2 after clearing and adding key 69:\n");
	for (auto [key, value, index] : m2)
	{
		printf("Index: %d, Key: %d, Value: %s\n", index, key, value);
	}
	printf("\n");

	if (m.Includes(m2))
	{
		printf("Map m includes map m2\n");
	}
	else
	{
		printf("Map m does not include map m2\n");
	}

	return 0;
}