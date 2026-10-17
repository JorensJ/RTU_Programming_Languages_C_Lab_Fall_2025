// Student Name: Jorens Jekabsons
// Student ID: 251RDC082
// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming
// TODO: Implement functions to load, save, add, and list students.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[], int max);
int save_students(const Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(const Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    count = load_students(students);
    printf("Loaded %d students(s) students.txt\n", count);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            choice = 0; 
        }
        getchar();

        switch (choice) {
            case 1:
            list_students(students, count);
                break;
            case 2:
            add_student(students, &count);
                break;
            case 3:
            if (save_students(students, count) == 0) {
                printf("Data saved Goodbye!\n");
            } else {
                printf("Error saving data.\n");
            }
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

int load_students(Student arr[], int max) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        return 0;
    }

    int count = 0;
    char line[256];
    while(fgets(line, sizeof(line), fp) != NULL && count < max) {
        if (sscanf(line, "%49s %d %f", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
            count++;
        }
    }
    fclose(fp);
    return count;
}
int load_students(Student arr[]) {
    // ...
    return 0;
}

int save_students(const Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    fclose(fp);
    return 0;
}
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum reached.\n");
        return;
    }
}

Student new student;
char input_buffer[256];
printf("Enter name: ");
fgets(input_buffer, sizeof(input_buffer), stdin);
input_buffer[strcspn(input_buffer, "\n")] = 0;

if (strlen(input_buffer) == 0) || strchr(input_buffer,',') != NULL) {
    printf("Name cannot be empty.\n");
    return;
}
strncpy(new_student.name, input_buffer);

printf("Enter ID: ");
fgets(input_buffer, sizeof(input_buffer), stdin);
if (sscanf(input_buffer, "%d", &new_student.id) != 1 || new_student.id <= 0) {
    printf("Invalid ID. Must be a positive integer.\n");
    return;
}
printf("Enter GPA: ");
fgets(input_buffer, sizeof(input_buffer), stdin);
if (sscanf(input_buffer, "%f", &new_student.gpa) != 1 || new_student.gpa <= 0.0 || new_student.gpa > 4.0) {
    printf("Invalid input. Student not added.\n");
    return;
}

arr[*count] = new_student;
(*count)++;
printf("No student found.\n");
return;
}

printf("ID NAME GPA\n");
for (int i = 0; i < count; i++) {
    printf("%-6d %-19s %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }
