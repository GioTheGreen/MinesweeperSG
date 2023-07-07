#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include <list>

enum tile
{
	bomb, blank, one, two, three, four, five, six, seven, eight, hidden, flag
};

class game
{
private:
	const int col{ 40 }, row{ 40 };
	int boxsize{ 20 };
	int bombs{ 200 };
    int flags{ 0 };
	tile map[40][40];
    tile show[40][40];

    sf::Texture ig_hidden;
    sf::Texture ig_flag;
    sf::Texture ig_bomb;
    sf::Texture ig_n0;
    sf::Texture ig_n1;
    sf::Texture ig_n2;
    sf::Texture ig_n3;
    sf::Texture ig_n4;
    sf::Texture ig_n5;
    sf::Texture ig_n6;
    sf::Texture ig_n7;
    sf::Texture ig_n8;

    std::vector<sf::RectangleShape> shapes;
public:
	void initialise();
    void update();
    std::vector<sf::RectangleShape> getShapes();
    void check(std::list<sf::Vector2i> l);
    void pressed(sf::Vector2i pos);
    void flagged(sf::Vector2i pos);
    void endGame(bool win);
};

