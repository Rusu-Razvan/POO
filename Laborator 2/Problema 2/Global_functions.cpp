#include "Global_functions.h"
#include "Student.h"
#include<iostream>

int Compare_Math_Grade(Student s1, Student s2) {

	if (s1.GetMathGrade() == s2.GetMathGrade())
		return 0;
	else if (s1.GetMathGrade() > s2.GetMathGrade())
		return 1;
	else return -1;

}

int Compare_English_Grade(Student s1, Student s2) {

	if (s1.GetEnglishGrade() == s2.GetEnglishGrade())
		return 0;
	else if (s1.GetEnglishGrade() > s2.GetEnglishGrade())
		return 1;
	else return -1;

}

int Compare_History_Grade(Student s1, Student s2) {

	if (s1.GetHistoryGrade() == s2.GetHistoryGrade())
		return 0;
	else if (s1.GetHistoryGrade() > s2.GetHistoryGrade())
		return 1;
	else return -1;

}

int Compare_Average(Student s1, Student s2) {

	if (s1.GetAverageGrade() == s2.GetAverageGrade())
		return 0;
	else if (s1.GetAverageGrade() > s2.GetAverageGrade())
		return 1;
	else return -1;

}

int Compare_Name(Student s1, Student s2)
{
	int s1_length = strlen(s1.GetName());
	int s2_length = strlen(s2.GetName());
	int length = s2_length;
	int i;
	

	if (s1_length < s2_length)
		length = s1_length;
	
	for (i = 0; i < length; i++)
		if (s1.GetName()[i] > s2.GetName()[i])
			return 1;
		else if (s1.GetName()[i] < s2.GetName()[i])
			return -1;

	if (s1_length == s2_length)
		return 0;
	else if (s1_length < s2_length) return -1;
	else return 1;



}

