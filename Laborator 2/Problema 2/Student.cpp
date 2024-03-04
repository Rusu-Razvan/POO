#include "Student.h"
#include<cstring>

void Student::SetName(char* name) {
	int length = strlen(name);
	for (int i = 0; i < length; i++)
		this->Name[i] = name[i];
	for (int i = length; i < 256; i++)
		this->Name[i] = '\0';
}

char* Student::GetName() {
	return this->Name;
}

void Student::SetMathGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		this->MathGrade = grade;
}

float Student::GetMathGrade() {
	return this->MathGrade;
}

float Student::GetEnglishGrade() {
	return this->EnglishGrade;
}

void Student::SetEnglishGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		this->EnglishGrade = grade;
}


void Student::SetHistoryGrade(float grade) {
	if (grade >= 1 && grade <= 10)
		this->HistoryGrade = grade;
}

float Student::GetHistoryGrade() {
	return this->HistoryGrade;
}

float Student::GetAverageGrade() {
	 this->Average = (this->MathGrade + this->EnglishGrade + this->HistoryGrade) / 3.0;
	return this->Average;
}
