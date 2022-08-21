#include <core/asserts.h>
#include <core/logger.h>

#include <core/application.h>

int main() {
    application_config config;
    config.start_pos_x = 100;
    config.start_pos_y = 100;
    config.start_width = 1920;
    config.start_height = 1080;
    config.name = "Sped Engine Test";

    application_create(&config);
    application_run();

    return 0;
}