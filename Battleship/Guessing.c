#include "lab_buttons.h"

const uint8_t guessing_bitmap[] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdd,0x8d,0xd0,0xfc,0x17,0x43,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0x86,0x1c,0x6e,0x82,0xe8,0x30,0xf8,0x2e,0x86,0xef,0xff,0xff,0xff,0xff
	,0xdd,0x75,0xd7,0x7f,0x77,0x5d,0x37,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xba,0xeb,0xa6,0xbe,0x6e,0xef,0xfe,0xee,0xba,0x6f,0xff,0xff,0xff,0xff
	,0xdd,0x75,0xd7,0x7f,0x77,0x5d,0x57,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xba,0xeb,0xaa,0xbe,0xae,0xef,0xfe,0xee,0xba,0xaf,0xff,0xff,0xff,0xff
	,0xe3,0x75,0xd0,0xff,0x77,0x43,0x67,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0x86,0x1b,0xac,0x86,0xce,0xf1,0xfe,0xee,0x86,0xcf,0xff,0xff,0xff,0xff
	,0xf7,0x75,0xd7,0x7f,0x77,0x5d,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xbe,0xfb,0xae,0xbe,0xee,0xfe,0xfe,0xee,0xba,0xef,0xff,0xff,0xff,0xff
	,0xf7,0x75,0xd7,0x7f,0x77,0x5d,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xbe,0xfb,0xae,0xbe,0xee,0xfe,0xfe,0xee,0xba,0xef,0xff,0xff,0xff,0xff
	,0xf7,0x8e,0x37,0x7f,0x78,0xdd,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xbe,0xfc,0x6e,0x82,0xee,0xe1,0xfe,0xf1,0xba,0xef,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x8e,0x10,0x7e,0x17,0x41,0x86,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xc7,0x08,0x3f,0x0b,0xa0,0xc3,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x75,0xfd,0xfd,0xf7,0x5f,0x7d,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xba,0xfe,0xfe,0xfb,0xaf,0xbe,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x75,0xfd,0xfd,0xf7,0x5f,0x7d,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xba,0xfe,0xfe,0xfb,0xaf,0xbe,0xfb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x06,0x3d,0xfd,0x97,0x43,0x8e,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0x83,0x1e,0xfe,0xcb,0xa1,0xc7,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x77,0xdd,0xfd,0xd7,0x5f,0xf7,0xd7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xbb,0xee,0xfe,0xeb,0xaf,0xfb,0xeb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xdf,0x77,0xdd,0xfd,0xd7,0x5f,0xf7,0xd7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xbb,0xee,0xfe,0xeb,0xaf,0xfb,0xeb,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xc1,0x74,0x3d,0xfe,0x18,0xc1,0x0c,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xba,0x1e,0xff,0x0c,0x60,0x86,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd8,0x61,0x83,0x0c,0x3d,0xd0,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xae,0xbe,0xfb,0xfd,0xd7,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xae,0xbe,0xfb,0xfd,0xd7,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd8,0x61,0x87,0x1c,0x7d,0xd0,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xee,0xbf,0xef,0xbd,0xd7,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xee,0xbf,0xef,0xbd,0xd7,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdb,0xee,0x82,0x18,0x7e,0x37,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xd8,0x31,0xfc,0x2e,0x83,0x0c,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xee,0xfb,0xee,0xbe,0xfb,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xee,0xfb,0xee,0xbe,0xfb,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xee,0xfb,0x2e,0x87,0x1c,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xee,0xfb,0xae,0xbf,0xef,0xb7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xee,0xfb,0xae,0xbf,0xef,0xb7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xde,0xf1,0xfc,0x71,0x82,0x18,0x77,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x00,0x00,0x00,0x00,0x00,0x07,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xc1,0x8c,0x18,0xdf,0xf7,0x50,0x61,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xc6,0x0c,0x6f,0xfb,0xa8,0x30,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x77,0x77,0x5f,0xf7,0x5d,0xdf,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbb,0xbb,0xaf,0xfb,0xae,0xef,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x77,0x77,0x5f,0xf7,0x5d,0xdf,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbb,0xbb,0xaf,0xfb,0xae,0xef,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x77,0x70,0x5f,0xf0,0x5d,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbb,0xb8,0x2f,0xf8,0x2e,0xf1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x77,0x77,0x5f,0xf7,0x5d,0xfd,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbb,0xbb,0xaf,0xfb,0xae,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x77,0x77,0x5f,0xf7,0x5d,0xfd,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xbb,0xbb,0xaf,0xfb,0xae,0xfe,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff
	,0xf7,0x8f,0x77,0x41,0xf7,0x5d,0xc3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xc7,0xbb,0xa0,0xfb,0xae,0xe1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
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
	,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};
