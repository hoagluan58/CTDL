#ifndef IO_HPP
#define IO_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include "json.hpp"
#include "book.hpp"
#include "Utils.hpp"

using json = nlohmann::json;


void BookToJson (std::string filename, ListOfBookPtr list){
        json data;
        while(list->next != NULL) {
                data += {
                        {"id", list->data.id},
                        {"status", list->data.status},
                        {"position", list->data.position}
                };
                list = list->next;
        }
        std::ofstream output(filename + ".json");
        output << std::setw(4) << data << std::endl;
}

void JsonToBook (std::string filename, ListOfBookPtr &list){
      json data;
      std::ifstream input(filename + ".json");
      input >> data;

      for (size_t i = 0; i < data.size(); i++) {
          Book temp;
          data[i].at("id").get_to(temp.id);
          data[i].at("position").get_to(temp.position);
          data[i].at("status").get_to(temp.status);
          InsertBookToList(&list, temp);
      }
}

void ShowBookList (ListOfBookPtr book){
  while (book->next != NULL) {
    std::cout << "ID: " << book->data.id << ", ";
    std::cout << "Status: " << book->data.status << ", ";
    std::cout << "Position: " << book->data.position << ".\n";
    book = book->next;
  }
}

void TitleToJson (BookTitlePtr list){
  json data;
  for (size_t i = 0; i < sizeof(list); i++) {
    data += {
      {"isbn", list[i].isbn},
      {"name", list[i].name},
      {"author", list[i].author},
      {"pages", list[i].pages},
      {"years", list[i].pages},
      {"genre", list[i].genre}
    };
  }
  std::ofstream output("BookTitle.json");
  if (output.is_open()) {
    output << std::setw(4) << data << std::endl;
    output.close();
  }
}

void JsonToTitle (BookTitlePtr &out){
  json data;
  std::ifstream infile("BookTitle.json", std::ios::in);
  if (infile.is_open()) {
    infile >> data;
    infile.close();
    out = new BookTitle[data.size()];
    for (size_t i=0; i < data.size(); i++){
      data[i].at("isbn").get_to(out[i].isbn);
      data[i].at("name").get_to(out[i].name);
      data[i].at("author").get_to(out[i].author);
      data[i].at("pages").get_to(out[i].pages);
      data[i].at("years").get_to(out[i].years);
      data[i].at("genre").get_to(out[i].genre);
      std::ifstream bookdata(out[i].name + ".json", std::ios::in);
      if (bookdata.is_open()) {
        json book;
        bookdata >> book;
        JsonToBook(out[i].name, out[i].BookList);
        bookdata.close();
      }
      else {
        std::cerr << "Unable to open file\n";
      }
    }
  }
  else {
    std::cerr << "Unable to open file\n";
  }
}

void ShowBookTitle (BookTitlePtr data, int n){
  for (size_t i = 0; i < n; i++) {
    std::cout << "ISBN: " << data[i].isbn << '\n';
    std::cout << "Name: " << data[i].name << '\n';
    std::cout << "Author: " << data[i].author << '\n';
    std::cout << "Pages: " << data[i].pages << '\n';
    std::cout << "Years: " << data[i].years << '\n';
    std::cout << "Genre: " << data[i].genre << '\n';
    std::cout << "_________________________________________" << '\n';
    ShowBookList(data[i].BookList);
    std::cout << "_________________________________________" << '\n';
  }
}

#endif
