#include<stdio.h>


#define MOD 1000000007
/*
long long Fibonacci(long long n){
    if (n <= 1) return n;
    else return (Fibonacci(n-1) + Fibonacci(n-2)) % MOD;
}

int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld", Fibonacci(n));

}
*/

long long Fibonacci(long long n){
    long long array[n+1];
    array[0] = 0;
    array[1] = 1;

    for (long long i = 2; i <= n; i++){
        array[i] = (array[i-1] + array[i-2]) % MOD;
    }
    return array[n];
}

int main(){
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", Fibonacci(n));

    return 0;

}

