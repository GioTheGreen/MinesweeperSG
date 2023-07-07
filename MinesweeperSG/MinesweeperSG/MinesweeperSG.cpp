// MinesweeperSG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "game.h"

int main()
{
    game g;
    g.initialise();
    sf::RenderWindow window(sf::VideoMode(800, 800), "Gio's Minesweeper");
    sf::Image icon;
    if (!icon.loadFromFile("images\\MS_bomb.png"))
    {
        std::cout << "error no icon" << std::endl;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    sf::Event e;
    sf::Mouse m;
   
    bool rightpressed = 0;
    bool leftpressed = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }
        //gameloop here
        if (m.isButtonPressed(sf::Mouse::Left))
        {
            leftpressed = 1;
        }
        else if (!(m.isButtonPressed(sf::Mouse::Left)) && leftpressed)
        {
            g.pressed(m.getPosition(window));
            leftpressed = 0;
        }

        if (m.isButtonPressed(sf::Mouse::Right))
        {
            rightpressed = 1;
        }
        else if (!(m.isButtonPressed(sf::Mouse::Right)) && rightpressed)
        {
            g.flagged(m.getPosition(window));
            rightpressed = 0;
        }
        g.update();

        //draw

        std::vector<sf::RectangleShape> tempshapes = g.getShapes();
        window.clear(sf::Color(0,0,0,255));
        for (size_t i = 0; i < tempshapes.size(); i++)
        {
            //shapes[i].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
            window.draw(tempshapes[i]);
        }
        window.display();
    }
    return 0;
}


