#ifndef IO_HPP
#define IO_HPP

#include "Utils.hpp"

int Menu_Add_Card (){
        int menu_count = 5, Name_check=0, Gender_check=0, ID=0;
        int pointer=0, prepointer=0, rows, columns, first;
        getWindowsSize(rows, columns);
        Visitor::nodeavl root = JsonToVisitor();
        ID = maxid(root) + 1;
        Visitor::card vcard;
        vcard.status = 1;

        std::string Menu[menu_count] = {"Ma the       :                                                    |",
                                        "Ho va ten    :                                                    |",
                                        "Gioi tinh    :                                                    |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};
        std::string name_temp;

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, 6);
        Menu_Box(rows, columns, 0);
        printMenu(Menu, 6, rows, columns);

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
                std::cout << ID;
                gotoxy(edge+15, first+2);
                std::cout << name_temp;

                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return 0;
                        }

                        if (pointer == -1) {
                                return 0;
                        }
                        else if (pointer == 0) {
                                prepointer = 0;
                                if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                getInput(pointer, 5, edge+15, first+2, 50, name_temp);
                                tofNamelName(vcard.fname, vcard.lname, name_temp);
                                if (vcard.fname != "" && vcard.lname != "") {
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
                                getInput(pointer, 5, edge+15, first+4, 50, vcard.gender);
                                if (strtolower(vcard.gender) == "nam"
                                    || strtolower(vcard.gender) == "nu") {
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
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        if (Name_check && Gender_check) {
                                                insert(root, ID, vcard);
                                                VisitorToJson(root);
                                                int return_pointer = 0;
                                                Menu_Box(rows, columns, 0, 0);
                                                gotoxy(columns/2-12, rows/2);
                                                std::cout << "Tiep tuc tao the moi?";
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
                        else if (pointer == 4) {
                                prepointer = 4;
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

void Menu (){
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

void ShowBookList (Book::ListPtr book){
        while (book->next != NULL) {
                std::cout << "ID: " << book->data.id << ", ";
                std::cout << "Status: " << book->data.status << ", ";
                std::cout << "Position: " << book->data.position << ".\n";
                book = book->next;
        }
}

void ShowBookTitle (Book::TitlePtr data, int n){
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
void PrintBookTitle(Book::Title x) {
        std::cout << "\n Ma ISBN: " << x.isbn;
        std::cout << "\n Ten sach: " << x.name;
        std::cout << "\n Tac gia: " << x.author;
        std::cout << "\n So trang: " << x.pages;
        std::cout << "\n Nam xuat ban: " << x.years;
        std::cout << "\n Loai sach: " << x.genre;
}

#endif
