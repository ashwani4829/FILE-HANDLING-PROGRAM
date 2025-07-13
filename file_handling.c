#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "sample.txt";
    char data[100];
    char ch;

    // 1. Create and write to a file
    printf("Creating and writing to a file...\n");
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    printf("Enter data to write to file (max 100 chars):\n");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data written successfully.\n\n");

    // 2. Read from the file
    printf("Reading from the file...\n");
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    printf("File contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);
    printf("\n\n");

    // 3. Append to the file
    printf("Appending to the file...\n");
    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error opening file for appending!\n");
        exit(1);
    }

    printf("Enter data to append to file (max 100 chars):\n");
    fgets(data, sizeof(data), stdin);
    fprintf(file, "%s", data);
    fclose(file);
    printf("Data appended successfully.\n\n");

    // 4. Read the file again to show appended content
    printf("Reading the file after appending...\n");
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    printf("Updated file contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }
    fclose(file);

    return 0;
}