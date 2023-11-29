#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printEnvironmentVariable(char *envVarName);
void printUserAndGroupIDs();
void printProcessIDs();

int main(int argc, char *argv[]) {
    int opt;

    while ((opt = getopt(argc, argv, "e:ugiip")) != -1) {
        switch (opt) {
            case 'e':
                printEnvironmentVariable(optarg);
                break;
            case 'u':
            case 'g':
                printUserAndGroupIDs();
                break;
            case 'i':
            case 'p':
                printProcessIDs();
                break;
            default:
                fprintf(stderr, "Usage: %s [-e <envVarName>] [-u | -g] [-i | -p]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void printEnvironmentVariable(char *envVarName) {
    char *envVarValue = getenv(envVarName);
    if (envVarValue == NULL) {
        fprintf(stderr, "Environment variable '%s' not found.\n", envVarName);
    } else {
        printf("%s=%s\n", envVarName, envVarValue);
    }
}

void printUserAndGroupIDs() {
    printf("Real User ID: %d\n", getuid());
    printf("Effective User ID: %d\n", geteuid());
    printf("Real Group ID: %d\n", getgid());
    printf("Effective Group ID: %d\n", getegid());
}

void printProcessIDs() {
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
}

