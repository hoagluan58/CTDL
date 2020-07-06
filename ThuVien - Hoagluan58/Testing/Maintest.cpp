#include <iostream>
#include <fstream>
#include <iomanip>
#include "IO.hpp"
#include "Utils.hpp"

int main(){

        BookTitlePtr list;
        JsonToTitle(list);
        ShowBookTitle(list, sizeof(list));






        return 0;
}
