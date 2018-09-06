/*
Sean Warnock
CSCI 15 Fall 2018


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
//Need to identify if I read in three "good" values.

    floatA = NAN;
    floatB = NAN;
    floatC = NAN;

    if (SomeFile.eof())
    {
        return 2;
    }
    else
    {
        SomeFile >> floatA >> floatB >> floatC;
    }
    if ((floatA == NAN) || (floatB == NAN) || (floatC == NAN))
    {
        return 1;
    }
    return 0;
}
int CalculateRoot (double doubleA, double doubleB, double doubleC)
{
    double  root;
// (floatB *2 - 4 * floatA * FloatC) < 0
// if OK
    //

    if (doubleA == 0)
    {
        //no solution
        return -1;
    }
    else if (((doubleB * doubleB)-4 * doubleA * doubleC) < 0)
    {
        //if complex roots
        return -2;
    }
    else
    {
        root = (-1 * doubleB) - sqrt((doubleB*doubleB) - 4 * doubleA * doubleC)/2 * doubleA;
        cout << "Root negative : " << root << endl;
        root = (-1 * doubleB) + sqrt((doubleB*doubleB) - 4 * doubleA * doubleC)/2 * doubleA;
        cout << "Root positive : " << root << endl;
        return 0;
    }
}
void PrintOutput (ofstream &SomeOutFile, float floatA, float floatB, float floatC)
{
    static bool boolFirstRun = true;

    if (boolFirstRun == true)
    {
        SomeOutFile << "Header!" << endl;
    }
    SomeOutFile << "floatA" << setw(5) << floatA << " floatB" << setw(5)  << floatB << " floatC" << setw(5)  << floatC << endl;
    boolFirstRun = false;
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
    ofstream outFile;

    SetConsoleTitle(ASSIGNMENT);
    system("cls");
    cout << "This program will calculate and print the roots of a quadratic equation." << endl;
    cout << "Please enter a file name in the local path to open. : ";
    cin >> stringInFileName;
    cout << "Please enter a file name in the local path to write. : ";
    cin >> stringOutFileName;

    inFile.open(stringInFileName);
    outFile.open(stringOutFileName);

    if (!inFile.is_open())
    {
        cout << "Unable to open file " << stringInFileName;
        exit(777);
    }
    if (!outFile.is_open())
    {
        cout << "Unable to open file " << stringOutFileName;
        exit(888);
    }

    shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
    while (shortLooper < 2)
    {
        cout << "ShortLooper IS: " << shortLooper;
        if (shortLooper == 1)
        {
            shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
        }
        else
        {
            CalculateRoot(floatQuadA, floatQuadB, floatQuadC);
            PrintOutput(outFile, floatQuadA, floatQuadB, floatQuadC);
            shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
        }
    }

    inFile.close();
    outFile.close();
    system("pause");
}
