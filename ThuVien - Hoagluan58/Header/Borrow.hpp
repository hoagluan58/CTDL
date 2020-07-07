#ifndef BORROW_HPP
#define BORROW_HPP

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
        if (isEmpty(list)) {
                list.head = newnode;
                list.tail = newnode;
        }
        else{
                newnode->next = list.head;
                list.head->prev = newnode;
                list.head = newnode;
        }
}

void delhead (D2L &list) //Xoa phan tu dau tien
{
        if (!isEmpty(list))
        {
                list.head = list.head->next; //Cho L tro den Node thu 2 trong danh sach
        }
}

void deltail (D2L &list) //Xoa phan tu dau tien
{
        if (!isEmpty(list))
        {
                list.tail = list.tail->prev;
                list.tail->next = NULL;
        }
}

void delk (D2L &list, int k){
        node *headptr = list.head, *tailptr;
        int i=1, l = len(list);
        if (k == 1) delhead(list);
        else {
                if (k == l) deltail(list);
                else{
                        while (headptr != NULL && i != k-1) {
                                i++;
                                headptr = headptr->next;
                        }
                        tailptr = headptr->next->next;
                        headptr->next = tailptr;
                        tailptr->prev = headptr;
                }
        }
}

int search (D2L list, abook data){
        node *ptr = list.head;
        int i=1;
        while (ptr != NULL && ptr->data.id != data.id) {
                ptr = ptr->next;
                i++;
        }
        if(ptr != NULL) return i;
        else return 0;
}

void delx (D2L &list, abook data){
        int l = search(list, data);
        while (l) {
                delk(list, l);
                l = search(list, data);
        }
}

} /* Borrow */

#endif
