#include "IO.hpp"



int main(){
        Visitor::card vcard;
        vcard.fname = "Hau";
        vcard.lname = "Huynh";
        vcard.gender = "Male";
        vcard.status = 1;
        Visitor::nodeavl root = Visitor::newnode(1, vcard);
        std::cout << root->data.fname << '\n';
        VisitorToJson(root);







        return 0;
}
