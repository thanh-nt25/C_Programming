#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main() {
  treetype tr;
  makeNullTree(&tr);
  if (isEmptyTree(tr)) printf("Empty Tree\n");

  // elmType r = {'+', 0};
  elmType giaithua = {'!', 0};
  elmType chia = {'/', 0};
  elmType tru = {'-', 0};
  elmType cong = {'+', 0};
  elmType a = {' ', 10};
  elmType b = {' ', 3};
  elmType c = {' ', 4};
  elmType d = {' ', 2};

  tr = create_node(cong);
  tr = Add_Left(tr, giaithua);
  tr = Add_Left(tr->left, a);

  tr = Add_Right(tr, chia);
  tr = Add_Right(tr->right, d);
  tr = Add_Left(tr->right, tru);
  tr = Add_Left(tr->right->left, b);
  tr = Add_Right(tr->right->left, c);

  return 0;
}