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
result = convert_to_integer(line);
return result;
}

double read_double ( string prompt )
{
string line;
double result;
line = read_string(prompt);
result = convert_to_double(line);
return result;
}

void output_crazy_age(int age)
{
    write(to_string(age) + " is a ");

    int i = 0;
    while ( i < 5)
    {
        write("crazy ");
        i++;
    }
    write_line("Age!");
}

void output_silly_age()
{
write_line("Thats a silly name!");
write_line("Are you sure that's you're real name?");
}

int main()
{
string name;
int age, current_year;
double weight, height;

name = read_string("Enter your name: ");
if (name == "Ovindu" or name == "Anushan")
{
    write_line("Hey there friend");
}else if (name == "Bello")
{
    write_line("You're me aren't ya?");
}else
{
    output_silly_age();
}


write_line("Welcome " + name);

age = read_integer("Enter your age this year: ");

if (age == 42){
    write_line("Interesting Age!");
    delay(200);
}else if (age < 0 or age > 120)
{
    write_line("Are you sure?");

}else if (age > 5 and age < 10)
{
    output_crazy_age(age);
}else
{
    write_line("Great you are " + to_string(age));
}

current_year = read_integer("Enter current Year: ");
write_line("You were born in: " + to_string(current_year-age));

weight = read_double("Enter your weight in kg: ");
height = read_double("Enter your height in cm: ");
write_line("Your BMI is: " + to_string(weight/((height/100)*(height/100))));

return 0;
}