
#include "CarEnemy.h"
CarEnemy::CarEnemy(sf::Vector2f location) :Dynamic("carEnemy", location)
{
}

CarEnemy ::~CarEnemy()
{
}
//פונקציה האחראית על הדפסת רכב אויב
void CarEnemy::draw(sf::RenderWindow& window, float m_clip, sf::Vector3f m_center, float m_scale, double m_collectX)
{
	int w = m_spritObject.getTextureRect().width;
	int h = m_spritObject.getTextureRect().height;
	float destX;
	// calculate the position, hight and width for reposition
	if (m_spritObject.getPosition().x != 0)
		destX = m_spritObject.getPosition().x + m_scale * m_collectX * 1024 / 2;
	else
		destX = m_center.x + m_scale * m_collectX * 1024 / 2;
	float destY = m_center.y + 4;
	float destW = w * m_center.z / 1000;
	float destH = h * m_center.z / 1000;


	if (m_spritObject.getPosition().x == 0)
		destX += destW * m_collectX;

	destY += destH * (-1);
	float clipH = destY + destH - m_clip;
	if (clipH < 0) clipH = 0;
	if (clipH >= destH) return;

	m_spritObject.setScale(destW / w, destH / h);
	m_spritObject.setPosition(destX, destY);
	window.draw(m_spritObject);
}



inline bool CarEnemy::m_registerit = Factory::registerit("carEnemy",
	[](sf::Vector2f location) -> std::unique_ptr<GameObject> { return std::make_unique<CarEnemy>(location); });