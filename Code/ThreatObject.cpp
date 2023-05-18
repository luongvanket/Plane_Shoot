#include "ThreatObject.h"


ThreatObject::ThreatObject()
{
	x_val = 0;
	y_val = 0;
	m_rect.w = WIDTH_THREAT;
	m_rect.h = HEIGHT_THREAT;
	m_rect.x = SCREEN_WIDTH / 2;
	m_rect.y = SCREEN_HEIGHT;
	
}
ThreatObject::~ThreatObject()
{
	if (p_bullet_list.size() > 0)
	{
		for (int i = 0; i < p_bullet_list.size(); i++)
		{
			BulletObject* p_bullet = p_bullet_list.at(i);
			if (p_bullet != NULL) {
				delete p_bullet;
				p_bullet = NULL;
			}
		}
		p_bullet_list.clear();
	}
}

void ThreatObject::InitBullet(BulletObject* p_bullet)
{
	if (p_bullet)
	{
		bool ret = p_bullet->LoadImg("bullet_threat.png", renderer);
		if (ret) {
			p_bullet->set_is_move(true);
			p_bullet->Set_Width_Height(WIDTH_BULLET_ROUND, HEIGHT_BULLET_ROUND);
			p_bullet->SetRect_x_y(m_rect.x, m_rect.y + 16 );
			p_bullet->set_x_val(2);
			p_bullet_list.push_back(p_bullet);

		}
	}
}
void ThreatObject::HandleMove(const int& x_border, const int& y_border)
{
	//
	m_rect.x -= x_val;
	if (m_rect.x < 0)
	{
		m_rect.x = x_border;
		int rand_y = rand() % (SCREEN_HEIGHT - 5);
		m_rect.y = rand_y;
	}
}
void ThreatObject::HandleInputAction(SDL_Event e)
{
	//
}

void ThreatObject::MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit)
{
	for (int i = 0; i < p_bullet_list.size(); i++)
	{
		BulletObject* p_bullet = p_bullet_list.at(i);
		if (p_bullet)
		{
			if (p_bullet->get_is_move())
			{
				p_bullet->Render(des);
				p_bullet->HandleMove_BulletThreat();
			}
			else
			{
				p_bullet->set_is_move(true);
				p_bullet->SetRect_x_y(m_rect.x, m_rect.y + 16);
			}
		}
	}
}
void ThreatObject::Reset(const int& xboder)
{
	m_rect.x = xboder;
	int rand_y = rand() % (SCREEN_HEIGHT - 5);
	m_rect.y = rand_y;
	for (int b = 0; b < p_bullet_list.size(); b++)
	{
		BulletObject* p_bullets = p_bullet_list.at(b);
		if (p_bullets)
		{
			Resetbullet(p_bullets);
		}
	}

}
void ThreatObject::Resetbullet(BulletObject* p_bull)
{
	p_bull->SetRect_x_y(m_rect.x, m_rect.y + 16);
}
