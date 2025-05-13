#include <iostream>

#include "Books.h"
#include "Plant.h"
#include "BookPlantPair.h"
#include <SFML/Graphics.hpp>

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


bool BookPlantPair::compareProgress(const BookPlantPair& second)const
{
    int firstRead = book->getPagesRead();
    int firstTotal = book->gettotalPages();
    int secondRead = second.book->getPagesRead();
    int secondTotal = second.book->gettotalPages();

    //returns true if first book has more progress
    return firstRead * secondTotal > secondRead * firstTotal;   //using cross multiplication logic
}

void BookPlantPair::display(RenderWindow& window, Font& font, float offsetY)
{
    //plant
    plant->setPosition(600, offsetY + 20);
    plant->draw(window);

    //defining the color to use
    sf::Color pastelPurple(177, 156, 217);

    //create and set text for title, author, and genre
    Text titleText, authorText, genreText;
    titleText.setFont(font);
    titleText.setString("Title: " + book->getTitle());
    titleText.setCharacterSize(20);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(50, offsetY + 10);  //adjusting vertical position with offset y

    authorText.setFont(font);
    authorText.setString("Author: " + book->getAuthor());
    authorText.setCharacterSize(18);
    authorText.setFillColor(pastelPurple);
    authorText.setPosition(50, 40 + offsetY);  //adjusting vertical position with offset y

    genreText.setFont(font);
    genreText.setString("Genre: " + book->getGenre());
    genreText.setCharacterSize(18);
    genreText.setFillColor(pastelPurple);
    genreText.setPosition(50, 70 + offsetY);  //adjusting vertical position with offset y

    //draw texts on window
    window.draw(titleText);
    window.draw(authorText);
    window.draw(genreText);
    
    //progress bars
    displayProgressBar(window, offsetY);
}

void BookPlantPair::displayProgressBar(RenderWindow& window, float offsetY)
{
    //getting pages
    int pagesRead = book->getPagesRead();
    int totalPages = book->gettotalPages();

    float barWidth = 200.0f;
    float barHeight = 20.0f;
    float barXPos = 50.0f;
    float barYPos = 180.0f + offsetY;  //adjusting vertical position with offset y

    //get float progress ratio while avoiding undefined conditions
    float progressRatio = 0.0f;
    if (totalPages != 0) {
        progressRatio = (pagesRead * 1.0f) / totalPages;
    }

    //progress bar background
    sf::RectangleShape backgroundBar(sf::Vector2f(barWidth, barHeight));
    backgroundBar.setFillColor(sf::Color(180, 180, 180));
    backgroundBar.setPosition(barXPos, barYPos);

    //the actual progress bar
    sf::RectangleShape progressBar(sf::Vector2f(barWidth * progressRatio, barHeight));
    progressBar.setFillColor(sf::Color::Green);
    progressBar.setPosition(barXPos, barYPos);

    //draw
    window.draw(backgroundBar);
    window.draw(progressBar);
}