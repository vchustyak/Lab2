#include "MyDoyble.h"
#include<iomanip>
#include<fstream>

MyDouble::MyDouble(double x, double y)
{
	this->SetX(x);
	this->SetY(y);
}

std::ostream& operator<<(std::ostream& os, const MyDouble& obj)
{
	os<<std::setw(20);
	os<<std::setprecision(5)<<obj.x<<" "<<obj.y<<std::endl;
	return os;
}

std::ifstream& operator>>(std::ifstream& is, MyDouble& obj)
{
	double x,y;
	is>>x>>y;
	obj.SetX(x);
	obj.SetY(y);
	return is;
}
bool MyDouble::operator<(const MyDouble& myDouble)
{
	return y<myDouble.y;
}

bool MyDouble::operator>=(const MyDouble& myDouble)
{
	return !(*this<myDouble);
}