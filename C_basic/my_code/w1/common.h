#ifndef __COMMON__
#define __COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
   SUCCESS,
   FAIL,
   OPEN_FAIL,
   SEEK_FAIL,
   MALLOC_FAIL,
   MAX_ELEMENT = 20
};

// the phone book structure
typedef struct {
   char name[20];
   char tel[12];
   char email[28];
} phoneAddress_t;

#endif