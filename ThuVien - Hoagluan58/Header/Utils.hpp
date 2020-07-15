#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "conio.h"
#include "json.hpp"
#include "Struct.hpp"

using json = nlohmann::json;

int countWord (std::string info){
        if (info == "") {
                return 0;
        }
        int result=1, i=0;
        while ((size_t)i < info.length()) {
                if (info[i] == ' ') {
                        result++;
                }
                i++;
        }
        return result;
}

void tofNamelName (std::string &fname, std::string &lname, std::string info){
        int count = countWord(info);
        if (count < 2) {
                return;
        }
        int i=0, k=0;
        while (k < count-1) {
                if (info[i] == ' ') {
                        k++;
                }
                fname += info[i];
                i++;
        }
        fname.pop_back();
        while ((size_t)i < info.length()) {
                lname += info[i];
                i++;
        }
        return;
}

void inorder (Visitor::nodeavl root){
        if (root != NULL) {
                inorder(root->left);
                std::cout << root->data.fname << ' ' << root->data.lname <<"\n";
                inorder(root->right);
        }
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
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

void getInput(int &pointer, int maxpointer, int x, int y, size_t max, std::string &input){
        int rows, columns, start = input.length() > 49 ? input.length()-49 : 0;
        getWindowsSize(rows, columns);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ShowConsoleCursor(true);

        std::string clear(50, ' ');
        unsigned char capture;
        size_t pos = input.length();

        gotoxy(x, y);
        std::cout << input.substr(start);

        while (true) {
                if (kbhit()) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                pointer++;
                                Sleep(125);
                                return;
                        }
                        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                pointer = -1;
                                return;
                        }
                        else if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                                std::string cclear(input.length(), ' ');
                                gotoxy(x, y);
                                std::cout << cclear;
                                if (input == "") {
                                        continue;
                                }
                                else {
                                        input.pop_back();
                                        gotoxy(x, y);
                                        std::cout << input.substr(start);
                                        pos--;
                                        gotoxy(x+pos, y);
                                        if (start > 0) {
                                                start--;
                                                gotoxy(x+48, y);
                                        }
                                        Sleep(125);
                                        continue;
                                }
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        pointer--;
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < maxpointer) {
                                        pointer++;
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                if (pos > 0) {
                                        pos--;
                                        gotoxy(x+pos, y);
                                        if (start > 0) {
                                                start--;
                                                gotoxy(x+49, y);
                                        }

                                }
                                Sleep(125);
                                continue;
                        }
                        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                if (pos < input.length()) {
                                        pos++;
                                        gotoxy(x+pos, y);
                                        if (pos > 49) {
                                                start++;
                                                gotoxy(x+49, y);
                                        }
                                }
                                Sleep(125);
                                continue;
                        }
                        else {
                                capture = getch();
                                while(kbhit()) getch();
                                if (input.length() == max) {
                                        continue;
                                }
                                else {
                                        if (isprint(capture)) {
                                                input.insert(pos, 1, capture);
                                                pos++;
                                                gotoxy(x,y);
                                                if (pos > 49) {
                                                        start++;
                                                }
                                                std::cout << input.substr(start);
                                                gotoxy(x+pos, y);
                                                if (pos > 49) {
                                                        gotoxy(x+49, y);
                                                }
                                                continue;
                                        }
                                }
                        }
                }
        }
}

void getNumInput(int &pointer, int maxpointer, int x, int y, size_t max, int &data){
        std::string input = std::to_string(data);
        int rows, columns;
        getWindowsSize(rows, columns);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        ShowConsoleCursor(true);

        std::string clear(max, ' ');
        unsigned char capture;
        size_t pos=input.length();

        gotoxy(x, y);
        std::cout << input;

        while (true) {
                if (kbhit()) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                pointer++;
                                Sleep(125);
                                data = stoi(input);
                                return;
                        }
                        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                pointer = -1;
                                data = stoi(input);
                                return;
                        }
                        else if (GetAsyncKeyState(VK_BACK) & 0x8000) {
                                if (pos-1 < 0) {
                                        continue;
                                }
                                input.erase(pos-1,1);
                                pos--;
                                gotoxy(x, y);
                                std::cout << clear;
                                gotoxy(x, y);
                                std::cout << input;
                                gotoxy(x+pos, y);
                                Sleep(125);
                                continue;
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        pointer--;
                                        data = stoi(input);
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < maxpointer) {
                                        pointer++;
                                        data = stoi(input);
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                if (pos > 0) {
                                        pos--;
                                        gotoxy(x+pos, y);
                                }
                                continue;
                        }
                        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                if (pos < input.length()) {
                                        pos++;
                                        gotoxy(x+pos, y);
                                }
                                continue;
                        }
                        else {
                                capture = getch();
                                while(kbhit()) getch();
                                if (input.length() == max) {
                                        continue;
                                }
                                else {

                                        if (isdigit(capture)) {
                                                input.insert(pos, 1, capture);
                                                pos++;
                                                gotoxy(x,y);
                                                std::cout << input;
                                                gotoxy(x+pos, y);
                                                continue;
                                        }
                                }
                        }
                }
        }
}

std::ostream& operator<<(std::ostream& os, const Borrow::abook& data){
        os << "ID: " << data.id << "\n";
        os << "Ngay muon: "
           << data.datebor.day << "/" << data.datebor.month << "/" << data.datebor.year << "\n";
        if (data.status == 1) {
                os << "Return: "
                   << data.dateret.day << "/" << data.dateret.month << "/" << data.dateret.year << "\n";
        }
        else if (data.status == 2) {
                os << "Mat sach" << "\n";
        }
        else {
                os << "Chua den han tra sach\n";
        }

        return os;
}

void InsertBookToList (Book::ListPtr *head, Book::aBook datain){
        Book::ListPtr newnode = new Book::List();
        newnode->data = datain;
        newnode->next = (*head);
        (*head) = newnode;
}

void BookToJson (std::string filename, Book::ListPtr list){
        json data;
        while(list->next != NULL) {
                data += {
                        {"id", list->data.id},
                        {"status", list->data.status},
                        {"position", list->data.position}
                };

                list = list->next;
        }
        if (data != NULL) {
                std::ofstream output("Data/Book/" + filename + ".json");
                output << std::setw(4) << data << std::endl;
        }
}

void JsonToBook (std::string filename, Book::ListPtr &list){
        json data;
        std::ifstream input(filename + ".json");
        input >> data;

        for (size_t i = 0; i < data.size(); i++) {
                Book::aBook temp;
                data[i].at("id").get_to(temp.id);
                data[i].at("position").get_to(temp.position);
                data[i].at("status").get_to(temp.status);
                InsertBookToList(&list, temp);
        }
}

void TitleToJson (Book::TitlePtr list){
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

void JsonToTitle (Book::TitlePtr &out, int &count){
        json data;
        std::ifstream infile("Data/BookTitle.json", std::ios::in);
        if (infile.is_open()) {
                infile >> data;
                infile.close();
                out = new Book::Title[data.size()];
                count = data.size();
                for (int i=0; i < count; i++) {
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
                }
        }
}

void vjson (Visitor::nodeavl root, json &data){
        if (root!= NULL) {
                vjson(root->left, data);
                Visitor::card card = root->data;
                data += {
                        {"id", root->id},
                        {"fname", card.fname},
                        {"lname", card.lname},
                        {"status", card.status},
                        {"gender", card.gender}
                };
                vjson(root->right, data);
        }
}

void VisitorToJson (Visitor::nodeavl root){
        json data;
        vjson(root, data);
        std::ofstream out("Data/Visitor.json");
        out << std::setw(4) << data;
        out.close();
}

Visitor::nodeavl JsonToVisitor (){
        Visitor::nodeavl root = NULL;
        std::ifstream inp("Data/Visitor.json");
        Visitor::card vcard;
        int vid = 0;
        json data;
        inp >> data;
        for (size_t i = 0; i < data.size(); i++) {
                data[i].at("fname").get_to(vcard.fname);
                data[i].at("lname").get_to(vcard.lname);
                data[i].at("gender").get_to(vcard.gender);
                data[i].at("status").get_to(vcard.status);
                data[i].at("id").get_to(vid);
                root = Visitor::insert(root, vid, vcard);
        }
        return root;
}

std::string strtolower (std::string input){
        std::string result;

        for (size_t i=0; i < input.length(); i++) {
                result += tolower(input[i]);
        }
        return result;
}

int maxid(Visitor::nodeavl root){
        Visitor::nodeavl p=root;
        if (root != NULL) {
                while(p->right != NULL) {
                        p = p->right;
                }
                return p->id;
        }
        else{
                return 0;
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


#endif
