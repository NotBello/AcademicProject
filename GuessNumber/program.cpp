#include "splashkit.h"

# define RND 6
using namespace std;

/**This function reads string inputs from user
 * 
 * @param prompt    The message displayed to prompt the user to supply data
 * 
 * @return result   The line of text entered by the user
*/
string read_string ( string prompt )
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

/**This function reads string input from user using read string function and converts it into integer, while also case checking.
 * 
 * @param prompt    The message displayed to prompt the user to supply data
 * 
 * @return result   The integer from user
*/
int read_integer ( string prompt )
{
    string line;
    int result;
    line = read_string(prompt);
    while (not is_integer(line))
    {
        write_line("Inavild input. Retry");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

/**This function generates a ranodom number
 * 
 * @return result   The line of text entered by the user
*/
int random ()
{
    int result;
    result = rnd(RND);
    return result;
}

/**This function reads integer input from user and compares it with the generated random number.
 * 
 * @param randomnum    The random generated using function
 * 
 * @return result      A value between 0 or 1. This is used for condition checking withe rest of the program
*/
int randomCondition( int randomnum )
{
    int guessInput;
    int result;
    result = 0;
    guessInput = read_integer("Enter your guess between 0 and 5 : ");
    if ( guessInput == randomnum )
    {
        result = 1;
        write_line("Great guess");
    }
    else if ( guessInput < randomnum)
    {
        result = 0;
        write_line("Your guess is lower than the target");
    }
    else if ( guessInput > randomnum )
    {
        result = 0;
        write_line("Your guess is higher than the target");
    }
    else
    {
        result = 0;
    }
    return result;
}

/**This function loops the random function until the user exits
 * 
 * @param result      A value between 0 or 1 computed from previous functions
 * 
 * @param randomNumber Generated number
 * 
 * @return result   A value between 0 or 1. This is used for condition checking withe rest of the program
*/
int randomloop( int result, int randomNumber )
{
    while (result == 0)
    {
        result = randomCondition( randomNumber );
    }
    return result;
}

/**This function loops the random function until the user exits
 * 
*/
void randomfunction()
{
    int randomNumber;
    int result = 0;
    randomNumber = random();
    randomloop( result, randomNumber );
}

/**The main sequence of the program. This will -
 * 
 * engange the loop function which generates a number and checks it with the user inputed number.
 * 
 * Repeat the loop fuunction until the user decided not to by not typing 'yes'
 * 
 * @return          0 to indicate success to the operating systems
 */
int main()
{
    string userinput;
    randomfunction();
    write_line("If you want to type again type 'yes' ");
    userinput = read_line();
    while ( userinput == "yes" )
    {
        randomfunction();
        userinput = read_line();
    }
    write_line("Thank you for playing");
    
    return 0;
}