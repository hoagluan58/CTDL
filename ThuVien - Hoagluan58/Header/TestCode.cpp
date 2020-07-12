#include <iostream>
#include <fstream>
#include <iomanip>
#include "IO.hpp"



int main(){

        Borrow::DoubledLinkedList root;
        Borrow::InitDoubledLinkedList(root);
        Borrow::abook mybook =  {"kkk", {1,3,2020}, {1,4,2020}, 0};
        Borrow::insertNode(root, mybook);
        std::cout << root.head->data << '\n';






        return 0;
}
