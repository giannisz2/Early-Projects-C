// Dynapic programming method.

#include <stdio.h>
#include <stdlib.h>

int solve(int n, int m, int **A) {
    int i, j, m_c, **CD; 
    
    CD = malloc(n* sizeof(int*)); 
    if(CD == NULL) {
        printf("\nMemory allocation problem. Try again.");
        return -1;
    }
    for(i = 0; i < n; i++) {
        CD[i] = malloc(m * sizeof(int));
        if(CD[i] == NULL) {
            printf("\nMemory allocation problem. Try again.");
            return -1;
        }
        for(j = 0; j < m; j++)
            CD[i][j] = 0;
    }   

    for(i = 0; i < n; i++) //Dynamic loop
        for(j = 0; j < m; j++) {
            if(i == 0 && j == 0) 
                CD[i][j] = A[i][j];
            else if(i == 0 && j > 0)
                CD[i][j] = CD[i][j-1] + A[i][j];
            else if(i > 0 && j == 0)
                CD[i][j] = CD[i-1][j] + A[i][j];
            else if(CD[i-1][j] > CD[i][j-1]) {
                CD[i][j] = CD[i-1][j] + A[i][j];
            }
            else {
                CD[i][j] = CD[i][j-1] + A[i][j];
            }
        }
    
    m_c = CD[n-1][m-1];

    for(i = 1; i < n; i++)
        for(j = 1; j < m; j++)
            if(CD[i][j] && (CD[i][j] != CD[i-1][j]) && (CD[i][j] != CD[i][j-1])) 
                printf(".(%d,%d)/%d --> ", i, j, CD[i][j]);

    for(i = 0; i < n; i++) 
        free(CD[i]);
    free(CD);

    return m_c;

}