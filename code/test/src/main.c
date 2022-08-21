#include <core/asserts.h>
#include <platform/platform.h>
#include <core/logger.h>

int main() {
    SFATAL("A test message: %f", 3.14);
    SERROR("A test message: %f", 3.14);
    SWARN("A test message: %f", 3.14);
    SINFO("A test message: %f", 3.14);
    SDEBUG("A test message: %f", 3.14);
    STRACE("A test message: %f", 3.14);

    platform_state state;
    if(platform_startup(&state, "Sped Engine test", 100, 100, 1920, 1080)) {
        while(TRUE) {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);

    return 0;
}