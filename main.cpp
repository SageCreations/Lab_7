/*
 * Edward Cruz, October 29, 2019
 * Programming Fundamentals, Lab 7
 */
#include <iostream>
#include <iomanip>

using namespace std;

void printThem(double a[3][3], double b[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t\t\t";
        for (int j = 0; j < 3; j++)
        {
            cout << fixed;
            cout << setw(7) << a[i][j];
        }
        cout << "\t ";
        for(int j = 0; j < 3; j++)
        {
            cout << fixed;
            cout << setw(7) << b[i][j];
        }
    }
}

void inverseEq(double x[3][3], double y[3][3], double temp[3][3])
{
    //temp = temp
    // x = pB
    // y = B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = 0;
            for (int k = 0; k < 3; k++)
                temp[i][j] = temp[i][j] + x[i][k] * y[k][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            x[i][j] = 0;
            x[i][j] = temp[i][j];
        }
    }
}


void subtractThem(double x[3][3], double y[3][3], double z[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j= 0; j < 3; j++)
        {
            z[i][j] = x[i][j] - y[i][j];
        }
    }
}

void addThem(double x[3][3], double z[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j= 0; j < 3; j++)
        {
            z[i][j] = z[i][j] + x[i][j];
        }
    }
}

void multiplyThem(double x[3][3], double y[3][3], double z[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            z[i][j] = 0;
            for (int k = 0; k < 3; k++)
                z[i][j] = z[i][j] + x[i][k] * y[k][j];
        }
    }
}

int main() {

    double A[3][3] = {{1./2, 1.00, 0.00}, {0.00, 2./3, 0.00}, {-1./2, -1.00, 2./3}};
    double I[3][3] = {{1.00, 0.00, 0.00}, {0.00, 1.00, 0.00}, {0.00, 0.00, 1.00}};
    double B[3][3], invA[3][3], pB[3][3], temp[3][3], prod[3][3];

    //Gets B Value.
    subtractThem(I, A, B);
    subtractThem(I, A, pB);

    //first part of the equation
    addThem(I, invA);
    addThem(B, invA);

    //rest of equation
    for (int i = 0; i < 20; i++) {
        inverseEq(pB, B, temp);
        addThem(pB, invA);
    }

    multiplyThem(invA, A, prod);
    cout << "\n\t\t\t\t      invA\t\t\t\t    invA  *  A";
    cout << setprecision(2);
    printThem(invA, prod);

    return 0;
}