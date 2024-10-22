#include <stdlib.h>

long long Nem(int n) {
    if (n == 0 || n == 1) return 1; // Change to return 1 for factorial 0! and 1!

    long long res = 1; // Use long long for larger results
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

long long Compute(int k, int n) {
    if (k > n) return 0; // No need for .0, return 0 directly
    return Nem(n) / (Nem(k) * Nem(n - k)); // Ensure everything uses long long
}

int main() {
    int n, k;
    printf("Enter values for k and n: ");
    scanf("%d %d", &k, &n);
    printf("C(%d, %d) = %lld\n", k, n, Compute(k, n)); // Print as long long
    return 0;
}
