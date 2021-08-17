#pragma once
#include"Dynamic.h"
#include <SFML/Graphics.hpp>
#include"Factory.h"
class CarEnemy :public Dynamic
{
public:
	CarEnemy(sf::Vector2f location);
	~CarEnemy();
	void draw(sf::RenderWindow& window, float m_clip, sf::Vector3f m_center, float m_scale, double m_collectX);
protected:
	static bool m_registerit;

};