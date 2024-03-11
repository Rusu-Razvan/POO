#include "Canvas.h"
#include <cmath>
#include <iostream>

Canvas::Canvas(int width, int height) : width(width), height(height) {
	
		canvas = new char* [height];
		for (unsigned i = 0; i < height; i++) {
			canvas[i] = new char[width];
		}
	
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				canvas[i][j] = ' ';

}

Canvas::~Canvas() {
	for (unsigned i = 0; i < height; ++i) {
		delete[] canvas[i];
	}

	delete[] canvas;
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (x >= 0 && x < width && y >= 0 && y < height)
		canvas[y][x] = ch;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (pow(j - x, 2) + pow(i - y, 2) >= pow(ray, 2)-1.2*ray 
				&& pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2)+1.2*ray && i >= 0 && j >= 0 && i < height && j < width)
				canvas[i][j] = ch;
  
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2)-1.2*ray
				&& pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2) + 1.2 * ray && i >= 0 && j >= 0 && i < height && j < width)
				canvas[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			if (i == top or i == bottom or j == left or j == right)
				canvas[i][j] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
				canvas[i][j] = ch;
}



void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {
	

	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (true)
	{
		SetPoint(x0, y0, ch);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if (e2 >= dy)
			if (x0 == x1) break;
		{error = error + dy;
			x0 = x0 + sx;
		}
		if (e2 <= dx)
			if (y0 == y1) break;
		{error = error + dx;
		y0 = y0 + sy;
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			std::cout << canvas[i][j];
		std::cout << std::endl;
	}
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			canvas[i][j] = ' ';
}