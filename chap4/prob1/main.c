#include <stdio.h>
/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[])
//./cat a.txt 두개라서 arge=2, argv는 0번에./cat, 1번에 a.txt
{
   FILE *fp;
   int c;
   if (argc < 2) 
      fp = stdin; 			// 명령줄 인수가 없으면 표준입력 사용 
   else  fp = fopen(argv[1],"r");	// 읽기 전용으로 파일 열기 
//argv[1] = a.txt

   c = getc(fp); 	// 가장 처음 문자의 포인터를 c에 저장
									// 파일로부터 문자 읽기
   while (c != EOF) { 		// 파일끝이 아니면, 포인터를 반복해서 돌림
      putc(c, stdout); 		// 읽은(c에 저장한) 문자를 표준출력에 출력
      c = getc(fp); 		// 파일로부터 문자 읽기 
   }
   fclose(fp); 
   return 0;
}
