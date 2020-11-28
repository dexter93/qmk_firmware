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
    {70},
    {
        {   0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13 },
        {  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27 },
        {  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41 },
        {  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55 },
        {  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,  68,  69 },
},
    {
        // Row 0
        "Key: Escape",
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


        // Row 1
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

        // Row 2
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
        "Reserved",
        "Key: Enter",

        // Row 3

        "Key: Left Shift",
        "Reserved",
        "Key: Z",
        "Key: X",
        "Key: C",
        "Key: V",
        "Key: B",
        "Key: N",
        "Key: M",
        "Key: ,",
        "Key: .",
        "Key: Right Shift",
        "Key: Up Arrow",
        "Key: /",

        // Row 5

        "Key: Left Control",
        "Key: Left Windows",
        "Key: Left Alt",
        "Reserved",
        "Reserved",
        "Reserved",
        "Key: Space",
        "Reserved",
        "Reserved",
        "Key: Right Alt",
        "Key: Right Fn",
        "Key: Left Arrow",
        "Key: Down Arrow",
        "Key: Right Arrow",

    },
};
