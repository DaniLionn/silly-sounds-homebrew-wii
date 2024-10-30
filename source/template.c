//Silly Sound Maker
//DaniLionn, 2024
//Made using the devkitPPC MP3 player template!

#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>
#include <mp3player.h>

// include generated header
#include "sound0_mp3.h"
#include "sound1_mp3.h"
#include "sound2_mp3.h"
#include "sound3_mp3.h"
#include "sound4_mp3.h"
#include "sound5_mp3.h"
#include "sound6_mp3.h"
#include "sound7_mp3.h"
#include "sound8_mp3.h"
#include "sound9_mp3.h"
#include "sound10_mp3.h"
#include "sound11_mp3.h"
#include "sound12_mp3.h"
#include "sound13_mp3.h"
#include "sound14_mp3.h"
#include "sound15_mp3.h"
#include "sound16_mp3.h"
#include "sound17_mp3.h"
#include "sound18_mp3.h"
#include "sound19_mp3.h"
#include "sound20_mp3.h"
#include "sound21_mp3.h"
#include "sound22_mp3.h"
#include "sound23_mp3.h"
#include "sound24_mp3.h"
#include "sound25_mp3.h"

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

//---------------------------------------------------------------------------------
int main(int argc, char **argv) {
//---------------------------------------------------------------------------------

	// Initialise the video system
	VIDEO_Init();

	// Initialise the attached controllers
	WPAD_Init();

	// Initialise the audio subsystem
	ASND_Init();
	MP3Player_Init();

	// Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);

	// Allocate memory for the display in the uncached region
	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));

	// Initialise the console, required for printf
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);

	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);

	// Tell the video hardware where our display memory is
	VIDEO_SetNextFramebuffer(xfb);

	// Make the display visible
	VIDEO_SetBlack(false);

	// Flush the video register changes to the hardware
	VIDEO_Flush();

	// Wait for Video setup to complete
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();


	// The console understands VT terminal escape codes
	// This positions the cursor on row 2, column 0
	// we can use variables for this with format codes too
	// e.g. printf ("\x1b[%d;%dH", row, column );
	printf("\x1b[2;0H");

	printf("SILLY SOUND MAKER\nPress any button to make a sound!\nPress HOME to exit.\n");



	while(1) {

		// Call WPAD_ScanPads each loop, this reads the latest controller states
		WPAD_ScanPads();

		// WPAD_ButtonsDown tells us which buttons were pressed in this loop
		// this is a "one shot" state which will not fire again until the button has been released
		u32 pressed = WPAD_ButtonsDown(0);

		// We return to the launcher application via exit
		if ( pressed & WPAD_BUTTON_HOME ) exit(0);
		if ( pressed & WPAD_BUTTON_A ) 	MP3Player_PlayBuffer(sound0_mp3, sound0_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_B ) 	MP3Player_PlayBuffer(sound1_mp3, sound1_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_1 ) 	MP3Player_PlayBuffer(sound2_mp3, sound2_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_2 ) 	MP3Player_PlayBuffer(sound3_mp3, sound3_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_PLUS ) 	MP3Player_PlayBuffer(sound4_mp3, sound4_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_MINUS ) 	MP3Player_PlayBuffer(sound5_mp3, sound5_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_UP ) 	MP3Player_PlayBuffer(sound6_mp3, sound6_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_DOWN ) 	MP3Player_PlayBuffer(sound7_mp3, sound7_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_LEFT ) 	MP3Player_PlayBuffer(sound8_mp3, sound8_mp3_size, NULL);
		if ( pressed & WPAD_BUTTON_RIGHT ) 	MP3Player_PlayBuffer(sound9_mp3, sound9_mp3_size, NULL);
		if ( pressed & WPAD_NUNCHUK_BUTTON_C ) 	MP3Player_PlayBuffer(sound10_mp3, sound10_mp3_size, NULL);
		if ( pressed & WPAD_NUNCHUK_BUTTON_Z ) 	MP3Player_PlayBuffer(sound11_mp3, sound11_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_A) 	MP3Player_PlayBuffer(sound12_mp3, sound12_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_B) 	MP3Player_PlayBuffer(sound13_mp3, sound13_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_X) 	MP3Player_PlayBuffer(sound14_mp3, sound14_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_Y) 	MP3Player_PlayBuffer(sound15_mp3, sound15_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_PLUS) 	MP3Player_PlayBuffer(sound16_mp3, sound16_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_MINUS) 	MP3Player_PlayBuffer(sound17_mp3, sound17_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_FULL_L) 	MP3Player_PlayBuffer(sound18_mp3, sound18_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_FULL_R) 	MP3Player_PlayBuffer(sound19_mp3, sound19_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_ZL) 	MP3Player_PlayBuffer(sound20_mp3, sound20_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_ZR) 	MP3Player_PlayBuffer(sound21_mp3, sound21_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_UP) 	MP3Player_PlayBuffer(sound22_mp3, sound22_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_DOWN) 	MP3Player_PlayBuffer(sound23_mp3, sound23_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_LEFT) 	MP3Player_PlayBuffer(sound24_mp3, sound24_mp3_size, NULL);
		if ( pressed & WPAD_CLASSIC_BUTTON_RIGHT) 	MP3Player_PlayBuffer(sound25_mp3, sound25_mp3_size, NULL);

		// Wait for the next frame
		VIDEO_WaitVSync();
	}

	return 0;
}
