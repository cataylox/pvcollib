/*---------------------------------------------------------------------------------


	sgm test with no specific feature
	-- alekmaul


---------------------------------------------------------------------------------*/
#include "sgmtest.h"

//---------------------------------------------------------------------------------
// The NMI routine. Gets called 50 or 60 times per second 
// nothing to update for bitmap example
void nmi (void) {
}

void show_ay8910(void) {
	char i = 0; 
	score_t score = {0,0};

	for (i = R0; i <= R15 ; i++) {
		sys_sgm_aycntl = i;
		sys_sgm_get_ay8910();
		score.lo = i;
		vdp_putstring(4,6+i,"R");
		vdp_putstring(5,6+i,sys_scostr(&score,2));
		vdp_putstring(8,6+i,sys_str(sys_sgm_aycntl));
	}
}
//---------------------------------------------------------------------------------
void main (void) {
	unsigned char i = 0;
	unsigned char delay = 0;
	// Check if sgm is available
	sys_sgminit();

	// Put screen in text mode 2
	vdp_setmode2txt();

	// Put default char in VRAM and duplicate to all areas
	//  as we are going to write to line 8, it is in the second area
	vdp_setdefaultchar(FNTNORMAL);
	vdp_duplicatevram();
	vdp_fillvram(0x2000,0xf1,128*8); 	// Change color (or we will see nothing)
	vdp_enablescr();

    // Check now if we were ok with SGM initialization
    if (sys_sgmok==1) {
        // Print text as we are not going to do something else
		vdp_putstring(4,1,"YEAH SGM SUPPORT IS OK !");
    } else {
        // Print text as we are not going to do something else
		vdp_putstring(8,5,"NO SGM SUPPORT...");
	}

	// Wait for nothing :P
	while(1) {
		// Wait Vblank
		vdp_waitvblank(1);
		if (sys_sgmok==1) {
			if (i==0) {
				vdp_putstring(4,3,"AY-3-8910 registers");
				sys_sgm_set_ay8910(R8, 12);
				sys_sgm_set_ay8910(R9, 12);
				sys_sgm_set_ay8910(R10, 12);
				sys_sgm_set_ay8910(R7, 0x38);
			}

			if (delay++ < QNOTE) {
				if (delay > (QNOTE-2)) {
					sys_sgm_set_ay8910(R0, 0);
					sys_sgm_set_ay8910(R1, 0);
					sys_sgm_set_ay8910(R2, 0);
					sys_sgm_set_ay8910(R3, 0);
					sys_sgm_set_ay8910(R4, 0);
					sys_sgm_set_ay8910(R5, 0);
				} 
				continue;
			}

			if(main_song_a[i].fine == 0) {
				sys_sgm_set_ay8910(R7, 0x3f);
				sys_sgm_set_ay8910(R8, 0);
				sys_sgm_set_ay8910(R9, 0);
				sys_sgm_set_ay8910(R10, 0);
				show_ay8910();
				if (joypad_1 & PAD_RIGHT)
					i=0; // Restart song
			} else {
				if (main_song_a[i].course != 255) {	
					sys_sgm_set_ay8910(R0, main_song_a[i].fine);
					sys_sgm_set_ay8910(R1, main_song_a[i].course);
				}
				if (main_song_b[i].course != 255) {	
					sys_sgm_set_ay8910(R2, main_song_b[i].fine);
					sys_sgm_set_ay8910(R3, main_song_b[i].course);
				}
				if (main_song_c[i].course != 255) {	
					sys_sgm_set_ay8910(R4, main_song_c[i].fine);
					sys_sgm_set_ay8910(R5, main_song_c[i].course);
				}
				show_ay8910();
				i++;
			}
			delay = 0;
		}
	}

	// startup module will issue a soft reboot if it comes here 
}
