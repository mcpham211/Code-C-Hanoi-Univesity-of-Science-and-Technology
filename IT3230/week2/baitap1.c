#include <stdio.h>
#include <stdlib.h>

void print_usage() {
    printf("Usage: mycp <source_file> <destination_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        print_usage();
        return 1;
    }

    FILE *source = fopen(argv[1], "r");
    if (source == NULL) {
        fprintf(stderr, "Error: Could not open source file '%s'.\n", argv[1]);
        return 1;
    }

    FILE *destination = fopen(argv[2], "w");
    if (destination == NULL) {
        fclose(source);
        fprintf(stderr, "Error: Could not open or create destination file '%s'.\n", argv[2]);
        return 1;
    }

    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully from '%s' to '%s'.\n", argv[1], argv[2]);

    return 0;
}

