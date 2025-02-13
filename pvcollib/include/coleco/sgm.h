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

/**
 *  \brief sys_sgmok is set if sgm module is present<br>
 *	when calling sys_sgminit function<br>
 */
extern volatile u8 sys_sgmok;

/**
 *  \brief sgm_aycntl allows reading of sgm module ay registers<br>
 *	<br>
 */
extern volatile u8 sys_sgm_aycntl;

/**
 * \fn void sys_sgminit(void)
 * \brief Activate sgm device<br>
 * Activate SGM and init sys_sgmok variable with 1 if it is ok<br>
*/
void sys_sgminit(void);

/**
 * \fn void sys_get_ay8910(void)
 * \brief Read AY-3-8910 register value<br>
 * Read Value from register in sys_sgm_ayctrl, value returned<br>
*/
void sys_get_ay8910(void);
u8 sys_sgm_get_ay8910(u8);

/**
 * \fn void sys_sgmset_ay8910(reg, value)
 * \brief Set AY-3-8910 Registers to value<br>
 * Write value to reg where reg = 0-15<br>
*/
void sys_sgm_set_ay8910(u8, u8);

#endif
