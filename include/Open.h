#pragma once

#include <SFML/Graphics.hpp>
#include "Command.h"

class Open :public Command
{
public:
	virtual int execute(sf::RenderWindow& window, sf::Vector2f location)override;
	Open(std::string string, sf::Vector2f position);
	~Open();
	virtual void draw(sf::RenderWindow& window) const;
	virtual void endelClick(sf::RenderWindow& window, bool& start)const;
protected:

};
