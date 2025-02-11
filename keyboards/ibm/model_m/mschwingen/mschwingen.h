/*
 * Copyright 2020 Michael Schwingen

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

extern void update_layer_leds(void);
/*
>>>>>>> 913992b438 (redox handwire fork: jambodox):keyboards/redox/redox.h
#if defined(KEYBOARD_redox_rev1)
#     include "rev1.h"
#elif defined(KEYBOARD_redox_media)
#    include "media.h"
#elif defined(KEYBOARD_redox_teensylc)
#    include "teensylc.h"
#elif defined(KEYBOARD_redox_teensy32)
*/
//#    include "teensy32.h"
#    include "jambo3.h"
/*
 * #endif
*/

#include "quantum.h"
