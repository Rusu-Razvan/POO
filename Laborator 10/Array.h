#pragma once
#include<iostream>
#include<exception>
using namespace std;

//I have to implement the methods and also the exceptions

class IndexOutOfBoundsException : public exception {
public:
    virtual const char* what() const throw() {
        return "Index out of bounds!\n";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {
        Capacity = 0;
        Size = 0;
    }// Lista nu e alocata, Capacity si Size = 0

    ~Array() {
        delete[] List;
    }// destructor

    Array(int capacity) {
        T** List = new T * [capacity];
    }// Lista e alocata cu 'capacity' elemente

    Array(const Array<T>& otherArray) {
        // copy constructor
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = otherArray.List[i];

    }// constructor de copiere

    T& operator[] (int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        return *List[index];
    }// arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem) {

        if (Size == Capacity) {
            int newCapacity = Capacity + 1;
            T** newList = new T * [newCapacity];

            for (int i = 0; i < Size; ++i) {
                newList[i] = List[i];
            }

            delete[] List;
            List = newList;
            Capacity = newCapacity;
        }

        List[Size] = new T(newElem);
        Size++;
        return *this;
    }/// adauga un element de tipul T la sfarsitul listei si returneaza this

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        for (int i = Size; i > index; i--)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        Size++;
        return *this;
    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        if (Size + otherArray.Size > Capacity)
            throw IndexOutOfBoundsException();
        for (int i = Size + otherArray.Size - 1; i >= index + otherArray.Size; i--)
            List[i] = List[i - otherArray.Size];
        for (int i = 0; i < otherArray.Size; i++)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        delete List[index];
        for (int i = index; i < Size - 1; i++)
            List[i] = List[i + 1];
        Size--;
        return *this;
    }// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray)
            return false;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++)
            List[i] = otherArray.List[i];
        return true;
    }// operator de atribuire

    void Sort() {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (*List[i] > *List[j])
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
        // sorteaza folosind operator<
    }// sorteaza folosind comparatia intre elementele din T

    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (compare(*List[i], *List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }

    }// sorteaza folosind o functie de comparatie

    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++)
            for (int j = i + 1; j < Size; j++)
                if (comparator->CompareElements(List[i], List[j]) > 0)
                {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }

    }// sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (*List[mid] == elem)
                return mid;
            if (*List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }// cauta un element folosind binary search in Array

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (compare(*List[mid], elem) == 0)
                return mid;
            if (compare(*List[mid], elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;

    }//  cauta un element folosind binary search si o functie de comparatie

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (comparator->CompareElements(List[mid], &elem) == 0)
                return mid;
            if (comparator->CompareElements(List[mid], &elem) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }//  cauta un element folosind binary search si un comparator

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++)
            if (*List[i] == elem)
                return i;
        return -1;
    }// cauta un element in Array

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++)
            if (compare(*List[i], elem) == 0)
                return i;
        return -1;
    }//  cauta un element folosind o functie de comparatie

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++)
            if (comparator->CompareElements(List[i], &elem) == 0)
                return i;
        return -1;
    }//  cauta un element folosind un comparator

    int GetSize() {
        return Size;
    }

    int GetCapacity() {
        return Capacity;
    }

};