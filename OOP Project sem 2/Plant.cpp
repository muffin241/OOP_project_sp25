#include "Plant.h"
#include <iostream>

Plant::Plant(const string& imageFile) : growthScale(1.0f) {
    if (!plantTexture.loadFromFile(imageFile)) {
        cerr << "Failed to load plant image." << endl;
    }
    plantSprite.setTexture(plantTexture);
    plantSprite.setScale(growthScale, growthScale);
}

void Plant::setPosition(float x, float y) {
    plantSprite.setPosition(x, y);
}

void Plant::draw(sf::RenderWindow& window) {
    window.draw(plantSprite);
}

void Plant::grow() {
    growthScale += 0.05f; // increase growth scale
    plantSprite.setScale(growthScale, growthScale);
}

void Plant::updateMood(int finishedBooks) {
    if (finishedBooks >= 5) {
        plantSprite.setColor(sf::Color::Green); // healthy plant
    }
    else if (finishedBooks >= 2) {
        plantSprite.setColor(sf::Color(150, 255, 150)); // medium mood
    }
    else {
        plantSprite.setColor(sf::Color(200, 200, 200)); // dull for low progress
    }
}

sf::FloatRect Plant::getBounds() const {
    return plantSprite.getGlobalBounds();
}
