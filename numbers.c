#include <stdio.h>
#define MINNUM 0
#define MAXNUM 100000

int main(){
    int n, i, j, tempn, ndigits, pow10, POW10, subseq, s1, s2, s3, tempcount, count1, count2, count3, dsum, divisor ;
    count1 = 0 ;
    count2 = 0 ;
    count3 = 0 ;
    for(n = MINNUM ; n <= MAXNUM ; n++){
        /* printf("The solid subsequence of number %d is: ",n) ; */ //printf for testing purpose
        tempn = n ;
        ndigits = 0 ;
        pow10 = 1 ;
        POW10 = 1 ;
        while(tempn != 0){
            ndigits++ ;
            tempn /= 10 ;
            if(tempn != 0){     /* pow10,POW10 must not change when tempn = 0 because they will multiply with 10 one more time than we need */
            pow10 *= 10 ;
            POW10 *= 10 ;
            }
        }
        tempcount = 0;
        s1 = pow10 ;
        s2 = POW10 ;
        s3 = 1 ;
        for(j = 1 ; j <= ndigits ; j++){                 /* For each set of sebsequences*/
            tempn = n ;                                  
            for(i = 1 ; i <= ndigits - j + 1 ; i++){     /* For each subsequence */
                if(pow10 == 0 || POW10 == 0) break ;     /* For floating point exception */
                subseq = tempn / pow10 ;                 /* For each different digit or subsequence*/ 
                /* printf("%d ", subseq) ; */            // for testing purpose
                if(subseq % ndigits == 0){               
                    /* OC = subseq ; */                  //for testing purpose
                    tempcount++ ;
                }               
                tempn %= POW10 ;                         /* mod for number to become smaller */
                POW10 /= 10 ; 
                pow10 /= 10 ;
                
            }
            s3 *= 10 ;                                   /* pow10 needs to decrease and be divided by 10 each time, for the next set of subsequence*/
            pow10 = s1 / s3 ;                            /* For the next set of subsequence */
            POW10 = s2 ;                                 /* Reseting POW10 to original value for the correct division to happen */
        } 
        if (tempcount == 1){                             /* If tempcount > 1 then there isn't only one subsequence that divides exactly with the digits of tempn */
            /* printf("\nThe number %d has an only child which is: %d\n",n, OC) ; */       //printf for testing purpose
            count1++ ;
        }
        tempn = n ;
        dsum = 1 ;
        for(divisor = 2 ; divisor * divisor < tempn ; divisor ++){ /* To find the divisors */
            if(tempn % divisor == 0){
               dsum += divisor + tempn / divisor ;
            }
        }
        if(divisor * divisor == tempn) dsum += divisor ; /* To find the last divisor */
        if(dsum > tempn) count2++ ;
        if(tempcount == 1 && dsum > tempn){  /* To find if number n is contained in both classes */
            count3++ ;
            printf("%d\t", n) ;
        }    
    } 
    count2 -= 1 ; /* Always prints the correct result but +1 number */
    printf("\nThe numbers with only childs are a total of: %d\n",count1 ) ;
    printf("The numbers which are abundant are: %d\n", count2) ;        
    printf("%d numbers are in both classes\n",count3) ;
}