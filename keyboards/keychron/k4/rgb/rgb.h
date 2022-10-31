#ifndef RGB_H
#define RGB_H

#include "quantum.h"

#if defined(KEYBOARD_keychron_k4_rgb_v1)
  #include "v1.h"
#elif defined(KEYBOARD_keychron_k4_rgb_v2)
  #include "v2.h"
#endif // Keychron K4 RGB revisions

#endif
