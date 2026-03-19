#include <stdio.h>
#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n===== Student Grade Management System =====\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by ID\n");
        printf("4. Calculate average score\n");
	printf("5. Find highest score\n");
	printf("6. Save data to file\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                calculateAverage(students, count);
                break;
	    case 5:
                findHighest(students, count);
                break;
	    case 6:
                saveToFile(students, count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}