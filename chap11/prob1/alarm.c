#include <stdio.h>
#include <unistd.h>
unsigned int alarm(unsigned int sec);

/* 알람 시그널을 보여주는 프로그램 */
int main( )
{
   alarm(5);
   printf("무한 루프 \n");
   int a=1;
   while (1) {
      sleep(1);
      printf("%d초 경과 \n",a);
      a++;
   }
   printf("실행되지 않음 \n");
}

