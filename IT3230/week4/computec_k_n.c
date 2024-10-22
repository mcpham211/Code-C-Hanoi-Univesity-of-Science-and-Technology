#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max_N 1000000007


long long Nem(long long n){
    if (n == 0 || n == 1) return 1;

    long long res = 1;
    for (int i = 2; i <= n; i++){
        res =(res * i) % Max_N;
    }
    return res;

}

long long Compute (long long k, long long n){
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
  //  return (Nem(n)/(Nem(k) * Nem(n - k)) % Max_N);

  // Nghich dao Modulo
    long long numator = Nem(n);
    long long denomiator = (Nem(k) * Nem(n - k)) % Max_N;
    long long exponent = Max_N - 2;
    long long inverse_denominator = 1;

    while (exponent > 0){
        if (exponent % 2 == 1) inverse_denominator = (inverse_denominator * denomiator) % Max_N;
        denomiator = (denomiator * denomiator) % Max_N;
        exponent/=2;
    }
    return (numator * inverse_denominator) % Max_N;


}

int main(){
    long long n, k;
    scanf("%lld %lld", &k , &n);

    if (k > n) printf("0\n");
    else if (k == 0 || k == n) printf("1\n");
  //  if (k >= n - k) k = n - k;

    else printf("%lld", Compute(k, n));

    return 0;
}
