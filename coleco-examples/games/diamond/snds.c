// this file contains sounds
//  converted from asm to C

#include "snds.h"

const u8 sound1[]={
    0x40,0x25,0x62,1,
    0x40,0x74,0x51,1,
    0x40,0x86,0x00,2,
    0x50,
};

const u8 sound2[]={
    0x80,0xdb,0x01,1,
    0x80,0x7b,0x02,1,
    0x80,0xf0,0x21,1,
    0x80,0x2c,0x22,1,
    0x80,0x4c,0x32,1,
    0x80,0x98,0x52,1,
    0x80,0xfe,0x81,1,
    0x80,0x7f,0xa1,1,
    0x90,
};

const u8 sound3[]={
    0xc0,0xcc,0x50,1,
    0xc0,0xdc,0x00,1,
    0xc0,0x3f,0x01,1,
    0xc0,0xac,0x01,1,
    0xc0,0x13,0x02,1,
    0xc0,0x82,0x02,1,
    0xc0,0xde,0x02,1,
    0xc0,0x33,0x03,1,
    0xc0,0x91,0x03,1,
    0xed,
    0xc0,0xbb,0xa0,1,
    0xc0,0xb8,0x90,1,
    0xc0,0x3d,0x91,1,
    0xc0,0xb4,0x91,1,
    0xc0,0x54,0x92,1,
    0xc0,0xbe,0x92,1,
    0xc0,0x44,0xa3,1,
    0xc0,0xb1,0xa3,1 ,
    0xd0,
};

const u8 sound4[]={
    0x02,0x14,64,0x12,0x42,
    0x10,
};

const u8 sound5[]={
    0x40,0x1d,0x51,6,
    0x40,0xd5,0x50,6,
    0x40,0xa9,0x50,6,
    0x40,0xd5,0x50,6,
    0x40,0xa9,0x50,6,
    0x40,0x8e,0x50,6,
    0x40,0xa9,0x50,6,
    0x40,0x8e,0x50,6,
    0x40,0x6a,0x50,24,
    0x50,
};

const u8 sound6[]={
    0x80,0x3a,0x52,6,
    0x80,0xab,0x51,6,
    0x80,0x53,0x51,6,
    0x80,0x1d,0x51,6,
    0x80,0xd5,0x50,6,
    0x80,0xa9,0x50,6,
    0x80,0xd5,0x50,6,
    0x80,0xa9,0x50,6,
    0x80,0x8e,0x50,24,
    0x90,
};

//---------------------------------------------------------------------------------
// mandatory soundtable declaration
// For some reason the very first entry MUST be SOUNDAREA1.  SOUNDAREA1 is the lowest priority sound effect.  
// I recommend using SOUNDAREA1-SOUNDAREA3 to be music track. SOUNDAREA4-6 to be sound effects. 
const sound_t snd_table[]={
	{ sound1,			  				SOUNDAREA1},	// sound entry 1	
	{ sound2,			  				SOUNDAREA2},	// sound entry 2	
	{ sound3,			  				SOUNDAREA3},	// sound entry 3	
	{ sound4,			  				SOUNDAREA4},	// sound entry 4	
	{ sound5,			  				SOUNDAREA5},	// sound entry 5	
	{ sound6,			  				SOUNDAREA6},	// sound entry 6
};
