

#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H
#include "BaseObject.h"
#include "Common_Function.h"
#include "BulletObject.h"


#define WIDTH_THREAT 70
#define HEIGHT_THREAT 40

class ThreatObject : public BaseObject
{
public:
	ThreatObject();
	~ThreatObject();

	void HandleMove(const int& x_border, const int& y_border);
	void HandleInputAction(SDL_Event e);
	void set_y_val(const int& y) { y_val = y; };
	void set_x_val(const int& x) { x_val = x; };
	int get_y_val() const { return y_val; };
	int get_x_val() const { return x_val; };

	void SetBulletList(std::vector<BulletObject*> bullet_list) { p_bullet_list = bullet_list; };
	std::vector<BulletObject*> GetBulletList() const { return p_bullet_list; };

	void InitBullet(BulletObject* p_bullet);
	void MakeBullet(SDL_Renderer* des, const int& x_limit, const int& y_limit);

	void Reset(const int& xboder);
	void Resetbullet(BulletObject* p_bull);


private:
	int x_val;
	int y_val; 
	std::vector<BulletObject*> p_bullet_list;
};

#endif // !THREAT_OBJECT_H

