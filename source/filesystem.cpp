//shamelessly grabbed from Smealum's portal3DS
//https://github.com/smealum/portal3DS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>
#include "filesystem.h"


FILE* openFile(const char* fn, const char* mode)
{
	if(!fn || !mode)return NULL;
	return fopen(fn, mode);
}

void* bufferizeFile(const char* filename, u32* size, bool binary, bool linear)
{
	FILE* file;
	
	if(!binary)file = openFile(filename, "r");
	else file = openFile(filename, "rb");
	
	if(!file) return NULL;
	
	u8* buffer;
	long lsize;
	fseek (file, 0 , SEEK_END);
	lsize = ftell (file);
	rewind (file);
	if(linear)buffer=(u8*)linearMemAlign(lsize, 0x80);
	else buffer=(u8*)malloc(lsize);
	if(size)*size=lsize;
	
	if(!buffer)
	{
		fclose(file);
		return NULL;
	}
		
	fread(buffer, 1, lsize, file);
	fclose(file);
	return buffer;
}
