// Copyright 2024 JOK Inc. All Rights Reserved.
// Author: easytojoin@163.com (jok)

#include "HashTable.h"

static u_int32_t cal_hash(const char* key) {
  u_int32_t hash = 0;
  const char* ptr = key;
  while (*ptr) {
    hash += *ptr++;
  }
  return hash % HASH_TABLE_SIZE;
}

void insert(HashTable* table, const char* key, int val) {
  u_int32_t hash = cal_hash(key);
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->key, key);
  node->val = val;
  node->next = table->table[hash];
  table->table[hash] = node;
}

int search(HashTable* table, const char* key, int* val) {
  u_int32_t hash = cal_hash(key);
  Node* node = table->table[hash];
  while (node) {
    if (strcmp(node->key, key) == 0) {
      *val = node->val;
      return 0;
    }
    node = node->next;
  }
  return -1;
}
