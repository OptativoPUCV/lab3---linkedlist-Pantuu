#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node* new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* new = (List *)malloc(sizeof(List));
     return new;
}

void * firstList(List * list) {
    if (list == NULL || list->head == NULL) {
        return NULL;
    }
    void* data = list->head->data;
    list->current = list->head;
  
  
      return data; 
}

void * nextList(List * list) {
  if (list == NULL || list->current == NULL || list->current->next == NULL)
  {
    return NULL;
  }
  list->current = list->current->next;
  void* data = list->current->data;

    return data;
}

void * lastList(List * list) {
   if (list == NULL || list->tail == NULL)
  {
     return NULL;
  }
  void* data = list->tail->data;
  list->current = list->tail;
  
  return data;
}

void * prevList(List * list) {
  if (list == NULL || list->current == NULL || list->current->prev == NULL)
  {
    return NULL;
  }
  list->current = list->current->prev;
  void* data = list->current->data;
    return data;
}

void pushFront(List * list, void * data) {
  Node* newNode = createNode(data);
  if (list->head == NULL) 
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->head;
    list->head->prev = newNode;
    list->head = newNode;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node* newNode = createNode(data);
    if (list->current == list->tail) 
  {
    list->current->next = newNode;
    newNode->prev = list->current;
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->current->next;
    newNode->prev = list->current;
    list->current->next->prev = newNode;
    list->current->next = newNode;
  }
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if (list == NULL || list->current == NULL)
  {
    return NULL;
  }
  void* data = list->current->data;
  if (list->head == list->current && list->tail == list->current) 
  {
    free(list->current);
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
  }
  else if (list->head == list->current)
  {
    list->head = list->current->next;
    list->head->prev = NULL;
    free(list->current);
    list->current = list->head;
  }
  else if (list->tail == list->current)
  {
    list->tail = list->current->prev;
    list->tail->next = NULL;
    free(list->current);
    list->current = list->tail;
  }
  else
  {
    list->current->prev->next = list->current->next;
    list->current->next->prev = list->current->prev;
    Node *temp = list->current->next;
    free(list->current);
    list->current = temp;
  }
    return data;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}