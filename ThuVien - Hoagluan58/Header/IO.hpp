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
                                        if (isalnum(capture)) {
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

int Menu_Add_Card (){
        const int menu_count = 5;
        int ID_Check=0, Name_check=0, Gender_check=0, Pass_check=0;
        int pointer=1, prepointer=1, rows, columns, first;
        getWindowsSize(rows, columns);

        Visitor::card newCard;
        std::string Menu[menu_count] = {"Ma the       :                                                    |",
                                        "Ho va ten    :                                                    |",
                                        "Gioi tinh    :                                                    |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};
        std::string name_temp;

        getWindowsSize(rows, columns);

        //tinh khoang trong 2 ben
        int edge = getEdge(columns, 67);

        //tinh vi tri in dau tien
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns, 0);
        printMenu(Menu, menu_count, rows, columns);
        gotoxy(edge+67, first+2);
        std::cout << "XX";
        gotoxy(edge+67, first+4);
        std::cout << "XX";


        while (true) {

                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                gotoxy(edge+15, first);
                gotoxy(edge+15, first+2);
                std::cout << name_temp;
                gotoxy(edge+15, first+4);
                gotoxy(edge+15, first+6);

                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return 0;
                        }

                        if (pointer == -1) {
                                return 0;
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                getInput(pointer, 5, edge+15, first+2, 50, name_temp);

                                if (1) {
                                        Name_check = 1;
                                        gotoxy(edge+67, first+2);
                                        std::cout << "OK";
                                }
                                else {
                                        gotoxy(edge+67, first+2);
                                        Name_check = 0;
                                        std::cout << "XX";
                                }
                                break;
                        }
                        else if (pointer == 2) {
                                prepointer = 2;
                                if (1) {
                                        Gender_check = 1;
                                        gotoxy(edge+67, first+4);
                                        std::cout << "OK";
                                }
                                else {
                                        gotoxy(edge+67, first+4);
                                        Gender_check = 0;
                                        std::cout << "XX";
                                }
                                break;
                        }
                        else if (pointer == 3) {
                                prepointer = 3;
                                if (1) {
                                        Pass_check = 1;
                                        gotoxy(edge+67, first+6);
                                        std::cout << "OK";
                                }
                                else {
                                        gotoxy(edge+67, first+6);
                                        Pass_check = 0;
                                        std::cout << "XX";
                                }
                                break;

                        }
                        else if (pointer == 4) {
                                prepointer = 4;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        if (ID_Check && Name_check && Gender_check && Pass_check) {
                                                int return_pointer = 0;
                                                Menu_Box(rows, columns, 0, 0);
                                                gotoxy(columns/2-12, rows/2);
                                                std::cout << "Tiep tuc them sinh vien?";
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                                                gotoxy(columns/2-4, rows/2+1);
                                                std::cout << "Tiep tuc";
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                                gotoxy(columns/2-4, rows/2+2);
                                                std::cout << "Thoat";
                                                Sleep(125);
                                                while (true) {
                                                        if (return_pointer == 0) {
                                                                if(GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                                                        gotoxy(columns/2-4, rows/2+1);
                                                                        std::cout << "Tiep tuc";
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                                                                        gotoxy(columns/2-4, rows/2+2);
                                                                        std::cout << "Thoat";
                                                                        return_pointer++;
                                                                        Sleep(125);
                                                                        continue;
                                                                }
                                                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                                                        Sleep(125);
                                                                        return 1;
                                                                }
                                                        }
                                                        else {
                                                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                                                                        gotoxy(columns/2-4, rows/2+1);
                                                                        std::cout << "Tiep tuc";
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                                                        gotoxy(columns/2-4, rows/2+2);
                                                                        std::cout << "Thoat";
                                                                        return_pointer--;
                                                                        Sleep(125);
                                                                        continue;
                                                                }
                                                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                                                        Sleep(125);
                                                                        return 0;
                                                                }
                                                        }
                                                }
                                        }
                                        break;
                                }
                        }
                        else if (pointer == 5) {
                                prepointer = 5;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        Sleep(125);
                                        return 0;
                                }
                        }

                }
                Sleep(125);
        }
}

void Menu_Visitor (){
        const int menu_count = 5;
        int pointer=0, prepointer=0, rows, columns;;
        std::string Menu[menu_count] = {"Tao the thu vien  ",
                                        "Thay doi thong tin",
                                        "Huy the thu vien  ",
                                        "Sach muon qua han ",
                                        "Thoat             "};

        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, menu_count);

        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        //Read data here

        while (true) {
                int oldChoosePos = firstMenuPosition+prepointer*2;
                int newChoosePos = firstMenuPosition+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);

                while (true) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                if (pointer == 0) {
                                        Menu_Add_Card();
                                        //Load data
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        //Load data
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        //load data
                                        break;
                                }
                                else if (pointer == 2) {


                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {


                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
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

void Menu_Book (){
        const int menu_count = 4;
        int pointer=0, prepointer=0, rows, columns;;
        std::string Menu[menu_count] = {"Them dau sach     ",
                                        "Danh muc sach     ",
                                        "Thoat             "};

        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, menu_count);

        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

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
                                        Menu_Visitor();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 2) {
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {
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
                                if (pointer < 3) {
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

void Menu_Borrow (){
        const int menu_count = 4;
        int pointer=0, prepointer=0, rows, columns;;
        std::string Menu[menu_count] = {"Sach dang muon  ",
                                        "Tra sach        ",
                                        "Tim sach        ",
                                        "Thoat           "};

        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, menu_count);

        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

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
                                        Menu_Visitor();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 2) {
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {
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
                                if (pointer < 3) {
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

void Menu_Admin (){
        const int menu_count = 4;
        int pointer=0, prepointer=0, rows, columns;;
        std::string Menu[menu_count] = {"Quan li doc gia   ",
                                        "Quan li dau sach  ",
                                        "Muon tra sach     ",
                                        "Thoat             "};

        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, menu_count);

        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

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
                                        Menu_Visitor();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        Menu_Book();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 2) {
                                        Menu_Borrow();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {
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
                                if (pointer < 3) {
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

void ShowBookList (ListOfBookPtr book){
        while (book->next != NULL) {
                std::cout << "ID: " << book->data.id << ", ";
                std::cout << "Status: " << book->data.status << ", ";
                std::cout << "Position: " << book->data.position << ".\n";
                book = book->next;
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
        if (data != NULL) {
                std::ofstream output("Data/Book/" + filename + ".json");
                output << std::setw(4) << data << std::endl;
        }
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

void JsonToTitle (BookTitlePtr &out, int &count){
        json data;
        std::ifstream infile("Data/BookTitle.json", std::ios::in);
        if (infile.is_open()) {
                infile >> data;
                infile.close();
                out = new BookTitle[data.size()];
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
/* void InsertBookTitle(BookTitle &x) {
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
 */
void PrintBookTitle(BookTitle x) {
        std::cout << "\n Ma ISBN: " << x.isbn;
        std::cout << "\n Ten sach: " << x.name;
        std::cout << "\n Tac gia: " << x.author;
        std::cout << "\n So trang: " << x.pages;
        std::cout << "\n Nam xuat ban: " << x.years;
        std::cout << "\n Loai sach: " << x.genre;
}

#endif
