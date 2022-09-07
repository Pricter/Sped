#pragma once

#include "defines.h"

typedef struct clock {
    f64 start_time;
    f64 elapsed;
} clock;

SAPI void clock_update(clock* clock);
SAPI void clock_start(clock* clock);
SAPI void clock_stop(clock* clock);