#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Books.h"
#include "Plant.h"
#include "BookPlantPair.h"
using namespace std;
using namespace sf;

int main()
{
    Font font;
    if (!font.loadFromFile("PlayfairDisplay-Regular.otf")) {
        cout << "Error loading font!" << endl;
        return -1;
    }

   //creating window
    RenderWindow window(VideoMode(800, 600), "Book Plant Tracker");

   //creating objects
    Fantasy* fantasyBook = new Fantasy("The Hobbit", "Tolkien", 300, 100, "Quote", false, 1, 5);
    Mystery* mysteryBook = new Mystery("Sherlock Holmes", "Arthur Conan Doyle", 250, 50, "Another quote", false, 2, 4);

    //creating the plants for them
    Flower* flower = new Flower();
    Tree* tree = new Tree();

    flower->setThePlant();
    tree->setThePlant();

    flower->setPosition(500, 100);
    tree->setPosition(500, 300);

    //printing book's data on terminal
    fantasyBook->display();
    mysteryBook->display();

    //creating pairs
    BookPlantPair pair1(fantasyBook, flower);
    BookPlantPair pair2(mysteryBook, tree);

    //updating
    pair1.updateProgress(100); 
    pair2.updateProgress(120); 

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        pair1.display(window, font);
        pair1.displayProgressBar(window);

        pair2.display(window, font);
        pair2.displayProgressBar(window);

        window.display();
    }

    // Cleanup
    delete fantasyBook;
    delete mysteryBook;
    delete flower;
    delete tree;

    return 0;
}