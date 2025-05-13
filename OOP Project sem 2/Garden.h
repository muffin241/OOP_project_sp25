#pragma once
#include <iostream>
#include <string>
#include "BookPlantPair.h"
class Garden
{
private:
	BookPlantPair** pairs;
	int capacity;                      //max
	int current;                   //current number of objects stored

public:
	Garden(int);
	void addPair(BookPlantPair* );
	void display(RenderWindow&, Font&);
	void updateReading(int, int);
	~Garden()
	{
		for (int i = 0; i < current; i++)
		{
			delete pairs[i];
		}
		delete[]pairs;
	}
};