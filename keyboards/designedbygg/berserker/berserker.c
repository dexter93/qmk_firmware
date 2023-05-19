/* Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
 *
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

#include "quantum.h"

/* Handle the Win Lock LED */
void keyboard_pre_init_kb(void) {
#ifdef LED_WIN_LOCK_PIN
	setPinOutput(LED_WIN_LOCK_PIN);
	writePin(LED_WIN_LOCK_PIN, !LED_PIN_ON_STATE);
#endif
}

bool led_update_user(led_t led_state) {
	keymap_config.raw = eeconfig_read_keymap();
	writePin(LED_WIN_LOCK_PIN,!keymap_config.no_gui);
    return true;
}