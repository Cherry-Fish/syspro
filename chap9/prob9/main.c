#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        // 자식 프로세스에서 명령어 실행
        char *args[MAX_COMMAND_LENGTH];
        char *token = strtok(command, " ");
        int i = 0;

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;

        execvp(args[0], args);
        perror("Error");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        // 부모 프로세스에서 자식 프로세스의 종료를 기다림
        waitpid(pid, &status, 0);
    }
}

void shell() {
    char input[MAX_COMMAND_LENGTH];
    char *token;

    while (1) {
        printf("[shell] ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        // 개행 문자 제거
        if ((token = strchr(input, '\n')) != NULL) {
            *token = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *commands[MAX_COMMAND_LENGTH];
        char *command;
        int i = 0;

        // 세미콜론을 기준으로 명령어 분리
        token = strtok(input, ";");
        while (token != NULL) {
            commands[i++] = token;
            token = strtok(NULL, ";");
        }

        commands[i] = NULL;

        for (int j = 0; j < i; j++) {
            command = commands[j];

            // 후면 실행 여부 확인
            int background = 0;
            if ((token = strchr(command, '&')) != NULL) {
                *token = '\0';
                background = 1;
            }

            // 입출력 리디렉션 확인
            char *outfile = strchr(command, '>');
            char *infile = strchr(command, '<');

            if (outfile != NULL) {
                *outfile = '\0';
                outfile++;
                freopen(outfile, "w", stdout);
            } else if (infile != NULL) {
                *infile = '\0';
                infile++;
                freopen(infile, "r", stdin);
            }

            execute_command(command);

            // 리디렉션 파일 닫기
            if (outfile != NULL || infile != NULL) {
                fclose(stdout);
                fclose(stdin);
            }

            // 후면 실행일 경우 부모 프로세스는 대기하지 않고 진행
            if (!background) {
                wait(NULL);
            }
        }
    }
}

int main() {
    shell();
    return 0;
}

