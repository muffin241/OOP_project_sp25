#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Books.h"
using namespace std;
using namespace sf;

int main()
{
   
    //adding the font file for text
    Font font;
    //if an error occurs in loading font then exit and show the error message
    if (!font.loadFromFile("PlayfairDisplay-Regular.otf")) {
        cout << "Error loading font!" << endl;
        return -1;
    }

    //// Creating objects using the derived classes
    //Fantasy fantasyBook("The Hobbit", "J.R.R. Tolkien", 310, 200, "Not all those who wander are lost.", false, 1, 5);
    //Mystery mysteryBook("The Girl with the Dragon Tattoo", "Stieg Larsson", 465, 465, "What she had realized was that love was that moment.", true, 2, 4);
    //Poetry poetryBook("Milk and Honey", "Rupi Kaur", 204, 80, "what is stronger / than the human heart / which shatters over and over", false, 3, 3);

    //// Displaying details
    //cout << "Genre: " << fantasyBook.getGenre() << endl;
    //fantasyBook.display();
    //cout << endl;

    //cout << "Genre: " << mysteryBook.getGenre() << endl;
    //mysteryBook.display();
    //cout << endl;

    //cout << "Genre: " << poetryBook.getGenre() << endl;
    //poetryBook.display();
    //cout << endl;

    //// Marking one as finished
    //poetryBook.markAsFinished();
    //poetryBook.display();

    // Create a book object (example: Fiction book)
    Fantasy myBook("The Hobbit", "J.R.R. Tolkien", 310, 150, "In a hole in the ground there lived a hobbit.", false, 1, 5);

    // Create SFML window
    RenderWindow window(sf::VideoMode(800, 600), "Book Tracker");

    // Set up text elements
    Text titleText;
    titleText.setFont(font);
    titleText.setString("Title: " + myBook.getTitle());
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Black);
    titleText.setPosition(50, 50);

    Text authorText;
    authorText.setFont(font);
    authorText.setString("Author: " + myBook.getAuthor());
    authorText.setCharacterSize(24);
    authorText.setFillColor(sf::Color::Black);
    authorText.setPosition(50, 100);

    Text genreText;
    genreText.setFont(font);
    genreText.setString("Genre: " + myBook.getGenre());
    genreText.setCharacterSize(24);
    genreText.setFillColor(sf::Color::Black);
    genreText.setPosition(50, 150);

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(titleText);
        window.draw(authorText);
        window.draw(genreText);
        window.display();
    }


	return 0;
}