#ifndef VISITOR_HPP
#define VISITOR_HPP
#include "Borrow.hpp"

namespace Visitor {

typedef struct {
        std::string fname;
        std::string lname;
        std::string gender;
        int status;
        Borrow::DoubledLinkedList curBrring;
} card;

struct avlnode {
        int id;
        card data;
        struct avlnode *left;
        struct avlnode *right;
        int height;
};

typedef struct avlnode *nodeavl;

int max (int a, int b){
        return (a > b) ? a : b;
}

int height (nodeavl n){
        if (n == NULL) return 0;
        return n->height;
}

nodeavl newnode (int id, card data){
        nodeavl node = new struct avlnode();
        node->id = id;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
}

nodeavl rightrotate (nodeavl root){
        nodeavl x = root->left;
        nodeavl y =  x->right;

        x->right = root;
        root->left = y;

        root->height = max(height(root->left), height(root->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        return x;
}

nodeavl leftrotate (nodeavl root){
        nodeavl x = root->right;
        nodeavl y =  x->left;

        x->left = root;
        root->right = y;

        root->height = max(height(root->left), height(root->right))+1;
        x->height = max(height(x->left), height(x->right))+1;

        return x;
}

int getbalance (nodeavl root){
  if (root == NULL){
    return 0;
  }
  return height(root->left) - height(root->right);
}

nodeavl insert (nodeavl node, int id, card data){
  if (node == NULL){
    return (newnode(id, data));
  }
  if (id < node->id){
    node->left = insert(node->left, id, data);
  }
  else if (id > node->id){
    node->right = insert(node->right, id, data);
  }
  else return node;

  node->height = 1 + max(height(node->left), height(node->right));
  int balance = getbalance(node);

  //Left left rotate
  if (balance > 1 && id < node->left->id){
    return rightrotate(node);
  }
  //Right right rotate
  if  (balance < -1 && id > node->right->id){
    return leftrotate(node);
  }
  //left right rotate
  if (balance > 1 && id > node->left->id){
    node->left = leftrotate(node->left);
    return rightrotate(node);
  }
  //Right left rotate
  if (balance < -1 && id < node->right->id){
    node->right = rightrotate(node->right);
    return leftrotate(node);
  }
  return node;
}

} /* Visitor */






#endif
