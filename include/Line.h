#pragma once
#include <vector>
#include "Const.h"
#include "Factory.h"
#include "Coins.h"
#include "Car.h"
#include"Static.h"
#include"Resources.h"
//#include "CollisionHandling.h"
using namespace sf;
using std::make_shared;

using std::shared_ptr;

class Line
{
public:
	Line(int,int&);
	~Line() = default;
	void convert(int, int, int, int);
	void draw(RenderWindow&)const;
	Vector3f getCenter()const { return m_center; }
	void setClip(float c) { m_clip = c; }
	bool hasCollect()const;
	std::unique_ptr<GameObject> getCollect() { return std::move(m_collect); }
	bool collides(const std::unique_ptr<Car>& player)const;
	float m_curve;
private:
	void setCollect(int,int&);
	void drawObject(RenderWindow&, double)const;
	std::unique_ptr<GameObject> m_collect;
	shared_ptr<Texture> m_texture;
	std::vector<Texture> m_objects;
	Vector2f m_objX;    // objects position
	double m_collectX;  // collect x position
	Vector3f m_center; //3d center of line
	float z,  //screen coord
		m_scale,
		m_clip;
	int m_totalFule = 0;


};
