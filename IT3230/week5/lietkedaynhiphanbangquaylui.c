#include<stdio.h>
#include<stdlib.h>


int x[10001];
int n;
int Check (int n, int v){
    return 1;
}

int Solution(){
    for (int i = 1; i <= n; i++) printf("%d", x[i]);
    printf("\n");
}

int Try (int k){
    for (int v = 0; v <= 1; v++){
        if (Check(n, v)){
            x[k] = v;
            if(k == n) Solution();
            else Try (k + 1);
        }
    }

}

int main(){
    scanf("%d", &n);
    Try (1);

}
