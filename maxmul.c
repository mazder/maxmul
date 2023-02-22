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


void pmaxmul(int k, int m, int n, int A[m][k], int B[k][n], int C[m][n], int argc, char* argv[]){

    int p, q, r, P, rank, Fsize, Tsize;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &P);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    Fsize = rank * m/P;
    Tsize = (rank+1) * m/P;

    //scatter rows of matrix A
    MPI_Scatter(A, m*k/P, MPI_INT, A[Fsize], m*k/P, MPI_INT,0,MPI_COMM_WORLD);

    //broadcast matrix B
    MPI_Bcast(B, k*n, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    for (p=Fsize; p<Tsize; p++){
        for (q=0; q<k; q++) {
          C[p][q]=0;
          for (r=0; r<n; r++)
            C[p][q] += A[p][r]*B[r][q];
        }
    }

    MPI_Gather(C[Fsize], m*n/P, MPI_INT, C, m*n/P, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

}





