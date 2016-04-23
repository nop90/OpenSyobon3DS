//shamelessly grabbed from Smealum's portal3DS
//https://github.com/smealum/portal3DS


#include <stdlib.h>
#include <stdio.h>
#include <3ds.h>
#include "sfx.h"
#include "filesystem.h"

SFX_s SFX[NUMSFX];

bool soundEnabled;

void initSound()
{
	int i;
	for(i=0;i<NUMSFX;i++)
	{
		SFX[i].used=false;
	}

	if(csndInit()==0)soundEnabled=true;
	else soundEnabled=false;
}

void exitSound(void)
{
	int i;
	for(i=0;i<NUMSFX;i++)
	{
		if(SFX[i].used)
		{
			if(SFX[i].data)
			{
				linearFree(SFX[i].data);
				SFX[i].data=NULL;
			}
			SFX[i].used=false;
		}
	}
	if(soundEnabled)csndExit();
}

void initSFX(SFX_s* s)
{
	if(!s)return;

	s->data=NULL;
	s->size=0;
	s->used=true;
}

void loadSFX(SFX_s* s, const char* filename, u32 format)
{
	if(!s)return;

	initSFX(s);

	s->data=(u8*) bufferizeFile(filename, &s->size, true, true);
	s->format=format;
}

SFX_s* createSFX(const char* filename, u32 format)
{
	int i;
	for(i=0;i<NUMSFX;i++)
	{
		if(!SFX[i].used)
		{
			loadSFX(&SFX[i], filename, format);

			if(!SFX[i].data)return NULL;
			return &SFX[i];
		}
	}
	return NULL;
}

int channel;

void playSFX(SFX_s* s)
{
	if(!s || !s->used || !s->data || !soundEnabled)return;

	channel++;
	channel%=7;

	csndPlaySound(channel+8, s->format, 22050, 1.0, 0.0, (u32*)s->data, (u32*)s->data, s->size);
}

void playMSC(SFX_s* s)
{
//	CSND_SetPlayState(15, 0);//Stop music audio playback.
//	csndExecCmds(0);
	if(!s || !s->used || !s->data || !soundEnabled)return;
	csndPlaySound(15, s->format | SOUND_REPEAT, 22050, 1.0, 0.0, (u32*)s->data, (u32*)s->data, s->size);
}

void stopSFX(void)
{
	int i;
	for (i=0;i<7;i++)
		CSND_SetPlayState(8+i, 0);//Stop music audio playback.
	csndExecCmds(0);
}

void stopMSC(void)
{
	CSND_SetPlayState(15, 0);//Stop music audio playback.
	csndExecCmds(0);
}