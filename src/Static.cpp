#include "Static.h"
#include<iostream>


Static::Static(const std::string& string, sf::Vector2f location):GameObject(string, location)
{

	
}

void Static::draw(sf::RenderWindow& window, float m_clip, sf::Vector3f m_center, float m_scale, double m_collectX)
{


	int w = m_spritObject.getTextureRect().width;
	int h = m_spritObject.getTextureRect().height;

	// calculate the position, hight and width for reposition
	float destX = m_center.x + m_scale * m_collectX * 1024 / 2;
	float destY = m_center.y + 4;
	float destW = w * m_center.z / 1000;
	float destH = h * m_center.z / 1000;

	destX += destW * m_collectX;
	destY += destH * (-1);

	float clipH = destY + destH - m_clip;
	if (clipH < 0) clipH = 0;
	if (clipH >= destH) return;

	m_spritObject.setScale(destW / w, destH / h);
	m_spritObject.setPosition(destX, destY);

	window.draw(m_spritObject);
}


void Static::setColor()
{
	m_spritObject.setColor(sf::Color::Transparent);
}
