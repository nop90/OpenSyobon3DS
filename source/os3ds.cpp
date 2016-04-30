#include "os3ds.h"


#include <sys/stat.h>
#include "Roboto_Regular_ttf.h"


sftd_font *font;
int sound;

//SDL_Joystick* joystick;

//bool keysHeld[SDLK_LAST];

int os3ds_Init()
{
    sf2d_init();
	sf2d_set_3D(false);
	
	sftd_init();
	
	romfsInit();
	
// In case game dir doesn't exist
    mkdir("/3ds", 0777);
    mkdir("/3ds/OpenSyobon3DS", 0777);

    font = sftd_load_font_mem(Roboto_Regular_ttf, Roboto_Regular_ttf_size);

	initSound();	
	sound = true;
    
    return 0;
}

//Main screen
//SDL_Surface *screen;

//Fonts
byte fontsize = 0;

//Strings
void SetFontSize(byte size)
{
    fontsize = size;
}

byte fontType = 0;//DX_FONTTYPE_NORMAL;
void ChangeFontType(byte type)
{
    fontType = type;
}

void DrawString(int a, int b, const char *x, int c)
{
	int shadow;
	
	shadow = (c==RGBA8(0x0, 0x0, 0x0, 0xff))?RGBA8(0xff, 0xff, 0xff, 0xff):RGBA8(0x0, 0x0, 0x0, 0xff);


	sftd_draw_text(font, 80 + a/scale-1, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale+1, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale-1, b/scale+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale+1, b/scale+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale-1, b/scale+1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale, b/scale+1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, 80 + a/scale+1, b/scale+1+y_off, shadow, fontsize/scale, x);

	sftd_draw_text(font, 80 + a/scale, b/scale+y_off, c, fontsize/scale, x);

}

void DrawFormatString(int a, int b, int color, const char *str, ...)
{
    va_list args;
    char *newstr = new char[strlen(str) + 16];
    va_start(args, str);
    vsprintf(newstr, str, args);
    va_end(args);
    DrawString(a, b, newstr, color);
    delete newstr;
}

bool ex = false;

void UpdateKeys()
{
	hidScanInput();
}

byte ProcessMessage()
{
    return aptMainLoop()?0:1 ;//ex;
}

byte CheckHitKey(int key)
{
    return (keysHeld()&key)?1:0;
}

byte CheckDownKey(int key)
{
    return (keysDown()&key)?1:0;
}

byte WaitKey()
{
    while (!hidKeysDown()) hidScanInput();
	
	return hidKeysDown(); 	
}

void DrawBG(int a, int b, sf2d_texture * mx)
{
	if(mx)
    {
		sf2d_draw_texture(mx, a,b);
	}
}

void DrawBG(int a, int b, t_graph * mx)
{
	if(mx)
    {
		sf2d_draw_texture_part(mx->texture, a,b,mx->x, mx->y, mx->width, mx->height);
	}
}


void DrawGraphZ(int a, int b, sf2d_texture * mx)
{
	if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, 1.08/scale);
	}
}
void DrawGraphZ(int a, int b, t_graph * mx)
{
	if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx->texture, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, 1.08/scale, 1.08/scale);
	}
}

void DrawTurnGraphZ(int a, int b, sf2d_texture * mx)
{
    if(mx)
    {

		sf2d_draw_texture_part_rotate_scale(mx, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, 1.08/scale);
    }
}

void DrawTurnGraphZ(int a, int b, t_graph * mx)
{
    if(mx)
    {

		sf2d_draw_texture_part_rotate_scale(mx->texture, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, -1.08/scale, 1.08/scale);
    }
}

void DrawVertTurnGraph(int a, int b, sf2d_texture * mx)
{
    if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, -1.08/scale);
    }
}

void DrawVertTurnGraph(int a, int b, t_graph * mx)
{
    if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx->texture, 80 + (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, 1.08/scale, -1.08/scale);
    }
}

t_graph *DerivationGraph(int srcx, int srcy, int width, int height,
			     sf2d_texture * src)
{

	if(!src) return NULL;
	t_graph * g;
	g = (t_graph*) malloc(sizeof(t_graph));
	g->texture=src;
	g->x=srcx;
	g->y=srcy;
	g->width=width;
	g->height=height;
	return g;
}


void PlaySoundMem(SFX_s* s, int l)
{
   if (s)
	if(sound && s->used) playSFX(s);
}

void Mix_PlayMusic(SFX_s* s, int l)
{
   if (s)
	if(sound && s->used) playMSC(s);
}

void StopSoundMem(SFX_s* s)
{
   stopSFX();
}

void Mix_HaltMusic(void)
{
   stopMSC();
}

