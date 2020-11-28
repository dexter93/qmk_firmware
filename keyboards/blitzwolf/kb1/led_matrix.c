#include <string.h>
#include "rgb.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "color.h"

/*
    COLS key / led
    PWM PWM00A - PWM21A (PWM15A unused)
    2ty transistors PNP driven high
    base      - GPIO
    collector - LED Col pins
    emitter   - VDD

    VDD     GPIO
    (E)     (B)
     |  PNP  |
     |_______|
         |
         |
        (C)
        LED

    ROWS RGB
    PWM PWM22A - PWM21B (PWM10B unused)
    C 0-15
    j3y transistors NPN driven low
    base      - GPIO
    collector - LED RGB row pins
    emitter   - GND

        LED
        (C)
         |
         |
      _______
     |  NPN  |
     |       |
    (B)     (E)
    GPIO    GND
*/

LED_TYPE led_state[DRIVER_LED_TOTAL];

void init(void) {}

static void flush(void) {}

void set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    led_state[index].r = r;
    led_state[index].g = g;
    led_state[index].b = b;
}

static void set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i=0; i<DRIVER_LED_TOTAL; i++)
        set_color(i, r, g, b);
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = init,
    .flush         = flush,
    .set_color     = set_color,
    .set_color_all = set_color_all,
};

// byte order: R,B,G
static uint8_t caps_lock_color[3] = { 0x00, 0x00, 0xFF };

void led_set(uint8_t usb_led) {
    // dk63 has only CAPS indicator
    if (usb_led >> USB_LED_CAPS_LOCK & 1) {
        set_color(11, caps_lock_color[0], caps_lock_color[2], caps_lock_color[1]);
    } else {
        set_color(11, 0x00, 0x00, 0x00);
    }
}

const led_matrix_config_t g_led_matrix_config =
{
    {"Keyboard"},
    {ZONE_TYPE_MATRIX},
    {126},
    {
        { 0,       1,       2,       3,       4,       5,       6,       7,       8,       9,      10,       11,       12,       13,       14,       15,     16,     17,     18,     19,     20 },
        { 21,      22,     23,      24,      25,      26,      27,      28,      29,      30,      31,       32,       33,       34,       35,       36,     37,     38,     39,     40,     41 },
        { 42,      43,     44,      45,      46,      47,      48,      49,      50,      51,      52,       53,       54,       55,       56,       57,     58,     59,     60,     61,     62 },
        { 63,      64,     65,      66,      67,      68,      69,      70,      71,      72,      73,       74,       75,       76,       77,       78,     79,     80,     81,     82,     83 },
        { 84,      85,     86,      87,      88,      89,      90,      91,      92,      93,      94,       95,       96,       97,       98,       99,    100,    101,    102,    103,    104 },
        { 105,     106,   107,     108,     109,     110,     111,     112,     113,     114,     115,      116,      117,      118,      119,      120,    121,    122,    123,    124,    125 },
    },
    {
        // Row 0
        "Key: Escape",
        "Reserved",
        "Key: F1",
        "Key: F2",
        "Key: F3",
        "Key: F4",
        "Key: F5",
        "Key: F6",
        "Key: F7",
        "Key: F8",
        "Key: F9",
        "Key: F10",
        "Key: F11",
        "Key: F12",
        "Key: Print Screen",
        "Key: Scroll Lock",
        "Key: Pause/Break",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",

        // Row 1
        "Key: ~",
        "Key: 1",
        "Key: 2",
        "Key: 3",
        "Key: 4",
        "Key: 5",
        "Key: 6",
        "Key: 7",
        "Key: 8",
        "Key: 9",
        "Key: 0",
        "Key: -",
        "Key: +",
        "Key: Backspace"
        "Key: Insert",
        "Key: Home",
        "Key: Page Up",
        "Key: Num Lock",
        "Key: Number Pad /",
        "Key: Number Pad *",
        "Key: Number Pad -",

        // Row 2
        "Key: Tab",
        "Key: Q",
        "Key: W",
        "Key: E",
        "Key: R",
        "Key: T",
        "Key: Y",
        "Key: U",
        "Key: I",
        "Key: O",
        "Key: P",
        "Key: [",
        "Key: ]",
        "Key: \\ (ANSI)",
        "Key: Delete",
        "Key: End",
        "Key: Page Down",
        "Key: Number Pad 7",
        "Key: Number Pad 8",
        "Key: Number Pad 9",
        "Key: Number Pad +",

        // Row 3
        "Key: Caps Lock",
        "Key: A",
        "Key: S",
        "Key: D",
        "Key: F",
        "Key: G",
        "Key: H",
        "Key: J",
        "Key: K",
        "Key: L",
        "Key: ;",
        "Key: '",
        "Key: Enter",
        "Reserved",
        "Reserved",
        "Reserved",
        "Reserved",
        "Key: Number Pad 4",
        "Key: Number Pad 5",
        "Key: Number Pad 6",
        "Reserved",

        // Row 5
        "Key: Left Shift",
        "Key: Z",
        "Key: X",
        "Key: C",
        "Key: V",
        "Key: B",
        "Key: N",
        "Key: M",
        "Key: ,",
        "Key: .",
        "Key: /",
        "Key: Right Shift",
        "Reserved",
        "Reserved",
        "Reserved",
        "Key: Up Arrow",
        "Reserved",
        "Key: Number Pad 1",
        "Key: Number Pad 2",
        "Key: Number Pad 3",
        "Key: Number Pad Enter",

        // Row 6
        "Key: Left Control",
        "Key: Left Windows",
        "Key: Left Alt",
        "Reserved",
        "Reserved",
        "Reserved",
        "Key: Space",
        "Reserved",
        "Reserved",
        "Reserved",
        "Key: Right Alt",
        "Key: Right Fn",
        "Key: Menu",
        "Key: Right Control",
        "Key: Left Arrow",
        "Key: Down Arrow",
        "Key: Right Arrow",
        "Key: Number Pad 0",
        "Reserved",
        "Key: Number Pad .",
        "Reserved",
    },
};