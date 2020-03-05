#pragma once
#include <iostream>
class MyDouble
{
private:
	double x;
	double y;
public:
	MyDouble(double x=0, double y=0);
	double GetX(){return x;} const
	double GetY(){return y;} const
	void SetX(double x){this->x=x;}
	void SetY(double y){this->y=y;}
	friend std::ostream& operator<<(std::ostream& os, const MyDouble& obj);
	friend std::ifstream& operator>>(std::ifstream& is, MyDouble& obj);
	bool operator<(const MyDouble& myDouble);
	bool operator>=(const MyDouble& myDouble);

	
};

