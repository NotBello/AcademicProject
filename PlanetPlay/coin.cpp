#include "splashkit.h"
#include "planet_play.h"

/**
 * This function creates new coin with animation
 * 
 * @param double x      the x axis location of the new coin
 * @param double y      the y axis location of the new coin
 * 
 * @return result       the new coin 
*/
coin_data new_coin(double x, double y)
{
    coin_data result;

    result.x = x;
    result.y = y;
    result.coin_animation = create_animation("coins", "spin");

    return result;
}

/**
 * This function loads the bitmap gold coin 
 * 
 * @return          the new_coin function with their random coordinates
 *                  within the game screen
*/
coin_data new_coin()
{
    bitmap coin_bmp = bitmap_named("gold_coin");
    return new_coin( rnd(screen_width() - bitmap_width(coin_bmp)), rnd(screen_height() - bitmap_height(coin_bmp)));
}

/**
 * This function draws the coin bitmap
 * @param &coin       the coin to be display
*/
void draw_coin(const coin_data &coin)
{
    draw_bitmap("gold_coin", coin.x, coin.y, option_with_animation(coin.coin_animation));

}

/**
 * This function updates the coin animation
 * 
 * @param coin      the coin to be displayed
*/
void update_coin(coin_data &coin)
{
    update_animation(coin.coin_animation);
}

/**
 * This is a boolean function to check if the coin hit planet
 * @param planet        the planets which is colliding with the coins
 * @param coins         the coins which is gets collided by the planets
 * 
 * @return true / false     based on the condition
*/
bool coin_hit_planet(const vector<planet_data> &planet, const coin_data &coin)
{
    bitmap coin_bmp = bitmap_named("gold_coin");
    int coin_cell = animation_current_cell(coin.coin_animation);
    
    for(int i = 0 ; i < planet.size(); i++)
    {
         bitmap planet_bmp = planet_bitmap(planet[i].kind);
         if( bitmap_collision(
        coin_bmp, coin_cell, coin.x, coin.y,
        planet_bmp, 0, planet[i].x, planet[i].y))
        {
            return true;
        }
    
    }
    return false;  

}