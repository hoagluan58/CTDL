#ifndef BORROW_HPP
#define BORROW_HPP
#include "Utils.hpp"

namespace Borrow {

typedef struct {
        int day;
        int month;
        int year;
}date;

typedef struct {
        std::string id;
        date datebor;
        date dateret;
        int status;
}abook;

struct node {
        abook data;
        struct node *prev;
        struct node *next;
};

typedef struct {
        struct node *head;
        struct node *tail;
} D2L;

void InitD2L(D2L &list){
        list.head = NULL;
        list.tail = NULL;
}

int isEmpty(D2L list){
        return (list.head == NULL);
}

int len(D2L list){
        node *headptr = list.head, *tailptr = list.tail;
        int i=0;
        if (headptr != NULL) i = 1;
        while (headptr != NULL) {
                if (headptr == tailptr) break;
                headptr = headptr->next;
                i++;
                if (headptr == tailptr) break;
                tailptr = tailptr->prev;
                i++;
        }
        return i;
}

node *Make_node (abook data){
  node *newnode = (node *) malloc (sizeof(node));
  newnode->data = data;
  newnode->next = NULL;
  newnode->prev = NULL;
  return newnode;
}

void insertNode (D2L &list, abook data){
  node *newnode;
  newnode = Make_node(data);
  if (isEmpty(list)){
    list.head = newnode;
    list.tail = newnode;
  }
  else{
    newnode->next = list.head;
    list.head->prev = newnode;
    list.head = newnode;
  }
}

void delK(D2L &list, abook &data, int k){
  
}


} /* Borrow */

#endif
