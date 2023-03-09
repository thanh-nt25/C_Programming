#include "sort_t.h"

void swap(T *x, T *y) {
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

void insertion_sort(T a[], const int n) {
  for (int i = 0; i < n; i++) {
    T next = a[i];
    int j;
    for (j = i - 1; j >= 0 && lt(next.key, &a[j]); j--) a[j + 1] = a[j];
    a[j + 1] = next;
  }
}

void selection_sort(T a[], const int n) {
  for (int i = 0; i < n - 1; i++) {
    int mi = i;  // mi: min_index - index of min value
    for (int j = i + 1; j < n; j++)
      if (lt(a[j].key, &a[mi])) mi = j;
    swap(&a[i], &a[mi]);
  }
}

// === Heap sort ===

void adjust(T lst[], const int root, const int n) {
  T temp = lst[root];
  // keyT rootkey = lst[root].key;
  int child = 2 * root;
  
  while (child <= n) {
    if ((child < n) && (lt(lst[child].key, &lst[child + 1]))) child++;
    if (gt(lst[root].key, &lst[child]))
      break;
    else {
      lst[child / 2] = lst[child];
      child *= 2;
    }
  }
  lst[child / 2] = temp;
}

// ascending order (max heap)
void heapsort(T lst[], const int n) {
  for (int i = n / 2; i > 0; i--) adjust(lst, i, n);
  for (int i = n - 1; i > 0; i--) {
    swap(&lst[1], &lst[i + 1]);
    adjust(lst, 1, i);
  }
}


void quicksort(T list[], const int left, const int right)
{
  if (left < right) {
    int i = left;    
    int j = right+1;
    // keyT pivot = list[left].key;
    do {
      do i++; while (gt(list[left].key, &list[i]));
      do j--; while (lt(list[left].key, &list[j]));
      if (i < j) swap(&list[i], &list[j]);
    } while (i < j);
    swap(&list[left], &list[j]);
    quicksort(list, left, j-1);
    quicksort(list, j+1, right);
  }
}
