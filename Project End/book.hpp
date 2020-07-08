#ifndef BOOK_HPP
#define BOOK_HPP
#include "json.hpp"

using json = nlohmann::json;

typedef struct {
        std::string id;
        int status;
        std::string position;
}Book;

struct ListOfBook {
        Book data;
        struct ListOfBook *next = NULL;
};
typedef struct ListOfBook *ListOfBookPtr;

struct BookTitle {
  std::string isbn;
  std::string name;
  std::string author;
  int pages;
  int years;
  std::string genre;
  ListOfBookPtr BookList = new ListOfBook;
};
typedef struct BookTitle *BookTitlePtr;



#endif
