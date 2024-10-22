#include<stdio.h>
#include<stdlib.h>

#define maxN 1000

int mark[maxN], array[maxN], n, T, M, t;

int Solution(){
    for (int i = 1; i <= n; i++) printf("%d ", array[i]);
    printf("\n");
}

int Check (int v, int k){
 //   if (mark[v] == 1) return 0; // dong code liet ke cac so hoan vi khac nhau
    if (k < 2) return 0;
    if (array[k - 1] + array [k] >= t) return 0;
    array[k + 1] = t - array[k] - array[k - 1];
    return 1;
   // if (k < n) return 1;
//    return T + v == M;
}

int Try (int k){
    for (int v = 1; v <= n; v++){
        array[k] = v;
        if (Check(v, k)){
        //    array[k] = v;
        //    T = T + v;
         //   mark[v] = 1;
            if (k == n) Solution();
            else Try(k + 1);
       //     T = T - v;
         //   mark[v] = 0;
        }

    }
}

int main(){
    scanf("%d %d", &n, &t);
   // T = 0;
    Try(1);
    return 0;

}
