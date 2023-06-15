#include "splashkit.h"
#include "planet_play.h"

/**
 * This function intiialises a new game with fresh data
 * 
 * @return result       The new game data after reset
*/
space_game_data new_game()
{
    space_game_data result;
    result.player = new_player();
    result.planets = reset_planet();
    add_random_coin(result);
    add_random_planet(result);
    result.score = 0;

    return  result;
}

/**
 * This function draws the bitmaps required for the game
 * 
 * @param game      The game data
*/
void draw_game(const space_game_data &game)
{
    clear_screen(COLOR_BLACK);
    draw_player(game.player);

    for(int i = 0; i < game.planets.size(); i++)
    {
        draw_planet(game.planets[i]);
    }

    for(int i = 0; i < game.coins.size(); i++)
    {
        draw_coin(game.coins[i]); 
    }

    draw_text("score: " + std::to_string(game.score),COLOR_WHITE, 10, 10);
    refresh_screen(30);
}

/**
 * This function removes coins
 * 
 * @param coins     the coins dynamic array
 * @param idx       the index of the coin we want to remove
*/
void remove_coin(vector<coin_data> &coins, int idx)
{
    free_animation(coins[idx].coin_animation);

    coins[idx] = coins[coins.size() - 1];
    coins.pop_back();
}

/**
 * This function removes the planets
 * @param planets       the planets dynamic array
 * @param idx           the index of the planet we want to remove
*/
void remove_planet(vector<planet_data> &planets, int idx)
{
    planets[idx] = planets[planets.size() - 1];
    planets.pop_back();
}

/**
 * This function increments the score of the player
 * @param game  the game data
*/
void increment_score(space_game_data &game)
{
    game.score++;
}

/**
 * This function decrements the score of the player
 * @param game  the game data
*/
void decrement_score(space_game_data &game)
{
    game.score--;
}

/**
 * This function updates the coins based on the player action
 * @param coins         The coins dynamic array
 * @param planets       The planets dynamic array
 * @param player        The player data
 * @param game          The game data
*/
void update_coins(vector<coin_data> &coins ,vector<planet_data> &planets, const player_data &player, space_game_data &game)
{
    vector<int> to_remove;

    for(int i = 0; i < coins.size(); i++)
    {
        update_coin(coins[i]);

        if (player_hit_coin(player, coins[i]))
        {
            to_remove.push_back(i);

            increment_score(game); // Call the new function to increment the score
        }
        else if(coin_hit_planet(planets, coins[i]))
        {
            to_remove.push_back(i);
        }
    }

    for(int i = to_remove.size() - 1; i >= 0; i--)
    {
        remove_coin(coins, to_remove[i]);
    }
}

/**
 * This function updates the planets based on the player action
 * @param planets       The planets dynamic array
 * @param player        The player data
 * @param game          The game data
*/
void update_planets(vector<planet_data> &planets, const player_data &player, space_game_data &game)
{
    bool currently_collidng = false;    

    for(int i = 0; i < planets.size(); i++)
    {
        update_planet(planets[i]);


        if (player_hit_planet(player, planets[i]))
        {
            decrement_score(game); // Call the new function to decremcrement the score
            currently_collidng = true;
        }
    }

    if(currently_collidng and not game.player.previously_collided)
            {
                play_sound_effect("explosion");
                game.player.previously_collided = true;
            }
            else if(not currently_collidng) game.player.previously_collided = false;
    
    if(off_screen(planets)) planets = reset_planet();
}

/**
 * This functions handles the user inputs and updates the game
 * @param game      the game data
*/
void update_game(space_game_data &game)
{
    handle_input(game.player);

    for(int i = 0; i < game.planets.size(); i++){
    update_planet(game.planets[i]);
    }
    
    update_coins(game.coins, game.planets, game.player, game);
    update_planets(game.planets, game.player, game);

    if ( rnd() < 0.03 )
    {
        add_random_coin(game);
    }
}

/**
 * This function spawns random coin
 * @param game      the game data
*/
void add_random_coin(space_game_data &game)
{
    game.coins.push_back( new_coin());
}

/**
 * This function spawns random planets
 * @param game      the game data
*/
void add_random_planet(space_game_data &game)
{
    game.planets.push_back( new_planet());
}
