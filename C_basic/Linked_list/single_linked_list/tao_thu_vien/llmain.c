// https://code.visualstudio.com/docs/cpp/config-linux
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

int main() {
  data_t sv1 = {"001", "sv1", 2};
  data_t sv2 = {"002", "sv2", 4};
  data_t sv3 = {"003", "sv3", 6};
  data_t sv4 = {"004", "sv4", 8};
  data_t sv5 = {"005", "sv5", 10};
  data_t aSV[] = {{"001", "sv1", 2},
                  {"002", "sv2", 4},
                  {"003", "sv3", 6},
                  {"004", "sv4", 8},
                  {"005", "sv5", 10}};

  root_t lst = llInit();
  for (int i = 0; i < sizeof(aSV) / sizeof(aSV[0]); i++)
    lst = llInsertHead(lst, aSV[i]);
  // lst = llInsertHead(lst, sv2);
  // lst = llInsertHead(lst, sv3);
  // lst = llInsertHead(lst, sv4);
  // lst = llInsertHead(lst, sv5);

  // for (int i = 0; i < 5; i++) {
  //   lst = llInsertTail(lst, convert(i));
  //   lst = llInsertHead(lst, convert(-i));
  // }
  llPrint(lst);

  node_t *p = llSeek(lst, 1);
  lst = llDeleteAfter(lst, p);
  lst = llDeleteHead(lst);
  lst = llDeleteTail(lst);

  llPrint(lst);

  lst = llDeleteAll(lst);

  return 0;
}