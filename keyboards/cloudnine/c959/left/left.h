#pragma once

#include "quantum.h"
/* Define layer names */
enum layers{
  _BASE,
  _FN
};

typedef struct {
    bool fn_active;
    bool macro;
} extended_led_t;
