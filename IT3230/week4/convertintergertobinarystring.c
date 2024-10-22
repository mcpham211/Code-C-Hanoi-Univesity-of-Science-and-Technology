#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Convertinttobinarystring(int n){
    if (n == 0) return 0;
        int a = n % 2;
        Convertinttobinarystring (n/2);
        printf("%d", a);
}


int main(){
    int n;
    scanf("%d", &n);
    Convertinttobinarystring(n);

}
