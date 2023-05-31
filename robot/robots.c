#include <stdio.h>
#include <stdlib.h>
#include "solve.h"

int main(void) {
    
    int i, j, n, m, **A;
    unsigned int max_coins;
    char coin, c1, c2;
    
    
    printf("Give 2 dimensions.\n");


    c1 = 'C';
    c2 = '.';

    scanf("%d %d",&n,&m); // Give dimensions.

    A = malloc((n+1) * sizeof(int*));   
    if(A == NULL) {
        return -1;
    }                    
    for(i = 0; i <= n; i++) {
        A[i] = malloc((m+1) * sizeof(int));
        if(A[i] == NULL)
            return -1;
    }

    printf("Choose the coin layout. You can only use the character 'C' for coin presence or '.' for coin absence.\n ");
    for(i = 0; i < n ; i++) 
        for(j = 0; j < m ; j++) {
            scanf(" %c",&coin);
            if(coin == 'C') {
                A[i][j] = 1;
            }else if(coin == '.') {
                A[i][j] = 0;
            }else {
                printf("Wrong character. Try again.");
                return -1;
            }    
        }

    putchar('\n'); //Print grid.
    printf("The grid is:\n");    
    for(i=0; i < n ; i++) {
        for(j=0; j < m; j++)
            printf("%c ",(*(A[i]+j) == 1) ? c1 : c2);
        putchar('\n');
    }  

    printf("\nPath is:");
   
    max_coins = solve(n,m,A);
   
    printf("\nThe max coins that the robot can collect in this grid are %d\n", max_coins);

    for(i = 0; i <= n ; i++) 
        free(A[i]);
    free(A);
      
    
    
    return 0;
}