#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Books.h"
#include "Plant.h"
#include "BookPlantPair.h"
#include "Garden.h"
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
    RenderWindow window(VideoMode(1500, 900), "My Reading Bloom");

    // Create Garden
    Garden myGarden(3);

    // Create derived book types
    Books* book1 = new Fantasy("The Hobbit", "J.R.R. Tolkien", 310, 50, "In a hole in the ground there lived a hobbit.", false, 1, 5);
    Books* book2 = new Mystery("The Hound of the Baskervilles", "Arthur Conan Doyle", 256, 180, "The world is full of obvious things.", false, 2, 4);
    Books* book3 = new CrimeFiction("Gone Girl", "Gillian Flynn", 422, 422, "Love makes you want to be a better man. But maybe love, real love, also gives you permission to just be the man you are.", true, 3, 5);

    // Create plants
    Plant* plant1 = new Plant();
    Plant* plant2 = new Plant();
    Plant* plant3 = new Plant();

    // Create BookPlantPairs
    BookPlantPair* pair1 = new BookPlantPair(book1, plant1);
    BookPlantPair* pair2 = new BookPlantPair(book2, plant2);
    BookPlantPair* pair3 = new BookPlantPair(book3, plant3);

    // Add to Garden
    myGarden.addPair(pair1);
    myGarden.addPair(pair2);
    myGarden.addPair(pair3);

    // Simulate progress updates
    myGarden.updateReading(100, 0);  // now Hobbit has 100 read
    myGarden.updateReading(256, 1);  // now Mystery book finished
    myGarden.updateReading(422, 2);  // already finished

    // SFML window loop
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        myGarden.display(window, font);
        window.display();
    }

    return 0;



}