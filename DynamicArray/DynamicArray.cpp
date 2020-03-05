#include "DynamicArray.h"

DynamicArray DynamicArray::operator=(const DynamicArray& da)
{
	if (this->pArray != NULL)
		delete[] this->pArray;
	this->pArray = new MyDouble[da.GetLength()];
	this->length = da.GetLength();
	this->currentIndex = da.currentIndex;
	for (int i = 0; i < length; i++)
		this->pArray[i] = MyDouble(da.pArray[i].GetX(), da.pArray[i].GetY());
	return *this;
}

DynamicArray::DynamicArray(void)
{
	pArray=NULL;
	length=0;
	currentIndex = -1;
}

DynamicArray::DynamicArray(const DynamicArray& dynamicArray)
{
	if (dynamicArray.length == 0)
	{
		pArray = NULL;
		length = 0;
		currentIndex = -1;
		return;
	}
	this->pArray=new MyDouble[dynamicArray.length];
	length=dynamicArray.length;
	for (int i=0;i<length;i++)
	{
		this->pArray[i]=dynamicArray.pArray[i];
	}
	currentIndex = dynamicArray.currentIndex;
}

DynamicArray::DynamicArray(int length)
{
	pArray=new MyDouble[length];
	this->length=length;
	currentIndex = 0;
}

MyDouble& DynamicArray::operator[](int index)
{
	if (index>=0 && index<length)
		return this->pArray[index];
}

DynamicArray::~DynamicArray(void)
{
	if (pArray!=NULL)
		delete [] pArray;
	length=0;
	currentIndex = -1;
}
std::ostream& operator<<(std::ostream& os, const DynamicArray& da)
{
	os<<"Length is "<<da.length<<" elements\n";
	for (int i=0;i<da.length;i++)
		os<<da.pArray[i];
	return os;
}

bool DynamicArray::Add(const MyDouble& myDouble)
{
	if (currentIndex < length)
	{
		pArray[currentIndex++] = myDouble;
		return true;
	}
	else
	{
		DynamicArray da(this->length+1);
		for (int i = 0; i < length; i++)
			da[i] = (*this)[i];
		da.currentIndex = this->currentIndex;
		da[da.currentIndex++]=myDouble;
		delete[] this->pArray;
		this->pArray = new MyDouble[da.length];
		for (int i = 0; i < da.length; i++)
			this->pArray[i] = da.pArray[i];
		this->currentIndex = da.currentIndex;
		this->length = da.length;
	}
}
