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
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList()
{
  List* list = (List *) malloc(sizeof(List)); // Se inicializa la lista.
  return list;
}

void * firstList(List * list)
{
  if (list == NULL || list->head == NULL)
  {
    return NULL; // La lista no tiene elementos.
  }
  
  list->current = list->head; // Se modifica el current al inicio de la lista.
  return (list->current->data); // Se retorna el dato del current.
}

void * nextList(List * list)
{
  if (list == NULL || list->current == NULL || list->current->next == NULL)
  {
    return NULL; // No hay siguiente elemento.
  }
  
  list->current = list->current->next; // Se mueve el current al siguiente nodo.
  return (list->current->data); // Se retorna el dato del current.
  return NULL;
}

void * lastList(List * list)
{
  if (list->head == NULL)
  {
    return NULL; // No hay lista.
  }
  
  list->current = list->tail; // Se modifica el current al final de la lista.
  return (list->current->data); // Se retorna el dato del current.
}

void * prevList(List * list)
{
  if (list == NULL || list->current == NULL || list->current->prev == NULL)
  {
    return NULL; // No hay elemento anterior.
  }
  
  list->current = list->current->prev; // Se mueve el current al nodo anterior.
  return (list->current->data); // Se retorna el dato del current.
}

void pushFront(List * list, void * data) 
{
  Node * newNode = createNode(data); // Se crea un nuevo nodo y se guarda su información.

  if (list->head == NULL)
  {
    list->head = newNode; // Se establece el nodo tanto al inicio como al final de la lista.
    list->tail = newNode;
  }
  else
  {
    newNode->next = list->head; // El nodo siguiente al nuevo es la cabeza actual.
    list->head->prev = newNode; // La cabeza actual tiene como previo al nuevo nodo.
    list->head = newNode; // Se actualiza la cabeza al nuevo nodo.
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data)
{
  Node * newNode = createNode(data); // Se crea un nuevo nodo.
  newNode->prev = list->current; // El nodo anterior del nuevo nodo es el current actual.
  newNode->next = list->current->next; // El nodo siguiento del nuevo nodo es el siguiente al current actual.

  if (list->current->next != NULL) // Si el siguiente nodo al actual no es NULO
  { // Entonces
    list->current->next->prev = newNode; // El nodo previo del siguiente nodo del current, apunta el nuevo nodo.
  }
  list->current->next = newNode; // El nodo siguiente al current apunta al nuevo nodo.

  if (list->current == list->tail) // Si el current es el elemento final de la lista
  { // Entonces
    list->tail = newNode; // El final de la lista es el nuevo nodo.
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

void * popCurrent(List * list)
{
  void * data = list->current->data; // Se crea un auxiliar de la data del nodo a borrar.
  Node *popNode = list->current; // Se establece el nodo a borrar.

  if (popNode->prev != NULL) // Si el nodo a eliminar tiene un nodo antes
  { // Entonces
    popNode->prev->next = popNode->next; // Se actualiza el nodo anterior para que apunte al nodo siguiente del cual se va a eliminar.
  }
  
  if (popNode->next != NULL) // Si el nodo a eliminar tiene un nodo después
  { // Entonces
    popNode->next->prev = popNode->prev; // Se actualiza el siguiente nodo para que apunte al nodo anterior del cual se va a eliminar.
  }
  
  if (popNode == list->head) // Si el nodo a eliminar es el primero de la lista
  { // Entonces
    list->head = popNode->next; // El inicio de la lista apunta al siguiente.
  }

  if (popNode == list->tail) // Si el nodo a eliminar es el último de la lista
  { // Entonces
    list->tail = popNode->prev; // El final de la lista apunta al anterior.
  }
  
  free(popNode); // Se libera la memoria del nodo.
  return data; // Se retorna el dato eliminado.
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}