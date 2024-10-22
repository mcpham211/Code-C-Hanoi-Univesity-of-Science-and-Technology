#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void convertToUpper(const char *filename) {
    FILE *file;
    long length;
    char *buffer;

    file = fopen(filename, "r+");
    if (file == NULL) {
        printf("%s.\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *)malloc(length + 1);
    if (buffer == NULL) {
        printf("\n");
        fclose(file);
        exit(1);
    }
    fread(buffer, 1, length, file);
    buffer[length] = '\0';

    for (int i = 0; i < length; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, length, file);

    free(buffer);
    fclose(file);

    printf("\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("uconvert <filename>\n");
        return 1;
    }

    convertToUpper(argv[1]);

    return 0;
}

