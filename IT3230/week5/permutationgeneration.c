#include<stdio.h>
#include<stdlib.h>

int mark[10001], n, x[10001];

int Check (int v, int k){
    if (mark[v] == 1) return 0;
    else return 1;
}

int Solution(){
    for (int i = 1; i <= n; i++) printf("%d ", x[i]);
    printf("\n");
}

int Try (int k){
    for (int v = 1; v <= n; v++){
        if (Check (v, k)){
            x[k] = v;
            mark[v] = 1;
            if (k == n) Solution();
            else Try(k + 1);
            mark[v] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    Try(1);
    return 0;

}
