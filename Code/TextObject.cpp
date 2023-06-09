#include "TextObject.h"

TextObject::TextObject()
{
	text_color = { 255, 255, 255, 255 };
}
TextObject::~TextObject()
{

}
void TextObject::SetColor(const int& type)
{
	if (type == RED_TEXT)
	{
		SDL_Color color = { 255, 0, 0 };
		text_color = color;
	}
	else if (type == WHITE_TEXT)
	{
		SDL_Color color = { 255,255, 255 };
		text_color = color;
	}
	else
	{
		SDL_Color color = { 0, 0, 0 };
		text_color = color;
	}
}
void TextObject::CreateGameText(TTF_Font* font, SDL_Renderer* des)
{
	loadSurface = TTF_RenderText_Solid(font, str_val.c_str(), text_color);
	m_object = SDL_CreateTextureFromSurface(des,loadSurface);
	Render(des);
}