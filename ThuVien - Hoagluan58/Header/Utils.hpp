#ifndef UTILS_HPP
#define UTILS_HPP
#include "book.hpp"


void InsertBookToList (ListOfBookPtr *head, Book datain){
        ListOfBookPtr newnode = new ListOfBook();
        newnode->data = datain;
        newnode->next = (*head);
        (*head) = newnode;
}




#endif
