#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include "conio.h"
#include "json.hpp"
#include "Struct.hpp"
#include <algorithm>


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

void highLightChoose(std::string info, int y, int columns, int left=0){
        int x;
        left == 1 ? x = 5 : x = getEdge(columns, info.length());
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
        gotoxy(x, y);
        std::cout << info;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void deHighLightChoose(std::string info, int y, int columns, int left=0){
        int x;
        left == 1 ? x = 5 : x = getEdge(columns, info.length());
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

void getInput(int &pointer, int maxpointer, int x, int y, size_t max, std::string &input, int color=240){
        int rows, columns, start = input.length() > 49 ? input.length()-49 : 0;
        getWindowsSize(rows, columns);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
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
                                        Sleep(120);
                                        return;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < maxpointer) {
                                        pointer++;
                                        data = stoi(input);
                                        Sleep(125);
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
        while(list != NULL) {
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
        list = new Book::List();
        json data;
        std::ifstream input("Data/Book/" + filename + ".json");
        input >> data;

        for (size_t i = 0; i < data.size(); i++) {
                Book::aBook temp;
                data[i].at("id").get_to(temp.id);
                data[i].at("position").get_to(temp.position);
                data[i].at("status").get_to(temp.status);
                InsertBookToList(&list, temp);
        }
}

void TitleToJson (Book::TitlePtr title, int titlecount){
        json data;
        for (size_t i = 0; i < titlecount; i++) {
                data += {
                        {"isbn", title[i].isbn},
                        {"name", title[i].name},
                        {"author", title[i].author},
                        {"pages", title[i].pages},
                        {"years", title[i].pages},
                        {"genre", title[i].genre},
                        {"borrow", title[i].borrow}
                };
        }
        std::ofstream output("Data/BookTitle.json");
        if (output.is_open()) {
                output << std::setw(4) << data << std::endl;
                output.close();
        }
}

json BorrowToJson (Borrow::DoubledLinkedList lst){
        json data;
        Borrow::node *head = lst.head;
        while(head != NULL) {
                data += {
                        {"bID", head->data.id},
                        {"bday", head->data.datebor.day},
                        {"bmonth", head->data.datebor.month},
                        {"byear", head->data.datebor.year},
                        {"rday", head->data.dateret.day},
                        {"rmonth", head->data.dateret.month},
                        {"ryear", head->data.dateret.year},
                        {"status", head->data.status}
                };
                head = head->next;
        }
        return data;
}

void JsonToBorrow (Borrow::DoubledLinkedList &ls, json data){
        for (size_t i = 0; i < data.size(); i++) {
                Borrow::abook temp;
                data[i].at("bID").get_to(temp.id);
                data[i].at("bday").get_to(temp.datebor.day);
                data[i].at("bmonth").get_to(temp.datebor.month);
                data[i].at("byear").get_to(temp.datebor.year);
                data[i].at("rday").get_to(temp.dateret.day);
                data[i].at("rmonth").get_to(temp.dateret.month);
                data[i].at("ryear").get_to(temp.dateret.year);
                data[i].at("status").get_to(temp.status);
                Borrow::insertNode(ls, temp);
        }
}

void JsonToTitle (Book::TitlePtr &out, int &count){
        json data;
        std::ifstream infile("Data/BookTitle.json", std::ios::in);
        if (infile.peek() != std::ifstream::traits_type::eof()) {
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
                        data[i].at("borrow").get_to(out[i].borrow);
                        std::ifstream bookdata("Data/Book/" + out[i].name + ".json", std::ios::in);
                        if (bookdata.is_open()) {
                                bookdata.close();
                                JsonToBook(out[i].name, out[i].BookList);

                        }
                }
        }
        else {
                out = NULL;
        }
}

void vjson (Visitor::nodeavl root, json &data){
        if (root!= NULL) {
                vjson(root->left, data);
                Visitor::card card = root->data;
                json bdata = BorrowToJson(root->data.history);
                data += {
                        {"id", root->id},
                        {"namef", card.fname},
                        {"namel", card.lname},
                        {"status", card.status},
                        {"gender", card.gender},
                        {"book", bdata}
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
        if (inp.is_open()) {
                inp >> data;
                for (size_t i = 0; i < data.size(); i++) {
                        data[i].at("namef").get_to(vcard.fname);
                        data[i].at("namel").get_to(vcard.lname);
                        data[i].at("gender").get_to(vcard.gender);
                        data[i].at("status").get_to(vcard.status);
                        data[i].at("id").get_to(vid);
                        if (!data[i].at("book").empty()) {
                            Borrow::InitDoubledLinkedList(vcard.history);
                                JsonToBorrow(vcard.history, data[i].at("book"));
                        }
                        else {
                               Borrow::InitDoubledLinkedList(vcard.history);
                        }
                        root = Visitor::insertvst(root, vid, vcard);
                }
        }
        return root;
}

std::vector<int> getCID (Visitor::nodeavl root){
        std::vector<int> out;
        if (root!=NULL) {
                out.push_back(root->id);
                std::vector<int> left = getCID(root->left);
                std::vector<int> right = getCID(root->right);
                out.insert(out.end(), left.begin(), left.end());
                out.insert(out.end(), right.begin(), right.end());
        }
        return out;
}

std::vector<std::string> getName (std::vector<int> CID, Visitor::nodeavl root, int swid){
        std::vector<std::string> out;
        if (swid) {
                for (size_t i=0; i<CID.size(); i++) {
                        out.push_back(Visitor::getNamebyID(CID[i], root) + " | CID: " + std::to_string(CID[i]));
                }
        }
        else {
                std::vector<std::string> temp;
                for (size_t i=0; i<CID.size(); i++) {
                        temp.push_back(Visitor::getLnamebyID(CID[i], root));
                }
                std::sort(temp.begin(), temp.end());
                for (size_t i=0; i<CID.size(); i++) {
                        out.push_back(Visitor::getNamebyLname(temp[i], root));
                }
        }
        return out;
}

void getNamewID (std::vector<std::string> &name, std::vector<int> &id, Visitor::nodeavl root){
        if (root != NULL) {
                id.push_back(root->id);
                name.push_back(root->data.lname);
                getNamewID(name, id, root->left);
                getNamewID(name, id, root->right);
        }
}

void gName (std::vector<std::string> &name, std::vector<std::string> &namebyid, Visitor::nodeavl root){
        std::vector<int> tempid;
        std::vector<std::string> tempname;
        getNamewID(tempname, tempid, root);
        int n = tempid.size();
        for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n-i-1; j++) {
                        if (tempid[j] > tempid[j+1]) {
                                int temp;
                                temp = tempid[j];
                                tempid[j] = tempid[j+1];
                                tempid[j+1] = temp;
                                std::string tmp;
                                tmp = tempname[j];
                                tempname[j] = tempname[j+1];
                                tempname[j+1] = tmp;
                        }
                }
        }

        for (int i=0; i<n; i++) {
                namebyid.push_back(Visitor::getNamebyID(tempid[i], root) + "| CID: " + std::to_string(tempid[i]));
        }


        for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < n-i-1; j++) {
                        if (tempname[j] > tempname[j+1]) {
                                int temp;
                                temp = tempid[j];
                                tempid[j] = tempid[j+1];
                                tempid[j+1] = temp;
                                std::string tmp;
                                tmp = tempname[j];
                                tempname[j] = tempname[j+1];
                                tempname[j+1] = tmp;
                        }
                }
        }
        for (int i=0; i<n; i++) {
                name.push_back(Visitor::getNamebyID(tempid[i], root) + "| CID: " + std::to_string(tempid[i]));
        }

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

void Menu_Box (int rows, int columns, std::string info = "CHUONG TRINH QUAN LI THU VIEN", int speed=0, int showinfo=1){
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
                gotoxy(getEdge(columns, info.length()), 4);
                std::cout << "GV: Luu Nguyen Ky Thu";
                gotoxy(getEdge(columns, 28), 6);
                std::cout << info;
                gotoxy(0, 4);
                std::cout << "||" << std::setfill('_') << std::setw(columns-3) << "||";
        }
}

void sortTitlebyName (Book::TitlePtr &book, int head, int tail){
        Book::Title temp;
        for (int i=head; i < tail-1; i++) {
                for (int j=head; j < tail-i-1; j++) {
                        if (book[j].name[0] > book[j+1].name[0]) {
                                temp = book[j];
                                book[j] = book[j+1];
                                book[j+1] = temp;
                        }
                }
        }
}

void sortTitlebyGenre (Book::TitlePtr &book, int n){
        Book::Title temp;
        int p = 0;
        for (int i=0; i < n-1; i++) {
                for (int j=0; j < n-i-1; j++) {
                        if (book[j].genre[0] > book[j+1].genre[0]) {
                                temp = book[j];
                                book[j] = book[j+1];
                                book[j+1] = temp;
                        }
                }
        }

        for (int i=0; i < n-1; i++) {
                if (book[i].genre != book[i+1].genre) {
                        sortTitlebyName(book, p, i);
                        p = i+1;
                }
        }
}

void TitleToStr (std::string (&data)[10], Book::TitlePtr book, int n, int page){
        sortTitlebyGenre(book, n);
        int k = n - page*10;
        for (int i=0; i<10; i++) {
                int ptr = i + page*10;
                if (i < k) {
                        data[i] = "Gerne: " + book[ptr].genre + "| " + book[ptr].name + "| Author: " + book[ptr].author;
                }
                else {
                        data[i] = "";
                }
        }
        return;
}

void FoundTitleToStr (std::string (&data)[10], Book::TitlePtr book, int n, int page){
        sortTitlebyGenre(book, n);
        int k = n - page*10;
        for (int i=0; i<10; i++) {
                int ptr = i + page*10;
                if (i < k) {
                        data[i] = "ISBN: " + book[ptr].isbn + "| " + book[ptr].name + "| Author: " + book[ptr].author + "| Year: " + std::to_string(book[ptr].years) + "| Genre: " + book[ptr].genre;
                }
                else {
                        data[i] = "";
                }
        }
        return;
}

void foundBook (std::string (&data)[10], std::string (&id)[10], Book::ListPtr book, int page){
        Book::ListPtr temp = book;
        int i=0;
        int k = Book::sizeofListPtr(book);
        while (i < (page*10)){
            if ((i >= page*10 - 10) && (i%10 < k-1)){
                if (temp != NULL){
                    id[i%10] = temp->data.id;
                    data[i%10] = "ID: " + temp->data.id + "| Status: " + std::to_string(temp->data.status) + "| Position: " + temp->data.position;
                }
                else {
                    data[i%10] = "";
                    id[i%10] = "";
                }
                i++;
                temp = temp->next;

             }
            else if (page > 1){
                i++;
                temp = temp->next;
            }
            else {
                i++;
            }
        }

        return;
}

void printTitle (std::string Menu[], int n){
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int first = 8;
        for(int i=0; i<n; i++) {
                gotoxy(5, first+i*2);
                std::cout << Menu[i];
        }
}

void clearpage (std::string Menu[], int n){
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int first = 8;
        for(int i=0; i<n; i++) {
                std::string blks (Menu[i].length(), ' ');
                gotoxy(5, first+i*2);
                std::cout << blks;
        }
}

void sortTitle (Book::TitlePtr &data, int n){
        Book::Title temp;
        for (int i=0; i < n-1; i++) {
                for (int j=0; j < n-i-1; j++) {
                        if (data[j].borrow < data[j+1].borrow) {
                                temp = data[j];
                                data[j] = data[j+1];
                                data[j+1] = temp;
                        }
                }
        }
        return;
}

void TopTitle (){
        int titlecount, first = 12;
        Book::TitlePtr title;
        JsonToTitle(title, titlecount);
        if ((title[0].name == "") || (title == NULL)) {
                return;
        }
        sortTitle(title, titlecount);
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        gotoxy(12, first-2);
        std::cout << "<Sach muon nhieu>";
        gotoxy(90, first-2);
        std::cout << "<Sach muon nhieu>";

        int k, m;
        titlecount > 10 ? k=10 : k=titlecount;
        titlecount > 5 ? m=5 : m=titlecount;
        for (int i=0; i<m; i++) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i%2) + 2);
                gotoxy(10, first + i*2);
                try {
                        if (title[i].name.length() > 20) {
                                std::cout << i+2 << ". " << title[i].name.substr(0, 17) << "...";
                        }
                        else {
                                std::cout << i+2 << ". " << title[i].name;
                        }

                }
                catch (...) {
                        break;
                }
        }
        if (k > 5) {
                for (int i=5; i < k; i++) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3 - (i%2));
                        gotoxy(88, first + (i-5)*2);
                        if (title[i+5].name.length() > 20) {
                                std::cout << i << ". " << title[i].name.substr(0, 17) << "...";
                        }
                        else {
                                std::cout << i << ". " << title[i].name;
                        }
                }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void printCard (std::vector<std::string> name){
        ShowConsoleCursor(false);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        int first = 8;
        int n;
        name.size() >= 10 ? n = 10 : n = name.size();
        for(int i=0; i < n; i++) {
                gotoxy(5, first+i*2);
                std::cout << name[i];
        }
}

void expireCheck(Visitor::nodeavl root){
        Borrow::date cdate, bdate;
        cdate.getDate();
        if (root != NULL) {
                if (root->data.history.head != NULL) {
                        bdate = root->data.history.head->data.datebor;
                        if (Borrow::isExpire(bdate)) {
                                root->data.status = 0;
                        }
                        else if (root->data.history.over3()) {
                                root->data.status = 0;
                        }
                }
                expireCheck(root->left);
                expireCheck(root->right);
        }
}

void regcard (Visitor::nodeavl &root, int cid, std::string bid){
    if (root != NULL){
        regcard(root->left, cid, bid);
        if ((root->id == cid) && (root->data.status == 1)){
                Borrow::abook book;
                book.id = bid;
                book.status = 0;
                book.datebor.getDate();
                Borrow::insertNode(root->data.history, book);
            return;
        }
        regcard(root->right, cid, bid);
    }
}

void regbk (Book::ListPtr &book, std::string bid){
        if (book != NULL){
            if (book->data.id == bid){
                book->data.status = 1;
                return;
            }
            regbk(book->next, bid);
        }
}

void regBorrow (Visitor::nodeavl &root, int cid, Book::ListPtr &book, std::string bid){
    regcard(root, cid, bid);
    regbk(book, bid);
    VisitorToJson(root);
}

#endif
