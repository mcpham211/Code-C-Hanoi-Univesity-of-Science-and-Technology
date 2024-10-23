#include <stdio.h>
#include<stdlib.h>




void GenerateCombination(int n, int *arr, int index, int start) {
    if (index == n){
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[index] = i;
        GenerateCombination(n, arr, index + 1, i + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("%d", n);
    GenerateCombination(n, arr, 0, 1);

    return 0;
}

