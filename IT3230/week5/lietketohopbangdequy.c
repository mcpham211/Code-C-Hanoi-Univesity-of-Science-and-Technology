#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define maxN 1001

long long n, array[maxN], multi, k;

long long Factorial(long long n){
    if (n == 0 || n == 1) return 0;
    long long multi = 1;
    for (int i = 1; i <= n; i++){
        multi = multi*i;
    }
    return multi;
}


long long Recursion(long long n, long long k ){
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return (Factorial(n)/(Factorial(k) * (Factorial(n - k))));
}

int main(){
    scanf("%lld %lld", &n, &k);
    printf("%lld", Recursion(n, k));

}
