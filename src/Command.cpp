#include "Command.h"

Command::Command(std::string string, sf::Vector2f location)
{

    auto it = Resources::instance().m_image.find(string);
    if (it == Resources::instance().m_image.end())
        throw std::out_of_range("GameObjectIndex item not found.");
    //exit(1);

    auto& vec = it->second;
    for (int i = 0; i < vec.size(); i++)
    {
        auto sprite = sf::Sprite(vec[i]);
        sprite.setPosition(location.x + (i) * 400, location.y);

        auto txt = sprite.getTexture();
        m_type.push_back(sprite);
    }
}



Command::~Command()
{
}

void Command::draw(sf::RenderWindow& window) const
{
    for (int i = 0; i < m_type.size(); i++)
    {
        window.draw(m_type[i]);
    }
}

int Command::execute(sf::RenderWindow& window, sf::Vector2f position)
{
    for (int i = 0; i < m_type.size(); i++)
    {
        if (m_type[i].getGlobalBounds().contains(position))
        {
            window.clear();
            return i;
        }
    }
    return m_type.size();
}


