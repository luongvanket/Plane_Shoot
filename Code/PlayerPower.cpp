#include "PlayerPower.h"

PlayerPower::PlayerPower()
{
	number_ = 0;
}
PlayerPower::~PlayerPower()
{

}

void PlayerPower::AddPos(const int& x_pos)
{
	pos_list.push_back(x_pos);
}
void PlayerPower::RenderPos(SDL_Renderer* des)
{
	if (number_ == pos_list.size())
	{
		for (int i = 0; i < pos_list.size(); i++)
		{
			m_rect.x = pos_list.at(i);
			Render(des);
		}
	}
}
void PlayerPower::Init(SDL_Renderer* des)
{
	LoadImg("layer_power.png", des);
	number_ = 3;
	if (pos_list.size() > 0)
	{
		pos_list.clear();
	}
	AddPos(20);
	AddPos(60);
	AddPos(100);
}
void PlayerPower::Decrease()
{
	number_--;
	pos_list.pop_back();
}