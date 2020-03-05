#pragma once
#include "MyDoyble.h"
class DynamicArray
{
private:
	MyDouble* pArray;
	int length;
	int currentIndex;
public:
	int GetLength() const { return length; }
	DynamicArray(void);
	DynamicArray(const DynamicArray& pDynamicArray);
	DynamicArray(int length);
	
	bool Add(const MyDouble& myDouble);
	
	MyDouble& operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, const DynamicArray& da);
	DynamicArray operator=(const DynamicArray& da);

	void sort();
	int CountElementsInInterval(double a, double b);
	~DynamicArray(void);
};

