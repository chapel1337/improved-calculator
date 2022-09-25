#include <iostream>
#include <string> // for read() function
#include <windows.h> // for sleep function
using std::cout; using std::cin; using std::string;

// written by chapel1337
// made on 9/25/2022
// 
// my largest and most irritating project let
// this was a nightmare to make, i learned a decent amount when making it though
// does not support decimals and breaks when the second integer is smaller than the first
// i have lost all motivation to continue this project, so i will not be fixing those issues

std::string read()
{
    std::string s{};
    std::getline(std::cin >> std::ws, s);
    return s;
}

string inputEquation{ "undefined" };
string number1{ "undefined" };
string number2{ "undefined" };
// string operation{};

long result{};

namespace calculate
{
    void add()
    {
        result = std::stol(number1) + std::stol(number2);
    }

    void subtract()
    {
        result = std::stol(number1) - std::stol(number2);
    }

    void multiply()
    {
        result = std::stol(number1) * std::stol(number2);
    }

    void divide()
    {
        result = std::stol(number1) / std::stol(number2);
    }

    void modulus()
    {
        result = std::stol(number1) % std::stol(number2);
    }
}

void menu();

void invalidInput()
{

    system("cls");
    cout << "invalid input\n";

    Sleep(2000);
    system("cls");

    menu();
}

void checkOperation()
{
    /*
    if (number1.length() >= 2)
    {
        operation = inputEquation.substr(inputEquation.find(' ') + 1, inputEquation.find(' ') - number1.length() + 1);
    }
    else
    {
        operation = inputEquation.substr(inputEquation.find(' ') + 1, inputEquation.find(' '));
    }
    */
    number1 = inputEquation.substr(0, inputEquation.find(' '));
    number2 = inputEquation.substr(inputEquation.find(' ') + 3, inputEquation.length());

    if (number1 == "undefined")
    {
        invalidInput();
    }
    if (number2 == "undefined")
    {
        invalidInput();
    }

    // inability to convert string to char has left me no choice but to else if spam : (
    if (inputEquation.find('+') != string::npos)
    {
        calculate::add();
    }
    else if (inputEquation.find('-') != string::npos)
    {
        calculate::subtract();
    }
    else if (inputEquation.find('*') != string::npos)
    {
        calculate::multiply();
    }
    else if (inputEquation.find('/') != string::npos)
    {
        calculate::divide();
    }
    else if (inputEquation.find('%') != string::npos)
    {
        calculate::modulus();
    }
    else
    {
        cout << "something went wrong :coffin:\n";
        // invalidInput();
    }
}

void checkForInvalid()
{
    // You are now entering: Hell
    
    if (inputEquation.find('+') == string::npos && inputEquation.find('-') == string::npos && inputEquation.find('*') == string::npos && inputEquation.find('/') == string::npos && inputEquation.find('%') == string::npos)
    {
        invalidInput();
    }

    if (inputEquation == "undefined")
    {
        invalidInput();
    }
    
    checkOperation();

    // You are now exiting: Hell
}

void menu()
{
    cout << "input an equation: \n";
    inputEquation = read();

    checkForInvalid();

    cout << "result: " << result << "\n\n";

    menu();
}

int main()
{
    menu();
}