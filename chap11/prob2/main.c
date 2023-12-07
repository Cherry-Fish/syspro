#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
unsigned int alarm(unsigned int sec);

void alarmHandler();
/* 알람 시그널을 처리한다. */
int main( )
{
   signal(SIGALRM, alarmHandler);
   alarm(5);    /* 알람 시간 설정 */
   printf("무한 루프 \n");
   int a=1;
   while (1) {
      sleep(1);
      printf("%d초 경과 \n",a);
      a++;
   }
   printf("실행되지 않음 \n");
}

void alarmHandler(int signo)
{
   printf("일어나세요\n");
   exit(0);
}
