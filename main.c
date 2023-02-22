#include<stdio.h>

#include "maxmul.h"

int main(int argc, char* argv[]){

    int m=3,n=2,k=3;
    int i, j;
    int A[m][k], B[k][n], C[m][n];

    maxmul(k, m, n, A, B, C);

    printf("Results C===\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
