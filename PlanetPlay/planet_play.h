#include "splashkit.h" 
#include <vector>

using namespace std;

#define PLAYER_SPEED 7
#define PLANET_DRIFT 3

enum ship_kind
{
    AQUARII,
    GLIESE,
    PEGASI
};

enum planet_kind
{
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    PLUTO
};

bitmap planet_bitmap(planet_kind kind);

struct player_data
{
    ship_kind kind;
    bool previously_collided;   
    double x;
    double y;
};

struct planet_data
{
    planet_kind kind;
    double x;
    double y;
};

struct coin_data
{
    animation coin_animation;
    double x;
    double y;
};

struct space_game_data
{
    player_data                 player;
    vector<planet_data>         planets;
    vector<coin_data>           coins;
    int                         score;
};


player_data new_player();
void draw_player(const player_data &player_to_draw);
void handle_input(player_data &player); 
bool player_hit_coin(const player_data &player, const coin_data &coin);
bool player_hit_planet(const player_data &player, const planet_data &planet);

planet_data new_planet();
planet_kind random_planet_kind();
void update_planet(planet_data &planet);
void update_planets(vector<planet_data> &planets, const player_data &player, space_game_data &game);
void draw_planet(const planet_data &planet_to_draw);
vector<planet_data> reset_planet();
bool coin_hit_planet(const vector<planet_data> &planet, const coin_data &coin);
bool off_screen(const vector<planet_data> &planet);

coin_data new_coin(double x, double y);
coin_data new_coin();
void draw_coin(const coin_data &coin);
void update_coin(coin_data &coin);
void update_coins(vector<coin_data> &coins ,vector<planet_data> &planets, const player_data &player, space_game_data &game);
void increment_score(space_game_data &game);
void decrement_score(space_game_data &game);

space_game_data new_game();
void update_game(space_game_data &game);
void draw_game(const space_game_data &game);
void add_random_coin(space_game_data &game);
void add_random_planet(space_game_data &game);


