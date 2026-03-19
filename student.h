#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    char id[20];
    float score;
} Student;

void addStudent(Student students[], int *count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count);
void calculateAverage(Student students[], int count);
void findHighest(Student students[], int count);
void saveToFile(Student students[], int count);
void loadFromFile(Student students[], int *count);

#endif