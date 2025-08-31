// https://leetcode.com/problems/valid-anagram/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int list[26]; //sync with a-z
    // init
    for(int i=0; i<26; i++){
        list[i] = 0;
    }

    // count the freq. of the each sigle alphabet
    while(*s != '\0'){
        list[(int)*(s++) - (int)'a']++;
    }

    // minus the freq. of the each sigle alphabet
    int index;
    while(*t != '\0'){
        index = (int)*(t++) - (int)'a';
        if(list[index] < 0){
            return false;
        }
        list[index]--;
    }
    for(int i=0; i<26; i++){
        if(list[i] != 0){
            return false;
        }
    }
    return true;
}

int main(){
    char* s = "anagram";
    char* t = "nagaram";
    printf("%d\n", isAnagram(s, t));
    return 0;
}