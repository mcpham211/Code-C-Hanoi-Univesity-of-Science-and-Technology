#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int greatestcommondivsor(int a, int b){
    if(a == b) return a;
    else if (a > b) return greatestcommondivsor(a - b, b);
    else if (a < b) return greatestcommondivsor(b - a, a);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", greatestcommondivsor(a, b));

    return 0;
}
