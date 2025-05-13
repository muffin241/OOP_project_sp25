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
	void display(RenderWindow&, Font&);
	void displayProgressBar(RenderWindow&);
	bool compareProgress(const BookPlantPair& )const ;
};