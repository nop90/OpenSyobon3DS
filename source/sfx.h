//shamelessly grabbed from Smealum's portal3DS
//https://github.com/smealum/portal3DS

#ifndef SFX_H
#define SFX_H

#define NUMSFX (32)

typedef struct
{
	u8* data;
	u32 size;
	u32 format;
	bool used;
}SFX_s;

void initSound(void);
void exitSound(void);
void initSFX(SFX_s* s);
void loadSFX(SFX_s* s, const char* filename, u32 format);
SFX_s* createSFX(const char* filename, u32 format);
void playSFX(SFX_s* s);
void playMSC(SFX_s* s);
void stopSFX(void);
void stopMSC(void);

#endif
