#include "hash.h"

#include <string.h>

static element_t hashtable[TABLE_SIZE];  // <===
static int N = 0;

// Hash Code Maps: Component Sum
static const int transform(const int key) { return key; }

// Compression map
int hash(const int key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table() {  // <===
  for (int i = 0; i < TABLE_SIZE; i++) hashtable[i].key = NULLKEY;
  N = 0;  // so nut hien co khoi dong bang 0
}

// Check the state of table
static const int full() { return (N == TABLE_SIZE - 1 ? 1 : 0); }

static const int empty() { return (N == 0 ? 1 : 0); }

int findElement(const int k) {
  const int hk = hash(k);
  int pki = hk;
  for (int i = 0; hashtable[pki].key != NULLKEY && hashtable[pki].key != k;) {
    // Quadratic probing
    i = i + 1;
    pki = (hk + i * i) % TABLE_SIZE;
  }
  if (hashtable[pki].key == k)  // found
    return pki;
  else
    return -1;  // not found
}

// Khong kiem tra da co key cu trong hashtable hay chua
int insertItem(const int k) {
  if (full()) {
    printf("\n Hash table is full. Can not insert 	the 	key %d ", k);
    return -1;  // <===
  }

  const int hk = hash(k);   // hk: h(k)
  int pki = hk;             // pki: p(k,i)
  for (int i = 0; hashtable[pki].key != NULLKEY;) {
    // Quadratic probing
    i = i + 1;
    pki = (hk + i * i) % TABLE_SIZE;
  }
  hashtable[pki].key = k;
  N = N + 1;
  return pki;
}

// int removeElement(int i) {
//   int j, r, a, cont = 1;
//   do {
//     hashtable[i].key = NULLKEY;
//     j = i;
//     do {
//       i = i + 1;
//       if (i >= TABLE_SIZE) i = i - TABLE_SIZE;
//       if (hashtable[i].key == NULLKEY)
//         cont = 0;
//       else {
//         r = hash(hashtable[i].key);
//         a = (j < r && r <= i) || (r <= i && i < j) || (i < j && j < r);
//       }
//     } while (cont && a);
//     if (cont) hashtable[j].key = hashtable[i].key;
//   } while (cont);
// }

void traverse() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    if (hashtable[i].key != NULLKEY) {
      printf("\n(i, key) = (%d, %d)\n", i, hashtable[i].key);
    }
  }
}