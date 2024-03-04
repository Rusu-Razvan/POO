#include<iostream>
#include "Student.h"
#include "Global_functions.h"
using namespace std;

int main()
{
	Student student1;
	Student student2;
	

	student1.SetName((char*)"ab");
	student1.SetMathGrade(5.6);
	student1.SetEnglishGrade(10);
	student1.SetHistoryGrade(7);

	student2.SetMathGrade(5);
	student2.SetName((char*)"abd");

	cout << Compare_Name(student1, student2);
	cout << endl;

	cout << student1.GetName() << ' ' << student1.GetMathGrade()<<' ' << student1.GetEnglishGrade() << ' ' << student1.GetHistoryGrade() << ' ' << student1.GetAverageGrade();


	return 0;
}