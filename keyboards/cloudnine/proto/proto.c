
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
    {0, CB4_O,  CB5_O,  CB6_O},




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
    {0, CA4_G,  CA5_G,  CA6_G},
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
    {0, CB1_M,  CB2_M,  CB3_M}
};

#endif
//bool is_keyboard_left_impl(void) {
  // return false;
//}

#include <stdint.h>
#include <string.h>
#include <ch.h>

#define bkpt() __asm volatile("BKPT #0\n")

// Fault type decoder for ARM Cortex-M0
typedef enum {
    FAULT_RESET     = 1,
    FAULT_NMI       = 2,
    FAULT_HARDFAULT = 3,
} FaultType;

static volatile char debug_buffer[512] = {0};
static volatile uint16_t debug_buffer_index = 0;

static void append_debug_char(char c) {
    if (debug_buffer_index < sizeof(debug_buffer) - 1) {
        debug_buffer[debug_buffer_index++] = c;
    }
}

static void append_string(const char *s) {
    while (*s) append_debug_char(*s++);
}

static void append_hex32(uint32_t value) {
    append_string("0x");
    for (int i = 7; i >= 0; i--) {
        uint8_t nibble = (value >> (i * 4)) & 0xF;
        append_debug_char(nibble < 10 ? '0' + nibble : 'A' + nibble - 10);
    }
}

static void append_reg_line(const char *label, uint32_t value) {
    append_string(label);
    append_string(": ");
    append_hex32(value);
    append_string("\r\n");
}

static void append_fault_type(uint32_t ipsr) {
    append_string("Fault Type: ");
    switch (ipsr) {
        case FAULT_RESET:
            append_string("Reset");
            break;
        case FAULT_NMI:
            append_string("NMI");
            break;
        case FAULT_HARDFAULT:
            append_string("HardFault");
            break;
        default:
            append_string("IRQ ");
            append_hex32(ipsr);
            break;
    }
    append_string("\r\n");
}

// Cortex-M0 only supports PSP/MSP, no fault status registers.
// __attribute__((naked)) not used to keep this portable with ChibiOS
void HardFault_Handler(void) {
    uint32_t *sp;

    // Try to determine active stack pointer (MSP or PSP)
    __asm volatile (
        "mrs %[result], msp"
        : [result] "=r" (sp)
    );

    uint32_t r0  = sp[0];
    uint32_t r1  = sp[1];
    uint32_t r2  = sp[2];
    uint32_t r3  = sp[3];
    uint32_t r12 = sp[4];
    uint32_t lr  = sp[5];
    uint32_t pc  = sp[6];
    uint32_t psr = sp[7];

    append_string("********* EXCEPTION DUMP *********\r\n");

    append_reg_line("R0", r0);
    append_reg_line("R1", r1);
    append_reg_line("R2", r2);
    append_reg_line("R3", r3);
    append_reg_line("R12", r12);
    append_reg_line("LR", lr);   // Link Register (return address)
    append_reg_line("PC", pc);   // Program Counter (where it faulted)
    append_reg_line("PSR", psr); // Program Status Register

    uint32_t ipsr;
    __asm volatile ("mrs %0, ipsr" : "=r"(ipsr));
    append_fault_type(ipsr);

    append_string("**********************************\r\n");

    //signal_fault(); // Optional LED or pin signaling

    bkpt(); // Wait for debugger if attached
    NVIC_SystemReset(); // Reboot
}

// Aliases for M0 (only HardFault exists, no MemManage, BusFault, UsageFault)
void MemManage_Handler(void) __attribute__((alias("HardFault_Handler")));
void BusFault_Handler(void) __attribute__((alias("HardFault_Handler")));
void UsageFault_Handler(void) __attribute__((alias("HardFault_Handler")));
void _unhandled_exception(void) __attribute__((alias("HardFault_Handler")));
