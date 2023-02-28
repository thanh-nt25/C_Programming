#include "hash.h"

#include <string.h>

static element_t hashtable[TABLE_SIZE];  // <===
static int N = 0;

// Hash Code Maps
// Component Sum
static const int transform(const int key) { return key; }

// Compression map
int hashfunc(const int key) { return (transform(key) % TABLE_SIZE); }

int hashfunc2(const int key) {
  return (TABLE_SIZE - 2 - key % (TABLE_SIZE - 2));
}

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
  int pki = hashfunc(k);
  const int h2k = hashfunc2(k);
  while (hashtable[pki].key != NULLKEY && hashtable[pki].key != k) {
    // Rehashing
    pki = (pki + h2k) % TABLE_SIZE;  // <=== error
  }
  if (hashtable[pki].key == k)  // found
    return pki;
  else  // not found
    return TABLE_SIZE;
}

int insertItem(const int k) {
  if (full()) {
    printf("\n Hash table is full. Can not insert 	the 	key %d ", k);
    return TABLE_SIZE;
  }
  if (findElement(k) < TABLE_SIZE) {
    printf("This key exist in the hash table -> insert fail\n");
    return TABLE_SIZE;
  }

  int pki = hashfunc(k);
  const int h2k = hashfunc2(k);
  while (hashtable[pki].key != NULLKEY) {
    // Rehashing
    pki = (pki + h2k) % TABLE_SIZE;
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