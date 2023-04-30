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

#define CA1_A 0x20
#define CA1_B 0x21
#define CA1_C 0x22
#define CA1_D 0x23
#define CA1_E 0x24
#define CA1_F 0x25
#define CA1_G 0x26
#define CA1_H 0x27
#define CA1_I 0x28
#define CA1_J 0x29
#define CA1_K 0x2A
#define CA1_L 0x2B
#define CA1_M 0x2C
#define CA1_N 0x2D
#define CA1_O 0x2E
#define CA1_P 0x2F

#define CA2_A 0x30
#define CA2_B 0x31
#define CA2_C 0x32
#define CA2_D 0x33
#define CA2_E 0x34
#define CA2_F 0x35
#define CA2_G 0x36
#define CA2_H 0x37
#define CA2_I 0x38
#define CA2_J 0x39
#define CA2_K 0x3A
#define CA2_L 0x3B
#define CA2_M 0x3C
#define CA2_N 0x3D
#define CA2_O 0x3E
#define CA2_P 0x3F

#define CA3_A 0x40
#define CA3_B 0x41
#define CA3_C 0x42
#define CA3_D 0x43
#define CA3_E 0x44
#define CA3_F 0x45
#define CA3_G 0x46
#define CA3_H 0x47
#define CA3_I 0x48
#define CA3_J 0x49
#define CA3_K 0x4A
#define CA3_L 0x4B
#define CA3_M 0x4C
#define CA3_N 0x4D
#define CA3_O 0x4E
#define CA3_P 0x4F

#define CA4_A 0x50
#define CA4_B 0x51
#define CA4_C 0x52
#define CA4_D 0x53
#define CA4_E 0x54
#define CA4_F 0x55
#define CA4_G 0x56
#define CA4_H 0x57
#define CA4_I 0x58
#define CA4_J 0x59
#define CA4_K 0x5A
#define CA4_L 0x5B
#define CA4_M 0x5C
#define CA4_N 0x5D
#define CA4_O 0x5E
#define CA4_P 0x5F

#define CA5_A 0x60
#define CA5_B 0x61
#define CA5_C 0x62
#define CA5_D 0x63
#define CA5_E 0x64
#define CA5_F 0x65
#define CA5_G 0x66
#define CA5_H 0x67
#define CA5_I 0x68
#define CA5_J 0x69
#define CA5_K 0x6A
#define CA5_L 0x6B
#define CA5_M 0x6C
#define CA5_N 0x6D
#define CA5_O 0x6E
#define CA5_P 0x6F

#define CA6_A 0x70
#define CA6_B 0x71
#define CA6_C 0x72
#define CA6_D 0x73
#define CA6_E 0x74
#define CA6_F 0x75
#define CA6_G 0x76
#define CA6_H 0x77
#define CA6_I 0x78
#define CA6_J 0x79
#define CA6_K 0x7A
#define CA6_L 0x7B
#define CA6_M 0x7C
#define CA6_N 0x7D
#define CA6_O 0x7E
#define CA6_P 0x7F

#define CA7_A 0x80
#define CA7_B 0x81
#define CA7_C 0x82
#define CA7_D 0x83
#define CA7_E 0x84
#define CA7_F 0x85
#define CA7_G 0x86
#define CA7_H 0x87
#define CA7_I 0x88
#define CA7_J 0x89
#define CA7_K 0x8A
#define CA7_L 0x8B
#define CA7_M 0x8C
#define CA7_N 0x8D
#define CA7_O 0x8E
#define CA7_P 0x8F

#define CA8_A 0x90
#define CA8_B 0x91
#define CA8_C 0x92
#define CA8_D 0x93
#define CA8_E 0x94
#define CA8_F 0x95
#define CA8_G 0x96
#define CA8_H 0x97
#define CA8_I 0x98
#define CA8_J 0x99
#define CA8_K 0x9A
#define CA8_L 0x9B
#define CA8_M 0x9C
#define CA8_N 0x9D
#define CA8_O 0x9E
#define CA8_P 0x9F

#define CA9_A ( CA1_A + 0x80 )
#define CA9_B ( CA1_B + 0x80 )
#define CA9_C ( CA1_C + 0x80 )
#define CA9_D ( CA1_D + 0x80 )
#define CA9_E ( CA1_E + 0x80 )
#define CA9_F ( CA1_F + 0x80 )
#define CA9_G ( CA1_G + 0x80 )
#define CA9_H ( CA1_H + 0x80 )
#define CA9_I ( CA1_I + 0x80 )
#define CA9_J ( CA1_J + 0x80 )
#define CA9_K ( CA1_K + 0x80 )
#define CA9_L ( CA1_L + 0x80 )
#define CA9_M ( CA1_M + 0x80 )
#define CA9_N ( CA1_N + 0x80 )
#define CA9_O ( CA1_O + 0x80 )
#define CA9_P ( CA1_P + 0x80 )

#define CB1_A ( CA2_A + 0x80 )
#define CB1_B ( CA2_B + 0x80 )
#define CB1_C ( CA2_C + 0x80 )
#define CB1_D ( CA2_D + 0x80 )
#define CB1_E ( CA2_E + 0x80 )
#define CB1_F ( CA2_F + 0x80 )
#define CB1_G ( CA2_G + 0x80 )
#define CB1_H ( CA2_H + 0x80 )
#define CB1_I ( CA2_I + 0x80 )
#define CB1_J ( CA2_J + 0x80 )
#define CB1_K ( CA2_K + 0x80 )
#define CB1_L ( CA2_L + 0x80 )
#define CB1_M ( CA2_M + 0x80 )
#define CB1_N ( CA2_N + 0x80 )
#define CB1_O ( CA2_O + 0x80 )
#define CB1_P ( CA2_P + 0x80 )

#define CB2_A ( CA3_A + 0x80 )
#define CB2_B ( CA3_B + 0x80 )
#define CB2_C ( CA3_C + 0x80 )
#define CB2_D ( CA3_D + 0x80 )
#define CB2_E ( CA3_E + 0x80 )
#define CB2_F ( CA3_F + 0x80 )
#define CB2_G ( CA3_G + 0x80 )
#define CB2_H ( CA3_H + 0x80 )
#define CB2_I ( CA3_I + 0x80 )
#define CB2_J ( CA3_J + 0x80 )
#define CB2_K ( CA3_K + 0x80 )
#define CB2_L ( CA3_L + 0x80 )
#define CB2_M ( CA3_M + 0x80 )
#define CB2_N ( CA3_N + 0x80 )
#define CB2_O ( CA3_O + 0x80 )
#define CB2_P ( CA3_P + 0x80 )

#define CB3_A ( CA4_A + 0x80 )
#define CB3_B ( CA4_B + 0x80 )
#define CB3_C ( CA4_C + 0x80 )
#define CB3_D ( CA4_D + 0x80 )
#define CB3_E ( CA4_E + 0x80 )
#define CB3_F ( CA4_F + 0x80 )
#define CB3_G ( CA4_G + 0x80 )
#define CB3_H ( CA4_H + 0x80 )
#define CB3_I ( CA4_I + 0x80 )
#define CB3_J ( CA4_J + 0x80 )
#define CB3_K ( CA4_K + 0x80 )
#define CB3_L ( CA4_L + 0x80 )
#define CB3_M ( CA4_M + 0x80 )
#define CB3_N ( CA4_N + 0x80 )
#define CB3_O ( CA4_O + 0x80 )
#define CB3_P ( CA4_P + 0x80 )

#define CB4_A ( CA5_A + 0x80 )
#define CB4_B ( CA5_B + 0x80 )
#define CB4_C ( CA5_C + 0x80 )
#define CB4_D ( CA5_D + 0x80 )
#define CB4_E ( CA5_E + 0x80 )
#define CB4_F ( CA5_F + 0x80 )
#define CB4_G ( CA5_G + 0x80 )
#define CB4_H ( CA5_H + 0x80 )
#define CB4_I ( CA5_I + 0x80 )
#define CB4_J ( CA5_J + 0x80 )
#define CB4_K ( CA5_K + 0x80 )
#define CB4_L ( CA5_L + 0x80 )
#define CB4_M ( CA5_M + 0x80 )
#define CB4_N ( CA5_N + 0x80 )
#define CB4_O ( CA5_O + 0x80 )
#define CB4_P ( CA5_P + 0x80 )

#define CB5_A ( CA6_A + 0x80 )
#define CB5_B ( CA6_B + 0x80 )
#define CB5_C ( CA6_C + 0x80 )
#define CB5_D ( CA6_D + 0x80 )
#define CB5_E ( CA6_E + 0x80 )
#define CB5_F ( CA6_F + 0x80 )
#define CB5_G ( CA6_G + 0x80 )
#define CB5_H ( CA6_H + 0x80 )
#define CB5_I ( CA6_I + 0x80 )
#define CB5_J ( CA6_J + 0x80 )
#define CB5_K ( CA6_K + 0x80 )
#define CB5_L ( CA6_L + 0x80 )
#define CB5_M ( CA6_M + 0x80 )
#define CB5_N ( CA6_N + 0x80 )
#define CB5_O ( CA6_O + 0x80 )
#define CB5_P ( CA6_P + 0x80 )

#define CB6_A ( CA7_A + 0x80 )
#define CB6_B ( CA7_B + 0x80 )
#define CB6_C ( CA7_C + 0x80 )
#define CB6_D ( CA7_D + 0x80 )
#define CB6_E ( CA7_E + 0x80 )
#define CB6_F ( CA7_F + 0x80 )
#define CB6_G ( CA7_G + 0x80 )
#define CB6_H ( CA7_H + 0x80 )
#define CB6_I ( CA7_I + 0x80 )
#define CB6_J ( CA7_J + 0x80 )
#define CB6_K ( CA7_K + 0x80 )
#define CB6_L ( CA7_L + 0x80 )
#define CB6_M ( CA7_M + 0x80 )
#define CB6_N ( CA7_N + 0x80 )
#define CB6_O ( CA7_O + 0x80 )
#define CB6_P ( CA7_P + 0x80 )

#define CB7_A ( CA8_A + 0x80 )
#define CB7_B ( CA8_B + 0x80 )
#define CB7_C ( CA8_C + 0x80 )
#define CB7_D ( CA8_D + 0x80 )
#define CB7_E ( CA8_E + 0x80 )
#define CB7_F ( CA8_F + 0x80 )
#define CB7_G ( CA8_G + 0x80 )
#define CB7_H ( CA8_H + 0x80 )
#define CB7_I ( CA8_I + 0x80 )
#define CB7_J ( CA8_J + 0x80 )
#define CB7_K ( CA8_K + 0x80 )
#define CB7_L ( CA8_L + 0x80 )
#define CB7_M ( CA8_M + 0x80 )
#define CB7_N ( CA8_N + 0x80 )
#define CB7_O ( CA8_O + 0x80 )
#define CB7_P ( CA8_P + 0x80 )
