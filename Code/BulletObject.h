#pragma once
#ifndef BULLET_OBJECT_H
#define BULLET_OBJECT_H

#include "BaseObject.h"


#define WIDTH_BULLET_LASER 30
#define HEIGHT_BULLET_LASER 10

#define WIDTH_BULLET_ROUND 10
#define HEIGHT_BULLET_ROUND 10

class BulletObject : public BaseObject
{
public:
	enum BulletType
	{
		NONE = 0,
		LASER = 1,
	    ROUND = 2
	};
	BulletObject();
	void HandleInputAction(SDL_Event e);
	void HandleMove(const int& x_border, const int& y_border);
	int get_type() const { return bullet_type; };
	void set_type(const int& type) {bullet_type = type; };

	bool get_is_move() const { return is_move; };
	void set_is_move(const bool move) { is_move = move; };

	void Set_Width_Height(const int& Width, const int& Height) { m_rect.w = Width, m_rect.h = Height; };
	void set_y_val(const int& y) { y_val = y; };
	void set_x_val(const int& x) { x_val = x; };
	void HandleMove_BulletThreat();
	~BulletObject();
	
private:
	int x_val;
	int y_val;
	bool is_move;
	int bullet_type;
};


#endif // !BULLET_OBJECT_H
