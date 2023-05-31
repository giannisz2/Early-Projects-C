// .c FILE BEAUTIFIER

#include <stdio.h>

int main() {
    int ch, wh = 0, st = 1, bl = 0, in = 0 , ap = 0, da = 0, dw = 0, hash2 = 1 ; 
        while((ch = getchar()) != EOF) { 
            if(ch == ' '|| ch == '\n' || ch == '\t') {
                wh = 1 ;
                continue ;
            }
            if(ch == '\\') {
                putchar(ch);
                ch = getchar(); //If you find backslash print next character because it will be a character following in the other program.
                putchar(ch);
                continue;
            }
            if(ch == '\"') {
                if(ap == 0) {      //If you are inside apostrofe just putchar(ch).
                    putchar(ch);
                    if(da == 1) {
                        da = 0;    // When you find \" again then we are no more inside \".
                        continue;  // If you find " print everything inside until you find " again. 
                    }              // (If it finds \" it will be ignored because of the first if).
                    da = 1;
                    continue;
                }
                putchar(ch);
                continue;
            }
            if(da == 1) {     // If da = 0 we aren't inside \".
                putchar(ch);  // We are inside " " so until da == 0 again we are printing everything inside.
                continue;
            }
            if(ch == '}'&& ap == 0) //If you find '}' count -= 1 except if you are inside apostrofe.
                bl--;           
            if(st == 1 && in == 0)   //If you are inside () ignore tabs.  
                for(int i = 0; i < bl; i++ )  //Check in how many blocks we are inside and putchar tabs accordingly.
                    if(hash2 != 1 && ap == 0) {     //If you find hash or apostrofe dont put tabs. 
                        putchar('\t');
                    }    
                    else continue;    
            if(ch == '#') {
                hash2 = 1;
                putchar('\n');   //Line 40 - 45: If you find '#' flag = 1 and we are in new line. 
                putchar(ch);
                st = 1;
                continue;
                
            }
            if(in > 0) 
                if(ch == '|') {
                    if(dw == 0)
                        putchar(' ');
                    putchar(ch);
                    dw += 1;           //Line 48 - 59: If you are inside intercalation put the right spaces in between '||' and expressions.
                    if(dw == 2) {
                        putchar(' ');
                        dw = 0;
                    }    
                    continue;
                }
            if(ch == '(') {
                if(ap == 0) {
                    wh = 0;
                    putchar(ch);   //Line 60 - 78: If you find  '(' increase the count and decrease it if you find ')',helps in "for" loop. 
                    in += 1;        
                    continue;
                }
                putchar(ch);
                continue;    
            }    
            else if(ch == ')') {
                if(ap == 0) {
                    wh = 0;
                    putchar(ch);       
                    in -= 1;
                    continue;
                }
                putchar(ch);
                continue;    
            }
            if(ch == ';' || ch == '{' || ch == '}') {
                hash2 = 0;
                if(ap == 1) {
                    putchar(ch);  //Based on line 75 - 88.
                    continue;
                }
                if(in > 0) {
                    putchar(ch);  //If you are inside a '(' don't change line,print the the next characters until count = 0,means we are out of ().)
                    continue;
                }
                if(ch == '{'){
                    putchar(' ');   //if you find '{' count += 1.
                    bl++;
                }
                putchar(ch) ;
                putchar('\n') ;
                st = 1 ;
                wh = 0 ;
                continue ;
            }
            if(ch == '\'') {
                if(in > 0) {
                    putchar(ch);   
                    continue;
                }
                putchar(ch);
                if(ap == 1) {
                    ap -= 1 ;                
                }                       //Line 100 - 113: Check how many apostrofes we have,if count of apostrofes > 0, putchar next character whatever it is. 
                else if(ap == 0) {
                    ap += 1 ;
                }
                continue;
            } 
               
            if(wh == 1 && st == 0) 
                putchar(' ') ;
            wh = 0 ;
            st = 0 ;
            putchar(ch) ;       
        }   
}