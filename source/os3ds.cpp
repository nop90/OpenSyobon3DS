#include "os3ds.h"


#include "Roboto_Regular_ttf.h"
//#include "sazanami_gothic_ttf.h"

sftd_font *font;
int sound;

//SDL_Joystick* joystick;

//bool keysHeld[SDLK_LAST];

int os3ds_Init()
{
    sf2d_init();
	sf2d_set_3D(false);
	
	sftd_init();

    font = sftd_load_font_mem(Roboto_Regular_ttf, Roboto_Regular_ttf_size);
//    font = sftd_load_font_mem(sazanami_gothic_ttf, sazanami_gothic_ttf_size);

	initSound();	
	sound = true;
    

/*
    //Audio Rate, Audio Format, Audio Channels, Audio Buffers
#define AUDIO_CHANNELS 4
    if (sound && Mix_OpenAudio(22050, AUDIO_S16SYS, AUDIO_CHANNELS, 1024)) {
        fprintf(stderr, "Unable to init SDL_mixer: %s\n", Mix_GetError());
        sound = false;
        }
    //Try to get a joystick
    joystick = SDL_JoystickOpen(0);

    for (int i = 0; i < SDLK_LAST; i++)
	keysHeld[i] = false;
    for (int i = 0; i < FONT_MAX; i++)
	font[i] = NULL;
    srand(time(NULL));
*/
    return 0;
}

//Main screen
//SDL_Surface *screen;

//Fonts
byte fontsize = 0;
//TTF_Font *font[FONT_MAX];

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

void DrawString(int a, int b, const char *x, u32 c)
{
	int shadow;
	
	shadow = (c==RGBA8(0x0, 0x0, 0x0, 0xff))?RGBA8(0xff, 0xff, 0xff, 0xff):RGBA8(0x0, 0x0, 0x0, 0xff);


	sftd_draw_text(font, a/scale-1, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale+1, b/scale-1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale-1, b/scale+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale+1, b/scale+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale-1, b/scale+1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale, b/scale+1+y_off, shadow, fontsize/scale, x);
	sftd_draw_text(font, a/scale+1, b/scale+1+y_off, shadow, fontsize/scale, x);

	sftd_draw_text(font, a/scale, b/scale+y_off, c, fontsize/scale, x);

}

void DrawFormatString(int a, int b, u32 color, const char *str, ...)
{
    va_list args;
    char *newstr = new char[strlen(str) + 16];
    va_start(args, str);
    vsprintf(newstr, str, args);
    va_end(args);
    DrawString(a, b, newstr, color);
    delete newstr;
}

//void DrawFormatString(int a, int b, int c

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
//    if(key == SDLK_z && keysHeld[SDLK_SEMICOLON]) return true;
    return (keysHeld()&key)?1:0;
}

byte CheckDownKey(int key)
{
//    if(key == SDLK_z && keysHeld[SDLK_SEMICOLON]) return true;
    return (keysDown()&key)?1:0;
}

byte WaitKey()
{
    while (!hidKeysDown()) hidScanInput();
	
	return hidKeysDown(); 	
/*	
	SDL_Event event;
    while (true) {
	while (SDL_PollEvent(&event))
	    if (event.type == SDL_KEYDOWN)
		return event.key.keysym.sym;
    }
*/
}

/*Uint32 GetColor(byte r, byte g, byte b)
{
    return r << 8 * 3 | g << 8 * 2 | b << 8 | 0xFF;
}*/


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
		sf2d_draw_texture_part_rotate_scale(mx, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, 1.08/scale);
	}
}
void DrawGraphZ(int a, int b, t_graph * mx)
{
	if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx->texture, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, 1.08/scale, 1.08/scale);
	}
}

void DrawTurnGraphZ(int a, int b, sf2d_texture * mx)
{
    if(mx)
    {

		sf2d_draw_texture_part_rotate_scale(mx, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, 1.08/scale);
    }
}

void DrawTurnGraphZ(int a, int b, t_graph * mx)
{
    if(mx)
    {

		sf2d_draw_texture_part_rotate_scale(mx->texture, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, -1.08/scale, 1.08/scale);
    }
}

void DrawVertTurnGraph(int a, int b, sf2d_texture * mx)
{
    if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, 0, 0, mx->width, mx->height, 1.08/scale, -1.08/scale);
    }
}

void DrawVertTurnGraph(int a, int b, t_graph * mx)
{
    if(mx)
    {
		sf2d_draw_texture_part_rotate_scale(mx->texture, (a+mx->width/2)/scale, (b+mx->height/2)/scale+y_off, 0, mx->x, mx->y, mx->width, mx->height, 1.08/scale, -1.08/scale);
    }
}

t_graph *DerivationGraph(int srcx, int srcy, int width, int height,
			     sf2d_texture * src)
{

	t_graph * g;
	g = (t_graph*) malloc(sizeof(t_graph));
	g->texture=src;
	g->x=srcx;
	g->y=srcy;
	g->width=width;
	g->height=height;
	return g;
}


//Noticably different than the original
/*
SDL_Surface *LoadGraph(const char *filename)
{
    SDL_Surface *image = IMG_Load(filename);

    if (image) return image;
	fprintf(stderr, "Error: Unable to load %s: %s\n", filename, IMG_GetError());
	exit(1);
}
*/
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


/*
char * LoadSoundMem(const char* f)
{

    if(!sound) return NULL;

    Mix_Chunk* s = Mix_LoadWAV(f);
    if(s) return s;
    fprintf(stderr, "Error: Unable to load sound %s: %s\n", f, Mix_GetError());

    return NULL;
}

char* LoadMusicMem(const char* f)
{

    if(!sound) return NULL;

    Mix_Music* m = Mix_LoadMUS(f);
    if(m) return m;
    fprintf(stderr, "Error: Unable to load music %s: %s\n", f, Mix_GetError());
 
   return NULL;
}
*/
