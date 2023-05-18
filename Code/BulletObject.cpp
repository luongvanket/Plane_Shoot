#include "BulletObject.h"

BulletObject::BulletObject()
{
	x_val = 0;
	y_val = 0;
	m_rect.x = 0;
	m_rect.y = 0; 
	//m_rect.w = WIDTH_BULLET;
	//m_rect.h = HEIGHT_BULLET;
	is_move = false;
	bullet_type = NONE;
}


BulletObject::~BulletObject()
{
	;
}

void BulletObject::HandleInputAction(SDL_Event e)
{
	;
}

void BulletObject::HandleMove(const int& x_border, const int& y_border)
{
	m_rect.x += x_val;
	if (m_rect.x > x_border)
	{
		is_move = false;
	}
}
void BulletObject::HandleMove_BulletThreat()
{
	m_rect.x -= x_val;
	if (m_rect.x < 0)
	{
		is_move = false;
	}
}