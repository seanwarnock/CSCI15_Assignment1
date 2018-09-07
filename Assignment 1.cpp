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

int FileRead (ifstream &SomeFile, double &floatA, double &floatB, double &floatC)
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
    //verify if we got a number
    if (isnan(floatA) || isnan(floatB) || isnan(floatC))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int CalculateRoot (double doubleA, double doubleB, double doubleC, double &doublePosRoot, double &doubleNegRoot)
{
    double holder;
    double bottum;
    double thesquare;

    if (doubleA == 0)
    {
        //no solution available return -1 and exit.
        return -1;
    }
    else if (((doubleB * doubleB)-4 * doubleA * doubleC) < 0)
    {
        //if complex roots return -2 and exit.
        return -2;
    }
    else
    {

        //Perform the actual calculation for roots.
//        cout << "doublB times -1: ";
//        cout << (-1 * doubleB) << endl;
        holder = pow(doubleB,2) - 4 * doubleA * doubleC;
//        cout << "holder value: " << holder << endl;
        bottum = double(2) * doubleA;
//        cout << "calculated bottum value : " << bottum << endl;
        thesquare = sqrt(holder);
//        cout << "Square root is : " << thesquare << endl;
        doublePosRoot = (-doubleB + thesquare)/bottum;
//        cout << "Root positive : " << root << endl;


        holder = pow(doubleB,2) - 4 * doubleA * doubleC;
        bottum = double(2) * doubleA;
        thesquare = sqrt(holder);
        doubleNegRoot = (-doubleB - thesquare)/bottum;

        //Does not work correctly but this is the base equation attempt.
        //root = (-doubleB - sqrt((doubleB*doubleB) - 4 * doubleA * doubleC)/2 * doubleA;

        return 0;
    }
}
void PrintOutput (ofstream &SomeOutFile, double floatA, double floatB, double floatC, double doublePosRoot, double doubleNegRoot, int intCalcStatus)
{
    static bool boolFirstRun = true;
    int shortspace = 10;
    int longspace = 15;

    if (boolFirstRun == true)
    {
        cout << endl;
        cout << setw(shortspace) << "A value" << setw(shortspace) << "B value" << setw(shortspace) << "C value" << setw(longspace) << "Positive root" << setw(longspace) << "Negative root" << endl;
        SomeOutFile << setw(shortspace) << "A value" << setw(shortspace) << "B value" << setw(shortspace) << "C value" << setw(longspace) << "Positive root" << setw(longspace) << "Negative root" << endl;
    }
    if (intCalcStatus == 0)
    {
        cout << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << doublePosRoot << setw(longspace) << doubleNegRoot << endl;
        SomeOutFile << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << doublePosRoot << setw(longspace) << doubleNegRoot << endl;
    }
    else if (intCalcStatus == -1)
    {
        cout << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << "no solution" << setw(longspace) << "no solution" << endl;
        SomeOutFile << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << "no solution" << setw(longspace) << "no solution" << endl;
    }
    else if (intCalcStatus == -2)
    {
        cout << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << "complex root" << setw(longspace) << "complex root" << endl;
        SomeOutFile << setw(shortspace) << floatA  << setw(shortspace)  << floatB << setw(shortspace)  << floatC << setw(longspace) << "complex root" << setw(longspace) << "complex root" << endl;
    }

    boolFirstRun = false;
}
int main()
{
    string stringInFileName = "";
    string stringOutFileName = "";
    double floatQuadA;
    double floatQuadB;
    double floatQuadC;
    double doublePositiveRoot;
    double doubleNegativeRoot;
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

    outFile << "Input File: " << stringInFileName << endl;
    outFile << "Output File: " << stringOutFileName << endl;

    //Time to loop through the file line by line.
    shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
    while (shortLooper < 2)
    {
        if (shortLooper == 0)
        {
            shortLooper = CalculateRoot(floatQuadA, floatQuadB, floatQuadC, doublePositiveRoot, doubleNegativeRoot);
            PrintOutput(outFile, floatQuadA, floatQuadB, floatQuadC, doublePositiveRoot, doubleNegativeRoot, shortLooper);
            shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
        }
        else
        {
            shortLooper = FileRead(inFile, floatQuadA, floatQuadB, floatQuadC);
        }
    }
    inFile.close();
    outFile.close();
}
