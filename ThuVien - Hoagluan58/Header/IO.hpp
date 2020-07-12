#ifndef IO_HPP
#define IO_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "json.hpp"
#include "Book.hpp"
#include "Visitor.hpp"
#include "Utils.hpp"

using json = nlohmann::json;

std::ostream& operator<<(std::ostream& os, const Borrow::abook& data)
{
    os << "ID: " << data.id << "\n";
    os << "Ngay muon: "
       << data.datebor.day << "/" << data.datebor.month << "/" << data.datebor.year << "\n";
    if (data.status == 1){
      os << "Return: "
         << data.dateret.day << "/" << data.dateret.month << "/" << data.dateret.year << "\n";
    }
    else if (data.status == 2){
      os << "Mat sach" << "\n";
    }
    else {
      os << "Chua den han tra sach\n";
    }

    return os;
}

void ShowConsoleCursor(bool showFlag) {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
}

void gotoxy(int x, int y) {
        SHORT sx = SHORT(x), sy = SHORT(y);
        static HANDLE h = NULL;
        if(!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD c = { sx, sy };
        SetConsoleCursorPosition(h,c);
}

int getEdge(int num, int charnum){
        return ((num-charnum)/2);
}

void getWindowsSize(int &rows, int &columns){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top +1;
}

void highLightChoose(std::string info, int y, int columns){
        int x = getEdge(columns, info.length());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 124);
        gotoxy(x, y);
        std::cout << info;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void deHighLightChoose(std::string info, int y, int columns){
        int x = getEdge(columns, info.length());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoxy(x, y);
        std::cout << info;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void printMenu(std::string Menu[], int n, int rows, int columns){
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int first = getEdge(rows, n);
        for(int i=0; i<n; i++) {
                int temp = Menu[i].length();
                temp = getEdge(columns, temp);
                gotoxy(temp, first+i*2);
                std::cout << Menu[i];
        }
}

void Menu_Box (int rows, int columns,int speed=0, int showinfo=1){
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ShowConsoleCursor(false);
        std::cout << " " << std::setfill('_') << std::setw(columns-1) << " \n";
        // Sleep(speed);
        for (int i=1; i<rows-2; i++) {
                std::cout << "||" << std::setfill(' ') << std::setw(columns-2) << "||\n";
                // Sleep(speed);
        }
        std::cout << "||" << std::setfill('_') << std::setw(columns-3) << "||";
        if (showinfo == 1) {
                gotoxy(getEdge(columns, 39), 2);
                std::cout << "Hoc Vien Cong Nghe Buu Chinh Vien Thong";
                gotoxy(getEdge(columns, 35), 3);
                std::cout << "De Tai Cuoi Ky Mon Cau Truc Du Lieu";
                gotoxy(getEdge(columns, 21), 4);
                std::cout << "GV: Luu Nguyen Ky Thu";
                gotoxy(getEdge(columns, 28), 7);
                std::cout << "CHUONG TRINH QUAN LI THU VIEN";
                gotoxy(0, 4);
                std::cout << "||" << std::setfill('_') << std::setw(columns-3) << "||";
        }
}


void Menu_Admin (){
        int pointer=0, prepointer=0, rows, columns;;
        std::string Menu[5] = {"Quan li doc gia   ",
                               "Quan li dau sach  ",
                               "Them dau sach     ",
                               "Muon tra sach     ",
                               "Thoat             "};

        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, 5);

        Menu_Box(rows, columns);
        printMenu(Menu, 5, rows, columns);

        //Read data here

        while (true) {
                int oldChoosePos = firstMenuPosition+prepointer*2;
                int newChoosePos = firstMenuPosition+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);

                while (true) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                if (pointer == 0) {
                                        //Load data
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, 5, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        //Load data
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, 5, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        //load data
                                        break;
                                }
                                else if (pointer == 2) {


                                        Menu_Box(rows, columns);
                                        printMenu(Menu, 5, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {

                                        Menu_Box(rows, columns);
                                        printMenu(Menu, 5, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 4) {
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        prepointer = pointer;
                                        pointer--;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < 4) {
                                        prepointer = pointer;
                                        pointer++;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }
                }
                Sleep(125);
        }
}

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
                for (size_t i=0; i < data.size(); i++) {
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
        for (int i = 0; i < n; i++) {
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

//Nhập xuất độc giả
void InsertVisitor(Visitor::card &x) {
    // Thiếu nhập id tự động

    std::cout << "\n Nhap ten doc gia: ";
    std::getline(std::cin, x.fname);

    fflush(stdin);
    std::cout << "\n Nhap ho doc gia: ";
    std::getline(std::cin, x.lname);

    fflush(stdin);
    std::cout << "\n Nhap gioi tinh: ";
    std::getline(std::cin, x.gender);
    x.status = true; // Thẻ được mượn sách
}

void PrintVisitor(Visitor::card x) {
    std::cout << "\n Ma the: ";
    std::cout << "\n Ten doc gia: " << x.fname;
    std::cout << "\n Ho doc gia: " << x.lname;
    std::cout << "\n Gioi tinh: " << x.gender;
    std::cout << "\n Trang thai the: " << x.status;
}
// Nhập xuất thông tin sách
void InsertBookTitle(BookTitle &x) {
    std::cout << "\n Nhap ma ISBN: ";
    std::getline(std::cin, x.isbn);

    std::cout << "\n Nhap ten sach: ";
    std::getline(std::cin, x.name);

    std::cout << "\n Nhap ten tac gia: ";
    std::getline(std::cin, x.author);

    std::cout << "\n Nhap so trang: ";
    std::getline(std::cin, x.pages);

    std::cout << "\n Nhap nam xuat ban: ";
    std::getline(std::cin, x.years);
     
    std::cout << "\n Nhap loai sach: ";
    std::getline(std::cin, x.genre);
}

void PrintBookTitle(BookTitle x) {
    std::cout << "\n Ma ISBN: " << x.isbn;
    std::cout << "\n Ten sach: " << x.name;
    std::cout << "\n Tac gia: " << x.author;
    std::cout << "\n So trang: " << x.pages;
    std::cout << "\n Nam xuat ban: " << x.years;
    std::cout << "\n Loai sach: " << x.genre;
}

#endif
