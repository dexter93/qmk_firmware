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

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "progmem.h"

typedef struct sled1734x_led {
    uint8_t driver : 2;
    uint8_t r;
    uint8_t g;
    uint8_t b;
} __attribute__((packed)) sled1734x_led;

extern const sled1734x_led PROGMEM g_sled1734x_leds[RGB_MATRIX_LED_COUNT];

void SLED1734X_init(uint8_t addr);
void SLED1734X_write_register(uint8_t addr, uint8_t reg, uint8_t data);
void SLED1734X_write_pwm_buffer(uint8_t addr, uint8_t *pwm_buffer);

void SLED1734X_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
void SLED1734X_set_color_all(uint8_t red, uint8_t green, uint8_t blue);

void SLED1734X_set_led_control_register(uint8_t index, bool red, bool green, bool blue);

// This should not be called from an interrupt
// (eg. from a timer interrupt).
// Call this while idle (in between matrix scans).
// If the buffer is dirty, it will update the driver with the buffer.
void SLED1734X_update_pwm_buffers(uint8_t addr, uint8_t index);
void SLED1734X_update_led_control_registers(uint8_t addr, uint8_t index);

#define C1_A 0x20
#define C1_B 0x21
#define C1_C 0x22
#define C1_D 0x23
#define C1_E 0x24
#define C1_F 0x25
#define C1_G 0x26
#define C1_H 0x27
#define C1_I 0x28
#define C1_J 0x29
#define C1_K 0x2A
#define C1_L 0x2B
#define C1_M 0x2C
#define C1_N 0x2D
#define C1_O 0x2E
#define C1_P 0x2F

#define C2_A 0x30
#define C2_B 0x31
#define C2_C 0x32
#define C2_D 0x33
#define C2_E 0x34
#define C2_F 0x35
#define C2_G 0x36
#define C2_H 0x37
#define C2_I 0x38
#define C2_J 0x39
#define C2_K 0x3A
#define C2_L 0x3B
#define C2_M 0x3C
#define C2_N 0x3D
#define C2_O 0x3E
#define C2_P 0x3F

#define C3_A 0x40
#define C3_B 0x41
#define C3_C 0x42
#define C3_D 0x43
#define C3_E 0x44
#define C3_F 0x45
#define C3_G 0x46
#define C3_H 0x47
#define C3_I 0x48
#define C3_J 0x49
#define C3_K 0x4A
#define C3_L 0x4B
#define C3_M 0x4C
#define C3_N 0x4D
#define C3_O 0x4E
#define C3_P 0x4F

#define C4_A 0x50
#define C4_B 0x51
#define C4_C 0x52
#define C4_D 0x53
#define C4_E 0x54
#define C4_F 0x55
#define C4_G 0x56
#define C4_H 0x57
#define C4_I 0x58
#define C4_J 0x59
#define C4_K 0x5A
#define C4_L 0x5B
#define C4_M 0x5C
#define C4_N 0x5D
#define C4_O 0x5E
#define C4_P 0x5F

#define C5_A 0x60
#define C5_B 0x61
#define C5_C 0x62
#define C5_D 0x63
#define C5_E 0x64
#define C5_F 0x65
#define C5_G 0x66
#define C5_H 0x67
#define C5_I 0x68
#define C5_J 0x69
#define C5_K 0x6A
#define C5_L 0x6B
#define C5_M 0x6C
#define C5_N 0x6D
#define C5_O 0x6E
#define C5_P 0x6F

#define C6_A 0x70
#define C6_B 0x71
#define C6_C 0x72
#define C6_D 0x73
#define C6_E 0x74
#define C6_F 0x75
#define C6_G 0x76
#define C6_H 0x77
#define C6_I 0x78
#define C6_J 0x79
#define C6_K 0x7A
#define C6_L 0x7B
#define C6_M 0x7C
#define C6_N 0x7D
#define C6_O 0x7E
#define C6_P 0x7F

#define C7_A 0x80
#define C7_B 0x81
#define C7_C 0x82
#define C7_D 0x83
#define C7_E 0x84
#define C7_F 0x85
#define C7_G 0x86
#define C7_H 0x87
#define C7_I 0x88
#define C7_J 0x89
#define C7_K 0x8A
#define C7_L 0x8B
#define C7_M 0x8C
#define C7_N 0x8D
#define C7_O 0x8E
#define C7_P 0x8F

#define C8_A 0x90
#define C8_B 0x91
#define C8_C 0x92
#define C8_D 0x93
#define C8_E 0x94
#define C8_F 0x95
#define C8_G 0x96
#define C8_H 0x97
#define C8_I 0x98
#define C8_J 0x99
#define C8_K 0x9A
#define C8_L 0x9B
#define C8_M 0x9C
#define C8_N 0x9D
#define C8_O 0x9E
#define C8_P 0x9F
