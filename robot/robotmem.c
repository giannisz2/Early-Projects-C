// Recursion with memoization.

#include <stdio.h>
#include <stdlib.h>


int solve(int i,int j,int **M) {
    static int f = 0, **C;
    int k,l;

    if(f == 0){  
        C = malloc((i+1) * sizeof(int*));
        if(C == NULL)
            return -1;
        for(k = 0; k <= i; k++) {
            C[k] = malloc((j+1) * sizeof(int));
            if(C[k] == NULL)
                return -1;
            for(l = 0; l <= j; l++)
                C[k][l] = -1;
        }
        f = 1;
    }
    if(C[i][j] == -1) {  
        if(i == 0 && j == 0) {
            C[i][j] = M[i][j];
        }
        else if(i == 0 && j > 0) {
            C[i][j] = solve(i,j-1,M) + M[i][j];
        }
        else if(i > 0 && j == 0) {
            C[i][j] = solve(i-1,j,M) + M[i][j];
        }
        else if(solve(i-1,j,M) > solve(i,j-1,M)) {
            if(M[i][j] == 1)
                printf(".(%d,%d)/%d -->",i,j,M[i][j]);
            C[i][j] = solve(i-1,j,M) + M[i][j];
        }
        else {
            if(M[i][j] == 1)
                printf(".(%d,%d)/%d -->",i,j,M[i][j]); //Paths
            C[i][j] = solve(i,j-1,M) + M[i][j];
        }
    } 
    else
        return C[i][j];
}