/* Copyright 2020 DmNosachev
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

void matrix_init_kb(void) {
    gpio_set_pin_output(NUM_LOCK_LED_PIN);
    gpio_set_pin_output(CAPS_LOCK_LED_PIN);
    gpio_set_pin_output(SCROLL_LOCK_LED_PIN);

    gpio_write_pin_low(NUM_LOCK_LED_PIN);
    gpio_write_pin_low(CAPS_LOCK_LED_PIN);
    gpio_write_pin_low(SCROLL_LOCK_LED_PIN);

    matrix_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        gpio_write_pin(NUM_LOCK_LED_PIN, !led_state.num_lock);
        gpio_write_pin(CAPS_LOCK_LED_PIN, !led_state.caps_lock);
        gpio_write_pin(SCROLL_LOCK_LED_PIN, !led_state.scroll_lock);
    }
    return res;
}
