/*
Sean Warnock
CSCI 15 Fall 2018


Write a program, broken into functions as specified below, to read the coefficients of a series of quadratic equations from a text file and print the associated roots (or appropriate error messages if there are no real roots) to another text file.  The coefficients of a quadratic are the a, b and c of an expression of the form ax2 + bx + c, and the roots are the values of x that make the value of the expression 0.  The roots are given by this formula:

*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#ifdef _WIN32
  #include <windows.h>
#endif
#ifdef __linux__

#endif

#define ASSIGNMENT "CSCI 15 Assignment 1"

using namespace std;


int FileRead (ifstream & SomeFile, float &floatA, float &floatB, float &floatC)
{
//Need to identify if I read in three "good" values.
  if (SomeFile.eof())
  {
    return 2;
  }
  else
  {
    SomeFile >> floatA >> floatB >> floatC;
    return 0;
  }

}

int CalculateRoot ()
{
// (b2-4ac) < 0
// if OK
return 0;
//no solution
return -1;
//if complex roots
return -2;
}
void PrintOutput (float &floatA, float &floatB, float &floatC)
{
  cout << "floatA" << floatA << "floatB" << floatB << "floatC" << floatC << endl;
}

int main()
{
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
    shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
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
