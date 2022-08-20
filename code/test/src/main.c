#include <core/asserts.h>
#include <core/logger.h>

// TODO: Test
#include <platform/platform.h>

int main() {
    SFATAL("A test message: %f", 3.14f);
    SERROR("A test message: %f", 3.14f);
    SWARN("A test message: %f", 3.14f);
    SINFO("A test message: %f", 3.14f);
    SDEBUG("A test message: %f", 3.14f);
    STRACE("A test message: %f", 3.14f);

    platform_state state;
    if(platform_startup(&state, "Sped Engine Test", 100, 100, 1280, 720)) {
        while(TRUE) {
            platform_pump_messages(&state);
        }
    }

    platform_shutdown(&state);

    return 0;
}