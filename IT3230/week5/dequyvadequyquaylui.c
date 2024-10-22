#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define maxN 10001

int n, t, k;
int a[maxN];

void Solution(){
    for(int i = 1; i <= k; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

int Try(int i, int start){
    for(int v = start; v <= n; v++){
            a[i] = v;
            if(i == k) Solution();
            else Try(i + 1, v + 1);
        }
}

int main(){
    scanf("%d %d", &n, &k);
    Try(1, 1);
    return 0;

}
