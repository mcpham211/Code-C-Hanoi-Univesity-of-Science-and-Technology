#include<stdio.h>
#include<stdlib.h>

int n;
int x[10001];

int Check(int k, int v){
    if (v == 1 && x[k-1] == 1) return 0;
    return 1;
}

int Solution(){
    for (int i = 1; i <= n; i++) printf("%d", x[i]);
    printf("\n");

}

int Try (int k) {
    for (int v = 0; v <= 1; v++){
        if (Check (k, v)){
            x[k] = v;
            if (k == n) Solution();
            else Try (k + 1);
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;
}
