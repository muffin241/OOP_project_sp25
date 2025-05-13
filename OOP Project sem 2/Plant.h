#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class Plant
{
protected:
	Texture plantImage;
	Sprite plantAppearance;
	float size;
	float posX;
	float posY;
public:
	Plant();
	virtual void setThePlant();
	void setPosition(float, float);
	void draw(RenderWindow&);
	void updateGrowth(int, int);
};

//fiction
class Flower : public Plant
{
public:
	Flower();
	void setThePlant();
};
//non fiction
class Tree : public Plant
{
public:
	Tree();
	void setThePlant();
};
//poetry
class Vine : public Plant
{
public:
	Vine();
	void setThePlant();
};


