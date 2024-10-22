#include <stdio.h>
#include <stdlib.h>

void appendFile(const char *file1, const char *file2) {
    FILE *f1, *f2;
    char buffer[1024];

    f1 = fopen(file1, "a");
    if (f1 == NULL) {
        printf("%s.\n", file1);
        exit(1);
    }

    f2 = fopen(file2, "r");
    if (f2 == NULL) {
        printf("%s.\n", file2);
        fclose(f1);
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), f2) != NULL) {
        fputs(buffer, f1);
    }

    printf("%s.\n", file2, file1);

    fclose(f1);
    fclose(f2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("apd <file1> <file2>\n");
        return 1;
    }
    appendFile(argv[1], argv[2]);

    return 0;
}
