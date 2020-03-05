#pragma once
#include "DynamicArray.h"
#include<cmath>
#include<iostream>
class Tabul
{
private:
	double a;
	double b;
	double h;
	DynamicArray* dynamicArray;
	double function(double x)
	{
		return sin(x);
	}
	static int pageSize;
public:
	Tabul(double a, double b, double h);
	~Tabul();
	void tabulyuvannya();	
	void PrintResults();
};


