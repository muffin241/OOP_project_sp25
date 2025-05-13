#include "Plant.h"
#include <iostream>

Plant::Plant() 
{
    size = 0.02f;
}

void Plant::setThePlant(const string& filename) 
{
    if (!plantImage.loadFromFile(filename)) {
        cerr << "Could not load: " << filename << endl;
    }
    plantAppearance.setTexture(plantImage);
    plantAppearance.setScale(size, size);
}

void Plant::setPosition(float x, float y) 
{
    posX = x;
    posY = y;
    plantAppearance.setPosition(posX, posY);
}

void Plant::draw(RenderWindow& window) 
{
    window.draw(plantAppearance);
}

void Plant::updateGrowth(int pagesRead, int totalPages) 
{
    int ReadPercent = 0;
    if (totalPages != 0)
    {
        ReadPercent = (pagesRead * 100) / totalPages;
    }
    if (ReadPercent == 100)
    {
        size = 0.4f;
    }
    else if (ReadPercent >= 90)
    {
        size = 0.2f;
    }
    else if (ReadPercent >= 70)
    {
        size = 0.1f;
    }
    else if (ReadPercent >= 50)
    {
        size = 0.05f;
    }
    else
    {
        size = 0.03f;
    }

    plantAppearance.setScale(size, size); 
}

//derived class's constructors
//no implementation in them rn
Flower::Flower() : Plant() {}
Tree::Tree() : Plant() {}
Vine::Vine() : Plant() {}

//overloading setThePlant for the derived class
void Flower::setThePlant()
{
    if (!plantImage.loadFromFile("flower.png")) {
        cerr << "Could not load: " << "flower.png" << endl;
    }
    plantAppearance.setTexture(plantImage);
    plantAppearance.setScale(size, size);
}

void Tree::setThePlant()
{
    if (!plantImage.loadFromFile("flower.png")) {
        cerr << "Could not load: " << "tree.png" << endl;
    }
    plantAppearance.setTexture(plantImage);
    plantAppearance.setScale(size, size);
}

void Vine::setThePlant()
{
    if (!plantImage.loadFromFile("vine.png")) {
        cerr << "Could not load: " << "vine.png" << endl;
    }
    plantAppearance.setTexture(plantImage);
    plantAppearance.setScale(size, size);
}


