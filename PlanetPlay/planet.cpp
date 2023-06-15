#include "splashkit.h"
#include "planet_play.h"    
#include <vector>

using namespace std;

/**
 * This function chooses a random planet 
 * @return random index pointing to array of planets
*/
planet_kind random_planet_kind()
{
    return static_cast<planet_kind>( rnd(8) );
}

/**
 * function to return different planet bitmaps based on different case
 * @param kind      planet kind from the other function
*/
bitmap planet_bitmap(planet_kind kind)
{
    switch (kind)
    {
        case MERCURY:
            return bitmap_named("mercury");
        case VENUS:
            return bitmap_named("venus");
        case EARTH:
            return bitmap_named("earth");
        case MARS:
            return bitmap_named("mars");
        case JUPITER:
            return bitmap_named("jupiter");
        case SATURN:
            return bitmap_named("saturn");
        case URANUS:
            return bitmap_named("uranus");
        case NEPTUNE:
            return bitmap_named("neptune");
        default:
            return bitmap_named("pluto");
    }
}

/**
 * This function intialises new planet with new data
 * @return result       the initialised planet
*/
planet_data new_planet()
{
    planet_data result;
    result.kind = random_planet_kind();
    result.x = screen_width() + rnd(300);
    result.y = rnd(screen_height()) - 50;
    return result;

}

/**
 * This function draws planets
 * @param planet_to_draw        This function draws planet
*/
void draw_planet(const planet_data &planet_to_draw)
{
    bitmap to_draw;
    to_draw = planet_bitmap(planet_to_draw.kind);
    draw_bitmap(to_draw, planet_to_draw.x, planet_to_draw.y);
}

/**
 * This function checks for offscreen
 * @param planet        the dynamic array of planets in the screen
 * @return true / false     based on the condition
*/
bool off_screen(const vector<planet_data> &planet)
{
    for(int i = 0; i < planet.size(); i++ )
    {
        if(planet[i].x > -300) return false;
    }
    return true;
}

/**
 * This function updates planets
*/
void update_planet(planet_data &planet)
{   
    if(planet.x < -300) planet = new_planet();
    else planet.x -= PLANET_DRIFT;
}

/**
 * This function resets the planets after they move off screen 
*/
vector<planet_data> reset_planet()
{
    vector<planet_data> result;
    int count = rnd(1,3);

    for(int i = 0; i < count; i++)
    {
        result.push_back(new_planet());
    }

    return result;

}