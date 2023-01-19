#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

void printPhoneArr(phoneAddress_t phoneArr[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%s-", phoneArr[i].name);
        printf("%s-", phoneArr[i].tel);
        printf("%s\n", phoneArr[i].email);
    }
}

// read from this file to array again
phoneAddress_t* readFromFile(const char *fn, int startIndex, int len, int* pIrc) {
    // Memory allocation
    phoneAddress_t *buf = (phoneAddress_t *)malloc(len * sizeof(phoneAddress_t));
    if (buf == NULL) {
        printf("Memory allocation failed!\n");
        exit(MALLOC_FAIL);
    }

    FILE *fp = fopen(fn, "rb");
    if (fp == NULL) {
        printf("Can not open %s.\n", fn);
        exit(OPEN_FAIL);
    }

    int retVal = fseek(fp, startIndex * sizeof(buf[0]), SEEK_SET);
    if (retVal != 0) {
        printf("Fseek failed!\n");
        fclose(fp);
        exit(SEEK_FAIL);
    }

    *pIrc = fread(buf, sizeof(buf[0]), len, fp);
    fclose(fp);

    return buf;
}

int writeToFile(const char *fn, phoneAddress_t buf[], int startIndex, int len) {
    FILE *fp = fopen(fn, "wb");
    if (fp == NULL) {
        printf("Can not open %s.\n", fn);
        exit(OPEN_FAIL);
    }

    int retVal = fseek(fp, startIndex * sizeof(buf[0]), SEEK_SET);
    if (retVal != 0) {
        printf("Fseek failed!\n");
        fclose(fp);
        exit(SEEK_FAIL);
    }
    
    int irc = fwrite(buf, sizeof(buf[0]), len, fp);
    fclose(fp);
    return irc;
}

int main(void)
{
    const int startIndex = 1;
    const int stopIndex = 2;
    const int len = (stopIndex - startIndex + 1);

    phoneAddress_t *phoneArr = NULL;
    const char *fn = "phonebook.dat";
    int irc;

    printf("Read from 2sd data to 3rd data \n");
    
    phoneArr = readFromFile(fn, startIndex, len, &irc);
    printPhoneArr(phoneArr, len);

    printf("\nModifying some data\n\n");

    strcpy(phoneArr[1].name, "Lan");
    strcpy(phoneArr[1].tel, "0923456");
    strcpy(phoneArr[1].email, "lovelybuffalo@hut.edu.vn");

    printf("Rewrite to file\n\n");
    writeToFile(fn, phoneArr, startIndex, len);
    free(phoneArr);    phoneArr = NULL;

    printf("Read file again - to check\n\n");
    phoneArr = readFromFile(fn, startIndex, len, &irc);
    printPhoneArr(phoneArr, irc);

    free(phoneArr);
    return SUCCESS;
}
