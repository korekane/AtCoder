#include <stdio.h>
//int memo[MAX_N + 1];
int memo[100 + 1];


int fib (int n){
    if (n<=1) return n;
    return fib(n-1)+fib(n-2);
}

int fib_2(int n){
    if (n<=1) return n;
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib_2(n-1) + fib_2(n-2);
}


int main(void)
{
    int a = 6;
    printf("%d\n",fib(a));
    printf("%d\n",fib_2(a));

    return 0;
}
