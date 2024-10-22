#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char sourceFile[100], destinationFile[100];
    int choice, blockSize;
    clock_t startTime, endTime;
    while (1) {
        printf("Copy by character\n");
        printf("Copy by line\n");
        printf("Copy by block\n");
        printf("Quit\n");
        scanf("%d", &choice);
        if (choice == 4) {
            break;
        }
        scanf("%s", sourceFile);
        scanf("%s", destinationFile);
        if (choice == 3) {
            scanf("%d", &blockSize);
        }
        startTime = clock();
        switch (choice) {
            case 1:
                copyByCharacter(sourceFile, destinationFile);
                break;
            case 2:
                copyByLine(sourceFile, destinationFile);
                break;
            case 3:
                copyByBlock(sourceFile, destinationFile, blockSize);
                break;
            default:
                printf("Invalid choice!\n");
        }
        endTime = clock();
        printf("Time taken: %.3f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
    }
    return 0;
}
