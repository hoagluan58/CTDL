#ifndef STRUCT_HPP
#define STRUCT_HPP
#include <string>
#include <ctime>



namespace Borrow {

typedef struct dt {
        int day;
        int month;
        int year;
        void getDate(){
                std::time_t now = std::time(0);
                std::tm *time = localtime(&now);
                day = time->tm_mday;
                month = time->tm_mon + 1;
                year = time->tm_year + 1900;
                return;
        }
        bool isLeap (){
                if ((year % 4 == 0) && (year % 100 != 0)) return true;
                else return false;
        }
        int daysOfmonth (int mth){
                switch (mth) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                        return 31;
                        break;
                case 4:
                case 6:
                case 9:
                case 11:
                        return 30;
                        break;
                case 2:
                        if (isLeap()) return 29;
                        else return 28;
                        break;
                }
                return 0;
        }
        int fromheadint (){
                int k = day;
                for (int i=1; i < month; i++) {
                        k += daysOfmonth(i);
                }
                return k;
        }
        int fromtailint (){
                int k = day;
                for (int i=12; i > month; i--) {
                        k += daysOfmonth(i);
                }
                return k;
        }
}date;

typedef struct bk{
        std::string id;
        date datebor = {-1,-1,-1};
        date dateret = {-1,-1,-1};
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

        bool over3 (){
                int ret;
                struct node* temp = head;
                while (temp != NULL) {
                        ret++;
                        temp = temp->next;
                }
                return ret > 3 ? true : false;
        }
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
        struct node *newnode = new struct node;
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

bool isExpire (date exdate){
        date cdate;
        cdate.getDate();
        if (cdate.year == exdate.year) {
                int k = cdate.fromheadint() - exdate.fromheadint();
                return k > 7 ? true : false;
        }
        else if (cdate.year > exdate.year) {
                int k = cdate.fromheadint() + exdate.fromtailint();
                return k > 7 ? true : false;

        }
        else {
                return false;
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

typedef struct avlnode* nodeavl;

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

nodeavl insertvst(nodeavl node, int key, card data){
        if (node == NULL)
                return(newnode(key, data));
        if (key < node->id)
                node->left = insertvst(node->left, key, data);
        else if (key > node->id)
                node->right = insertvst(node->right, key, data);
        else {
                return node;
        }
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

nodeavl minValueNode(nodeavl node)  {
        nodeavl current = node;
        while (current->left != NULL)
                current = current->left;

        return current;
}

nodeavl delnode(nodeavl root, int key)  {
        if (root == NULL)
                return root;
        if ( key < root->id )
                root->left = delnode(root->left, key);
        else if( key > root->id )
                root->right = delnode(root->right, key);
        else{
                if( (root->left == NULL) ||
                    (root->right == NULL) )  {
                        nodeavl temp = root->left ?
                                       root->left :
                                       root->right;

                        if (temp == NULL) {
                                temp = root;
                                root = NULL;
                        }
                        else
                                *root = *temp;
                        free(temp);
                }
                else
                {
                        nodeavl temp = minValueNode(root->right);
                        root->id = temp->id;
                        root->right = delnode(root->right,
                                              temp->id);
                }
        }
        if (root == NULL)
                return root;

        root->height = 1 + max(height(root->left),
                               height(root->right));

        int balance = getbalance(root);
        if (balance > 1 &&
            getbalance(root->left) >= 0)
                return rightRotate(root);
        if (balance > 1 &&
            getbalance(root->left) < 0) {
                root->left = leftRotate(root->left);
                return rightRotate(root);
        }
        if (balance < -1 &&
            getbalance(root->right) <= 0)
                return leftRotate(root);

        if (balance < -1 &&
            getbalance(root->right) > 0) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
        }

        return root;
}

bool idsearch (nodeavl root, int tofind){
        while (root != nullptr) {
                if (root->id == tofind) {
                        return true;
                }
                else if (root->id < tofind) {
                        root = root->right;
                }
                else {
                        root = root->left;
                }
        }
        return false;
}

bool idtocard (int id, card &data, nodeavl root){
        while (root != nullptr) {
                if (root->id == id) {
                        data = root->data;
                        return true;
                }
                else if (root->id < id) {
                        root = root->right;
                }
                else {
                        root = root->left;
                }
        }
        return false;
}

int countNode (nodeavl root){
        int k=0;
        while (root!=NULL) {
                k++;
                k += countNode(root->left);
                k += countNode(root->right);
        }
        return k;
}

std::string getLnamebyID (int id, nodeavl root){
        std::string out = "";
        if (root!=NULL) {
                if (root->id == id) {
                        out = root->data.lname;
                        return out;
                }
                else {
                        out = getLnamebyID(id, root->left);
                        out = getLnamebyID(id, root->right);
                }
        }
        return out;
}

std::string getNamebyLname (std::string lname, nodeavl root){
        std::string out = "";
        if (root!=NULL) {
                if (root->data.lname == lname) {
                        out = root->data.fname + " " + root->data.lname;
                        return out;
                }
                else {
                        out = getNamebyLname(lname, root->left);
                        out = getNamebyLname(lname, root->right);
                }
        }
        return out;
}

std::string getNamebyID (int id, nodeavl root){
        std::string out = "";
        if (root!=NULL) {
                if (root->id == id) {
                        out += root->data.fname + " " + root->data.lname;
                        return out;
                }
                else {
                        out += getNamebyID(id, root->left);
                        out += getNamebyID(id, root->right);
                }
        }
        return out;
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
        struct List* next;

};
typedef struct List* ListPtr;

int sizeofListPtr (ListPtr data){
    int k=0;
    while (data != NULL){
        k++;
        data = data->next;
    }
    return k;
}

struct Title {
        std::string isbn;
        std::string name;
        std::string author;
        std::string genre;
        int pages=0;
        int years=0;
        int borrow=0;
        ListPtr BookList;
};
typedef struct Title *TitlePtr;




int isExist(TitlePtr data, int datacount, std::string name){
        int cnt = 0;
        size_t k;
        for (int i=0; i < datacount; i++) {
                k = data[i].name.find(name);
                if (k != std::string::npos) {
                        cnt++;
                }
        }
        return cnt;
}

TitlePtr getBookData (TitlePtr data, int datacount, std::string name, int &cnt){
        int n = isExist(data, datacount, name);
        if (n != 0) {
                TitlePtr ret = new Title[n];
                int j=0;
                size_t k;
                for (int i=0; i < datacount; i++) {
                        k = data[i].name.find(name);
                        if (k != std::string::npos) {
                                ret[j] = data[i];
                                j++;
                        }
                }
                cnt = j;
                return ret;
        }
        return NULL;
}

ListPtr listbook (TitlePtr data, int tcount, std::string isbn){
    for (int i=0; i<tcount; i++){
        if (data[i].isbn == isbn){
            return data[i].BookList;
        }
    }
    return NULL;
}

}


#endif
