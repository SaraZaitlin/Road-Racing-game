#include "BackgroundGame.h"
#include<iostream>
#include <thread>  
BackgroundGame::BackgroundGame(std::unique_ptr<Car>& car,int &level)
	:m_car(car), m_spritBam(Resources::instance().m_image.find("bam")->second[0]),m_level(level), m_speed(600), m_magnet(false)
{
	m_spritBam.setPosition(300, 400);
	auto it = Resources::instance().m_image.find("bg");
	if (it == Resources::instance().m_image.end())
		throw std::out_of_range("GameObjectIndex item not found.");
	auto& vec = it->second;
	
	sf::Sprite sprite;
	m_texturBackground1 = vec[0];
	m_texturBackground1.setRepeated(true);
	sprite.setTexture(m_texturBackground1);
	setSpritBg(sprite);

	m_texturBackground2 = vec[1];
	m_texturBackground2.setRepeated(true);
	sprite.setTexture(m_texturBackground2);
	setSpritBg(sprite);


	setTrack();
}
//פונקציה המגדירה את התמונת רקע של כל שלב
void BackgroundGame::setSpritBg(sf::Sprite &sprite)
{
	sprite.setTextureRect(IntRect(0, 0, 5000, 411));
	sprite.setPosition(-2000, 0);
	m_spritBackground.push_back(sprite);
}
BackgroundGame::~BackgroundGame()
{
}



//פונקציה המאתחלת את הלוח 
void BackgroundGame::setTrack()
{
	m_lines.clear();
	m_startPos = 1;
	m_Z = 0;
	for (int i = 0; i < m_size; i++)
		m_lines.emplace_back(std::make_unique<Line>(i,m_level));

}
//פונקציה המאתחלת את מספר השלב
void BackgroundGame::setLevel(int level)
{
	m_level = level;
}
//פונקציה האחראית להדפיס את הלוח
void BackgroundGame::run(RenderWindow& window)
{
	if (m_startPos >= TRACK_END)
	{ 
		setTrack();
	}
	m_startPos++;
	
	this->draw(window);
}

//פונקציה המדפיסה את הרקע
void BackgroundGame::draw(RenderWindow& window)
{
	window.clear(Color(0 ,191 ,255));
	window.draw(m_spritBackground[m_level-index]);
	drawRoad(window);
	drawLines(window);
}
//פונקציה המציירת את המסלול
void BackgroundGame::drawRoad(RenderWindow& window)
{
	float maxy = m_height;
	m_Z += m_speed;
	for (int n = m_startPos; n < m_startPos + 300; n++)
	{
		//convert to screen cord
		m_lines[n % m_lines.size()]->convert(m_car->getPosition().x, m_lines.size(), m_Z, m_speed);
		m_lines[n % m_lines.size()]->setClip(maxy);

		if (m_lines[n % m_lines.size()]->getCenter().y >= maxy) continue;
		maxy = m_lines[n % m_lines.size()]->getCenter().y;
		Color road = (n / 3) % 2 ? Color(107, 107, 107) : Color(105, 105, 105);
		Color grass;
		if (m_level == 1)  grass = (n / 3) % 2 ? Color(0, 100, 0) : Color(34, 139, 34); //ירוק
		else grass = (n / 3) % 2 ? Color(255 ,250 ,250) : Color(240 ,255 ,240);//לבן
		Color roadSide = (n / 3) % 2 ? Color::Black : Color::White;

		
		float x1 = m_lines[n % m_lines.size()]->getCenter().x;
		float y1 = m_lines[n % m_lines.size()]->getCenter().y;
		float w1 = m_lines[n % m_lines.size()]->getCenter().z;
		float x2 = m_lines[(n - 1) % m_lines.size()]->getCenter().x;
		float y2 = m_lines[(n - 1) % m_lines.size()]->getCenter().y;
		float w2 = m_lines[(n - 1) % m_lines.size()]->getCenter().z;
		

		drawQuad(window, grass, 0.f, y2, Width, 0.f, y1, Width);
		drawQuad(window, roadSide, x2, y2, w2 * 1.2, x1, y1, w1 * 1.2);
		drawQuad(window, road, x2, y2, w2, x1, y1, w1);
	}
}
//פונקציה המציירת את האוביקטים שבכל שורה (מטבעות.... 
void BackgroundGame::drawLines(RenderWindow& window)const
{
	for (int n = m_startPos + 300; n > m_startPos; n--) {
		if (m_lines[n % m_lines.size()]->getCenter().z>250)
		{
			if (m_lines[n % m_lines.size()]->hasCollect() &&
				m_lines[n % m_lines.size()]->collides(m_car))
			{
				if(processCollision(*m_car, *m_lines[n % m_lines.size()]->getCollect()))
					window.draw(m_spritBam);
			}
		}
		m_lines[n % m_lines.size()]->draw(window);
	}
	
}
//הדפסת שורה בלוח
void BackgroundGame::drawQuad(RenderWindow& window, Color c, float x1, float y1, float z1, float x2, float y2, float z2)const
{
	ConvexShape shape(4);
	shape.setFillColor(c);
	shape.setPoint(0, Vector2f(x1 - z1, y1));
	shape.setPoint(1, Vector2f(x2 - z2, y2));
	shape.setPoint(2, Vector2f(x2 + z2, y2));
	shape.setPoint(3, Vector2f(x1 + z1, y1));
	window.draw(shape);
}


