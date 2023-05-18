#pragma once
#ifndef MAKE_MENU_H
#define MAKE_MENU_H
#include "BaseObject.h"
#include "TextObject.h"


class MakeMenu : public BaseObject
{
public:
	MakeMenu();
	~MakeMenu();
	int ShowMenu(SDL_Renderer* des, TTF_Font* font);
	int ShowMenu_end(SDL_Renderer* des, TTF_Font* font);
	bool CheckFocusWithRect(const int& x, const int& y, SDL_Rect rect_m);
private:
	int xm;
	int ym;
};


#endif // !MAKE_MENU_H
