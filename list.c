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
  newNode->next = list->head; // Se actualiza el puntero.
  list->head = newNode; // Se actualiza el inicio de la lista. 
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data)
{/*
  Node * newNode = createNode(data); // Se crea un nuevo nodo.

  newNode->next = list->current->next; // Se actualiza el puntero.
  list->current->next = newNode; // Se añade el nodo en la posición siguiente al nodo actual.*/
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
{/*
  void * data = list->current->data; // Se crea un auxiliar de la data del nodo a borrar.
  Node *popNode = list->current; // Se establece el nodo a borrar.

  if (list->head == popNode) // Si el nodo a borrar es el inicio de la lista.
  {
    list->head = popNode->next; // Se actualiza el inicio de la lista al siguiente nodo.
    list->current = list->head; // Se actualiza el current al inicio de la lista.
  }
  else
  {
    Node *prevNode = list->head; // Se establece un "current" auxiliar para recorrer la lista.
    while (prevNode != NULL && prevNode->next != popNode) // Mientras el current no sea NULL y el siguiente a este no sea el nodo a borrar.
      {
        prevNode =prevNode->next; // Se apunta al siguiente nodo en el "current" auxiliar.
      }
      if (prevNode != NULL) 
      {
        prevNode->next = popNode->next; // El "Current" auxiliar apunta al siguiente nodo del que se borra.
        list->current = prevNode->next; // Se actualiza el "current" original.
      }
  }
  
  free(popNode); // Se libera la memoria del nodo.
  */
  return NULL; // Se retorna el dato del nodo eliminado.
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}