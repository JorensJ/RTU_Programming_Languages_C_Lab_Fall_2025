// Student Name: Jorens Jekabsons
// Student ID: 251RDC082
// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming
// TODO: Complete function implementations and file handling logic.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
int save_student(const Student *s, const char *filename);
int load_student(const char *filename, Student *out);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";
    Student loaded_student;

    printf("Saving student to file...\n");
    if (save_student(&s1, filename) != 0) {
        printf("Error saving student data.\n");
        return 1;
    }

    printf("Loading student from file...\n");
    if (load_student(filename, &loaded_student) != 0) {
        printf("Error loading student data.\n");
        return 1;   
    }

    printf("Loaded Student: Name: %s, %d, GPA %.2f\n", loaded_student.name, loaded_student.age, loaded_student.gpa);

    return 0;
}

int save_student(const Student *s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }
    fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);
    fclose(fp);
    return 0;
}

 int load_student(const char *filename, Student *out) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    int read_count = fscanf(fp, "%49s %d %f", out->name, &out->age, &out->gpa);
    fclose(fp);
    if (read_count != 3) {
        return -1;
    }
    return 0;
}
