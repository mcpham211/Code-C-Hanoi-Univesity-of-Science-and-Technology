#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[100];
    char phoneNumber[20];
    char emailAddress[100];
};

int main() {
    struct Contact contacts[100];
    int numContacts;
    scanf("%d", &numContacts);

    for (int i = 0; i < numContacts; i++) {
        printf("%d\n", i + 1);
        scanf("%s", contacts[i].name);
        scanf("%s", contacts[i].phoneNumber);
        scanf("%s", contacts[i].emailAddress);
    }
    FILE* file = fopen("phonebook.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fwrite(contacts, sizeof(struct Contact), numContacts, file);
    fclose(file);
    file = fopen("phonebook.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    fread(contacts, sizeof(struct Contact), numContacts, file);
    fclose(file);
    printf("Contact information:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%s\n", contacts[i].name);
        printf("%s\n", contacts[i].phoneNumber);
        printf("%s\n", contacts[i].emailAddress);
    }

    return 0;
}
