#include "sortInt.h"

#include <stdlib.h>

void swap(T *x, T *y) {
  T tmp = *x;
  *x = *y;
  *y = tmp;
}

void insertion_sort(T a[], const int n) {
  for (int i = 0; i < n; i++) {
    T next = a[i];
    int j;
    for (j = i - 1; j >= 0 && next < a[j]; j--) a[j + 1] = a[j];
    a[j + 1] = next;
  }
}

void selection_sort(T a[], const int n) {
  for (int i = 0; i < n - 1; i++) {
    int mi = i;  // mi: min_index - index of min value
    for (int j = i + 1; j < n; j++)
      if (a[j] < a[mi]) mi = j;
    swap(&a[i], &a[mi]);
  }
}

// === Heap sort ===
void correctHeapNode(T a[], const int n, const int i) {
  const int l = i * 2 + 1;
  const int r = l + 1;
  int m = i;
  if (l < n && a[l] > a[m]) m = l;
  if (r < n && a[r] > a[m]) m = r;
  if (m != i) {
    // swap(a, i, m);
    swap(&a[i], &a[m]);
    correctHeapNode(a, n, m);
  }
}

void adjust(T lst[], int root, int n) {
  T temp = lst[root];
  T rootkey = lst[root];
  int child = 2 * root;
  while (child <= n) {
    if ((child < n) && (lst[child] < lst[child + 1])) child++;
    if (rootkey > lst[child])
      break;
    else {
      lst[child / 2] = lst[child];
      child *= 2;
    }
  }
  lst[child / 2] = temp;
}



void buildHeap(T a[], const int n) {
  for (int i = (n / 2); i >= 0; i--) correctHeapNode(a, n, i);
}

void buildHeapSOICT(T a[], const int n) {
  for (int i = n / 2; i >= 0; i--) correctHeapNode(a, i, n);
}




// ascending order (max heap)
// Sai
void heapSortSOICT(T lst[], const int n) {
  buildHeapSOICT(lst, n);

  for (int i = n - 1; i > 0; i--) {
    swap(&lst[1], &lst[i+1]);
    correctHeapNode(lst, 1, i);
  }
}

void heapSortSOICT_v2(T lst[], const int n) {
  buildHeapSOICT(lst, n);

  for (int i = n; i > 1; i--) {
    swap(&lst[0], &lst[i-1]);
    // correctHeapNode(lst, 0, i-1);
    // adjust(lst, 0, i - 1);
    correctHeapNode(lst, i - 1, 0);
  }
}

void sortHeap(T a[], const int n) {
  buildHeap(a, n);

  for (int i = n; i > 1; i--) {
    swap(&a[0], &a[i - 1]);
    correctHeapNode(a, i - 1, 0);
  }
}

// void quicksort(char list[], int left, int right)
// {
//   int pivot, i, j;
//   char temp;
//   if (left < right) {
//     i = left;    j = right+1;
//     pivot = list[left];           // <===
//     do {
//       do i++; while (list[i] < pivot);
//       do j--; while (list[j] > pivot);
//       if (i < j) swap(&list[i], &list[j]);
//     } while (i < j);
//     swap(&list[left], &list[j]);
//     quicksort(list, left, j-1);
//     quicksort(list, j+1, right);
//   }
// }

void mergeParts_aux(T *a, const int l, const int m, const int r) {
  const int pn = m - l + 1;
  const int qn = r - m;

  T *p = (T *)malloc(pn * sizeof(T));  // p = a.slice(l, l + pn);
  memcpy(p, a + l, pn * sizeof(T));

  T *q = (T *)malloc(qn * sizeof(T));  // q = a.slice(m + 1, m + 1 + qn);
  memcpy(q, a + m + 1, qn * sizeof(T));

  for (int i = 0, j = 0; i < pn || j < qn;) {
    if ((i == pn) || (j < qn && p[i] > q[j])) {
      a[l + i + j] = q[j];
      j++;
    } else {
      a[l + i + j] = p[i];
      i++;
    }
  }

  free(p);
  free(q);
}

void mergeParts_inPlace(T a[], const int l, int m, const int r) {
  int i;
  T t;
  for (; m < r; m++) {
    t = a[m + 1];
    for (i = m; i >= l && a[i] > t; i--) a[i + 1] = a[i];
    a[i + 1] = t;
  }
}

// Merge Sort
void sortMergePart(T *a, const int l, const int r) {
  const int m = (l + r) / 2;
  if (m > l) sortMergePart(a, l, m);
  if (m + 1 < r) sortMergePart(a, m + 1, r);
  // mergeParts_aux(a, l, m, r);
  mergeParts_inPlace(a, l, m, r);
}

void mergeSort(T a[], const int n) { sortMergePart(a, 0, n - 1); }
