#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
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

    // 파일 내용을 읽어 배열에 저장
    while (fgets(savedText[line_count], sizeof(savedText[line_count]), file) != NULL) {
        line_count++;
    }

    fclose(file);

    // 각 줄을 역순으로 출력
    for (int i = line_count - 1; i >= 0; i--) {
        printf("%s", savedText[i]);
    }

    return 0;
}

