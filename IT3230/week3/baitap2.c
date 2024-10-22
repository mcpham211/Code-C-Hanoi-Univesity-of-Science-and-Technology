#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//const double PI = 3.14159

typedef struct point{
    double x;
    double y;
} point1;

typedef struct circle{
    point1 center;
    double radius;
} c1;

/*
struct Circle {
    double x;
    double y;
    double radius;
};
*/

int circle_t(c1 a, c1 b){
    double distance = sqrt(pow(c1 a.x - c1 b.x, 2) + pow(c1 a.y - c1 b.y, 2));
    return distance <= c1 a.radius + c1 b.radius;
}

int main(){
    c1 cicle1;
    c1 cicle2;
    scanf("%lf %lf", &cicle1, &cicle2);
    if (circle_t(&cicle1, &cicle 2)) printf("Hai duong tron giao nhau");
    else printf("Hai duong trong khong giao nhau");
    return 0;
}


