#pragma once

#include "defines.h"

typedef struct application_config {
    i16 start_pos_x;
    i16 start_pos_y;
    i16 start_width;
    i16 start_height;
    char* name;
} application_config;

SAPI b8 application_create(application_config* config);
SAPI b8 application_run();