#pragma once
#include <iostream>
#include <string>
#include "Books.h"
#include "Plant.h"
class BookPlantPair
{
private:
	Books* book;
	Plant* plant;
public:
	BookPlantPair(Books* , Plant* );
	void updateProgress(int );
	void display(RenderWindow&, Font&, float);
	void displayProgressBar(RenderWindow&, float);
	bool compareProgress(const BookPlantPair& )const ;
	~BookPlantPair()
	{
		delete book;
		delete plant;
	}
};