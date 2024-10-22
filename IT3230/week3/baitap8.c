#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Phone {
    char model[100];
    int memorySpace;
    float screenSize;
    float price;
};

struct Phone* readPhonesFromFile(const char* filename, int* numPhones) {
}

void writePhonesToFile(const char* filename, struct Phone* phones, int numPhones) {
}

struct Phone* readPhonesFromBinaryFile(const char* filename, int* numPhones) {
}

void displayPhones(struct Phone* phones, int numPhones) {
}

int searchPhoneByModel(struct Phone* phones, int numPhones, const char* model) {
}

int main() {
    struct Phone* phones;
    int numPhones, choice;
    char model[100];
    phones = readPhonesFromFile("PhoneDB.txt", &numPhones);
    writePhonesToFile("PhoneDB.dat", phones, numPhones);

    while (1) {
        printf("Choose an option:\n");
        printf("1. Import DB from text\n");
        printf("2. Import from DB\n");
        printf("3. Print All Database\n");
        printf("4. Search by phone by Phone Model\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                phones = readPhonesFromBinaryFile("PhoneDB.dat", &numPhones);
                displayPhones(phones, numPhones);
                break;
            case 3:
                displayPhones(phones, numPhones);
                break;
            case 4:
                printf("Enter phone model: ");
                scanf("%s", model);
                int index = searchPhoneByModel(phones, numPhones, model);
                if (index != -1) {
                    displayPhones(&phones[index], 1);
                } else {
                    printf("Phone not found.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    free(phones);

    return 0;
}

