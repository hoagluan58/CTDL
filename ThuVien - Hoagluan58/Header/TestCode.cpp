#include <iostream>
#include <fstream>
#include <iomanip>
#include "Borrow.hpp"

int main(){

        Borrow::DoubledLinkedList brr;
        Borrow::InitDoubledLinkedList(brr);
        Borrow::abook newbrr = {"12213", {1,4,2013}, {7, 5, 2013}, 0};
        Borrow::insertNode(brr, newbrr);






        return 0;
}