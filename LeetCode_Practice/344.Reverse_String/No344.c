#include <stdlib.h>
#include <stdio.h>

void reverseString(char* s, int sSize) {
    char tmp;
    for(int i=0; i<sSize/2; i++){
        tmp = s[i];
        s[i] = s[sSize-i-1];
        s[sSize-i-1] = tmp;
    }
}


int main(){
    char s[5] = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s, 5);
    printf("%s\n", s);
}