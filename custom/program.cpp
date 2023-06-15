#include <iostream>
#include <vector>
#include <string>
#include <splashkit.h>

using namespace std;

// Define the Employee struct
struct Employee
{
    string name;
    int age;
    string department;
};

/**
 * Add employees info into a dynamic array and store it.
 * 
 * @param employees     List of employees
*/
void addEmployee(vector<Employee>& employees)
{
    Employee newEmployee;
    write_line("Enter employee name: ");
    newEmployee.name = read_line();
    write_line("Enter employee age: ");
    newEmployee.age = convert_to_integer(read_line());
    write_line("Enter employee department: ");
    newEmployee.department = read_line();

    employees.push_back(newEmployee);
    write_line("Employee added successfully!");
}

/**Venujan_Malaiyandi_BSCP_CS_61_101*/

/**
 * Procedure to display all employees
 * 
 * @param employees     List of employees
*/
void displayEmployees(const vector<Employee>& employees)
{
    for (const auto& employee : employees)
    {
        write_line("Name: " + employee.name);
        write_line("Age: " + to_string(employee.age));
        write_line("Department: " + employee.department);
        write_line("-----------------------");
    }
}

/**
 *  Procedure to change employee's department
 * 
 * @param employees         List of employees
 * @param name              Name of the employee
 * @param newDepartement    Name of the New departement 
*/
void changeDepartment(vector<Employee>& employees, const string& name, const string& newDepartment)
{
    for (auto& employee : employees)
    {
        if (employee.name == name)
        {
            employee.department = newDepartment;
            write_line("Department changed successfully!");
            return;
        }
    }

    write_line("Employee not found!");
}

/**
 * Main  of the program which displays a menu of options
 * and reads inputs to choose one from them.
*/
int main()
{
    vector<Employee> employees;
    int choice;

    do
    {
        write_line("1. Add Employee");
        write_line("2. Display Employees");
        write_line("3. Change Department");
        write_line("4. Exit");
        write_line("Enter your choice: ");
        choice = convert_to_integer(read_line());

        string name, newDepartment;

        switch (choice)
        {
            case 1:
                addEmployee(employees);
                break;
            case 2:
                displayEmployees(employees);
                break;
            case 3:
                
                write_line("Enter employee name: ");
                name = read_line();
                write_line("Enter new department: ");
                newDepartment = read_line();
                changeDepartment(employees, name, newDepartment);
                break;
            case 4:
                write_line("Exiting program...");
                break;
            default:
                write_line("Invalid choice! Please try again.");
        }

        write_line("");

    } while (choice != 4);

    return 0;
}
