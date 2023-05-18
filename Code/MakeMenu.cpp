#include "MakeMenu.h"

MakeMenu::MakeMenu()
{
	xm = 0;
	ym = 0;
}
MakeMenu::~MakeMenu()
{

}
bool MakeMenu::CheckFocusWithRect(const int& x, const int& y, SDL_Rect rect_m)
{
	if (x >= rect_m.x && x <= rect_m.x + rect_m.w &&
		y >= rect_m.y && y <= rect_m.y + rect_m.h)
	{
		return true;
	}
	return false;
}
int MakeMenu::ShowMenu(SDL_Renderer* des, TTF_Font* font)
{
	const int kMenu = 2;
	SDL_Rect pos_arr[kMenu];
	pos_arr[0].x = 470;
	pos_arr[0].y = 350;
	pos_arr[0].w = 150;
	pos_arr[0].h = 60;


	pos_arr[1].x = 470;
	pos_arr[1].y = 450;
	pos_arr[1].w = 150;
	pos_arr[1].h = 60;

	TextObject text_menu[kMenu];

	text_menu[0].SetText("Play Game");
	text_menu[0].SetColor(TextObject::WHITE_TEXT);
	text_menu[0].SetRect_x_y(pos_arr[0].x, pos_arr[0].y);
	text_menu[0].SetRect_w_h(pos_arr[0].w, pos_arr[0].h);

	text_menu[1].SetText("Exit");
	text_menu[1].SetColor(TextObject::WHITE_TEXT);
	text_menu[1].SetRect_x_y(pos_arr[1].x, pos_arr[1].y);
	text_menu[1].SetRect_w_h(pos_arr[1].w, pos_arr[1].h);

	bool selected[kMenu] = { 0,0 };
	


	SDL_Event event_;
	while(true)
	{
		BaseObject bkg_menu;
		bkg_menu.LoadImg("Start_menu.png", des);
		bkg_menu.SetRect_w_h(SCREEN_WIDTH, SCREEN_HEIGHT);
		bkg_menu.Render(des);
		for (int i = 0; i < kMenu; i++)
		{
			text_menu[i].CreateGameText(font, des);
		}
		while (SDL_PollEvent(&event_))
		{
			switch (event_.type)
			{
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEMOTION:
			{
				xm = event_.motion.x;
				ym = event_.motion.y;

				for (int i = 0; i < kMenu; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
					{
						if (selected[i] == false)
						{
							selected[i] = 1;
							text_menu[i].SetColor(TextObject::RED_TEXT);
						}
					}
					else
					{
						if (selected[i] == true)
						{
							selected[i] = 0;
							text_menu[i].SetColor(TextObject::WHITE_TEXT);
						}
					}
				}
			}
			  break;
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = event_.button.x;
				ym = event_.button.y;

				for (int i = 0; i < kMenu; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
					{
						return i;
					}
				}
			}
			case SDL_KEYDOWN:
				if (event_.key.keysym.sym == SDLK_ESCAPE)
				{
					return 1;
				}
				break;
			default:
				break;
			}
		}
	    
		SDL_RenderPresent(des);
	}
	return 1;

}
int MakeMenu::ShowMenu_end(SDL_Renderer* des, TTF_Font* font)
{
	const int kMenu = 2;
	SDL_Rect pos_arr[kMenu];
	pos_arr[0].x = 440;
	pos_arr[0].y = 350;
	pos_arr[0].w = 200;
	pos_arr[0].h = 80;


	pos_arr[1].x = 440;
	pos_arr[1].y = 250;
	pos_arr[1].w = 200;
	pos_arr[1].h = 80;

	TextObject text_menu[kMenu];

	text_menu[0].SetText("Quit");
	text_menu[0].SetColor(TextObject::WHITE_TEXT);
	text_menu[0].SetRect_x_y(pos_arr[0].x, pos_arr[0].y);
	text_menu[0].SetRect_w_h(pos_arr[0].w, pos_arr[0].h);

	text_menu[1].SetText("Restart");
	text_menu[1].SetColor(TextObject::WHITE_TEXT);
	text_menu[1].SetRect_x_y(pos_arr[1].x, pos_arr[1].y);
	text_menu[1].SetRect_w_h(pos_arr[1].w, pos_arr[1].h);

	bool selected[kMenu] = { 0,0 };



	SDL_Event event_;
	while (true)
	{
		BaseObject bkg_menu;
		bkg_menu.LoadImg("End_menu.png", des);
		bkg_menu.SetRect_w_h(SCREEN_WIDTH, SCREEN_HEIGHT);
		bkg_menu.Render(des);
		for (int i = 0; i < kMenu; i++)
		{
			text_menu[i].CreateGameText(font, des);
		}
		while (SDL_PollEvent(&event_))
		{
			switch (event_.type)
			{
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEMOTION:
			{
				xm = event_.motion.x;
				ym = event_.motion.y;

				for (int i = 0; i < kMenu; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
					{
						if (selected[i] == false)
						{
							selected[i] = 1;
							text_menu[i].SetColor(TextObject::RED_TEXT);
						}
					}
					else
					{
						if (selected[i] == true)
						{
							selected[i] = 0;
							text_menu[i].SetColor(TextObject::WHITE_TEXT);
						}
					}
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN:
			{
				xm = event_.button.x;
				ym = event_.button.y;

				for (int i = 0; i < kMenu; i++)
				{
					if (CheckFocusWithRect(xm, ym, text_menu[i].GetRect()))
					{
						return i;
					}
				}
			}
			case SDL_KEYDOWN:
				if (event_.key.keysym.sym == SDLK_ESCAPE)
				{
					return 1;
				}
				break;
			default:
				break;
			}
		}

		SDL_RenderPresent(des);
	}
	return 1;
}