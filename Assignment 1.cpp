/*
Sean Warnock
CSCI 15 Assignment 1 Fall 2018

http://www.chabotcollege.edu/faculty/kmehl/csci15/Quadratic1.pdf
https://github.com/seanwarnock/

Write a program, broken into functions as specified below, to read the coefficients of a series of quadratic equations from a text file and print the associated roots (or appropriate error messages if there are no real roots) to another text file.  The coefficients of a quadratic are the a, b and c of an expression of the form ax2 + bx + c, and the roots are the values of x that make the value of the expression 0.  The roots are given by this formula:

*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <math.h>
#ifdef _WIN32
  #include <windows.h>
#endif
#ifdef __linux__

#endif

#define ASSIGNMENT "CSCI 15 Assignment 1"

using namespace std;


int FileRead (ifstream &SomeFile, float &floatA, float &floatB, float &floatC)
{
/*
This function will read the given text file
Confirm that it can read all three values
Return three valid numbers

*/
//Need to identify if I read in three "good" values.
    floatA = NAN;
    floatB = NAN;
    floatC = NAN;

    if (SomeFile.eof())
    {
        cout << "End of File!";
        return 2;
    }
    SomeFile >> floatA >> floatB >> floatC;
    if ((isnan(floatA)) || (isnan(floatB)) || (isnan(floatC)))
    {
       cout << "Not valid numbers!";
       return 1;
    }
    else
    {
        cout << "All good";
        return 0;
    }

}

int CalculateRoot (float floatA, float floatB, float floatC)
{
// if OK

//no solution
  if (floatA == 0)
  {
    return -1;
  }
//if complex roots
  else if ((floatB*floatB)-4 * floatA * floatC < 0)
  {
    return -2;
  }
  else
  {
    //ax2 + bx + c  Roots are items where the value of X evaluates the equation to 0
    return 0;
  }
}
void PrintOutput (float &floatA, float &floatB, float &floatC)
{
  cout << "floatA" << floatA << "floatB" << floatB << "floatC" << floatC << endl;
}

int main()
{
    //Variables
    string stringInFileName = "";
    string stringOutFileName = "";
    float floatQuadA;
    float floatQuadB;
    float floatQuadC;
    short shortLooper = 0;
    ifstream inFile;


    SetConsoleTitle(ASSIGNMENT);
    system("cls");
    cout << "This program will calculate and print the roots of a quadratic equation." << endl;
    cout << "Please enter a file name in the local path to open. : ";
    cin >> stringInFileName;

    inFile.open(stringInFileName);
    if (inFile.is_open())
    {
        while (shortLooper < 2)
        {
            cout << inFile.tellg();
            shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
            CalculateRoot
            cout << inFile.tellg();
        }
    }
    else
    {
        cout << "Unable to open file " << stringInFileName;
        exit(666);
    }
    inFile.close();

    PrintOutput(floatQuadA, floatQuadB, floatQuadC);

    system("pause");
  //Read file  and confirm I actually opened file

  //Send to file read function and read a line

  //Perform the root calculation


  //output stuff.

}
