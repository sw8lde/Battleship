#include "lab_buttons.h"

const uint8_t game_board_bitmap[] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xf0,0x0f,0xff,0xf3,0xff,0xf8,0x03,0xff,0xc0,0x1f,0xfe,0x7c,0xff,0xf0,0x03,0xff,0xc0,0x1f,0xf8,0x00,0xff,0xf0,0x0f,0xff,0x80,0x7f
	,0xff,0xff,0xff,0xff,0xe0,0x07,0xff,0xe3,0xff,0xf8,0x01,0xff,0xc0,0x0f,0xfe,0x7c,0xff,0xf0,0x03,0xff,0x80,0x1f,0xf8,0x00,0xff,0xe0,0x07,0xff,0x00,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xe3,0xff,0xff,0xf9,0xff,0xff,0xcf,0xfe,0x7c,0xff,0xf3,0xff,0xff,0x9f,0xff,0xff,0xfc,0xff,0xe7,0xe7,0xff,0x3f,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xff,0xf9,0xff,0xff,0xcf,0xfe,0x7c,0xff,0xf3,0xff,0xff,0x9f,0xff,0xff,0xfc,0xff,0xe7,0xe7,0xff,0x3f,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xff,0xf9,0xff,0xff,0xcf,0xfe,0x7c,0xff,0xf3,0xff,0xff,0x9f,0xff,0xff,0xf9,0xff,0xe7,0xe7,0xff,0x3f,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xff,0xf9,0xff,0xff,0xcf,0xfe,0x7c,0xff,0xf3,0xff,0xff,0x9f,0xff,0xff,0xf9,0xff,0xe7,0xe7,0xff,0x3f,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xfc,0x01,0xff,0xc0,0x0f,0xfe,0x00,0x7f,0xf0,0x07,0xff,0x80,0x3f,0xff,0xf3,0xff,0xf0,0x0f,0xff,0x00,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xf8,0x03,0xff,0xc0,0x0f,0xfe,0x00,0x7f,0xf0,0x03,0xff,0x80,0x1f,0xff,0xf3,0xff,0xf0,0x0f,0xff,0x80,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xf9,0xff,0xff,0xff,0xcf,0xff,0xfc,0xff,0xff,0xf3,0xff,0x9f,0x9f,0xff,0xe7,0xff,0xe7,0xe7,0xff,0xff,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xf9,0xff,0xff,0xff,0xcf,0xff,0xfc,0xff,0xff,0xf3,0xff,0x9f,0x9f,0xff,0xe7,0xff,0xe7,0xe7,0xff,0xff,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xf9,0xff,0xff,0xff,0xcf,0xff,0xfc,0xff,0xff,0xf3,0xff,0x9f,0x9f,0xff,0xcf,0xff,0xe7,0xe7,0xff,0xff,0x3f
	,0xff,0xff,0xff,0xff,0xe7,0xe7,0xff,0xf3,0xff,0xf9,0xff,0xff,0xff,0xcf,0xff,0xfc,0xff,0xff,0xf3,0xff,0x9f,0x9f,0xff,0xcf,0xff,0xe7,0xe7,0xff,0xff,0x3f
	,0xff,0xff,0xff,0xff,0xe0,0x07,0xff,0xf3,0xff,0xf8,0x01,0xff,0xc0,0x0f,0xff,0xfc,0xff,0xf0,0x03,0xff,0x80,0x1f,0xff,0xcf,0xff,0xe0,0x07,0xff,0x00,0x3f
	,0xff,0xff,0xff,0xff,0xf0,0x0f,0xff,0xf3,0xff,0xfc,0x01,0xff,0xc0,0x1f,0xff,0xfc,0xff,0xf0,0x07,0xff,0xc0,0x3f,0xff,0xcf,0xff,0xf0,0x0f,0xff,0x00,0x7f
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x80,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x80,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x80,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x80,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x38,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x38,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x80,0x7b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x00,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x3f,0x3b,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xe1,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xf3,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x33,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x33,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x03,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0x87,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe,0xff,0xff,0xf7,0xff,0xff,0xbf,0xff,0xfd,0xff,0xff,0xef,0xff,0xff,0x7f,0xff,0xfb,0xff,0xff,0xdf,0xff,0xfe
	,0xff,0xff,0xff,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};