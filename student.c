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

void calculateAverage(Student students[], int count) {
    int i;
    float total = 0;

    if (count == 0) {
        printf("No student data available.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        total += students[i].score;
    }

    printf("Average score: %.2f\n", total / count);
}

void findHighest(Student students[], int count) {
    int i, highestIndex = 0;

    if (count == 0) {
        printf("No student data available.\n");
        return;
    }

    for (i = 1; i < count; i++) {
        if (students[i].score > students[highestIndex].score) {
            highestIndex = i;
        }
    }

    printf("Highest score student:\n");
    printf("Name: %s\n", students[highestIndex].name);
    printf("ID: %s\n", students[highestIndex].id);
    printf("Score: %.2f\n", students[highestIndex].score);
}

void saveToFile(Student students[], int count) {
    FILE *file = fopen("data.txt", "w");
    int i;

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%.2f\n",
                students[i].name,
                students[i].id,
                students[i].score);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

void loadFromFile(Student students[], int *count) {
    FILE *file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("No saved file found.\n");
        return;
    }

    *count = 0;
    while (fscanf(file, " %49[^;];%19[^;];%f",
                  students[*count].name,
                  students[*count].id,
                  &students[*count].score) == 3) {
        (*count)++;
        if (*count >= MAX_STUDENTS) {
            break;
        }
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}