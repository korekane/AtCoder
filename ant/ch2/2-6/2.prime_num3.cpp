#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MAX_L 10000
#define MAX_SQRT_B 10000

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//[a,b]の整数に対してを行う．is_prime[i-a] = true <=> iが整数
int segment_sieve(ll a, ll b){
    for (int i = 0; (ll)i * i < b; i++){
        is_prime_small[i] = true;
    }
    for (int i = 0;i < b - a; i++){
        is_prime[i] = true;
    }
    for (int i = 2; (ll)i*i < b; i++){
        if (is_prime_small[i]){
            for (int j = 2*i; (ll)j * j < b ; j+=1){
                is_prime_small[j] = false;
            }
            for (ll j = max(2LL,(a+i-1)/i)*i; j<b; j+=i){
                is_prime[j - a] = false;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < b - a; i++){
        if (is_prime[i]){
            res++ ;
        }
    }
    return res;
}

int main(void){
    ll a = 22;
    ll b = 37;
    printf("%d",segment_sieve(a, b));
    return 0;
}