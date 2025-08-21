#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_alphanumeric(char c){
    if(c >= 'a' && c <= 'z'){
        return true;
    }
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    if(c >= '0' && c <= '9'){
        return true;
    }
    return false;
}
char to_lower(char c){
    if(c >= 'A' && c <= 'Z'){
        return c + (int)'a' - (int)'A';
    }
    return c;
}

bool isPalindrome(char* s) {
    int left = 0;
    int right = 0;
    // find the size of s    
    while(s[right] != '\0'){
        right++;
    }
    int i;
    while(right > left){
        while(right > left && !is_alphanumeric(s[left])) left++;
        while(right > left && !is_alphanumeric(s[right])) right--;
        
        if(right <= left){
            return true;
        }
        if(to_lower(s[left]) != to_lower(s[right])){
            return false;
        }
        else{
            left++;
            right--;
        }
    }
    return true;
}

int main(){
    char s[] = "A man, a plan, a canal: Panama";
    printf("%B\n", isPalindrome(s));
    char s2[] = "race a car";
    printf("%B\n", isPalindrome(s2));
    char s3[] = " ";
    printf("%B\n", isPalindrome(s3));

}