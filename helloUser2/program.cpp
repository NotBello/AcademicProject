#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

int main()
{
string name;
int age;
double height;
double weight;
double bmi;
int test;
double second_test;
string text;

name = read_string("Enter your name: ");
write_line("Welcome " + name);

age = read_integer("Enter your age: ");
write_line("Great you are " + to_string(age));

test = read_integer_range("Enter a value to test the range read integer function: ", 1, 13);
write_line(to_string(test));

second_test = read_double_range("Enter a value to test the range read double function: ", 0.00, 13.00);
write_line(to_string(second_test));

height = read_double("Enter your height: ");
weight = read_double("Enter your weight: ");
bmi = weight / (height * height);
write_line("Your BMI is " + to_string(bmi));

read_boolean("Are you satisfied with your bmi result?");

return 0;

}