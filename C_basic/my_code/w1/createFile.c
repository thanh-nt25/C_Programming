#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

int getData(phoneAddress_t buf[]) {
   int n;

   printf("How many contacts do you want to enter (<20)?");
   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      printf("name:");  scanf("%s", buf[i].name);
      printf("tel:");   scanf("%s", buf[i].tel);
      printf("email:"); scanf("%s", buf[i].email);
   }

   return n;
}

// write the entire array into the file
int write2File(const char* fn, phoneAddress_t buf[], int len) {
   FILE *fp = fopen(fn, "wb");
   if (fp == NULL) {
      printf("Can not open %s.\n", fn);
      exit(OPEN_FAIL);
   }

   int irc = fwrite(buf, sizeof(buf[0]), len, fp);
   printf(" fwrite return code = %d\n", irc);
   fclose(fp);
   return irc;
}

int readFromFile(const char* fn, phoneAddress_t buf[], int len) {
   FILE *fp = fopen(fn, "rb");
   if (fp == NULL) {
      printf("Can not open %s.\n", fn);
      exit(OPEN_FAIL);
   }
   int irc = fread(buf, sizeof(buf[0]), len, fp);
   fclose(fp);
   return irc;
}

void printPhoneArr(phoneAddress_t buf[], int len) {
   for (int i = 0; i < len; i++) {
      printf("%s-", buf[i].name);
      printf("%s-", buf[i].tel);
      printf("%s\n", buf[i].email);
   }
}

int main(void)
{
   char *fn = "phonebook.dat";
   int reval = SUCCESS;

   phoneAddress_t phonearr[MAX_ELEMENT];
   int n = getData(phonearr);

   int irc;  
   irc = write2File(fn, phonearr, n);
   printf(" fwrite return code = %d\n", irc);

   irc = readFromFile(fn, phonearr, n);
   printf(" fread return code = %d\n", irc);
   
   printPhoneArr(phonearr, n);

   return reval;
}