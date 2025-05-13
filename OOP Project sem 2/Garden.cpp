#include <iostream>
#include "Garden.h"

Garden::Garden(int c)
{
	capacity = c;
	current = 0;
	pairs = new BookPlantPair*[capacity];

}

void Garden::addPair(BookPlantPair* pair)
{
	if (current < capacity)
	{
		pairs[current++] = pair;
	}
}
void Garden::updateReading(int pages, int index)
{
	pairs[index]->updateProgress(pages);
}

// Display all pairs with vertical spacing
void Garden::display(RenderWindow& window, Font& font)
{
	float offsetY = 0.0f;
	for (int i = 0; i < current; i++) {
		pairs[i]->display(window, font, offsetY);
		offsetY += 300; 
	}
}