// Copyright 2024 JOK Inc. All Rights Reserved.
// Author: easytojoin@163.com (jok)

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100
#define MAX_KEY_LEN 50

typedef struct Node {
  char key[MAX_KEY_LEN];
  int val;
  struct Node* next;
} Node;

typedef struct HashTable {
  Node* table[HASH_TABLE_SIZE];
} HashTable;

void insert(HashTable* table, const char* key, int val);
int search(HashTable* table, const char* key, int* val);

#endif  // HASHTABLE_H_
