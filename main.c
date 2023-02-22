#include<stdio.h>

#include "maxmul.h"

int main(int argc, char* argv[]){



    int m,n,k;
    int A[m][k], B[k][n], C[m][n];

    int p, q, r, P, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank==0){
        maxmul(k, m, n, A, B, C);
    }

    pmaxmul(k, m, n, A, B, C, P, rank);

    MPI_Finalize();

    return 0;
}
