#include "splashkit.h"
using namespace std;

int main()
{
   string userName;  //variable declaration
   string stringAge;
   string stringCurrentYear;
   int age;
   int currentYear;
   int dateOfBirthYear;


   write("Enter your username : "); //taking username from the user
   userName = read_line(); //storing username value into variable
   write_line("Welcome !! " + userName); //concatonating variable with string and displaying
   
   write("Enter your age : "); //taking age from the user
   stringAge = read_line(); // storing values into variabel
   age = convert_to_integer(stringAge); //converting varaible into integer for calculations and stroing it in a separate variable

   write("Enter the current year : ");//similar logic from getting age from the user
   stringCurrentYear = read_line();
   currentYear = convert_to_integer(stringCurrentYear);

   dateOfBirthYear = currentYear - age;//performing calculations to find the year of birth
   
   write_line("Your year of birth is : " + to_string(dateOfBirthYear)); //displaying the output

   return 0;
}