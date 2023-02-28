#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
struct node_s {
  data_t data;
  struct node_s* l;
  struct node_s* r;
} node_t;
typedef struct node_s* tree_t;
data_t _max(data_t x, data_t y) { return x > y ? x : y; }

tree_t NEW(data_t data, tree_t l, tree_t r) {
  tree_t x = malloc(sizeof(node_t));
  x->data = data;
  x->l = l;
  x->r = r;
  return x;
}

tree_t max(data_t a[], int l, int r) {
  int m = (l + r) / 2;
  tree_t x = NEW(a[m], NULL, NULL);
  if (l == r) return x;

  x->l = max(a, l, m);
  x->r = max(a, m + 1, r);
  x->data = _max(x->l->data, x->r->data);
  return x;
}

int main() {
  data_t a[] = {5, 3, 6, 3, 7, 1, 3, 9};
  tree_t binTree = max(a, 0, sizeof(a) / sizeof(a[0]) - 1);

  printf("%d\n", binTree->data);
  // todo: free
  // giải phóng bộ nhớ thì dùng Duyệt cây được không?
  // Nếu được thì dùng duyệt kiểu gì?
  return 0;
}