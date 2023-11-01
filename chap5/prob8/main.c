#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found or unable to open.\n");
        return 1;
    }

    char savedText[MAX_LINES][MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(savedText[line_count], sizeof(savedText[line_count]), file) != NULL) {
        line_count++;
    }

    char input[100];
    printf("File read success\nTotal Line : %d\nYou can choose 1 ~ %d Line",line_count,line_count);
    printf("\nPls is the line to select : ");
    scanf("%s", input);

    if (strcmp(input, "*") == 0) {
        for (int i = 0; i < line_count; i++) {
            printf("%d: %s", i + 1, savedText[i]);
        }
    } else {
        char *token = strtok(input, ",");
        while (token != NULL) {
            if (strchr(token, '-') != NULL) {
                int start, end;
                if (sscanf(token, "%d-%d", &start, &end) == 2) {
                    for (int i = start - 1; i < end; i++) {
                        if (i >= 0 && i < line_count) {
                            printf("%d: %s", i + 1, savedText[i]);
                        }
                    }
                } else {
                    printf("Invalid input: %s\n", token);
                }
            } else {
                int number;
                if (sscanf(token, "%d", &number) == 1) {
                    int index = number - 1;
                    if (index >= 0 && index < line_count) {
                        printf("%d: %s", number, savedText[index]);
                    } else {
                        printf("Invalid input: %s\n", token);
                    }
                } else {
                    printf("Invalid input: %s\n", token);
                }
            }
            token = strtok(NULL, ",");
        }
    }

    fclose(file);

    return 0;
}

