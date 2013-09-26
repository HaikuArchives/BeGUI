//utf8_char_len.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "utf8_char_len.h"

uint32 
utf8_char_len(uchar byte) 
{ 
	return (((0xE5000000 >> ((byte >> 3) & 0x1E)) & 3) + 1); 
}//end