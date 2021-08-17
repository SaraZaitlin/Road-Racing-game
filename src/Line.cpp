//#include "stdafx.h"
#include "Line.h"
#include <ctime>
#include <stdlib.h>
#include <thread>
//set lines and the background displayed on each line
Line::Line(int i,int& level)
	:z(i), m_collect(nullptr)// * 300.f)
{
	m_clip = 768.f;
	m_curve = 0;
	
	if (i > 300 && i < 700)m_curve = 0.5;    if (i > 1100) m_curve = 9;
	if (i < 300 && i % 20 == 0) { m_objX = { -1.2, 0.25 }; m_texture = make_shared<Texture>(Resources::instance().m_image.find("tree")->second[level-index]); }
	if (i > 300 && i < 800 && i % 25 == 0) { m_objX = { -1.2 ,0.25 }; m_texture = make_shared<Texture>(Resources::instance().m_image.find("tree")->second[level-index]); }
	if (i > 800 && i < 1000 && i % 20 == 0) { m_objX = { -1.2, 0.25 }; m_texture = make_shared<Texture>(Resources::instance().m_image.find("tree")->second[level-index]); }
	if (i > 200 && i % 100 == 0) { m_objX = {-1.5, -1.5 }; m_texture = make_shared<Texture>(Resources::instance().m_image.find("home")->second[level-index]); }
	if (i > 1030 && i < 1500 && i % 20 == 0) { m_objX = {-1.2, 0.25 }; m_texture = make_shared<Texture>(Resources::instance().m_image.find("tree")->second[level-index]); }
	
	this->setCollect(i,level);
}
//Resources::instance().m_image[image]
//convert 3d coordinants to 2d coordinants
void Line::convert(int camX, int camY, int camZ,int speed)
{
	float camD = float(0.84); //camera depth

	m_scale = camD / (z*speed - camZ);
	m_center.x = (1 + m_scale * (0 - camX)) * Width / 2;
	m_center.y = (1 - m_scale * (0 - camY)) * Length /2;
	m_center.z = m_scale * 2000 * Width / 2;
}

//draw the objects onto the line
void Line::draw(sf::RenderWindow& window)const
{
	if (m_texture) {
		drawObject(window, m_objX.x);
		drawObject(window, m_objX.y);
	}
	if (m_collect)
		m_collect->draw(window, m_clip, m_center, m_scale, m_collectX);
}
//בדיקה אם מסוג מטבע אבן מתנות....
bool Line::hasCollect()const
{
	if (m_collect)
		return true;
	return false;
}

//get collectable that has been collided with
bool Line::collides(const std::unique_ptr<Car>& car)const
{
  return m_collect->collides(car);
}




//set the collectables on each line
void Line::setCollect(int i,int& level)
{
	int s = rand() % 2 -1;

	if (i > 213 && i % 20 == 0&&i<1200) {
		m_collectX = 2;
		m_collect = std::move(Factory::create("coins", sf::Vector2f(m_collectX, 0.25)));
	}

	if (i % 103 == 0) {
		m_collectX = -2;
		m_collect = std::move(Factory::create("coins", sf::Vector2f(m_collectX, 0.25)));
	}

	if (i % 350 == 0) {

		m_collectX = 0.7 * s;
	
		m_collect = std::move(Factory::create("stone", sf::Vector2f(m_collectX, 0.25)));//אבן
	}
	if (i > 1000 && i < 1100&&i % 105 == 0)
	{
		m_collectX = 0.7 * s;

		m_collect = std::move(Factory::create("addingFuel", sf::Vector2f(m_collectX, 0.25)));//הוספת דלק

	}
	if (i>300&&i<1000&& i % 110 == 0)
	{
	
		m_collectX = -2;
		m_collect = std::move(Factory::create("carEnemy", sf::Vector2f(m_collectX, 0.25)));//הוספת רכב אויב

	}
	if (i>300&&i<1000&&i % 150 == 0)
	{

		m_collectX =0.7;
		m_collect = std::move(Factory::create("carEnemy", sf::Vector2f(m_collectX, 0.25)));//הוספת רכב אויב

	}
	
	if (i % 120 == 0 && level == 2)
	{
		m_collectX = s * 0.7;
		m_collect = std::move(Factory::create("fox", sf::Vector2f(m_collectX, 0.25)));//הוספת דלק
	}
	
	
}

	

// draw background objects(trees houses etc)עצים בתים ...
void Line::drawObject(RenderWindow& window, double pos)const
{
	Sprite s;
	s.setTexture(*m_texture);

	int w = s.getTextureRect().width;
	int h = s.getTextureRect().height;

	float destX = m_center.x + m_scale * pos * Width / 2;
	float destY = m_center.y +4;
	float destW = w * m_center.z / 100;
	float destH = h * m_center.z /100;

	destX += destW * pos;
	destY += destH * (-1);

	float clipH = destY + destH - m_clip;
	if (clipH < 0) clipH = 0;
	if (clipH >= destH) return;

	s.setScale(destW / w, destH / h);
	s.setPosition(destX, destY);
	window.draw(s);
}



