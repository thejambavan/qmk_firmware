/*
Copyright 2018 Mattia Dal Ben <matthewdibi@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring of each half
//#define MATRIX_ROW_PINS { D4, D7, E6, B4, B5 }
#define MATRIX_ROW_PINS { LINE_PIN7, LINE_PIN8, LINE_PIN9, LINE_PIN10, LINE_PIN11 }
//#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }
#define MATRIX_COL_PINS {  LINE_PIN14, LINE_PIN15, LINE_PIN16, LINE_PIN17, LINE_PIN18, LINE_PIN19, LINE_PIN20}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
//#define SOFT_SERIAL_PIN LINE_PIN7

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* ws2812 RGB LED */
#define NOP_FUDGE 0.4
#define RGB_DI_PIN D3
#define RGBLED_NUM 14    // Number of LEDs
#define RGBLIGHT_SPLIT   // sync LEDs between RIGHT and LEFT hand

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
