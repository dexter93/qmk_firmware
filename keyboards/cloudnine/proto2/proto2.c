
#include "quantum.h"
#if defined(RGB_MATRIX_ENABLE)

#include "rgb_matrix.h"
const sled1734x_led_t PROGMEM g_sled1734x_leds[SLED1734X_LED_COUNT] = {
/* Driver
 *   |  R         G         B */
 
    {0, CA1_D,  CA3_D,  CA2_D},
    {0, CA1_E,  CA3_E,  CA2_E},
    {0, CA1_F,  CA3_F,  CA2_F},
    {0, CA1_G,  CA3_G,  CA2_G},
    {0, CA1_H,  CA3_H,  CA2_H},
    {0, CA1_I,  CA3_I,  CA2_I},

    {0, CA4_A,  CA5_A,  CA6_A},
    {0, CA4_B,  CA5_B,  CA6_B},
    {0, CA4_C,  CA5_C,  CA6_C},
    {0, CA4_F,  CA5_F,  CA6_F},
    {0, CA4_G,  CA5_G,  CA6_G},
    {0, CA4_H,  CA5_H,  CA6_H},
    {0, CA4_I,  CA5_I,  CA6_I},
    {0, CA4_J,  CA5_J,  CA6_J},

    {0, CA7_A,  CA8_A,  CA9_A},
    {0, CA7_B,  CA8_B,  CA9_B},
    {0, CA7_C,  CA8_C,  CA9_C},
    {0, CA7_D,  CA8_D,  CA9_D},
    {0, CA7_E,  CA8_E,  CA9_E},
    {0, CA7_F,  CA8_F,  CA9_F},
    {0, CA7_I,  CA8_I,  CA9_I},

    {0, CB1_A,  CB2_A,  CB3_A},
    {0, CB1_B,  CB2_B,  CB3_B},
    {0, CB1_C,  CB2_C,  CB3_C},
    {0, CB1_D,  CB2_D,  CB3_D},
    {0, CB1_E,  CB2_E,  CB3_E},
    {0, CB1_F,  CB2_F,  CB3_F},
    {0, CB1_G,  CB2_G,  CB3_G},

    {0, CB4_A,  CB5_A,  CB6_A},
    {0, CB4_B,  CB5_B,  CB6_B},
    {0, CB4_D,  CB5_D,  CB6_D},
    {0, CB4_E,  CB5_E,  CB6_E},
    {0, CB4_F,  CB5_F,  CB6_F},
    {0, CB4_G,  CB5_G,  CB6_G},
    {0, CB4_H,  CB5_H,  CB6_H},

    {0, CB4_I,  CB5_I,  CB6_I},
    {0, CB4_J,  CB5_J,  CB6_J},
    {0, CB4_K,  CB5_K,  CB6_K},
    {0, CB4_L,  CB5_L,  CB6_L},
    {0, CB4_O,  CB5_O,  CB6_O}


/*

    {0, CA1_C,  CA3_C,  CA2_C},
    {0, CA1_D,  CA3_D,  CA2_D},
    {0, CA1_E,  CA3_E,  CA2_E},
    {0, CA1_F,  CA3_F,  CA2_F},
    {0, CA1_G,  CA3_G,  CA2_G},
    {0, CA1_H,  CA3_H,  CA2_H},
    {0, CB1_H,  CB2_H,  CB3_H},
    {0, CA1_I,  CA3_I,  CA2_I},
    {0, CA1_J,  CA3_J,  CA2_J},
    {0, CA1_K,  CA3_K,  CA2_K},


    {0, CA4_A,  CA5_A,  CA6_A},
    {0, CA4_B,  CA5_B,  CA6_B},
    {0, CA4_C,  CA5_C,  CA6_C},
    {0, CA4_F,  CA5_F,  CA6_F},
    {0, CA4_P,  CA5_P,  CA6_P},
    {0, CA4_H,  CA5_H,  CA6_H},
    {0, CA4_I,  CA5_I,  CA6_I},
    {0, CA4_J,  CA5_J,  CA6_J},
    {0, CA4_K,  CA5_K,  CA6_K},
    {0, CA4_L,  CA5_L,  CA6_L},
    {0, CA4_M,  CA5_M,  CA6_M},
    {0, CA4_N,  CA5_N,  CA6_N},
    {0, CA4_O,  CA5_O,  CA6_O},
    {0, CA4_P,  CA5_P,  CA6_P},


    {0, CA7_A,  CA8_A,  CA9_A},
    {0, CA7_B,  CA8_B,  CA9_B},
    {0, CA7_C,  CA8_C,  CA9_C},
    {0, CA7_D,  CA8_D,  CA9_D},
    {0, CA7_E,  CA8_E,  CA9_E},
    {0, CA7_F,  CA8_F,  CA9_F},
    {0, CA7_I,  CA8_I,  CA9_I},
    {0, CA7_J,  CA8_J,  CA9_J},
    {0, CA7_K,  CA8_K,  CA9_K},
    {0, CA7_L,  CA8_L,  CA9_L},
    {0, CA7_M,  CA8_M,  CA9_M},
    {0, CA7_N,  CA8_N,  CA9_N},
    {0, CA7_O,  CA8_O,  CA9_O},
    {0, CA7_P,  CA8_P,  CA9_P},
    {0, CB1_I,  CB2_I,  CB3_I},


    {0, CB1_A,  CB2_A,  CB3_A},
    {0, CB1_B,  CB2_B,  CB3_B},
    {0, CB1_C,  CB2_C,  CB3_C},
    {0, CB1_D,  CB2_D,  CB3_D},
    {0, CB1_E,  CB2_E,  CB3_E},
    {0, CB1_F,  CB2_F,  CB3_F},
    {0, CB1_G,  CB2_G,  CB3_G},
    {0, CB1_N,  CB2_N,  CB3_N},
    {0, CB1_O,  CB2_O,  CB3_O},
    {0, CB1_P,  CB2_P,  CB3_P},


    {0, CB4_A,  CB5_A,  CB6_A},
    {0, CB4_B,  CB5_B,  CB6_B},
    {0, CB4_C,  CB5_C,  CB6_C},
    {0, CB4_D,  CB5_D,  CB6_D},
    {0, CB4_E,  CB5_E,  CB6_E},
    {0, CB4_F,  CB5_F,  CB6_F},
    {0, CB4_G,  CB5_G,  CB6_G},
    {0, CB4_L,  CB5_L,  CB6_L},
    {0, CB4_O,  CB5_O,  CB6_O},
    {0, CB4_P,  CB5_P,  CB6_P},
    {0, CB4_K,  CB5_K,  CB6_K},


    {0, CA1_L,  CA3_L,  CA2_L},
    {0, CA1_M,  CA3_M,  CA2_M},
    {0, CA1_N,  CA3_N,  CA2_N},
    {0, CA1_O,  CA3_O,  CA2_O},
    {0, CA1_P,  CA3_P,  CA2_P},
    {0, CB4_H,  CB5_H,  CB6_H},
    {0, CB4_I,  CB5_I,  CB6_I},
    {0, CB4_J,  CB5_J,  CB6_J},
    {0, CB1_L,  CB2_L,  CB3_L},
    {0, CB1_M,  CB2_M,  CB3_M}*/
};
#endif
//bool is_keyboard_left_impl(void) {
  // return false;
//}
/*
#include <stdint.h>
#include <string.h>
#include <ch.h>

///
 // Executes the BKPT instruction that causes the debugger to stop.
 // If no debugger is attached, this will be ignored.
 ///
#define bkpt() __asm volatile("BKPT #0\n")
//void NMI_Handler(void) __attribute__((weak));

//void NMI_Handler(void) {
  //  while (1)
    //    ;
//}

// Basic fault type for Cortex-M0
typedef enum {
    Reset      = 1,
    NMI        = 2,
    HardFault  = 3,
} FaultType;

static uint16_t debug_buffer_location = 0;
static char     debug_buffer[512]     = {0};

static void append_debug_char(char c) {
    debug_buffer[debug_buffer_location] = c;
    debug_buffer_location               = (debug_buffer_location + 1) % sizeof(debug_buffer);
}

static void exception_dump(char *s) {
    do {
        append_debug_char(*s);
    } while (*s++);
}

static void faulttype(FaultType type) {
    switch (type) {
        case NMI:
            exception_dump("NMI");
            break;

        case Reset:
            exception_dump("Reset");
            break;

        case HardFault:
            exception_dump("Hard Fault");
            break;
    }
}

static void hex2string(uint32_t hex) {
    uint8_t  i;
    char     ascii   = 0x0;
    uint32_t divider = 0x10000000;

    exception_dump("0x");

    for (i = 0; i < 8; i++) {
        ascii = hex / divider;
        hex -= (ascii * divider);
        divider /= 0x10;

        if (ascii >= 0xA) {
            append_debug_char('A' + (ascii - 0xA));
        } else {
            append_debug_char('0' + ascii);
        }
    }
}

void HardFault_Handler(void) {
    uint32_t stacked_r0, stacked_r1, stacked_r2, stacked_r3, stacked_r12, stacked_lr, stacked_pc, stacked_psr;
    uint32_t *stacked_frame = (uint32_t *)__get_PSP();

    // Retrieve stacked registers
    stacked_r0  = stacked_frame[0];
    stacked_r1  = stacked_frame[1];
    stacked_r2  = stacked_frame[2];
    stacked_r3  = stacked_frame[3];
    stacked_r12 = stacked_frame[4];
    stacked_lr  = stacked_frame[5];
    stacked_pc  = stacked_frame[6];
    stacked_psr = stacked_frame[7];

    exception_dump("********** Exception Dump **********\r\n");

    exception_dump("R0: ");
    hex2string(stacked_r0);
    exception_dump("\r\n");

    exception_dump("R1: ");
    hex2string(stacked_r1);
    exception_dump("\r\n");

    exception_dump("R2: ");
    hex2string(stacked_r2);
    exception_dump("\r\n");

    exception_dump("R3: ");
    hex2string(stacked_r3);
    exception_dump("\r\n");

    exception_dump("R12: ");
    hex2string(stacked_r12);
    exception_dump("\r\n");

    exception_dump("LR: ");
    hex2string(stacked_lr);
    exception_dump("\r\n");

    exception_dump("PC: ");
    hex2string(stacked_pc);
    exception_dump("\r\n");

    exception_dump("PSR: ");
    hex2string(stacked_psr);
    exception_dump("\r\n");

    exception_dump("Fault Type: ");
    faulttype((FaultType)__get_IPSR());
    exception_dump("\r\n");

    bkpt();
    NVIC_SystemReset();
}

void BusFault_Handler(void) __attribute__((alias("HardFault_Handler")));
void UsageFault_Handler(void) __attribute__((alias("HardFault_Handler")));
void MemManage_Handler(void) __attribute__((alias("HardFault_Handler")));
*/