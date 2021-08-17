#include "InformationDisplay.h"

InformationDisplay::~InformationDisplay()
{
}


InformationDisplay::InformationDisplay(std::unique_ptr<Car>& pCar)//:m_window(window)
{
	pCar->RegisterObserver(this);

	m_sprite.scale(100, 800);
	m_sprite.setPosition(800, 0);

	auto it = Resources::instance().m_image.find("infu");
	if (it == Resources::instance().m_image.end())
		throw std::out_of_range("GameObjectIndex item not found.");
	auto& vec = it->second;
	for (int i = 0; i < vec.size(); i++)
	{
		auto sprite = sf::Sprite(vec[i]);
		sprite.setPosition(80+i*215, 15);

		auto txt = sprite.getTexture();
		m_infu.push_back(sprite);
	}

	m_printLevel = sf::Text("LEVEL:", Resources::instance().getFont());


	auto yel = sf::Color::Yellow;

	m_printLevel.setColor(yel);
	m_printLevel.setPosition({ 750,50 });
	m_printLevel.setCharacterSize(50);

	

}

//פונקצייה שאחראית על תצוגת המידע

void InformationDisplay::UpdatingInformationView( sf::RenderWindow& window,int& level)
{
	auto black = sf::Color::Black;
	auto text = sf::Text(std::to_string(m_total_coins), Resources::instance().getFont());
	
	text.setPosition(210, 50);
	text.setCharacterSize(35);
	text.setColor(black);
	window.draw(m_infu[0]);
	window.draw(text);


	text = sf::Text(std::to_string(m_totalFule), Resources::instance().getFont());
	text.setPosition(430, 50);
	text.setCharacterSize(35);
	text.setColor(black);
	window.draw(m_infu[1]);
	window.draw(text);

	text = sf::Text(std::to_string(level), Resources::instance().getFont());
	text.setPosition(920, 50);
	text.setCharacterSize(50);
	text.setColor(black);
	window.draw(m_printLevel);
	window.draw(text);



}




void InformationDisplay::Update(int& coins, float& totalFule)
{
	m_total_coins = coins;
	m_totalFule = totalFule;

}

