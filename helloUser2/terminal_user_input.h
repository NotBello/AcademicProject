#include <string>
using std::string;
string read_string ( string prompt );
int read_integer ( string prompt );
double read_double ( string prompt );
int read_integer_range( string prompt, int min, int max);
double read_double_range( string prompt, double min, double max);
void read_boolean ( string prompt );
