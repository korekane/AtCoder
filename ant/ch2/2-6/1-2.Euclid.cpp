#include <cstdio>
#include <string.h>

int extgct(int a, int b, int& x, int& y){
    int d = a;
    if(b != 0){
        d = extgct(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
};

int main(){
    //入力
    int a = 4;
    int b = 11;
    
    //解の初期化
    int x = 0;
    int y = 0;

    printf("%d",extgct(a, b, x, y));
    return 0;
}