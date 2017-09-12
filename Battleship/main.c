//*****************************************************************************
// main.c
// Author: swilde2@wisc.edu
//*****************************************************************************
#include "lab_buttons.h"
#include "welcomeScreen.h"
#include "Ships.h"
#include "Guessing.h"
#include "GameBoard.h"
#include "GameOver.h"
/******************************************************************************
 * Global Constants and Variables
 *****************************************************************************/
#define COLOR_PRIMARY		LCD_COLOR_BLUE
#define LOCAL_ID     0x93
#define REMOTE_ID    0x91

// Turn Debuggin off
#undef DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x) printf x
#else
#define DEBUG_PRINT(x) do {} while (0)
#endif

int defenseGameBoard[10][10];
int attackGameBoard[10][10];

int myHits = 0;
int theirHits = 0;
Coord myGuess;
Coord theirGuess;
/******************************************************************************
 * Funtion declarations
 *****************************************************************************/
void welcomeScreen(void);
void placeShips(void);
void updateDefenseBoard(void);
void updateAttackBoard(void);
void attack(void);
void defend(void);
void win(void);
void loss(void);
//*****************************************************************************
//*****************************************************************************
int main(void) {
	
	for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
         defenseGameBoard[i][j] = 0;
         attackGameBoard[i][j] = 0;
      }
	}
	
	myGuess = newCoord(-1, -1);
	theirGuess = newCoord(-1, -1);
	
	ece210_initialize_board();
  ece210_wireless_init(LOCAL_ID,REMOTE_ID);
  welcomeScreen();
	placeShips();
	
	ece210_lcd_draw_rectangle(0, 240, 0, 80, LCD_COLOR_BLACK);
	ece210_lcd_print_string("WAITING FOR OPPONENT", 220, 10, COLOR_PRIMARY, LCD_COLOR_BLACK);
	
	// wait until each player is ready
	ece210_wireless_send(1);
	while(!ece210_wireless_data_avaiable()) {
		// wait
	}
	
	if(LOCAL_ID > REMOTE_ID) {
		attack();
	}
	while(1) {
		defend();
		if(theirHits == 17) {
			loss();
		}
		attack();
		if(myHits == 17) {
			win();
		}
	}
	
}

void welcomeScreen(void) {
	ece210_lcd_draw_image(0, 240, 0, 320, welcome_screen_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	
  bool cont = false;
	while(!cont) {
		cont = btn_down_pressed() || btn_left_pressed() || btn_right_pressed() || btn_up_pressed();
	}
	ece210_lcd_draw_rectangle(0, 240, 0, 320, LCD_COLOR_BLACK);
}

void placeShips(void) {
	ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	ece210_lcd_draw_rectangle(194, 45, 20, 31, LCD_COLOR_BLACK);
	
	updateDefenseBoard();
	
	bool shipsPlaced[5] = {false, false, false, false, false};
	const uint8_t *ship_bitmaps[5] = {carrier_bitmap, battleship_bitmap, destroyer_bitmap, sub_bitmap, patrol_bitmap};
	int curr = 0;
	bool updateCurr = false;
	int orientation = 0;
	int xpos = 0;
	int ypos = 0;
	while(!(shipsPlaced[0] && shipsPlaced[1] && shipsPlaced[2] && shipsPlaced[3] && shipsPlaced[4])) {
		ece210_lcd_draw_image(39, 100, 60, 20, ship_bitmaps[curr], LCD_COLOR_BLACK, COLOR_PRIMARY);
		ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
		if(AlertButtons) AlertButtons = false;
		int direction;
		bool ready_l_r = true;
		bool ready_down = true;
		bool ready_ps2 = true;
		while(!btn_up_pressed()) {
			if(AlertButtons) AlertButtons = false;
			
			// change orientation
			if(!btn_left_pressed() && !btn_right_pressed()) ready_l_r = true;
			if(btn_left_pressed() && ready_l_r) {
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_BLACK);
				orientation--;
				if(orientation < 0) orientation = 3;
				ready_l_r = false;
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
			}
			if(btn_right_pressed() && ready_l_r) {
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_BLACK);
				orientation++;
				if(orientation > 3) orientation = 0;
				ready_l_r = false;
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
			}
			
			// change ship
			if(!btn_down_pressed()) ready_down = true;
			if((btn_down_pressed() && ready_down) || updateCurr) {
				updateCurr = false;
				int itr = 0;
				do {
				curr++;
				if(curr > 4) curr = 0;
					itr++;
				} while(shipsPlaced[curr] && itr < 5);
				ece210_lcd_draw_image(39, 100, 60, 20, ship_bitmaps[curr], LCD_COLOR_BLACK, COLOR_PRIMARY);
				ready_down = false;
			}
			
			// draw cursor
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 19 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 19 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			
			direction = ece210_ps2_read_position();
			if(direction != PS2_CENTER && ready_ps2) {
				// erase cursor
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 19 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 19 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
			}
			// move cursor
			switch (direction) {
				case PS2_RIGHT: {
					if(ready_ps2) {
						xpos++;
						if(xpos > 9) {
							xpos = 0;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_LEFT: {
					if(ready_ps2) {
						xpos--;
						if(xpos < 0) {
							xpos = 9;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_UP: {
					if(ready_ps2) {
						ypos--;
						if(ypos < 0) {
							ypos = 9;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_DOWN: {
					if(ready_ps2) {
						ypos++;
						if(ypos > 9) {
							ypos = 0;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_CENTER: {
					ready_ps2 = true;
					break;
				}
				default: {
				// do nothing
				break;
			}
			}
		}
	
		// check placement of ship
		int length = 0;
		switch(curr) {
			case 0: {
				length = 5;
				break;
			}
			case 1: {
				length = 4;
				break;
			}
			case 2: {
				length = 3;
				break;
			}
			case 3: {
				length = 3;
				break;
			}
			case 4: {
				length = 2;
				break;
			}
		}
		switch(orientation) {
			case 0: {
				if(xpos > length - 2) {
					// check if a ship is already there
					bool valid = true;
					for(int i = 0; i < length; i++) {
						if(defenseGameBoard[ypos][xpos - i] != 0) {
							valid = false;
							break;
						}
					}
					if(valid) {
						// assign values
						for(int i = 0; i < length; i++) {
							defenseGameBoard[ypos][xpos - i] = 2;
						}
						shipsPlaced[curr] = true;
						updateDefenseBoard();
						updateCurr = true;
						ece210_lcd_draw_rectangle(194, 45, 20, 31, LCD_COLOR_BLACK);
						break;
					}
					// invalid position
					ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
					ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
					break;
				}
				// invalid position
				ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
				break;
			}
			case 1: {
				if(ypos > length - 2) {
					// check if a ship is already there
					bool valid = true;
					for(int i = 0; i < length; i++) {
						if(defenseGameBoard[ypos - i][xpos] != 0) {
							valid = false;
							break;
						}
					}
					if(valid) {
						// assign values
						for(int i = 0; i < length; i++) {
							defenseGameBoard[ypos - i][xpos] = 2;
						}
						shipsPlaced[curr] = true;
						updateDefenseBoard();
						updateCurr = true;
						ece210_lcd_draw_rectangle(194, 45, 20, 31, LCD_COLOR_BLACK);
						break;
					}
					// invalid position
					ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
					ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
					break;
				}
				// invalid position
				ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
				break;
			}
			case 2: {
				if(xpos < 11 - length) {
					// check if a ship is already there
					bool valid = true;
					for(int i = 0; i < length; i++) {
						if(defenseGameBoard[ypos][xpos + i] != 0) {
							valid = false;
							break;
						}
					}
					if(valid) {
						// assign values
						for(int i = 0; i < length; i++) {
							defenseGameBoard[ypos][xpos + i] = 2;
						}
						shipsPlaced[curr] = true;
						updateDefenseBoard();
						updateCurr = true;
						ece210_lcd_draw_rectangle(194, 45, 20, 31, LCD_COLOR_BLACK);
						break;
					}
					// invalid position
					ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
					ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
					break;
				}
				// invalid position
				ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
				break;
			}
			case 3: {
				if(ypos < 11 - length) {
					// check if a ship is already there
					bool valid = true;
					for(int i = 0; i < length; i++) {
						if(defenseGameBoard[ypos + i][xpos] != 0) {
							valid = false;
							break;
						}
					}
					if(valid) {
						// assign values
						for(int i = 0; i < length; i++) {
							defenseGameBoard[ypos + i][xpos] = 2;
						}
						shipsPlaced[curr] = true;
						updateDefenseBoard();
						updateCurr = true;
						ece210_lcd_draw_rectangle(194, 45, 20, 31, LCD_COLOR_BLACK);
						break;
					}
					// invalid position
					ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
					ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
					break;
				}
				// invalid position
				ece210_lcd_draw_image(0, 240, 0, 80, place_ships_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
				ece210_lcd_draw_line(206 + 9*orientation, 67, 211 + 9*orientation, 67, LCD_COLOR_WHITE);
				break;
			}
		}
	}
	
	ece210_lcd_draw_rectangle(0, 240, 0, 80, LCD_COLOR_BLACK);
}

void updateDefenseBoard(void) {
	// clear board
	ece210_lcd_draw_rectangle(0, 240, 80, 240, LCD_COLOR_BLACK);
	
	// draw board
	ece210_lcd_draw_image(0, 240, 80, 240, game_board_bitmap, LCD_COLOR_BLACK, LCD_COLOR_CYAN);
	
	// draw hits and misses
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(defenseGameBoard[i][j] == 0) {
				 // no hit or miss
				char c = '-';
			ece210_lcd_print_string(&c, 239 - 38 - 21*j, 80 + 32 + 21*i, LCD_COLOR_BLUE, LCD_COLOR_BLACK);
			} else if(defenseGameBoard[i][j] == 1) {
				// miss
				char c = 'O';
				ece210_lcd_print_string(&c, 239 - 35 - 21*j, 80 + 32 + 21*i, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
			} else if(defenseGameBoard[i][j] == 2) {
				// ship not hit
				ece210_lcd_draw_rectangle(31 + 21*j, 18, 80 + 31 + 21*i, 18, LCD_COLOR_GRAY);
			} else if(defenseGameBoard[i][j] == 3) {
				// hit
				ece210_lcd_draw_rectangle(31 + 21*j, 18, 80 + 31 + 21*i, 18, LCD_COLOR_GRAY);
				char c = 'X';
				ece210_lcd_print_string(&c, 239 - 35 - 21*j, 80 + 32 + 21*i, LCD_COLOR_RED, LCD_COLOR_GRAY);
			}
		}
	}
	
	ece210_lcd_draw_pixel(239, 339, LCD_COLOR_BLACK
	);
}

void updateAttackBoard(void) {
	// clear board
	ece210_lcd_draw_rectangle(0, 240, 80, 240, LCD_COLOR_BLACK);
	
	// draw board
	ece210_lcd_draw_image(0, 240, 80, 240, game_board_bitmap, LCD_COLOR_BLACK, LCD_COLOR_CYAN);
	
	// draw hits and misses
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(attackGameBoard[i][j] == 0) {
				 // no hit or miss
				char c = '-';
			ece210_lcd_print_string(&c, 239 - 38 - 21*j, 80 + 32 + 21*i, LCD_COLOR_BLUE, LCD_COLOR_BLACK);
			} else if(attackGameBoard[i][j] == 1) {
				// miss
				char c = 'O';
				ece210_lcd_print_string(&c, 239 - 35 - 21*j, 80 + 32 + 21*i, LCD_COLOR_WHITE, LCD_COLOR_BLACK);
			} else if(attackGameBoard[i][j] == 2) {
				// hit
				char c = 'X';
				ece210_lcd_print_string(&c, 239 - 35 - 21*j, 80 + 32 + 21*i, LCD_COLOR_RED, LCD_COLOR_BLACK);
			}
		}
	}
	
	ece210_lcd_draw_pixel(239, 339, LCD_COLOR_BLACK
	);
}

void attack(void) {
	updateAttackBoard();
	ece210_lcd_draw_image(0, 240, 0, 80, guessing_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	
	ece210_lcd_draw_line(0, 0, 54, 0, COLOR_PRIMARY);
	ece210_lcd_draw_line(0, 10, 54, 10, COLOR_PRIMARY);
	ece210_lcd_draw_line(0, 0, 0, 10, COLOR_PRIMARY);
	ece210_lcd_draw_line(54, 0, 54, 10, COLOR_PRIMARY);
	
	if(myHits > 9) {
		char myH[2] = {myHits / 10 + '0', myHits - 10 + '0'};
		ece210_lcd_print_string(myH, 240 - 10, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		char myH = myHits + '0';
		ece210_lcd_print_string(&myH, 240 - 10, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(theirHits > 9) {
		char theirH[2] = {theirHits / 10 + '0', theirHits - 10 + '0'};
		ece210_lcd_print_string(theirH, 240 - 131, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		char theirH = theirHits + '0';
		ece210_lcd_print_string(&theirH, 240 - 131, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(myGuess.x > -1) {
		char myGx = myGuess.x + '0';
		char myGy = myGuess.y + 'A';
		ece210_lcd_print_string(&myGy, 240 - 10, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(",", 240 - 25, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(&myGx, 240 - 35, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		ece210_lcd_print_string("None", 240 - 10, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(theirGuess.x > -1) {
		char tGx = theirGuess.x + '0';
		char tGy = theirGuess.y + 'A';
		ece210_lcd_print_string(&tGy, 240 - 131, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(",", 240 - 156, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(&tGx, 240 - 166, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		ece210_lcd_print_string("None", 240 - 131, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	
	int xpos = 0;
	int ypos = 0;
	bool cont = false;
	while(!cont) {
		if(AlertButtons) AlertButtons = false;
		
		
		int direction;
		bool ready_ps2 = true;
		while(!btn_up_pressed()) {
			if(AlertButtons) AlertButtons = false;
			
			// draw cursor
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 19 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			ece210_lcd_draw_line(30 + 19 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_RED);
			
			direction = ece210_ps2_read_position();
			if(direction != PS2_CENTER && ready_ps2) {
				// erase cursor
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 19 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 21*xpos, 80 + 30 + 21*ypos, 30 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
				ece210_lcd_draw_line(30 + 19 + 21*xpos, 80 + 30 + 21*ypos, 30 + 19 + 21*xpos, 80 + 30 + 19 + 21*ypos, LCD_COLOR_BLACK);
			}
			// move cursor
			switch (direction) {
				case PS2_RIGHT: {
					if(ready_ps2) {
						xpos++;
						if(xpos > 9) {
							xpos = 0;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_LEFT: {
					if(ready_ps2) {
						xpos--;
						if(xpos < 0) {
							xpos = 9;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_UP: {
					if(ready_ps2) {
						ypos--;
						if(ypos < 0) {
							ypos = 9;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_DOWN: {
					if(ready_ps2) {
						ypos++;
						if(ypos > 9) {
							ypos = 0;
						}
					}
					ready_ps2 = false;
					break;
				}
				case PS2_CENTER: {
					ready_ps2 = true;
					break;
				}
				default: {
				// do nothing
				break;
			}
			}
		}
		
		myGuess = newCoord(xpos, ypos);
		
		if(attackGameBoard[ypos][xpos] != 0) {
			ece210_lcd_print_string("INVALID", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
		} else {
			uint16_t data = (xpos << 8) + ypos;
			ece210_wireless_send(data);
			
			while(!ece210_wireless_data_avaiable()) {
				// wait
			}
			
			int res = ece210_wireless_get();
			
			if(res == 0) {
				attackGameBoard[ypos][xpos] = 1;
				ece210_lcd_print_string("MISS", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
				cont = true;
			} else if(res == 2) {
				attackGameBoard[ypos][xpos] = 2;
				ece210_lcd_print_string("HIT", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
				myHits++;
				cont = true;
			} else {
				ece210_lcd_print_string("INVALID", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
			}
		}
	}
}

void defend(void) {
	updateDefenseBoard();
	ece210_lcd_draw_image(0, 240, 0, 80, guessing_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	
	ece210_lcd_draw_line(121, 0, 205, 0, COLOR_PRIMARY);
	ece210_lcd_draw_line(121, 10, 205, 10, COLOR_PRIMARY);
	ece210_lcd_draw_line(121, 0, 121, 10, COLOR_PRIMARY);
	ece210_lcd_draw_line(205, 0, 205, 10, COLOR_PRIMARY);
	
	if(myHits > 9) {
		char myH[2] = {myHits / 10 + '0', myHits - 10 + '0'};
		ece210_lcd_print_string(myH, 240 - 10, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		char myH = myHits + '0';
		ece210_lcd_print_string(&myH, 240 - 10, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(theirHits > 9) {
		char theirH[2] = {theirHits / 10 + '0', theirHits - 10 + '0'};
		ece210_lcd_print_string(theirH, 240 - 131, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		char theirH = theirHits + '0';
		ece210_lcd_print_string(&theirH, 240 - 131, 62, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(myGuess.x > -1) {
		char myGx = myGuess.x + '0';
		char myGy = myGuess.y + 'A';
		ece210_lcd_print_string(&myGy, 240 - 10, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(",", 240 - 25, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(&myGx, 240 - 35, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		ece210_lcd_print_string("None", 240 - 10, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	if(theirGuess.x > -1) {
		char tGx = theirGuess.x + '0';
		char tGy = theirGuess.y + 'A';
		ece210_lcd_print_string(&tGy, 240 - 131, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(",", 240 - 156, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
		ece210_lcd_print_string(&tGx, 240 - 166, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	} else {
		ece210_lcd_print_string("None", 240 - 131, 25, COLOR_PRIMARY, LCD_COLOR_BLACK);
	}
	
	bool cont = false;
	while(!cont) {
		
		while(!ece210_wireless_data_avaiable()) {
			// wait
		}
		
		uint16_t data = ece210_wireless_get();
		theirGuess = newCoord(data >> 8, (uint8_t) (data));
		int res = defenseGameBoard[theirGuess.y][theirGuess.x];
		
		if(res == 0) {
			defenseGameBoard[theirGuess.y][theirGuess.x] = 1;
			ece210_lcd_print_string("MISS", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
			cont = true;
		} else if(res == 2) {
			defenseGameBoard[theirGuess.y][theirGuess.x] = 3;
			ece210_lcd_print_string("HIT", 240 - 75, 60, LCD_COLOR_RED, LCD_COLOR_BLACK);
			theirHits++;
			cont = true;
		}
		
		ece210_wireless_send(res);
	}
}

void win(void) {
	ece210_lcd_draw_image(0, 240, 0, 320, win_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	while(1) {
		// do nothing
	}
}

void loss(void) {
	ece210_lcd_draw_image(0, 240, 0, 320, loss_bitmap, LCD_COLOR_BLACK, COLOR_PRIMARY);
	while(1) {
		// do nothing
	}
}
