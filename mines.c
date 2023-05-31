// THE MINES GAME IN C. YOU NEED TO GIVE A TXT FILE AS INPUT REDIRECTION WHERE '.' IS FREE POSITION AND '*' IS WHERE THE MINE IS.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int i, j , n, m, **s, **c;
    char c1, c2, mi;

    c1 = '*';
    c2 = '.';

    if(argc < 3) {//An breis ligotera apo 3 orismata sthn ektelesh(2 diastaseis + to onoma tou ektelesimou arxeio) stamata.
        printf("Give the dimensions of the grid.\n");
        return -1;
    }
    

    n = atoi(argv[1]); //Synarthseis gia metatroph orismatos se akeraio.
    m = atoi(argv[2]);

    c = malloc(n * sizeof(int*)); // Desmeysh mnhmhs gia ton dysdiastato pinaka c(o c einai counter gia to poses mines yparxoyn sta geitonika blocks).
    if(c == NULL)
        return -1;
    for(i = 0; i < n; i++) {
        *(c + i) = malloc(m * sizeof(int));
        if( (*(c+i)) == NULL )
            return -1;
    } 

    for(i = 0; i < n; i++) //Arxikopoihsh pinaka c me 0.
        for(j = 0; j < m; j++)
            c[i][j] = 0;

    s = malloc(n * sizeof(int*)); //Desmeysh mnhmhs gia pinaka s(pinakas boolean: 1 an yparxei narkh, 0 an den yparxei)
    if(s == NULL)
        return -1;
    for(i = 0; i < n; i++) {
        *(s + i) = malloc(m * sizeof(int));
        if( (*(s+i)) == NULL )
            return -1;
    } 

    printf("Choose where you want the mines to be:\n");
    printf("(Mine is the character: '*'. Free square is the character: '.')\n");

    for(i = 0; i < n; i++) //Diabase xarakthres, analoga ti diabazeis bazei ston boolean pinaka tis katallhles times.
        for(j = 0; j < m; j++) {
            scanf("%c ",&mi);
            if(mi == '*')
                *(s[i] + j) = 1;
            else if (mi == '.')
                *(s[i] + j) = 0;
            else {
                printf("Put the correct character. Try again.\n");
                return -1;
            }
        }

    printf("\nThe grid is:\n");    
    for(i=0; i < n ; i++) {
        for(j=0; j < m; j++)
            printf("%c ",(*(s[i]+j) == 1) ? c1 : c2); // An s[i][j] == 1 tote ektypwse '*' alliws ektypwse '.' 
        putchar('\n');
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++) {
            if(s[i][j] == 0) { //An den eisai se narkh kai breis narki se geitoniko block ayjhse to counter kata 1.. Parakatw pairnw oles tis periptwseis gia kathe ksexwristh thesi tou pinaka pou yparxei.
                if(j == 0 && i == 0) { 
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j+1])
                        c[i][j] += 1;
                }
                if(j > 0 && j < (m-1) && i == 0) {
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                }
                if(j == (m-1) && i == 0) {
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j-1])
                        c[i][j] += 1;
                    if (s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                }
                if(j == 0 && i > 0 && i < (n-1)) {
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j+1])
                        c[i][j] += 1;
                }
                if(j > 0 && j < (m-1) && i > 0 && i < (n-1)) {
                    if(s[i][j] != s[i-1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j+1])
                        c[i][j] += 1;
                }
                if(j == (m-1) && i > 0 && i < (n-1)) {
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i+1][j])
                        c[i][j] += 1;
                }
                if(j == 0 && i == (n-1)) {
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                }
                if(j > 0 && j < (m-1) && i == (n-1)) {
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j+1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j+1])
                        c[i][j] += 1;
                }
                if(j == (m-1) && i == (n-1)) {
                    if(s[i][j] != s[i-1][j])
                        c[i][j] += 1;
                    if(s[i][j] != s[i-1][j-1])
                        c[i][j] += 1;
                    if(s[i][j] != s[i][j-1])
                        c[i][j] += 1;
                }
            }
        }
    
    printf("\nThe updated grid after mine sweeping is:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) 
            printf("%d ", c[i][j]); // Ektypwse ton anabathmizmeno pinaka me to pou briskontai oi narkes.
        putchar('\n');
    }       
    printf("The number 0 means mine.\n");

     for(i = 0; i < n; i++) // Apodesmeysh mnhmhs.
        free(s[i]);
    free(s);

    for(i = 0; i < n; i++)
        free(c[i]);
    free(c);


    return 0;
}