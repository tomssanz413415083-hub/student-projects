#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    printf("Enter student name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter student ID: ");
    scanf("%s", students[*count].id);

    printf("Enter student score: ");
    scanf("%f", &students[*count].score);

    (*count)++;
    printf("Student added successfully.\n");
}

void displayStudents(Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No student data available.\n");
        return;
    }

    printf("\n=== Student List ===\n");
    for (i = 0; i < count; i++) {
        printf("%d. Name: %s | ID: %s | Score: %.2f\n",
               i + 1,
               students[i].name,
               students[i].id,
               students[i].score);
    }
}

void searchStudent(Student students[], int count) {
    char searchId[20];
    int i, found = 0;

    printf("Enter student ID to search: ");
    scanf("%s", searchId);

    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, searchId) == 0) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %s\n", students[i].id);
            printf("Score: %.2f\n", students[i].score);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}