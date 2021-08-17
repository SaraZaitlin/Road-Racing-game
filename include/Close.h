#pragma once

#include <SFML/Graphics.hpp>
#include "Command.h"

class Close :public Command
{
public:
	virtual int execute(sf::RenderWindow& window, sf::Vector2f position)override;

	Close(std::string string, sf::Vector2f position);
	~Close();
	virtual void draw(sf::RenderWindow& window) const;
	virtual void endelClick(sf::RenderWindow& window, bool& start)const;
protected:

};
