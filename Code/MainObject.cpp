#include "MainObject.h"

MainObject::MainObject()
{
	m_rect.x = 0;
	m_rect.y = 0;
	m_rect.w = WIDTH_MAIN_OBJECT;
	m_rect.h = HEIGHT_MAIN_OBJECT;
	x_val = 0;
	y_val = 0;
}
MainObject::~MainObject()
{
	;
}

void MainObject::HandleInputAction(SDL_Event e, Mix_Music* bullet_sound[2])
{
	
	if (e.type == SDL_KEYDOWN)
	{
		switch (e.key.keysym.sym)
		{
		   case SDLK_UP: y_val -= speed; break;
		   case SDLK_DOWN: y_val += speed ; break;
		   case SDLK_LEFT: x_val -= speed ; break;
		   case SDLK_RIGHT: x_val += speed ; break;   
		}
	}
	else if(e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		   case SDLK_UP: y_val += speed; break;
		   case SDLK_DOWN: y_val -= speed; break;
		   case SDLK_LEFT: x_val += speed; break;
		   case SDLK_RIGHT: x_val -= speed; break;
		}
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		BulletObject* p_bullet = new BulletObject();
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			p_bullet->Set_Width_Height(WIDTH_BULLET_LASER, HEIGHT_BULLET_LASER);
			p_bullet->LoadImg("Bullet_laser_.png", renderer);
			p_bullet->set_type(BulletObject::LASER);
			Mix_PlayMusic(bullet_sound[0], 0);
			Mix_VolumeMusic(MIX_MAX_VOLUME);
		}
		else if (e.button.button == SDL_BUTTON_RIGHT)
		{
			p_bullet->Set_Width_Height(WIDTH_BULLET_ROUND, HEIGHT_BULLET_ROUND);
			p_bullet->LoadImg("Bullet_round_.png", renderer);
			p_bullet->set_type(BulletObject::ROUND);
			Mix_PlayMusic(bullet_sound[1], 0);
			Mix_VolumeMusic(MIX_MAX_VOLUME/4 );
		}
		p_bullet->SetRect_x_y(this->m_rect.x + 58, this->m_rect.y + 42 );
		p_bullet->set_x_val(3);
		p_bullet->set_is_move(true);
		p_bullet_list.push_back(p_bullet);
	}
}
void MainObject::MakeBullets(SDL_Renderer* des)
{
	for (int i = 0; i < p_bullet_list.size(); i++)
	{
		BulletObject* p_bullet = p_bullet_list.at(i);
		if (p_bullet != NULL)
		{
			if (p_bullet->get_is_move())
			{
				p_bullet->Render(des);
				p_bullet->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			}
			else
			{
				if (p_bullet != NULL)
				{
					p_bullet_list.erase(p_bullet_list.begin() + i);

					delete p_bullet;
					p_bullet = NULL;
				}
			}
		}
	}
}

void MainObject::HandleMove()
{
	m_rect.x += x_val;
	if (m_rect.x < 0 || (m_rect.x  > SCREEN_WIDTH - 100)) {
		m_rect.x -= x_val;
	}
	m_rect.y += y_val;
	if (m_rect.y < 0 || (m_rect.y  > SCREEN_HEIGHT - 55 )) {
		m_rect.y -= y_val;
	}
}
void MainObject::RemoveThreat(int& i)
{

		for (int a = 0; a < p_bullet_list.size(); a++)
		{
			if (i < p_bullet_list.size())
			{
				BulletObject* p_bullet = p_bullet_list.at(i);
				p_bullet_list.erase(p_bullet_list.begin() + i);
				if (p_bullet != NULL)
				{
					delete p_bullet;
					p_bullet = NULL;
				}
			}
			
		}
}