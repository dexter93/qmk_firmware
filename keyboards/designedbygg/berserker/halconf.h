#define HAL_USE_GPT TRUE
#define SN32_GPT_USE_CT16B1 TRUE
#include_next <halconf.h>
#undef HAL_USE_PWM
#define HAL_USE_PWM FALSE
