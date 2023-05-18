#include "ExplosionObject.h"


ExplosionObject::ExplosionObject()
{
	frame = 0;
	InitClip();
}
ExplosionObject::~ExplosionObject()
{
	//
}
void ExplosionObject::set_clip()
{
	clips_[0].x = 0;
	clips_[0].y = 0;
	clips_[0].w = WIDTH_EXP;
	clips_[0].h = HEIGHT_EXP;

	clips_[1].x = WIDTH_EXP;
	clips_[1].y = 0;
	clips_[1].w = WIDTH_EXP;
	clips_[1].h = HEIGHT_EXP;

	clips_[2].x = WIDTH_EXP*2;
	clips_[2].y = 0;
	clips_[2].w = WIDTH_EXP;
	clips_[2].h = HEIGHT_EXP;

	clips_[3].x = WIDTH_EXP*3;
	clips_[3].y = 0;
	clips_[3].w = WIDTH_EXP;
	clips_[3].h = HEIGHT_EXP;
}



void ExplosionObject::ShowExp(SDL_Renderer* des)
{
	if (frame >= 4)
	{
		frame = 0;
	}
	ExplosionObject::RenderClip(des, &clips_[frame], m_rect.x, m_rect.y);
}
void ExplosionObject::move()
{
	//
}
void ExplosionObject::RenderClip(SDL_Renderer* des, SDL_Rect* clip, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_RenderCopy(des, m_object, &clip[frame], &offset);
}
void ExplosionObject::InitClip()
{
	clips_[0].x = 0;
	clips_[0].y = 0;
	clips_[0].w = 0;
	clips_[0].h = 0;

	clips_[1].x = 0;
	clips_[1].y = 0;
	clips_[1].w = 0;
	clips_[1].h = 0;

	clips_[2].x = 0;
	clips_[2].y = 0;
	clips_[2].w = 0;
	clips_[2].h = 0;

	clips_[3].x = 0;
	clips_[3].y = 0;
	clips_[3].w = 0;
	clips_[3].h = 0;
}