#include "splashkit.h"
#include <vector>
using namespace std;

/**Struct to hold player name, playing position, and jersey number*/
struct player
{
    string name;
    string position;
    int    player_number;
};

/**Struct to hold team name, team captain, and team members */
struct team
{
    string TeamName;
    string Captain;

    vector<player> players;
};

/**Enum to store the menu options*/
enum MenuOption
{
    PRINT_TEAM,
    CHANGE_TEAM_NAME,
    CHANGE_CAPTAIN,
    EDIT_CAPTAIN_DETAILS,
    ADD_PLAYER,
    REMOVE_PLAYER,
    QUIT
};


/**
 * @param prompt     Text to be displayed when asking string.
 * 
 * @return result   reads strings
*/
string read_string ( string prompt )
{
    string result;

    write(prompt);
    result = read_line();

    return result;
}

/**
 * @param prompt    Text to be displayed when asking string.
 * 
 * @return result    Returns user inputed integer
*/
int read_integer ( string prompt )
{
    string line;
    int result;

    line = read_string(prompt);
    result = convert_to_integer(line);

    return result;
}

/**
 * This function takes details of the player as inputs
*/
player read_player()
{
    player result;

    result.name = read_string("Enter the player's name : ");
    result.position = read_string("Enter the player's position : ");
    result.player_number = read_integer("Enter the player's number : ");

    return result;
}

/**
 * This function takes the details of the team including
 * the total number of members and their captain, using a for loop.
*/
team read_team()
{
    team test;
    int count;

    test.TeamName = read_string("Enter the team's name : ");

    count = read_integer("Enter number of team mates : ");
    for(int i = 0; i < count; i++)
    {
        player teamMember;
        teamMember = read_player();
        test.players.push_back(teamMember);
    }

    test.Captain = read_string("Enter the team's captain name from the player list : ");

    return test;
}

/**
 * This function displayes the details of the designated player
*/
void print_player(const player &to_print)
{
    write_line(to_print.name + " " + to_print.position + " " + to_string(to_print.player_number));
}

/**
 * This function displayes the details of the team
*/
void print_team(const team &to_print)
{
    write_line("------------");
    write_line(to_print.TeamName);
    write_line("------------");
    for(player p : to_print.players)
    {
        print_player(p);
    }
    write_line("------------");
    write_line("The captain is");
    write_line(to_print.Captain);
}

/**
 * This function is used to get menu inputs(choices) from the user
 * 
 * @return  choice      with corresponding enum menu values
*/
MenuOption get_menu_choice()
{
    write_line("Menu Options:");
    write_line("1. Print team");
    write_line("2. Change team name");
    write_line("3. Change captain");
    write_line("4. Edit captain details");
    write_line("5. Add a new player");
    write_line("6. Remove a player");
    write_line("7. Quit");
    write("Enter your choice (1-7): ");

    int choice = read_integer("");
    // Validate the choice and return the corresponding menu option
    switch (choice)
    {
        case 1:
            return PRINT_TEAM;
        case 2:
            return CHANGE_TEAM_NAME;
        case 3:
            return CHANGE_CAPTAIN;
        case 4:
            return EDIT_CAPTAIN_DETAILS;
        case 5:
            return ADD_PLAYER;
        case 6:
            return REMOVE_PLAYER;
        case 7:
            return QUIT;
        default:
            write_line("Invalid choice. Please enter a number between 1 and 7.");
            return get_menu_choice(); // Recursive call to get a valid choice
    }
}

/**
 * The main sequence of the program
 * 
 * @return 0    Signfies the sucesseful execution to the operating systems
*/
int main()
{
    team test;
    test = read_team();

    while (true)
    {
        MenuOption choice = get_menu_choice();

        switch (choice)
        {
            case PRINT_TEAM:
                print_team(test);
                break;
            case CHANGE_TEAM_NAME:
                test.TeamName = read_string("Enter the new team name: ");
                break;
            case CHANGE_CAPTAIN:
                test.Captain = read_string("Enter the new captain name: ");
                break;
            case EDIT_CAPTAIN_DETAILS:
                {
                    player captainDetails = read_player();
                    test.Captain = captainDetails.name;
                    break;
                }
            case ADD_PLAYER:
                {
                    player newPlayer = read_player();
                    test.players.push_back(newPlayer);
                    break;
                }
            case REMOVE_PLAYER:
                {
                    write_line("Players in the team:");
                    for (int i = 0; i < test.players.size(); i++)
                    {
                        write_line(to_string(i + 1) + ". " + test.players[i].name);
                    }
                    int index = read_integer("Enter the index of the player to remove (0 to cancel): ");
                    if (index >= 1 && index <= test.players.size())
                    {
                        test.players.erase(test.players.begin() + index - 1);
                        write_line("Player removed successfully.");
                    }
                    else if (index != 0)
                    {
                        write_line("Invalid index. No player removed.");
                    }
                    break;
                }
            case QUIT:
                return 0;
        }
    }
}
