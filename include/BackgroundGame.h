#pragma once
#include <SFML/Graphics.hpp>
#include"Const.h"
#include "Line.h"
#include "Resources.h"
#include "Car.h"
#include"CollisionHandling.h"
class BackgroundGame
{
public:
	BackgroundGame(std::unique_ptr<Car>& car,int& level);

	~BackgroundGame();
	void setTrack();
	void setLevel(int level);
	void run(sf::RenderWindow&);
private:

	void setSpritBg(sf::Sprite& sprite);
	void draw(sf::RenderWindow&);
	void drawRoad(sf::RenderWindow&);
	void drawLines(sf::RenderWindow&)const;
	void drawQuad(sf::RenderWindow&, sf::Color, float, float, float, float, float, float) const;
	
	std::unique_ptr<Car>& m_car;
	std::vector<std::unique_ptr<Line>> m_lines;
	std::vector<sf::Sprite > m_spritBackground;

	sf::Texture m_texturBackground1;
	sf::Texture m_texturBackground2;

	sf::Sprite m_spritBam;

	

	float m_width = 1024; //width screen
	float m_height = 768; // height screenîñê
	int	m_size = 1500;  // size trackîñìåì 
	int m_startPos = 1; //first line printed 
	int m_pos = 0;
	int m_Z=0;
	int m_level;
	int m_speed;
	bool m_magnet;

};
