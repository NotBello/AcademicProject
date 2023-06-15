#include "splashkit.h"
#include "planet_play.h"

/**
 * This is the bitmap switch function to return ships
 * @param kind      the ship kind
*/
bitmap ship_bitmap(ship_kind kind)
{
    switch(kind)
    {
        case AQUARII:
            return bitmap_named("pegasi");
        case GLIESE:
            return bitmap_named("gliese");
        default:
            return  bitmap_named("aquarii");
    }
}

/**
 * This function creates new player with default ship and location
 * @return result       results the new spawn player data
*/
player_data new_player()
{
    player_data result;
    result.kind = PEGASI;
    result.x = 50;
    result.y = 200;

    return result;
}

/**
 * This function handles the inputs
 * @param player        player data
*/
void handle_input(player_data &player)
{
    if(key_typed(NUM_1_KEY)) player.kind = AQUARII;
    if(key_typed(NUM_2_KEY)) player.kind = GLIESE;
    if(key_typed(NUM_3_KEY)) player.kind = PEGASI;

    if(key_down(RIGHT_KEY)) player.x += PLAYER_SPEED;
    if(key_down(LEFT_KEY)) player.x -= PLAYER_SPEED;
    if(key_down(UP_KEY)) player.y -= PLAYER_SPEED;
    if(key_down(DOWN_KEY)) player.y += PLAYER_SPEED;
}

/**
 * This function draws player
 * @param   player_to_draw      The player bitmaps to draw
*/
void draw_player(const player_data &player_to_draw)
{
    bitmap to_draw;
    to_draw = ship_bitmap(player_to_draw.kind);
    draw_bitmap(to_draw, player_to_draw.x, player_to_draw.y);
}

/**
 * This is a boolean function to collision check player if they hit coin
 * @param player        the player data
 * @param coin          the coin data
 * @return true or false    based on the collsion condition
*/
bool player_hit_coin(const player_data &player, const coin_data &coin)
{
    bitmap coin_bmp = bitmap_named("gold_coin");
    int coin_cell = animation_current_cell(coin.coin_animation);
    
    bitmap ship_bmp = ship_bitmap(player.kind);

    return bitmap_collision(
        coin_bmp, coin_cell, coin.x, coin.y,
        ship_bmp, 0, player.x, player.y
    );

}

/**
 * This function checks for player if they hit planet
 * @param player        player data
 * @param planet        planet data
*/
bool player_hit_planet(const player_data &player, const planet_data &planet)
{
    bitmap ship_bmp = ship_bitmap(player.kind);
    bitmap planet_bmp = planet_bitmap(planet.kind);

    return bitmap_collision(
        ship_bmp, 0, player.x, player.y,
        planet_bmp, 0, planet.x, planet.y
    );
}

