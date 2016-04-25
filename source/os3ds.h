#ifndef __OS3DS_H__
#define __OS3DS_H__


//This file is a reverse engineered "DxLib.h" to the extent that
//Syobon Action uses it. Minor functions are just replaced with SDL
//counterparts.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <string>
#include <3ds.h>
#include <sf2d.h>
#include <sftd.h>
#include <sfil.h>
#include "sfx.h"

//#include "joyconfig.h"

#define scale 2 // To resize graphics to small 3DS screen
#define y_off 30 // To move down object to bottom of 3DS sceen

#define TRUE 1
#define FALSE 0
#define byte unsigned char

//#define ScreenFlip() SDL_Flip(screen)
#define TICKS_PER_MSEC 268123.480
#define GetNowCount() (svcGetSystemTick() / TICKS_PER_MSEC)

//UNIMPLEMENTED - macro substitution
#define SetFontThickness(f);
#define ChangeVolumeSoundMem(s, v);

//Nop90 - to be implemented
#define Mix_HaltChannel(int);
#define Mix_VolumeMusic(i); 

//Sound
#define CheckSoundMem(s) !s
#define DMIX_MAX_VOLUME 0xff
#define DX_PLAYTYPE_BACK 0

// FONT
#define DX_FONTTYPE_EDGE 0
#define DX_FONTTYPE_NORMAL 0


typedef struct  {
   sf2d_texture * texture;
   int   x,y,width,height;
} t_graph;

int os3ds_Init();

//Main screen
extern u32 *screen;

//Fonts

//Strings & fonts

void SetFontSize(byte size);
void ChangeFontType(byte type);
void DrawString(int a, int b, const char *x, u32 c);
void DrawFormatString(int a, int b, u32 color, const char *str, ...);

//Key Aliases
#define KEY_INPUT_ESCAPE KEY_SELECT
#define KEY_INPUT_LEFT KEY_LEFT
#define KEY_INPUT_RIGHT KEY_RIGHT
#define KEY_INPUT_DOWN KEY_DOWN
#define KEY_INPUT_UP KEY_UP
#define KEY_INPUT_F1 KEY_Y
#define KEY_INPUT_O KEY_X
#define KEY_INPUT_Z KEY_A
#define KEY_INPUT_RETURN KEY_START
#define KEY_INPUT_SPACE KEY_B

#define KEY_INPUT_1 0 //SDLK_0
#define KEY_INPUT_2 0 //SDLK_1
#define KEY_INPUT_3 0 //SDLK_3
#define KEY_INPUT_4 0 //SDLK_4
#define KEY_INPUT_5 0 //SDLK_5
#define KEY_INPUT_6 0 //SDLK_6
#define KEY_INPUT_7 0 //SDLK_7
#define KEY_INPUT_8 KEY_L //SDLK_8
#define KEY_INPUT_9 KEY_R //SDLK_9
#define KEY_INPUT_0 0 //SDLK_0


void UpdateKeys();
byte ProcessMessage();
byte CheckHitKey(int key);
byte CheckDownKey(int key);
byte WaitKey();

#define GetColor(r, g, b) RGBA8(r,g,b,0xff)

#define DrawGraph(a, b, mx, z) DrawGraphZ(a, b, mx)
void DrawGraphZ(int a, int b, sf2d_texture * mx);
void DrawGraphZ(int a, int b, t_graph * mx);

#define DrawTurnGraph(a, b, mx, z) DrawTurnGraphZ(a, b, mx)
void DrawTurnGraphZ(int a, int b, sf2d_texture * mx);
void DrawTurnGraphZ(int a, int b, t_graph * mx);

//#define DrawVertTurnGraph(x, y, e, a, mx, z) DrawRotaGraphZ(x, y, a, mx)
void DrawVertTurnGraph(int a, int b, sf2d_texture * mx);
void DrawVertTurnGraph(int a, int b, t_graph * mx);

t_graph *DerivationGraph(int srcx, int srcy, int width, int height,
			     sf2d_texture * src);

void DrawBG(int a, int b, sf2d_texture * mx);
void DrawBG(int a, int b, t_graph * mx);

void PlaySoundMem(SFX_s* s, int l);
void Mix_PlayMusic(SFX_s* m, int i);
void StopSoundMem(SFX_s* s);
void Mix_HaltMusic(void);


//Noticably different than the original
#define LoadGraph(filename) sfil_load_PNG_file(filename, SF2D_PLACE_RAM);
//SDL_Surface *LoadGraph(const char *filename);

#endif
