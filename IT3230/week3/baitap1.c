#include <stdio.h>
#include <string.h>
#include<stdlib.h>


char* subStr(char* s1, int offset, int number){
    int len = strlen(s1);
    if(offset < 0 || offset >= len) return NULL;
    if(number < 0) return NULL;
    int other = len - offset;
    if(number > other){
        number = other;
    }
    char* sub = (char*)malloc((number + 1)*sizeof(char));
    if(sub == NULL) return NULL;
    strncpy(sub, s1 + offset, number);
    sub[number] = '\0';
    return sub;
}

int main() {
    char s1[100000+1];
    int offset;
    int number;

    scanf("%s", s1);
    scanf("%d %d", &offset, &number);

    char* subscribe = subStr(s1, offset, number);
    if(subscribe != NULL){
        printf("%s\n", subscribe);
    }
    return 0;
}

