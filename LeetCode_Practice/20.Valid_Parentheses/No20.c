// https://leetcode.com/problems/valid-parentheses/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    // To ignore the space complexity, use array to simulate stack FILO feature

    char stack[strlen(s)];  // Fix#1: use strlen to get length, not declare maximum size of array
    int top = -1;  // Fix#2: To minus 1, reduce time for the minus behavior

    while(*s!='\0'){
        // If char is left side, push it.
        // If char is right side, verify last of stack == left side
        // True, pop it.
        // False, return false
        // Shall consider the corner case of size==0 but face right side.

        if(*s == '(' || *s == '[' || *s == '{'){
            stack[++top] = *s;
        }
        else{
            // Fix#3: Combined condition to make code be more clean
            if(top == -1 ||
                (*s == ')' && stack[top]!='(') ||
                (*s == ']' && stack[top]!='[') ||
                (*s == '}' && stack[top]!='{')){
                    return false;
                }
            else{
                top--;
            }
<<<<<<< HEAD
        }
=======
>>>>>>> main/main
        s++;
    }
    return top==-1;  // Fix#4: Removed the if to make code be more clean
}


int main(){
    printf("%B\n", isValid("[]"));     // 1
    printf("%B\n", isValid("[{}]"));   // 1
    printf("%B\n", isValid("[{]}"));   // 0
    printf("%B\n", isValid("[{}]}"));  // 0
    printf("%B\n", isValid("{[]}()")); // 1
    return 0;
}

