#include <stdio.h>
#include <stdlib.h>
#include <cstdio>

int gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main(){
    //点P1(x1, y1)
    int x1 = 1;
    int y1 = 11;

    //点P2(x2, y2)
    int x2 = 5;
    int y2 = 3;
    
    printf("%d\n", gcd(abs(x1 - x2), abs(y1 - y2)));
    return 0;
}