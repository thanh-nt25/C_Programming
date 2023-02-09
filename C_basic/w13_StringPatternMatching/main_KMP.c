#define _DEBUG_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "strMatching.h"

#define MAX (2000)

// output co kich thuoc n+1 ki tu
// n so ki tu co nghia trong output
// output[n] chua ki tu '\0' de tien viec hien thi
void iniStr(const char setOfChar[], const int setLen, char output[], int n) {
  static int initialized = 0;
  if (!initialized) {
    srand(time(0));
    initialized = 1;
  }

  for (int i = 0, j = 0; i < n; i++) {
    j = rand() % setLen;
    output[i] = setOfChar[j];
  }
  output[n] = '\0';
}


void FailureFunction(const char P[], int F[]) {
  const int m = strlen(P);
  for (int i = 0; i < m; i++) F[i] = 0;
  int i = 1;
  int j = 0;
  while (i < m) {
    if (P[i] == P[j]) {  // we have matched j+1 chars
      F[i] = j + 1;
      i++, j++;
    } else if (j > 0)  // use failure function to shift P
      j = F[j - 1];
    else {
      F[i] = 0;  // no match
      i++;
    }
  }
#ifdef _DEBUG_
  for (int i = 0; i < m; i++) printf("%d ", F[i]);
  printf("\n");
#endif
}

int KMPMatch(const char T[], const char P[]) {
  int *F = (int *)malloc(strlen(P) * sizeof(int));
  const int m = strlen(P);
  const int n = strlen(T);
  FailureFunction(P, F);
  int i = 0;
  int j = 0;
  while (i < n) {
    if (T[i] == P[j])
      if (j == m - 1) {
        free(F);
        return i - j;
      } else {
        i++, j++;
      }
    else {
      if (j > 0)
        j = F[j - 1];
      else
        i++;
    }
  }
  free(F);
  return -1;  // no match
}

int main() {
  // ==============================================
  // KMP string matching
  // ==============================================
  // Example
  // char setOfChar[] = "ab";
  // const int N = strlen(setOfChar);
  // char t[MAX + 1] = "abaabx";
  // char p[6] = "abaaba";
  // int F[6];
  // FailureFunction(p, F);

  // Exercise 13.3
  char setOfChar[] = "abcdef";
  const int N = strlen(setOfChar);
  char t[MAX + 1];
  char p[5];
  iniStr(setOfChar, strlen(setOfChar), t, MAX);
  iniStr(setOfChar, strlen(setOfChar), p, sizeof(p) - 1);

  // Example
  printf("\nText   :%s\n", t);
  printf("Pattern: %s\n", p);
  int retVal;
  retVal = KMPMatch(t, p);
  if (retVal == -1)
    printf("\nSubString not found\n");
  else
    printf("\nfound: '%d %s'\n", retVal, &t[retVal]);

  return 0;
}