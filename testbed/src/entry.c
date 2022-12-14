#include "game.h"
#include <entry.h>
#include <core/smemory.h>

b8 create_game(game* out_game) {
    out_game->app_config.start_pos_x = 100;
    out_game->app_config.start_pos_y = 100;
    out_game->app_config.start_width = 1920;
    out_game->app_config.start_height = 1080;
    out_game->app_config.name = "Sped Engine testbed";
    out_game->update = game_update;
    out_game->render = game_render;
    out_game->initialize = game_initialize;
    out_game->on_resize = game_on_resize;

    out_game->state = sallocate(sizeof(game_state), MEMORY_TAG_GAME);
    out_game->application_state = 0;

    return true;
}