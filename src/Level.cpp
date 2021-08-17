#include "Level.h"
//#include "Observer.h"
#include "Car.h"

Level::Level(std::unique_ptr<Car>& pCar) :m_car(pCar)
{
	pCar->RegisterObserver(this);

}

Level::~Level()
{
}
//פונקציה האחראית לנהל את שלבי המשחק
void Level::runLevel(sf::RenderWindow& window,std::string song)
{
	Resources::instance().getMusic(song).get()->play();
	int level=1;
	sf::Clock clock;
	window.clear();
	BackgroundGame BackgroundGame(m_car,level);
	InformationDisplay informationDisplay(m_car);
	while (window.isOpen()&& checkEndLevel(BackgroundGame,window))
	{
		auto deltaTime = clock.restart();
		endelEvent(window, deltaTime);
		BackgroundGame.run(window);
		m_car->decreaseFuel(deltaTime);
		informationDisplay.UpdatingInformationView(window, m_level);
		m_car->draw(window);
		window.display();
		window.clear();
	}
	howEndGame(window);
	Resources::instance().getMusic(song).get()->stop();

}
//פונקציה המטפלתת בלחיצות המתקבלות מהמשתמש להוזזת הרכב
void Level::endelEvent(sf::RenderWindow& window,sf::Time deltaTime)
{
	Event e;
	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
			window.close();
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			m_car->moveCar(-60, deltaTime);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			m_car->moveCar(60, deltaTime);
		}
	
	}
}
//פונקציה המעדכנת אתמספר המטבעות והדלק 
void Level::Update(int& coins, float& totalFule)
{
	m_total_coins = coins;
	m_totalFule = totalFule;
}
//פונקציה הבודקת אם הסתיים השלב ומטפלת בשלב הבא
bool Level::checkEndLevel(BackgroundGame& BackgroundGame, sf::RenderWindow& window)
{
	if (m_totalFule <= 0)
		return false;

	if (m_total_coins >= SumCoins * m_level)
	{
		m_level++;
		if (m_level >= 3)
			return false;
		BackgroundGame.setLevel(m_level);
		BackgroundGame.setTrack();
		m_car->additionFuel(200);
	}
	
	return true;
}

//פונקציה הבודקת איך הסתיים המשחק
void Level::howEndGame(sf::RenderWindow& window)
{

	if (m_totalFule <= 0)
		SetUpTextur(1,window);
	else
	  SetUpTextur(0,window);

}

//פונקציה אשר מגדירה את התמונה 
void Level::SetUpTextur(int index, sf::RenderWindow& window)
{

	window.clear();
	auto sprite = setTextur("howEnd", index);
	window.draw(sprite);
	window.display();
	using namespace std::chrono_literals;

	std::this_thread::sleep_for(2s);

	for (int i = 0; i < m_total_coins; i++)
	{
		window.clear();
		displayHowCoins(window,i);
	}

	std::this_thread::sleep_for(6s);


}
//-----------------------------------------
//פונקציה המדפיסה לשחקן בסוף המשחק כמה מטבעות אסף
void Level::displayHowCoins(sf::RenderWindow& window,int coin)
{
	
	auto spritebg = setTextur("background", 0);
	auto sprite = setTextur("infu", 0);
	auto yel = sf::Color::Yellow;
	auto text = sf::Text(std::to_string(coin), Resources::instance().getFont());

	text.setPosition(500, 50);
	text.setCharacterSize(80);
	text.setColor(yel);

	window.draw(spritebg);
	window.draw(sprite);
	window.draw(text);

	window.display();
	using namespace std::chrono_literals;

}

//-----------------------------
//פונקציה המגדירה sprite
sf::Sprite Level::setTextur(std::string name,int index)
{
	sf::Sprite sprite;
	sprite.setPosition(0, 0);
	sprite.setTexture(Resources::instance().m_image.find(name)->second[index]);
	sprite.scale(Width * 1.00f / sprite.getTexture()->getSize().x, Length * 1.00f / sprite.getTexture()->getSize().y);
	return sprite;
}
