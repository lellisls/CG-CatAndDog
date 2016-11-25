#ifndef MATRIX_H
#define MATRIX_H
double ** createSqMtx(int n);
void printMtx(double **a, int n);
void InverseMatrix(double **a, int n);
void MultiplyMtx(double ** m1, int n, double ** m2);
double DeterminantMtx(double ** a, int n);
void CoFactorMtx(double **a, int n, double **b);
void TransposeMtx(double **a, int n);

#endif // MATRIX_H
