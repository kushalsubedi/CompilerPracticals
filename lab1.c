// write a program in C that takes a string as input and determine if it is a comment or not 
//
//
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool isComment(const char* input){
    if (strlen(input)>=2){
        if (input[0]=='/'&& input [1]=='/')
            return true;
        else if (input[0]=='/'&& input [1]=='*'){
            if (strstr(input,"*/")){

                return true ;

            }
        }
    }
    return false;
}
int main (){
   char input [1000];
   printf("Enter a String");
   fgets(input,sizeof(input),stdin);
   if (isComment(input)){
       printf("Entered input is a comment");
   }
   else {
       printf("Entered input is not a comment");
   }
    
    return 0;
}

