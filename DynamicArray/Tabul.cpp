#include "Tabul.h"

int Tabul::pageSize=13;
Tabul::Tabul(double a, double b, double h)
{	
	if (a<b)
	{
		this->a=a;
		this->b=b;
	}
	else
	{
		this->a=b;
		this->b=a;
	}
	this->h=h;
	dynamicArray = new DynamicArray(10);
}


Tabul::~Tabul(void)
{
	if (dynamicArray != NULL)
	{
		delete dynamicArray;
	}
}

void Tabul::tabulyuvannya()
{
	int currentIndex = 0;
	for (long double i=a;i<=b;i+=h)
	{
		MyDouble myDouble(i,function(i));
		dynamicArray->Add(myDouble);
	}
}

void Tabul::PrintResults()
{
	for (int i=1;i<=dynamicArray->GetLength();i++)
	{
		std::cout<<(*dynamicArray)[i-1];
		if (i%Tabul::pageSize==0)
		{
			std::cout<<"Press any key to continue";
			std::cin.get();
			system("cls");
		}
	}
}


