#include "splashkit.h"
#include <vector>

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

    result = convert_to_double(line);
    return result;
}

void read_values(vector<double> &values, int count)
{
    double data;
    for(int i = 0; i < count; i++)
    {
        data = read_double("Enter the value : ");
        values.push_back(data);
    }
}

void print_values(vector<double> values)
{
    write_line("values are : ");
    for(int i = 0; i < values.size(); i++ )
    {
        write_line( values[i] );
    }
}

double sum(vector<double> values)
{
    double result = 0;

    for(int i = 0; i < values.size(); i++)
    {
        result += values[i];
    }

    return result;
}

int count_negative(vector<double> values)
{
    int nCount = 0;

    for(int i = 0; i < values.size(); i++)
    {
        if (values[i] < 0)
        {
            nCount += 1;
        }
        
    }
    return nCount;
}

double maximum(vector<double> values)
{
    double max = values[0];

    for(int i = 0; i < values.size(); i++)
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

    vector<double> temp;

    read_values(temp, count);

    print_values(temp);

    write_line("Sum is : ");
    write_line( sum(temp));
    
    write_line("The number of negative values : ");
    write_line( count_negative(temp) );

    write_line("The max : ");
    write_line( maximum(temp) );

    return 0;
}