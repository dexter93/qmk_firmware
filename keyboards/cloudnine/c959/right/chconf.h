#pragma once
#include_next <chconf.h>
#undef CH_CFG_USE_MUTEXES
#define CH_CFG_USE_MUTEXES TRUE
