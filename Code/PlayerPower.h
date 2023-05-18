#pragma once
#ifndef PLAYER_POWER_H
#define PLAYER_POWER_H
#include "BaseObject.h"
#include<vector>

class PlayerPower : public BaseObject
{
public:
	PlayerPower();
	~PlayerPower();
	void SetNumber(const int& num) { number_ = num; };
	void AddPos(const int& x_pos);
	void RenderPos(SDL_Renderer* des);
	void Init(SDL_Renderer* des);
	void Decrease();
private:
	int number_;
	std::vector<int> pos_list;
};

#endif // !PLAYER_POWER_H
