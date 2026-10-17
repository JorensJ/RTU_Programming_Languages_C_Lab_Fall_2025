// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void) {
    FILE *fp;
    char filename[100] = "data.txt";
    char line[256];

    printf("Writing to file: %s\n", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    fprintf(fp, "Line 1: Hello, file I/O in C!\n");
    fprintf(fp, "Line 2: This is another line\n");
    fclose(fp);

    printf("Reading contents:\n");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}
