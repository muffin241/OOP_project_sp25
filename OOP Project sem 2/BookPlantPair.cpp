#include <iostream>
#include <string>
#include "Books.h"
#include "Plant.h"
#include "BookPlantPair.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
//constructor
BookPlantPair::BookPlantPair(Books* b, Plant* p)
{
	book = b;
	plant = p;
}
//functions
void BookPlantPair::updateProgress(int pages)
{
	//updating the pages for book
	book->UpdateReadPages(pages);
	//updating display
	plant->updateGrowth(pages, book->gettotalPages());
}
void BookPlantPair::display(RenderWindow& window, Font& font)
{
    //defining a colour i wanna use
    sf::Color pastelPurple(177, 156, 217);

	Text titleText, authorText, genreText;
    titleText.setFont(font);
    titleText.setString("Title: " + book->getTitle());
    titleText.setCharacterSize(16);
    titleText.setFillColor(pastelPurple);
    titleText.setPosition(50, 50);

    authorText.setFont(font);
    authorText.setString("Author: " + book->getAuthor());
    authorText.setCharacterSize(16);
    authorText.setFillColor(pastelPurple);
    authorText.setPosition(50, 100);

    genreText.setFont(font);
    genreText.setString("Genre: " + book->getGenre());
    genreText.setCharacterSize(16);
    genreText.setFillColor(pastelPurple);
    genreText.setPosition(50, 150);

    window.draw(titleText);
    window.draw(authorText);
    window.draw(genreText);
    plant->draw(window);
}

void BookPlantPair::displayProgressBar(RenderWindow& window) 
{
    //get the pages
    int pagesRead = book->getPagesRead();
    int totalPages = book->gettotalPages();

    //dimensions for the bar
    float barWidth = 200.0f;
    float barHeight = 20.0f;
    float barXPos = 50.0f;
    float barYPos = 400.0f;

    //get float progress ratio while avoiding undefined conditions
    float progressRatio = 0.0f;
    if (totalPages != 0) {
        progressRatio = (pagesRead * 1.0f) / totalPages; // float result, no cast
    }

   //progress bar's background
    sf::RectangleShape backgroundBar(sf::Vector2f(barWidth, barHeight));
    backgroundBar.setFillColor(sf::Color(180, 180, 180));
    backgroundBar.setPosition(barXPos, barYPos);

    //the actual bar within it
    sf::RectangleShape progressBar(sf::Vector2f(barWidth * progressRatio, barHeight));
    progressBar.setFillColor(sf::Color::Green);
    progressBar.setPosition(barXPos, barYPos);

    window.draw(backgroundBar);
    window.draw(progressBar);
}

bool BookPlantPair::compareProgress(const BookPlantPair& second)const
{
    int firstRead = book->getPagesRead();
    int firstTotal = book->gettotalPages();
    int secondRead = second.book->getPagesRead();
    int secondTotal = second.book->gettotalPages();

    //returns true if first book has more progress
    return firstRead * secondTotal > secondRead * firstTotal;   //using cross multiplication logic
}