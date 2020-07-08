#ifndef VISITOR_HPP
#define VISITOR_HPP
#include "Utils.hpp"

typedef struct {
        int id;
        std::string firstname;
        std::string lastname;
        std::string gender;
        int status;
        muontra *list;
}card;

struct avlnode {
        int id;
        card info;
        int height;
        struct avlnode *left, *right;
};
typedef struct avlnode* node;

int Height (node anode){
        if (anode == NULL)
                return 0;
        return anode->height;
}

int GetBalance (node anode){
        if (anode == NULL)
                return 0;
        return height(anode->left) - height(anode->right);
}

node NewNode (int id){
        node anode = new avlnode;
        anode->id = id;
        anode->left = NULL;
        anode->right = NULL;
        anode->height = 1;
        return anode;
}

void AddInfo (node point, card datain){
        point->info.id = datain.id;
        point->info.firstname = datain.firstname;
        point->info.lastname = datain.lastname;
        point->info.gender = datain.gender;
        point->info.status = 1;
}

node RightRotate (node point){
        node pleft = point->left;
        node remain = pleft->right;
        //Rotate
        pleft->right = point;
        point->left = remain;
        //Update heights
        point->height = max(height(point->left), height(point->right)) + 1;
        pLeft->height = max(height(pLeft->left), height(pLeft->right)) + 1;
        return pleft;
}

node LeftRotate (node point){
        node pright = point->right;
        node remain = pRight->left;
        // Rotate
        pright->left = point;
        point->right = remain;
        // Update heights
        point->height = max(height(point->left), height(point->right)) + 1;
        pRight->height = max(height(pRight->left), height(pRight->right)) + 1;
        return pright;
}

node insertnodewInfo (node root, int id, card info){
        //insert to tree
        if (root == NULL) {
                node leaf = newnode(id);
                leaf->info = info;
                return leaf;
        }
        if (id < root->id) {
                root->left = insertnodewInfo(root->left, id, info);
        }
        else if (id > root->id) {
                root->right = insertnodewInfo(root->right, id, info);
        }
        else {
                return root;
        }
        //Update height
        root->height = max(height(root->left), height(root->right)) + 1;
        //Get balance
        int balance = getBalance(root);
        //Rotate if unbalance
        if (balance > 1 && id < root->left->id) {
                return rightRotate(root);
        }
        if (balance > 1 && id > root->left->id) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
        }
        if (balance < -1 && id > root->right->id) {
                return leftRotate(root);
        }
        if (balance < -1 && id < root->right->id) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
        }
        return root;
}






#endif
