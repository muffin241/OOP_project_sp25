#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Books.h"
#include "Plant.h"
using namespace std;
using namespace sf;

int main()
{
   
    Font font;
    if (!font.loadFromFile("PlayfairDisplay-Regular.otf")) {
        cout << "Error loading font!" << endl;
        return -1;
    }

    // Create a Fantasy book
    Fantasy myBook("The Hobbit", "J.R.R. Tolkien", 310, 150, "In a hole in the ground there lived a hobbit.", false, 1, 5);

    // Create a plant for Fantasy books
    Flower myPlant;
    myPlant.setThePlant( ); 
    myPlant.setPosition(100, 250);     // Positioning the plant
    myPlant.updateGrowth(myBook.getPagesRead(), myBook.gettotalPages());

    RenderWindow window(VideoMode(1000, 1000), "Book Tracker");

    Text titleText, authorText, genreText;

    titleText.setFont(font);
    titleText.setString("Title: " + myBook.getTitle());
    titleText.setCharacterSize(24);
    titleText.setFillColor(Color::Black);
    titleText.setPosition(50, 50);

    authorText.setFont(font);
    authorText.setString("Author: " + myBook.getAuthor());
    authorText.setCharacterSize(24);
    authorText.setFillColor(Color::Black);
    authorText.setPosition(50, 100);

    genreText.setFont(font);
    genreText.setString("Genre: " + myBook.getGenre());
    genreText.setCharacterSize(24);
    genreText.setFillColor(Color::Black);
    genreText.setPosition(50, 150);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(titleText);
        window.draw(authorText);
        window.draw(genreText);
        myPlant.draw(window); // draw plant
        window.display();
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
	return 0;
}