#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Contact {
    char name[100];
    char phoneNumber[20];
    char emailAddress[100];
};

struct Contact* readContactsFromFile(const char* filename, int* numContacts) {
}

void writeContactsToFile(const char* filename, struct Contact* contacts, int numContacts) {
}

void splitFile(const char* sourceFile, const char* file1, const char* file2, int numContacts) {
}

void mergeFiles(const char* file1, const char* file2, const char* outputFile) {
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s source_file num_contacts output_file1 output_file2\n", argv[0]);
        return 1;
    }

    const char* sourceFile = argv[1];
    int numContacts = atoi(argv[2]);
    const char* file1 = argv[3];
    const char* file2 = argv[4];

    struct Contact* contacts;
    int totalContacts;
    contacts = readContactsFromFile(sourceFile, &totalContacts);
    splitFile(sourceFile, file1, file2, numContacts);
    mergeFiles(file1, file2, sourceFile);

    contacts = readContactsFromFile(sourceFile, &totalContacts);
    printf("Merged contacts:\n");
    for (int i = 0; i < totalContacts; i++) {
        printf("%s - %s - %s\n", contacts[i].name, contacts[i].phoneNumber, contacts[i].emailAddress);
    }
    free(contacts);

    return 0;
}
