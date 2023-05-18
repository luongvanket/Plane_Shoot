
#ifndef COMMON_FUNTION_H
#define COMMON_FUNTION_H

#include<SDL.h>
#include<SDL_image.h>
#include<Windows.h>
#include<string>
#include<iostream>
#include<vector>
#include<SDL_mixer.h>

const int  WIDTH_MAIN_OBJECT = 100;
const int  HEIGHT_MAIN_OBJECT = 55 ;

const int WIDTH_BKG = 1100 * 4;
const int HEIGHT_BKG = 610;

const int SCREEN_WIDTH = 1100;
const int SCREEN_HEIGHT = 600;
const int NUM_THREATS = 3;

static Mix_Music* g_sound_bullet[2];
static Mix_Music* g_sound_exp[2];


static SDL_Window* window;
extern SDL_Renderer* renderer;
static SDL_Event event;



#endif
