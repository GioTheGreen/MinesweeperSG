#include "game.h"

void game::initialise()
{
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            map[i][j] = blank;
            show[i][j] = hidden;
        }
    }
    int tempbombs = bombs;
    while (tempbombs > 0)
    {
        int tempx = (rand() % col);
        int tempy = (rand() % row);
        if (map[tempx][tempy] != bomb)
        {
            map[tempx][tempy] = bomb;
            tempbombs--;
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (map[i][j] != bomb)
            {
                int prebombs = 0;
                bool left = (i - 1 >= 0);
                bool right = (i + 1 <= (col - 1));
                bool up = (j - 1 >= 0);
                bool down = (j + 1 <= (row - 1));

                if (left && map[i - 1][j] == bomb)
                    prebombs++;
                if (right && map[i + 1][j] == bomb)
                    prebombs++;
                if (up && map[i][j - 1] == bomb)
                    prebombs++;
                if (down && map[i][j + 1] == bomb)
                    prebombs++;
                if (left && up && map[i - 1][j - 1] == bomb)
                    prebombs++;
                if (left && down && map[i - 1][j + 1] == bomb)
                    prebombs++;
                if (right && up && map[i + 1][j - 1] == bomb)
                    prebombs++;
                if (right && down && map[i + 1][j + 1] == bomb)
                    prebombs++;

                map[i][j] = tile(prebombs + 1);
            }
        }
    }

    if (!ig_hidden.loadFromFile("images\\MS_hidden.png"))
    {
        std::cout << "failed to load MS_hidden";
    }
    if (!ig_flag.loadFromFile("images\\MS_flag.png"))
    {
        std::cout << "failed to load MS_flag";
    }
    if (!ig_bomb.loadFromFile("images\\MS_bomb.png"))
    {
        std::cout << "failed to load MS_bomb";
    }
    if (!ig_n0.loadFromFile("images\\MS_0.png"))
    {
        std::cout << "failed to load MS_0";
    }
    if (!ig_n1.loadFromFile("images\\MS_1.png"))
    {
        std::cout << "failed to load MS_1";
    }
    if (!ig_n2.loadFromFile("images\\MS_2.png"))
    {
        std::cout << "failed to load MS_2";
    }
    if (!ig_n3.loadFromFile("images\\MS_3.png"))
    {
        std::cout << "failed to load MS_3";
    }
    if (!ig_n4.loadFromFile("images\\MS_4.png"))
    {
        std::cout << "failed to load MS_4";
    }
    if (!ig_n5.loadFromFile("images\\MS_5.png"))
    {
        std::cout << "failed to load MS_5";
    }
    if (!ig_n6.loadFromFile("images\\MS_6.png"))
    {
        std::cout << "failed to load MS_6";
    }
    if (!ig_n7.loadFromFile("images\\MS_7.png"))
    {
        std::cout << "failed to load MS_7";
    }
    if (!ig_n8.loadFromFile("images\\MS_8.png"))
    {
        std::cout << "failed to load MS_8";
    }

    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(boxsize, boxsize));
            rect.setPosition(i * boxsize, j * boxsize);
            //rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
            /*if (show[i][j] == bomb)
            {
                rect.setTexture(&ig_bomb);
            }
            else if (show[i][j] == one)
            {
                rect.setTexture(&ig_n1);
            }
            else if (show[i][j] == two)
            {
                rect.setTexture(&ig_n2);
            }
            else if (show[i][j] == three)
            {
                rect.setTexture(&ig_n3);
            }
            else if (show[i][j] == four)
            {
                rect.setTexture(&ig_n4);
            }
            else if (show[i][j] == five)
            {
                rect.setTexture(&ig_n5);
            }
            else if (show[i][j] == six)
            {
                rect.setTexture(&ig_n6);
            }
            else if (show[i][j] == seven)
            {
                rect.setTexture(&ig_n7);
            }
            else if (show[i][j] == eight)
            {
                rect.setTexture(&ig_n8);
            }
            else if (show[i][j] == hidden)
            {
                rect.setTexture(&ig_hidden);
            }
            else if (show[i][j] == flag)
            {
                rect.setTexture(&ig_flag);
            }
            else
            {
                rect.setTexture(&ig_n0);
            }*/
            rect.setTexture(&ig_hidden);

            shapes.push_back(rect);
        }

    }
}

void game::update()
{
    shapes.clear();
    int checked{ 0 };
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            sf::RectangleShape rect;
            rect.setSize(sf::Vector2f(boxsize, boxsize));
            rect.setPosition(i * boxsize, j * boxsize);
            //rect.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
            if (show[i][j] == bomb)
            {
                rect.setTexture(&ig_bomb);
                endGame(0);
            }
            else if (show[i][j] == one)
            {
                rect.setTexture(&ig_n1);
            }
            else if (show[i][j] == two)
            {
                rect.setTexture(&ig_n2);
            }
            else if (show[i][j] == three)
            {
                rect.setTexture(&ig_n3);
            }
            else if (show[i][j] == four)
            {
                rect.setTexture(&ig_n4);
            }
            else if (show[i][j] == five)
            {
                rect.setTexture(&ig_n5);
            }
            else if (show[i][j] == six)
            {
                rect.setTexture(&ig_n6);
            }
            else if (show[i][j] == seven)
            {
                rect.setTexture(&ig_n7);
            }
            else if (show[i][j] == eight)
            {
                rect.setTexture(&ig_n8);
            }
            else if (show[i][j] == hidden)
            {
                rect.setTexture(&ig_hidden);
            }
            else if (show[i][j] == flag)
            {
                rect.setTexture(&ig_flag);
                if (map[i][j] == bomb)
                {
                    checked++;
                }
            }
            else
            {
                rect.setTexture(&ig_n0);
            }

            shapes.push_back(rect);
        }
    }
    if (bombs == checked)
    {
        endGame(1);
    }
}

std::vector<sf::RectangleShape> game::getShapes()
{
    return shapes;
}

void game::check(std::list<sf::Vector2i> l)
{   
    while (!l.empty())
    {
        bool left = (l.front().x - 1 >= 0);
        bool right = (l.front().x + 1 <= (col - 1));
        bool up = (l.front().y - 1 >= 0);
        bool down = (l.front().y + 1 <= (row - 1));
        const sf::Vector2i vec = l.front();
        l.pop_front();
        //if (vec.x >= 0 && vec.x <= (col - 1) && vec.y >= 0 && vec.y <= (row - 1))        i dont know if needed
        //if (map[int(vec.x)][int(vec.y)] == one)
        //{
        show[int(vec.x)][int(vec.y)] = map[int(vec.x)][int(vec.y)];
        //}
        if (show[int(vec.x)][int(vec.y)] == bomb)
        {
            //endGame();
        }
        else if (show[int(vec.x)][int(vec.y)] == blank)
        {
            if (left && show[vec.x - 1][vec.y] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x - 1, vec.y)) != l.end()))
                l.push_back(sf::Vector2i(vec.x - 1, vec.y));
            if (right && show[vec.x + 1][vec.y] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x + 1, vec.y)) != l.end()))
                l.push_back(sf::Vector2i(vec.x + 1, vec.y));
            if (up && show[vec.x][vec.y - 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x, vec.y - 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x, vec.y - 1));
            if (down && show[vec.x][vec.y + 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x, vec.y + 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x, vec.y + 1));
            if (left && up && show[vec.x - 1][vec.y - 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x - 1, vec.y - 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x - 1, vec.y - 1));
            if (left && down && show[vec.x - 1][vec.y + 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x - 1, vec.y + 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x - 1, vec.y + 1));
            if (right && up && show[vec.x + 1][vec.y - 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x + 1, vec.y - 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x + 1, vec.y - 1));
            if (right && down && show[vec.x + 1][vec.y + 1] == hidden && !(std::find(l.begin(), l.end(), sf::Vector2i(vec.x + 1, vec.y + 1)) != l.end()))
                l.push_back(sf::Vector2i(vec.x + 1, vec.y + 1));
        }
    }
    
}

void game::pressed(sf::Vector2i pos)
{
    //std::cout << map[pos.x / boxsize][pos.y / boxsize] << std::endl;
    if (show[pos.x / boxsize][pos.y / boxsize] == hidden)
    {
        std::list<sf::Vector2i> l;
        l.push_back(sf::Vector2i(pos.x / boxsize, pos.y / boxsize));
        check(l);
    }
}

void game::flagged(sf::Vector2i pos)
{
    if ((show[pos.x / boxsize][pos.y / boxsize] == hidden) && flags < bombs)
    {
        show[pos.x / boxsize][pos.y / boxsize] = flag;
        flags++;
    }
    else if (show[pos.x / boxsize][pos.y / boxsize] == flag)
    {
        show[pos.x / boxsize][pos.y / boxsize] = hidden;
        flags--;
    }
}

void game::endGame(bool win)
{
    if (win)
    {
        std::cout << "win";
    }
    else
    {
        std::cout << "lose";
    }
}
