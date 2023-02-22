#ifndef MAXMUL_H_INCLUDED
#define MAXMUL_H_INCLUDED

#include <stdlib.h>
#include "mpi.h"

void maxmul(int k, int m, int n, int A[m][k], int B[k][n], int C[m][n]);
void pmaxmul(int k, int m, int n, int A[m][k], int B[k][n], int C[m][n], int P, int myrank);
#endif // MAXMUL_H_INCLUDED
