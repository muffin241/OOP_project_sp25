//#pragma once
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class Plant
//{
//private:
//	
//};
//
////fiction
//class Flower : public Plant
//{
//
//};
////non fiction
//class Tree : public Plant
//{
//
//};
////poetry
//class Fruit : public Plant
//{
//
//};

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Plant {
private:

    Texture plantTexture;
    Sprite plantSprite;
    float growthScale; // scale factor for growth

public:
    Plant(const string& imageFile);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
    void grow(); // increases size to show growth
    void updateMood(int finishedBooks); // modifies appearance based on book progress
    FloatRect getBounds() const; // for interaction if needed
};

