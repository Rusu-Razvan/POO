#pragma once
using namespace std;
#include <iostream>
#include<vector>

class Sort
{
    vector<int> arr;

    // add data members
public:
    Sort(int elem_count, int min, int max);
    Sort(initializer_list<int> initList);
    Sort(const vector<int>& vec, int vecSize);
    Sort(int arg1, ...);
    //Sort(const char* s);
    // add constuctors
    void InsertSort(bool ascendent = false);
    void QuickSort( int st, int dr, bool ascendent = false );
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
