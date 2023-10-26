#include <stdio.h> 

struct student {
   int id; 
   char name[50];
   char category[20];
   short expired_date; 
   short stock;
};
int main(int argc, char* argv[]) { 
   struct student rec;
   FILE *fp;
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   fp = fopen(argv[1], "r");
   printf("%-3s %-10s %-10s %-10s %-5s\n", "id", "name", "category", "expired date", "stock"); 
   while (fscanf(fp,"%d %s %s %d %d", &rec.id, &rec.name, &rec.category, &rec.expired_date, &rec.stock) == 5) 
   
      printf("%-3d %-10s %-10s %-10d %-5d\n", rec.id, rec.name, rec.category, rec.expired_date, rec.stock);
   fclose(fp);
   return 0;
}