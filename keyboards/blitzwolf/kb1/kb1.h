#pragma once

#include "quantum.h"

#define XXXX KC_NO

#define LAYOUT_default( \
    /* 0,    1,    2,    3,    4,    5,    6     7,    8,    9,   10,   11,   12,   13,   */\
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013,     \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113,     \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211,       K213,     \
	K300,       K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,     \
	K400, K401, K402,                   K406,             K409, K410, K411, K412, K413      \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  XXXX,  K213 }, \
	{ K300,  XXXX,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313 }, \
	{ K400,  K401,  K402,  XXXX,  XXXX,  XXXX,  K406,  XXXX,  XXXX,  k309,  K410,  K411,  K412,  K413 }  \
}
