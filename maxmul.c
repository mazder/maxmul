#include "maxmul.h"

void maxmul(int k, int m, int n, int A[m][k], int B[k][n], int C[m][n]){
    int p, q, r;
    for(p=0; p<m; p++){
		for(q=0; q<k; q++){
			for(r=0; r<n; r++){
				C[p][r] += A[p][q] * B[q][r];
            }
        }
    }
}


void pmaxmul(int k, int m, int n, int A[m][k], int B[k][n], int C[m][n], int P, int myrank){

    int p, q, r, Fsize, Tsize;

    int **AA;
    int **CC;

    start = myrank * m/P;
    end = (myrank+1) * m/P;

    //scatter rows of matrix A
    MPI_Scatter(A, m*k/P, MPI_INT, AA, m*k/P, MPI_INT,0,MPI_COMM_WORLD);

    //broadcast matrix B
    MPI_Bcast(B, k*n, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    for (p=start; p<end; p++){
        for (q=0; q<k; q++) {
          CC[p][q]=0;
          for (r=0; r<n; r++)
            CC[p][q] += AA[p][r]*B[r][q];
        }
    }

    MPI_Gather(CC, m*n/P, MPI_INT, C, m*n/P, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);


}


