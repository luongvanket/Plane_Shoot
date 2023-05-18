

#pragma once
#ifndef MAIN_OBJECT_H
#define MAIN_OBJECT_H


#include "Common_Function.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>


class MainObject : public BaseObject
{
public:
	MainObject();
	~MainObject();
	void HandleInputAction(SDL_Event e, Mix_Music* bullet_sound[2]);
	void HandleMove();

	void SetBulletList(std::vector<BulletObject*> bullet_list) { p_bullet_list = bullet_list; };
	std::vector<BulletObject*> GetBulletList() const { return p_bullet_list; }; 
	void MakeBullets(SDL_Renderer* des);
	void RemoveThreat(int& i);
private:
	int x_val;
	int y_val;
	int speed = 3;
	std::vector<BulletObject*> p_bullet_list;
};




#endif // !MAIN_OBJECT_H

