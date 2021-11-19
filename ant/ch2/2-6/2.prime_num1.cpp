#include <cstdio>
#include <string.h>
#include <vector>
#include <map>
using namespace std;


//入力は全て正
//素数判定 O(√n)
bool is_prime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n != 1;
}


//約数の列挙 O(√n)
vector<int> divisor(int n){
    vector<int> res;
    for (int i = 1; i*i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            if (i != n/i){
                res.push_back(n/i);
            }
        }
    }
    return res;
}

//素因数分解 O(√n)
map<int, int>prime_factor(int n){
    map<int, int>res;
    for (int i = 2; i * i <= n; i++){
        while(n % i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1){
        res[n] = 1;
    }
    return res;
}

int main(){
    int n;
    int a;

    n = 295927;
    n = 12;
    a = is_prime(n);

    //出力
    printf("素数判定    ");
    if (a == false){
        printf("NO\n");

        printf("約数の集合  ｛");
        vector<int> vec = divisor(n);
        for (int i = 0; i < vec.size(); ++i){
            printf("%d, ", vec.at(i));
        }
        printf("｝\n");

        printf("素因数分解  ｛");
        map<int, int> PF = prime_factor(n);
        for (int i = 0; i < PF.size(); ++i){
            if (PF[i] != 0){
                printf("%d * %d, ", i, PF[i]);
            }
        }
        printf("｝\n");
    }else{
        printf("YES\n");
    }


    return 0;
}