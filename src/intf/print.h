#pragma once

#include <stdint.h>
#include <stddef.h>

enum {
    C_BLACK = 0,
	C_BLUE = 1,
	C_GREEN = 2,
	C_CYAN = 3,
	C_RED = 4,
	C_MAGENTA = 5,
	C_BROWN = 6,
	C_LIGHT_GRAY = 7,
	C_DARK_GRAY = 8,
	C_LIGHT_BLUE = 9,
	C_LIGHT_GREEN = 10,
	C_LIGHT_CYAN = 11,
	C_LIGHT_RED = 12,
	C_PINK = 13,
	C_YELLOW = 14,
	C_WHITE = 15,
};
void con_clear();
void print_c(char character);
void print(char* string);
void con_setc(uint8_t foreground, uint8_t background);