#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
class Command
{
public:
	Command(std::string string, sf::Vector2f location);
	virtual ~Command();
	virtual void draw(sf::RenderWindow& window) const;
	virtual int execute(sf::RenderWindow& window, sf::Vector2f position);

protected:
	std::vector<sf::Sprite>m_type;

};
