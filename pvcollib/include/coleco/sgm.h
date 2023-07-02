/*---------------------------------------------------------------------------------

	Generic sgm system functions

	Copyright (C) 2021
		Alekmaul

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you
		must not claim that you wrote the original software. If you use
		this software in a product, an acknowledgment in the product
		documentation would be appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and
		must not be misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source
		distribution.

---------------------------------------------------------------------------------*/
/**
 * \file sgm.h
 * \brief contains the basic definitions for controlling the sgm system device.
 *
 * This unit provides generic features related to sgm device.<br>
 *<br>
 * Here is the list of features:<br>
 * - enable and disable sgm<br>
*/

#ifndef COL_SGM_INCLUDE
#define COL_SGM_INCLUDE

#include <coleco/coltypes.h>


#define QNOTE 13

struct notes {
	unsigned char low;
	unsigned char high;
};
/*
08E3: 4E 05   ;   82.36 2E
08E5: 01 05   ;   87.31 2F
08E7: B9 04   ;   92.51 2F#
08E9: 76 04   ;   97.94 2G
08EB: 36 04   ;  103.75 2G#
08ED: F9 03   ;  109.97 2A
08EF: C0 03   ;  116.50 2A#
08F1: 8A 03   ;  123.45 2B
08F3: 57 03   ;  130.81 3C
08F5: 27 03   ;  138.59 3C#
08F7: FA 02   ;  146.78 3D
08F9: CF 02   ;  155.56 3D#
08FB: A7 02   ;  164.72 3E
08FD: 81 02   ;  174.49 3F
08FF: 5D 02   ;  184.87 3F#
0901: 3B 02   ;  195.88 3G
0903: 1B 02   ;  207.51 3G#
0905: FD 01   ;  219.74 3A
0907: E0 01   ;  233.01 3A#
0909: C5 01   ;  246.90 3B
090B: AC 01   ;  261.32 4C
090D: 94 01   ;  276.85 4C#
090F: 7D 01   ;  293.56 4D
0911: 68 01   ;  310.68 4D#
0913: 53 01   ;  329.93 4E
0915: 40 01   ;  349.52 4F
0917: 2E 01   ;  370.35 4F#
0919: 1D 01   ;  392.44 4G
091B: 0D 01   ;  415.79 4G#
091D: FE 00   ;  440.34 4A
091F: F0 00   ;  466.03 4A#
0921: E3 00   ;  492.72 4B
0923: D6 00   ;  522.65 5C
0925: CA 00   ;  553.70 5C#
0927: BE 00   ;  588.67 5D
0929: B4 00   ;  621.37 5D#
092B: AA 00   ;  657.93 5E*/
static const struct notes main_song_a[] = {
	{.low = 0xe3, .high = 0x00}, // 4B
	{0x1d, 0x01}, // 4G
	{0x1d, 0x01}, // 4G
	{0x1d, 0x01}, // 4G
 	{0xe3, 0x00}, // 4B
	{0x1d, 0x01}, // 4G
	{0x1d, 0x01}, // 4G
	{0x1d, 0x01}, // 4G
	{0xd6, 0x00}, // 5C
	{0xd6, 0x00}, // 5C
	{0xe3, 0x00}, // 4B
	{0xe3, 0x00}, // 4B
	{0xfe, 0x00}, // 4A
	{0xFF, 0xFF}, //rest TODO
	{0xd6, 0x00}, // 5C
	{0xd6, 0x00}, // 5C
	{0xe3, 0x00}, // 4B
	{0xe3, 0x00}, // 4B
	{0xfe, 0x00}, // 4A
	{0xfe, 0x00}, // 4A
	{0xAA, 0x00}, // 5E
	{0xAA, 0x00}, // 5E
	{0xBE, 0x00}, // 5D
	{0xd6, 0x00}, // 5C
	{0xe3, 0x00}, // 4B
	{0xfe, 0x00}, // 4A
	{0x1d, 0x01}, // 4G
	{0x00, 0x00},
};

static const struct notes main_song_b[] = {
	{0x3b, 0x02}, // 3G
	{0xc5, 0x01}, // 3B
	{0xFA, 0x02}, // 3D
	{0xc5, 0x01}, // 3B
	{0x3b, 0x02}, // 3G
	{0xc5, 0x01}, // 3B
	{0xFA, 0x02}, // 3D
	{0xc5, 0x01}, // 3B
	{0xFD, 0x01}, // 3A
	{0xAC, 0x01}, // 4C
	{0xFA, 0x02}, // 3D
	{0xAC, 0x01}, // 4C
	{0xFD, 0x01}, // 3A
	{0xAC, 0x01}, // 4C
	{0xFA, 0x02}, // 3D
	{0xAC, 0x01}, // 4C
	{0xFD, 0x01}, // 3A
	{0xAC, 0x01}, // 4C
	{0xFA, 0x02}, // 3D
	{0xAC, 0x01}, // 4C
	{0xFD, 0x01}, // 3A
	{0xAC, 0x01}, // 4C
	{0xFA, 0x02}, // 3D
	{0xAC, 0x01}, // 4C
	{0xFD, 0x01}, // 3A
	{0xAC, 0x01}, // 4C
	{0xFA, 0x02}, // 3D
	{0xAC, 0x01}, // 4C
	{0xc5, 0x01}, // 3B
	{0xFF, 0xFF}, // Reset
	{0x00, 0x00},
};

static const struct notes main_song_c[] = {
	{0xFF, 0xFF}, // Reset
	{0x3b, 0x02}, // 3G
	{0xFF, 0xFF}, // Reset
	{0x3b, 0x02}, // 3G
	{0xFF, 0xFF}, // Reset
	{0x3b, 0x02}, // 3G
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0xFD, 0x01}, // 3A
	{0xFF, 0xFF}, // Reset
	{0x3b, 0x02}, // 3G
	{0xFF, 0xFF}, // Reset
	{0x00, 0x00},
};

/**
 *  \brief sys_sgmok is set if sgm module is present<br>
 *	when calling sys_sgminit function<br>
 */
extern volatile u8 sys_sgmok;

/**
 *  \brief sgm_aycntl is r/w sgm module ay ctl register<br>
 *	<br>
 */
extern volatile u8 sys_sgm_aycntl;

/**
 * \fn void sys_sgminit(void)
 * \brief Activate sgm device<br>
 * Activate SGM and init sys_sgmok variable with 1 if it is ok<br>
*/
void sys_sgminit(void);
void sys_sgm_get_ay8910(void);
void sys_sgm_set_ay8910(unsigned char, unsigned char);

#endif
