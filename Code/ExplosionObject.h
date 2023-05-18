#pragma once
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "BaseObject.h"
#include "Common_Function.h"

const int WIDTH_EXP = 345;
const int HEIGHT_EXP = 375;

class ExplosionObject : public BaseObject
{
private:
	int frame;
	SDL_Rect clips_[4];
public:
	ExplosionObject();
	~ExplosionObject();
	void set_clip();
	void set_frame(int fr) { frame = fr; };
	void move();
	void ShowExp(SDL_Renderer* des);
	void RenderClip(SDL_Renderer* des, SDL_Rect* clip, int x, int y);
	void InitClip();
};




#endif // !EXPLOSION_H

