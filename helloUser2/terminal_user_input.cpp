#include "splashkit.h"
using namespace std;

string read_string ( string prompt )
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}


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

int read_integer_range( string prompt, int min, int max)
{
    int result;
    result = read_integer(prompt);
    while ( result < min or result > max )
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }
    return result;
}




double read_double ( string prompt )
{
    string line;
    int result;
    line = read_string(prompt);
    while (not is_double(line))
{
    write_line("Inavild input. Retry");
    line = read_string(prompt);
}
    result = convert_to_double(line);
    return result;
}

double read_double_range( string prompt, double min, double max)
{
    double result;
    result = read_double(prompt);
    while ( result < min or result > max )
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_double(prompt);
    }
    return result;
}

void read_boolean ( string prompt )
{
    string result;
    string trim_result;
    string low_result;

    write(prompt);
    result = read_line();
    low_result = to_lowercase(result);
    trim_result = trim(low_result);

    if (trim_result == "yes")
    {
        write("That's great!");
    }
    else if (trim_result == "y" )
    {
        write("That's great!");
    }
    else if (trim_result == "no")
    {
        write("sorry!");
    }
    else if (trim_result == "n")
    {
        write("sorry!");
    }
    else
    {
        write("Wrong input.Values can be only be of yes, no, y, n");
    }
    
}


