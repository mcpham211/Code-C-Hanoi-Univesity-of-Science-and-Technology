
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[100];
    float grades[5];
};


int main() {
    struct Student* students;
    int numStudents, choice, id;
    students = readStudentsFromFile("bangdiem.txt", &numStudents);
    writeStudentsToFile("grade.dat", students, numStudents);
    while(1){
        printf("TextToDat\n");
        printf("Display Dat file\n");
        printf("Search and Update\n");
        printf("Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                students = readStudentsFromBinaryFile("grade.dat", &numStudents);
                displayStudents(students, numStudents);
                break;
            case 3:
                printf("Enter student ID: ");
                scanf("%d", &id);
                int index = searchStudentById(students, numStudents, id);
                if (index != -1) {
                    updateStudentGrades(&students[index]);
                    writeStudentsToFile("grade.dat", students, numStudents);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    free(students);
    return 0;
}
