#include "splashkit.h"

using namespace std;

string read_string( string prompt )
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer( string prompt )
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


double read_double( string prompt )
{
    string line;
    double result;
    line = read_string(prompt);
    while (not is_double(line))
{
    write_line("Inavild input. Retry");
    line = read_string(prompt);
}
    result = convert_to_double(line);
    return result;
}

void read_values(double values[], int size)
{
    for(int i = 0; i < size; i++)
    {
        values[i] = read_double ("Enter double values : ");
    }
}

void print_values(double values[], int size)
{
    for(int i = 0; i < size; i++)
    {
        write_line( values[i] );
    }
}

double sum(const double values[], int size)
{
    double result = 0;

    for(int i = 0; i < size; i++)
    {
        result += values[i];
    }

    return result;
}

int count_negative(const double values[], int size)
{
    int nCount = 0;

    for(int i = 0; i < size; i++)
    {
        if (values[i] < 0)
        {
            nCount += 1;
        }
        
    }
    return nCount;
}

double maximum(const double values[], int size)
{
    double max = values[0];

    for(int i = 0; i < size; i++)
    {
        if (values[i] > max)
        {
            max = values[i];
        }
    }
    return max;
}

int main()
{
    int count;

    count = read_integer ("How many values : ");

    double temp[count];

    read_values(temp, count);
    print_values(temp, count);

    write_line("Sum is : ");
    write_line( sum(temp, count ));
    
    write_line("The number of negative values : ");
    write_line( count_negative(temp, count) );

    write_line("The max : ");
    write_line( maximum(temp, count) );

    return 0;
}