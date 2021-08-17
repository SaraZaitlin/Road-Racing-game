#include"Close.h"


Close::Close(std::string string, sf::Vector2f position) :Command(string, position)//, int width, int length) :Boutton(image, position, width, length)
{

}

Close::~Close()
{
}

void Close::draw(sf::RenderWindow& window) const
{

	window.draw(m_type[0]);
}

void Close::endelClick(sf::RenderWindow& window, bool& start) const
{
	window.close();
	start = false;
}
int Close::execute(sf::RenderWindow& window, sf::Vector2f position)
{
	if (m_type[0].getGlobalBounds().contains(position))
	{
		window.close();
		return 1;
	}
	return 0;
}


