#pragma once

#include "core/application.h"
#include "core/logger.h"
#include "core/smemory.h"
#include "game_types.h"

extern b8 create_game(game* out_game);

int main() {
    initialize_memory();

    game game_inst;
    if(!create_game(&game_inst)) {
        SFATAL("Could not create game!");
        return -1;
    }

    if(!game_inst.render || !game_inst.update || !game_inst.initialize || !game_inst.on_resize) {
        SFATAL("The game's function pointers must be assigned!");
        return -2;
    }
    
    if(!application_create(&game_inst)) {
        SINFO("Application falied to create!.");
        return 1;
    }

    if(!application_run()) {
        SINFO("Application did not shutdown gracefully.");
        return 2;
    }

    shutdown_memory();

    return 0;
}