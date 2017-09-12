#ifndef __SHIPS_H__
#define __SHIPS_H__

#include "ece210_api.h"

extern const uint8_t place_ships_bitmap[];
#define PLACE_SHIPS_WIDTH_PXL 	240
#define PLACE_SHIPS_HEIGHT_PXL	80

extern const uint8_t carrier_bitmap[];
#define CARRIER_WIDTH_PXL 	100
#define CARRIER_HEIGHT_PXL	20

extern const uint8_t battleship_bitmap[];
#define BATTLESHIP_WIDTH_PXL 	100
#define BATTLESHIP_HEIGHT_PXL	20

extern const uint8_t destroyer_bitmap[];
#define DESTROYER_WIDTH_PXL 	100
#define DESTROYER_HEIGHT_PXL	20

extern const uint8_t sub_bitmap[];
#define SUB_WIDTH_PXL 	100
#define SUB_HEIGHT_PXL	20

extern const uint8_t patrol_bitmap[];
#define PATROL_WIDTH_PXL 	100
#define PATROL_HEIGHT_PXL	20

typedef struct coord {
	int x;
	int y;
	bool hit;
} Coord;

Coord newCoord(int x, int y) {
	Coord c;
	c.x = x;
	c.y = y;
	c.hit = false;
	return c;
}

#endif
