// wap in C that recognise string over E={a,b} s.t they are in 
// the form a* or aab*
//
#include<stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatchingPattern(const char *input){
    int len = strlen(input);

    if (input[0]=='a'){
        if(len==1){
            return true; 
        } else if (len>=3 && input[1]=='a'&&input[2]=='b'){
            for (int i =3;i<len;i++){
                if (input[i]!='b')
                    return false ;
            }
            return true ;
        }
    }
    return false;
}
int main(){
    char input[1000];
    printf("Input a String to check the DFA : ");
    scanf ("%s",input);
    if (isMatchingPattern(input)){
        printf("The input string matches the DFA ");
    } else {
        printf ("The input does not match the DFA ");
    }

    return 0;
}
