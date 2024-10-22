#include <stdio.h>
#include <stdlib.h>

#define LINES_PER_PAGE 20

void displayFile(char *filename, int pageMode) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s\n", filename);
        return;
    }

    char line[100];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        count++;
        if (pageMode && count == LINES_PER_PAGE) {
            printf("\n");
            getchar();
            count = 0;
        }
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2 && argc != 3) {
        printf("S%s <tệp_tin> [-p]\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int pageMode = 0;
    if (argc == 3 && strcmp(argv[2], "-p") == 0) {
        pageMode = 1;
    }

    displayFile(filename, pageMode);

    return 0;
}
