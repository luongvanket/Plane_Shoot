#pragma once
#include "Common_Function.h"


class BaseObject
{
public:
	BaseObject();
	void SetRect_x_y(const int& x, const int& y) { m_rect.x = x, m_rect.y = y; };
	void SetRect_w_h(const int& w, const int& h) { m_rect.w = w, m_rect.h = h; };
	SDL_Rect GetRect() const { return m_rect; };
	SDL_Texture* GetObject() const { return m_object; };
	bool LoadImg(std::string path, SDL_Renderer* render);
	void Render(SDL_Renderer* des);
	void Free();
	~BaseObject();
	SDL_Rect m_rect;
	SDL_Surface* loadSurface;
	bool CheckCollision(const SDL_Rect object1, SDL_Rect object2);
	
protected:
	SDL_Texture* m_object;
};



