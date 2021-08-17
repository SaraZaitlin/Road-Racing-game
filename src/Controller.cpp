#include "Controller.h"
#include "Car.h"
Controller::Controller(std::unique_ptr<Command> c1, std::unique_ptr<Command> c2, std::unique_ptr<Command> c3, std::unique_ptr<Command> c4) : m_window(sf::VideoMode(Width, Length), ""), m_sprite(Resources::instance().m_image.find("background")->second[0])
{
    auto newSprite = m_sprite.getTexture();
    auto size = newSprite->getSize();
    sf::Vector2f position;
    position.x = Width / 3;
    position.y = Length / 3;
    m_sprite.scale(Width * 1.00f / size.x, Length * 1.00f / size.y);

    m_command.emplace_back(std::move(c1));
    m_command.emplace_back(std::move(c2));
    m_command.emplace_back(std::move(c3));
    m_command.emplace_back(std::move(c4));

}

Controller::~Controller()
{
}
//ציור שער כניסה
void Controller::draw()
{
    m_window.draw(m_sprite);
    m_command[startGame]->draw(m_window);
    m_command[exitGame]->draw(m_window);

}

//ציור בחירת רכבים
void Controller::drawMenuCar()
{
    m_window.draw(m_sprite);
    auto sprite = setTextur("choise", 0);
    m_window.draw(sprite);
    m_command[cars]->draw(m_window);
    m_window.display();


}
//ציור בחירת מנגינה
void Controller::drawMenuSong()
{
    m_window.draw(m_sprite);
    auto sprite = setTextur("choise", 1);
    m_window.draw(sprite);
    m_command[songs]->draw(m_window);
    m_window.display();

}

int Controller::bouttonPressed(int buttonNum, sf::Vector2f position)
{
    return m_command[buttonNum]->execute(m_window, position);
}

void Controller::run()
{
    bool game=false;
    while (m_window.isOpen())
    {
        game = false;
        m_window.clear();
        draw();

        m_window.display();
        auto location = hendlMouse();
        while ((bouttonPressed(startGame, location) || bouttonPressed(exitGame, location)) && !game)
        {

            int chose;
            int choseSong;
            drawMenuCar();
            auto   location1 = hendlMouse();

            while ((chose = bouttonPressed(cars, location1)) != 3 && !game)
            {
                drawMenuSong();
                auto location2 = hendlMouse();

                while ((choseSong = bouttonPressed(songs, location2) )!= 2 && !game)
                {
                    game = true;

                    std::unique_ptr<Car> m_car = std::make_unique<Car>(sf::Vector2f(450, 500), chose);

                    Level level(m_car);
                 

                    level.runLevel(m_window , std::to_string(choseSong));
                }
            }
        }
            
        
    }
}


sf::Vector2f Controller::hendlMouse()
{
    sf::Vector2f location;
    if (auto event = sf::Event{}; m_window.waitEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            m_window.close();
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            location = m_window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });
            return location;
        }

        }

    }
  
    return location;

}

//-----------------------------
//פונקציה המגדירה תמונה 
sf::Sprite Controller::setTextur(std::string name, int index)const
{
    sf::Sprite sprite;
    sprite.setPosition(280, 5);
    sprite.setTexture(Resources::instance().m_image.find(name)->second[index]);
    
    return sprite;
}
