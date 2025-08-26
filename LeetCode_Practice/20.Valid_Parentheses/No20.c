// https://leetcode.com/problems/valid-parentheses/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    // To ignore the space complexity, use array to simulate stack FILO feature

    char stack[10000];
    int size = 0;

    while(*s!='\0'){
        // If char is left side, push it.
        // If char is right side, verify last of stack == left side
        // True, pop it.
        // False, return false
        // Shall consider the corner case of size==0 but face right side.

        if(*s == '(' || *s == '[' || *s == '{'){
            stack[size] = *s;
            size++;
        }
        else{
            if(size == 0){
                return false;
            }
            else if(*s == ')'){
                if(stack[size-1] == '('){
                    size--;
                }
                else{
                    return false;
                }
            }
            else if(*s == ']'){
                if(stack[size-1] == '['){
                    size--;
                }
                else{
                    return false;
                }
            }
            else if(*s == '}'){
                if(stack[size-1] == '{'){
                    size--;
                }
                else{
                    return false;
                }
            }
        }
        s++;
    }
    if(size != 0){
        return false;
    }
    return true;
}


int main(){
    printf("%B\n", isValid("[]"));     // 1
    printf("%B\n", isValid("[{}]"));   // 1
    printf("%B\n", isValid("[{]}"));   // 0
    printf("%B\n", isValid("[{}]}"));  // 0
    printf("%B\n", isValid("{[]}()")); // 1
    return 0;
}

