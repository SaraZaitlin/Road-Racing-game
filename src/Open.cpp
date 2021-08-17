#include "Open.h"


Open::Open(std::string string, sf::Vector2f position) :Command(string, position)//, int width, int length) :Boutton(image, position, width, length)
{
}

Open::~Open()
{
}

void Open::draw(sf::RenderWindow& window) const
{
	window.draw(m_type[0]);
}

void Open::endelClick(sf::RenderWindow& window, bool& start) const
{
	window.clear();
}

int Open::execute(sf::RenderWindow& window, sf::Vector2f location)
{
	if (m_type[0].getGlobalBounds().contains(location))
	{
		window.clear();
		return 1;
	}
	return 0;
}