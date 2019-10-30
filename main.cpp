/*
 * Edward Cruz, October 29, 2019
 * Programming Fundamentals, Lab 7
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printThem(float a[][3]);
void matrixPower(float B[3][3], int size, float BPow[3][3]);
void multiplyThem(float invA[3][3], float I[3][3], float B[3][3], float BPow[3][3]);

void matrixPower(float B[3][3], int size, float BPow[3][3])
{
    int x = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            BPow[i][j] = 0;
        }
    }

    while (x < size)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    BPow[i][j] += B[i][k] * B[k][j];
                }
            }
        }
        x++;
    }
}

void printThem(float a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\n\t\t\t";
        for (int j = 0; j < 3; j++)
        {
            cout << fixed;
            cout << setw(7) << a[i][j];
        }
        cout << "\t";

    }
}

void multiplyThem(float invA[3][3], float I[3][3], float B[3][3], float BPow[3][3])
{
    // the first part of the equation A^-1 = (I + B) + ...
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            invA[i][j] = I[i][j] + B[i][j];
        }
    }

    // + B^2 + B^3 and so on.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                invA[i][j] = invA[i][j] + BPow[i][j];
            }
        }
    }


    /*for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            B[i][j] = 0;
            for (int k = 0; k < 3; k++)
                B[i][j] = B[i][j] + A[i][k] * I[k][j];
        }*/

}



int main() {

    float A[3][3] = {1./2, 1., 0., 0., 2./3, 0., -1./2, -1., 2./3};
    float I[3][3] = {1.  , 0., 0., 0.,   1., 0.,    0.,  0.,   1.};
    float B[3][3], invA[3][3], BPow[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            B[i][j] = I[i][j] - A[i][j];
        }
    }

    cout << "\n\t\t\t\t      invA";
    cout << setprecision(2);
    multiplyThem(invA, I, B, BPow);
    printThem(invA);

    cout << "\n\n";

    return 0;
}