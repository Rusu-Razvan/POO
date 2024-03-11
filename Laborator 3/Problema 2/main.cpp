#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {

	Canvas canvas(50, 50);

	canvas.DrawCircle(25, 25, 10, '@');
	canvas.Print();
	canvas.Clear();

	canvas.FillCircle(25, 25, 10, '@');
	canvas.Print();
	canvas.Clear();

	canvas.DrawRect(5, 15, 49,30,'@');
	canvas.Print();
	canvas.Clear();


	canvas.FillRect(5, 15, 49, 30, '@');
	canvas.Print();
	canvas.Clear();

	canvas.SetPoint(14, 17, '@');
	canvas.Print();
	canvas.Clear();
	
	canvas.DrawLine(15, 2, 40, 32, '@');
	canvas.Print();
	canvas.Clear();

	return 0;
}