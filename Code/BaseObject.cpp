#include "BaseObject.h"

BaseObject::BaseObject() {
	m_object = NULL;
	m_rect.x = 0;
	m_rect.y = 0;
	loadSurface = NULL;
	
}

BaseObject::~BaseObject() {
	Free();
}

bool BaseObject::LoadImg(std::string path, SDL_Renderer* render) {
	loadSurface = IMG_Load(path.c_str());
	m_object = SDL_CreateTextureFromSurface(render, loadSurface);
	if (loadSurface == NULL) {
		   // handle error
		return false;
	}
    if (m_object == NULL) {
			// handle error
			SDL_FreeSurface(loadSurface);
			return false;
	}
		return true;
}


void BaseObject::Render(SDL_Renderer* des) {
	SDL_RenderCopy(des, m_object, NULL, &m_rect);
}

void BaseObject::Free() {
	if (m_object != NULL) {
		SDL_DestroyTexture(m_object);
		m_object = NULL;
	}
}

bool BaseObject::CheckCollision(const SDL_Rect object1, SDL_Rect object2)
{
	return SDL_HasIntersection(&object1, &object2);
}