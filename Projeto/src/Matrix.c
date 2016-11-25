#include "stdlib.h"
#include "../inc/Matrix.h"
#include "math.h"
#include "stdio.h"
double ** createSqMtx(int n)
{
    int row, col;
    double ** mtx = malloc((n) * sizeof(double *));
    for (row = 0; row < n; row++) {
        mtx[row] = malloc((n) * sizeof(double));
        for (col = 0; col < n; ++col)
            mtx[row][col] = 0;
    }
    return mtx;
}

void printMtx(double **a, int n)
{
    int row, col;
    for (row = 0; row < n; ++row) {
        for (col = 0; col < n; ++col) {
            printf("%.2f ", a[row][col]);
        }
        printf("\n");
    }
}

void InverseMatrix(double **a, int n)
{
    double ** cof = malloc((n) * sizeof(double *));
    int row, col;
    for (row = 0; row < n; row++)
        cof[row] = malloc((n) * sizeof(double));
    CoFactorMtx(a, n, cof);
    TransposeMtx(cof, n);
    double det = DeterminantMtx(a, n);;

    for (row = 0; row < n; ++row)
        for (col = 0; col < n; ++col)
            a[row][col] = cof[row][col] / det;
}

void MultiplyMtx(double ** m1, int n, double ** m2)
{
    int row, col;
    double ** matTemp = malloc((n) * sizeof(double *));
    for (row = 0; row < n; row++)
        matTemp[row] = malloc((n) * sizeof(double));

    for (row = 0; row < n; ++row)
        for (col = 0; col < n; ++col)
            matTemp[row][col] = m1[row][0] * m2[0][col] + m1[row][1] * m2[1][col]
                                + m1[row][2] * m2[2][col] + m1[row][3] * m2[3][col];
    for (row = 0; row < n; ++row)
        for (col = 0; col < n; ++col)
            m2[row][col] = matTemp[row][col];
}

/*
   Recursive definition of determinate using expansion by minors.
*/
double DeterminantMtx(double ** a, int n)
{
    int i, j, j1, j2;
    double det = 0;
    double **m = NULL;

    if (n < 1) { /* Error */

    } else if (n == 1) { /* Shouldn't get used */
        det = a[0][0];
    } else if (n == 2) {
        det = a[0][0] * a[1][1] - a[1][0] * a[0][1];
    } else {
        det = 0;
        for (j1 = 0; j1 < n; j1++) {
            m = malloc((n - 1) * sizeof(double *));
            for (i = 0; i < n - 1; i++)
                m[i] = malloc((n - 1) * sizeof(double));
            for (i = 1; i < n; i++) {
                j2 = 0;
                for (j = 0; j < n; j++) {
                    if (j == j1)
                        continue;
                    m[i - 1][j2] = a[i][j];
                    j2++;
                }
            }
            det += pow(-1.0, j1 + 2.0) * a[0][j1] * DeterminantMtx(m, n - 1);
            for (i = 0; i < n - 1; i++)
                free(m[i]);
            free(m);
        }
    }
    return (det);
}

/*
   Find the cofactor matrix of a square matrix
*/
void CoFactorMtx(double **a, int n, double **b)
{
    int i, j, ii, jj, i1, j1;
    double det;
    double **c;

    c = malloc((n - 1) * sizeof(double *));
    for (i = 0; i < n - 1; i++)
        c[i] = malloc((n - 1) * sizeof(double));

    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {

            /* Form the adjoint a_ij */
            i1 = 0;
            for (ii = 0; ii < n; ii++) {
                if (ii == i)
                    continue;
                j1 = 0;
                for (jj = 0; jj < n; jj++) {
                    if (jj == j)
                        continue;
                    c[i1][j1] = a[ii][jj];
                    j1++;
                }
                i1++;
            }

            /* Calculate the determinate */
            det = DeterminantMtx(c, n - 1);

            /* Fill in the elements of the cofactor */
            b[i][j] = pow(-1.0, i + j + 2.0) * det;
        }
    }
    for (i = 0; i < n - 1; i++)
        free(c[i]);
    free(c);
}

/*
   Transpose of a square matrix, do it in place
*/
void TransposeMtx(double **a, int n)
{
    int i, j;
    double tmp;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}
