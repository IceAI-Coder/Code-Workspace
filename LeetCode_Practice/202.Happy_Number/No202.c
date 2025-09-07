#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isHappy(int n) {
    int sum;
    while(n != 1){
        sum = 0;
        while(n >= 10){
            sum += (n%10)*(n%10);
            n = (int)(n-n%10)/10;
        }
        sum += (n%10)*(n%10);
        n = sum;

        if(n==4){
            return false;
        }
    }
    return true;
}

int main(){
    printf("%d\n", isHappy(9));
    return 0;
}