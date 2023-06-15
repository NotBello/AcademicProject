#include "splashkit.h"
#include "planet_play.h"

/**
 * This function loads the required i-game resources and bitmaps
 * into the game
 * 
*/
void load_resources()           //loading resource budle
{
    load_resource_bundle("game_bundle", "planet_play.txt");
}

/**
 * This is the main function which is sequentially executed
 * @return 0        to show the successful execution of the
 *                  program to the operating system
*/
int main()                  //main function
{
    open_window("Space game by Bello  ", 800, 500);
    load_resources();

    space_game_data game;
    
    game = new_game();

    while ( not quit_requested() )
    {
        process_events();

        update_game(game);
        
        clear_screen(COLOR_SKY_BLUE);

        draw_game(game);
    }

    return 0;
}