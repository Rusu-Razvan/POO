#pragma once

class Student {
private:
	char Name[256];
	float MathGrade;
	float EnglishGrade;
	float HistoryGrade;
	float Average;

public:
	void SetName(char* name);
	char* GetName();

	void SetMathGrade(float grade);
	float GetMathGrade();

	void SetEnglishGrade(float grade);
	float GetEnglishGrade();

	void SetHistoryGrade(float grade);
	float GetHistoryGrade();

	float GetAverageGrade();


};
