#include "IO.hpp"



int main(){
        int numbook;
        BookTitlePtr book = (BookTitlePtr) malloc(sizeof(BookTitle));
        JsonToTitle(book, numbook);
        ShowBookTitle(book, numbook);
        for (int i=0 ; i<numbook; i++){
          BookToJson(book[i].name, book[i].BookList);
        }





        return 0;
}
