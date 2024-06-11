#pragma once

#define HAL_USE_SERIAL TRUE
#include_next <halconf.h>
#undef HAL_USE_PWM
#define HAL_USE_PWM FALSE
