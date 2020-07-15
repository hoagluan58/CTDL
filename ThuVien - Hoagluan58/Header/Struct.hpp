#ifndef STRUCT_HPP
#define STRUCT_HPP
#include <string>

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
}DoubledLinkedList;

void InitDoubledLinkedList(DoubledLinkedList &list){
        list.head = NULL;
        list.tail = NULL;
}

int isEmpty(DoubledLinkedList list){
        return (list.head == NULL);
}

int len(DoubledLinkedList list){
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

struct node *Make_node (abook data){
        struct node *newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        newnode->prev = NULL;
        return newnode;
}

void insertNode (DoubledLinkedList &list, abook data){
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

void delhead (DoubledLinkedList &list) //Xoa phan tu dau tien
{
        if (!isEmpty(list))
        {
                list.head = list.head->next; //Cho L tro den Node thu 2 trong danh sach
        }
}

void deltail (DoubledLinkedList &list) //Xoa phan tu dau tien
{
        if (!isEmpty(list))
        {
                list.tail = list.tail->prev;
                list.tail->next = NULL;
        }
}

void delk (DoubledLinkedList &list, int k){
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

int search (DoubledLinkedList list, abook data){
        node *ptr = list.head;
        int i=1;
        while (ptr != NULL && ptr->data.id != data.id) {
                ptr = ptr->next;
                i++;
        }
        if(ptr != NULL) return i;
        else return 0;
}

void delx (DoubledLinkedList &list, abook data){
        int l = search(list, data);
        while (l) {
                delk(list, l);
                l = search(list, data);
        }
}

}

namespace Visitor {

typedef struct {
        std::string fname;
        std::string lname;
        std::string gender;
        int status;
        Borrow::DoubledLinkedList history;
} card;

struct avlnode {
        int id;
        card data;
        struct avlnode *left;
        struct avlnode *right;
        int height;
};

typedef struct avlnode *nodeavl;

int max (int a, int b) {
        if (a > b)
                return a;
        else
                return b;
}

int height (nodeavl n){
        if (n == NULL) return 0;
        return n->height;
}

nodeavl newnode (int id, card data){
        nodeavl node = new avlnode();
        node->id = id;
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
}

nodeavl rightRotate(nodeavl y){
        nodeavl x = y->left;
        nodeavl T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        return x;
}

nodeavl leftRotate(nodeavl x)  {
        nodeavl y = x->right;
        nodeavl T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;
        return y;
}

int getbalance (nodeavl root){
        if (root == NULL) {
                return 0;
        }
        return height(root->left) - height(root->right);
}

nodeavl insert(nodeavl node, int key, card data){
        if (node == NULL)
                return(newnode(key, data));
        if (key < node->id)
                node->left = insert(node->left, key, data);
        else if (key > node->id)
                node->right = insert(node->right, key, data);
        else return node;
        node->height = 1 + max(height(node->left),
                               height(node->right));
        int balance = getbalance(node);
        if (balance > 1 && key < node->left->id)
                return rightRotate(node);
        if (balance < -1 && key > node->right->id)
                return leftRotate(node);
        if (balance > 1 && key > node->left->id) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
        }
        if (balance < -1 && key < node->right->id) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
        }
        return node;
}

}

namespace Book {
  typedef struct {
          std::string id;
          int status;
          std::string position;
  }aBook;

  struct List {
          aBook data;
          struct List *next = NULL;
  };
  typedef struct List *ListPtr;

  struct Title {
    std::string isbn;
    std::string name;
    std::string author;
    std::string genre;
    int pages;
    int years;
    int borrow;
    ListPtr BookList;
  };
  typedef struct Title *TitlePtr;
}


#endif
