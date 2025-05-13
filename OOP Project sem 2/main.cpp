#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

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

    //create the beautifullll garden
    Garden myGarden(3);

   //create derived books
    Books* book1 = new Classic("Oliver Twist", "Charles Dickens", 544, 300, "It is because I think so much of warm and sensitive hearts, that I would spare them from being wounded.", false, 1, 5);
    Books* book2 = new Poetry("Devotions", "Mary Oliver", 480, 180, "Tell me, what is it you plan to do | with your one wild and precious life ? ", false, 2, 3);
    Books* book3 = new Nonfiction("The Gift: Creativity and the Artist in the Modern World", "Lewis Hyde", 464, 464, "The spirit of a gift is kept alive by its constant donation.", true, 3, 5);

    //create plants
    Plant* plant1 = new Flower();
    plant1->setThePlant();
    Plant* plant2 = new Vine();
    plant2->setThePlant();
    Plant* plant3 = new Tree();
    plant3->setThePlant();
   //create pairs 
    BookPlantPair* pair1 = new BookPlantPair(book1, plant1);
    BookPlantPair* pair2 = new BookPlantPair(book2, plant2);
    BookPlantPair* pair3 = new BookPlantPair(book3, plant3);

    //add pairs to garden
    myGarden.addPair(pair1);
    myGarden.addPair(pair2);
    myGarden.addPair(pair3);

    //print book's details
    book1->display();
    book2->display();
    book3->display();
    //update
    myGarden.updateReading(350, 0);  
    myGarden.updateReading(480, 1);  
    myGarden.updateReading(464, 2);  

    //print book's details
    book1->display();
    book2->display();
    book3->display();

    //SFML window loop
    while (window.isOpen()) {
        //bird sounds
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile("birds.wav")) {
            std::cout << "Error loading bird sound!" << std::endl;
            return -1;
        }

        sf::Sound birdSound;
        birdSound.setBuffer(buffer);
        birdSound.setLoop(true); 
        birdSound.play();

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