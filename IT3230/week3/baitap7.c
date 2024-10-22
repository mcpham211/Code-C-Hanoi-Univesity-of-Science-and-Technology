#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DictionaryEntry {
    char vietnameseWord[100];
    char englishTranslation[100];
};
struct DictionaryEntry* readDictionaryEntriesFromFile(const char* filename, int* numEntries) {
}
void writeDictionaryEntriesToFile(const char* filename, struct DictionaryEntry* entries, int numEntries) {
}
struct DictionaryEntry* readDictionaryEntriesFromBinaryFile(const char* filename, int* numEntries) {
}

int main() {
    struct DictionaryEntry* entries;
    int numEntries, startPosition, endPosition;
    entries = readDictionaryEntriesFromFile("vnedict.txt", &numEntries);
    writeDictionaryEntriesToFile("dictionary.bin", entries, numEntries);
    entries = readDictionaryEntriesFromBinaryFile("dictionary.bin", &numEntries);
    printf("Enter starting position: ");
    scanf("%d", &startPosition);
    printf("Enter ending position: ");
    scanf("%d", &endPosition);

    if (startPosition < 0 || startPosition >= numEntries || endPosition < 0 || endPosition >= numEntries || startPosition > endPosition) {
        printf("Invalid positions.\n");
    } else {
        printf("Dictionary entries:\n");
        for (int i=startPosition;i<=endPosition;i++) {
            printf("%s - %s\n", entries[i].vietnameseWord, entries[i].englishTranslation);
        }
    }
    free(entries);

    return 0;
}
