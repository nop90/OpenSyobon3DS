//shamelessly grabbed from Smealum's portal3DS
//https://github.com/smealum/portal3DS

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <3ds.h>

//void filesystemInit(int argc, char** argv);
//void filesystemExit();

FILE* openFile(const char* fn, const char* mode);
void* bufferizeFile(const char* filename, u32* size, bool binary, bool linear);

#endif
