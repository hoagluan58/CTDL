#ifndef IO_HPP
#define IO_HPP

#include "Utils.hpp"

//void Expire_List (){
//    int page=0, cardcount=0, sortbyid=1;
//    int pointer=0, prepointer=0, rows, columns;
//    Visitor::nodeavl root = JsonToVisitor();
//    getWindowsSize(rows, columns);
//    Menu_Box(rows, columns, "SACH MUON QUA HAN");
//
//    while (true) {
//
//                int oldChoosePos = 8+prepointer*2;
//                int newChoosePos = 8+pointer*2;
//                deHighLightChoose(Menu[prepointer], oldChoosePos, columns, 1);
//                highLightChoose(Menu[pointer], newChoosePos, columns, 1);
//
//
//                while (true) {
//                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
//                                break;
//                        }
//                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
//                                if (pointer > 0) {
//                                        prepointer = pointer;
//                                        pointer--;
//                                        break;
//                                }
//                        }
//                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
//                                if (pointer < 9) {
//                                        prepointer = pointer;
//                                        pointer++;
//                                        break;
//                                }
//                        }
//                         else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
//                                if (page > 0) {
//                                        page--;
//                                        clearpage(Menu, 10);
//                                        printTitle(Menu, 10);
//                                        break;
//                                }
//                        }
//                         else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
//                                if (page < (cardcount/10)) {
//                                        page++;
//                                        clearpage(Menu, 10);
//                                        printTitle(Menu, 10);
//                                        break;
//                                }
//                        }
//                        else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
//                                return;
//                        }
//                }
//                Sleep(125);
//        }
//
//}

void Menu_List_Visitor (){
        int page=0, cardcount=0, sortbyid=1;
        int pointer=0, prepointer=0, rows, columns;
        Visitor::nodeavl root = JsonToVisitor();
        getWindowsSize(rows, columns);
        Menu_Box(rows, columns, "DANH SACH THE THU VIEN");
        std::string Menu[10];
        printTitle(Menu, 10);
        std::vector<int> id = getCID(root);
        std::vector<std::string> nameid;
        std::vector<std::string> name;
        gName(name, nameid, root);
        printCard(name);

        while (true) {

                int oldChoosePos = 8+prepointer*2;
                int newChoosePos = 8+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns, 1);
                highLightChoose(Menu[pointer], newChoosePos, columns, 1);


                while (true) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                break;
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        prepointer = pointer;
                                        pointer--;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < 9) {
                                        prepointer = pointer;
                                        pointer++;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                if (page > 0) {
                                        page--;
                                        clearpage(Menu, 10);
                                        printTitle(Menu, 10);
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                if (page < (cardcount/10)) {
                                        page++;
                                        clearpage(Menu, 10);
                                        printTitle(Menu, 10);
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

void Menu_Listbook (){
        int page=0, titlecount=0;
        int pointer=0, prepointer=0, rows, columns;
        Book::TitlePtr title;
        JsonToTitle(title, titlecount);
        getWindowsSize(rows, columns);
        Menu_Box(rows, columns, "DANH MUC SACH");
        std::string Menu[10];
        TitleToStr(Menu, title, titlecount, page);
        printTitle(Menu, 10);

        while (true) {

                int oldChoosePos = 8+prepointer*2;
                int newChoosePos = 8+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns, 1);
                highLightChoose(Menu[pointer], newChoosePos, columns, 1);

                while (true) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                break;
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        prepointer = pointer;
                                        pointer--;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < 9) {
                                        prepointer = pointer;
                                        pointer++;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                if (page > 0) {
                                        page--;
                                        clearpage(Menu, 10);
                                        TitleToStr(Menu, title, titlecount, page);
                                        printTitle(Menu, 10);
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                if (page < (titlecount/10)) {
                                        page++;
                                        clearpage(Menu, 10);
                                        TitleToStr(Menu, title, titlecount, page);
                                        printTitle(Menu, 10);
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

int Menu_Edit_Card (int id, Visitor::card data){
        int menu_count = 5, Name_check=0, Gender_check=0;
        int pointer=0, prepointer=0, rows, columns, first;
        Visitor::nodeavl root = JsonToVisitor();
        Visitor::card vcard;
        vcard.status = data.status;
        vcard.gender = data.gender;

        std::string Menu[menu_count] = {"Ma the       :                                                    |",
                                        "Ho va ten    :                                                    |",
                                        "Gioi tinh    :                                                    |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};
        std::string name_temp = data.fname + " " + data.lname;

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        gotoxy(edge+67, first+2);
        std::cout << "OK";
        gotoxy(edge+67, first+4);
        std::cout << "OK";

        while (true) {
                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                gotoxy(edge+15, first);
                std::cout << id;
                gotoxy(edge+15, first+2);
                std::cout << name_temp;
                gotoxy(edge+15, first+4);
                std::cout << vcard.gender;
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return 0;
                        }

                        if (pointer == -1) {
                                return -1;
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
                                getInput(pointer, menu_count, edge+15, first+2, 50, name_temp);
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
                                getInput(pointer, menu_count, edge+15, first+4, 50, vcard.gender);
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
                                                Visitor::delnode(root, id);
                                                Visitor::insertvst(root, id, vcard);
                                                VisitorToJson(root);
                                                return 1;
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

void Menu_Choose_Card (){
        int menu_count = 3, ID=0;
        int pointer=0, prepointer=0, rows, columns, first;
        Visitor::nodeavl root = JsonToVisitor();
        Visitor::card vcard;

        std::string Menu[menu_count] = {"Ma the       :                                                    |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        while (true) {
                ShowConsoleCursor(false);
                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                gotoxy(edge+15, first);
                std::cout << ID;
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }
                        if (pointer == -1) {
                                return;
                        }
                        else if (pointer == 0) {
                                prepointer = 0;
                                getNumInput(pointer, menu_count, edge+15, first, 50, ID);
                                break;
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        if (Visitor::idtocard(ID, vcard, root)) {
                                                if (Menu_Edit_Card(ID, vcard) == 1) {
                                                        int return_pointer = 0;
                                                        Menu_Box(rows, columns);
                                                        gotoxy(columns/2-12, rows/2);
                                                        std::cout << "Thay doi thanh cong!";
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
                                                                                Menu_Box(rows, columns);
                                                                                printMenu(Menu, menu_count, rows, columns);
                                                                                break;
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
                                                                                return;
                                                                        }
                                                                }
                                                        }
                                                }
                                                else {
                                                        Menu_Box(rows, columns);
                                                        printMenu(Menu, menu_count, rows, columns);
                                                        break;
                                                }
                                        }
                                        else {
                                                Menu_Box(rows, columns);
                                                gotoxy(columns/2-4, rows/2);
                                                std::cout << "Ma the khong ton tai";
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                                                gotoxy(columns/2-4, rows/2+1);
                                                std::cout << "An phim bat ky...";
                                                Sleep(125);
                                                while (true) {
                                                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                                                Sleep(125);
                                                                Menu_Box(rows, columns);
                                                                printMenu(Menu, menu_count, rows, columns);
                                                                break;
                                                        }
                                                }
                                        }

                                }
                                break;
                        }

                        else if (pointer == 2) {
                                prepointer = 2;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        Sleep(125);
                                        return;
                                }
                        }
                }
                Sleep(125);
        }
}

void Menu_Add_Card (){
        int menu_count = 5, Name_check=0, Gender_check=0, ID=0;
        int pointer=0, prepointer=0, rows, columns, first;
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
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
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
                std::cout << ID;
                gotoxy(edge+15, first+2);
                std::cout << name_temp;
                gotoxy(edge+15, first+4);
                std::cout << vcard.gender;
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }

                        if (pointer == -1) {
                                return;
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
                                getInput(pointer, menu_count, edge+15, first+2, 50, name_temp);
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
                                getInput(pointer, menu_count, edge+15, first+4, 50, vcard.gender);
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
                                                vcard.history.head = NULL;
                                                vcard.history.tail = NULL;
                                                root = Visitor::insertvst(root, ID, vcard);
                                                VisitorToJson(root);
                                                int return_pointer = 0;
                                                Menu_Box(rows, columns);
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
                                                                        return;
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
                                                                        return;
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
                                        return;
                                }
                        }
                }
                Sleep(125);
        }
}

void Menu_Del_Card (){
        int menu_count = 3, ID=0;
        int pointer=0, prepointer=0, rows, columns, first;
        Visitor::nodeavl root = JsonToVisitor();

        std::string Menu[menu_count] = {"Ma the   :                                                        |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        while (true) {
                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }

                        if (pointer == -1) {
                                return;
                        }
                        else if (pointer == 0) {
                                prepointer = 0;
                                getNumInput(pointer, menu_count, edge+15, first, 10, ID);
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        Visitor::delnode(root, ID);
                                        VisitorToJson(root);
                                        int return_pointer = 0;
                                        Menu_Box(rows, columns);
                                        gotoxy(columns/2-12, rows/2);
                                        std::cout << "Tiep tuc xoa?";
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
                                                                return;
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
                                                                return;
                                                        }
                                                }
                                        }

                                        break;
                                }

                        }
                        else if (pointer == 2) {
                                prepointer = 2;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        Sleep(125);
                                        return;
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
                                        "Danh sach the     ",
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
                                        Menu_Choose_Card();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 2) {
                                        Menu_Del_Card();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 3) {
                                        Menu_List_Visitor();
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

void Menu_Add_Title (){
        int menu_count = 9, bookcount=0;
        int pointer=0, prepointer=0, rows, columns, first;
        Book::Title title;
        std::string position = "";
        std::string Menu[menu_count] = {"ISBN         :                                                    |",
                                        "Ten sach     :                                                    |",
                                        "Tac gia      :                                                    |",
                                        "The loai     :                                                    |",
                                        "Nam xuat ban :                                                    |",
                                        "So trang     :                                                    |",
                                        "So luong sach:                                                    |",
                                        "Vi tri       :                                                    |",
                                        "                          Xac nhan                                 ",};

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        while (true) {
                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                gotoxy(edge+15, first);
                std::cout << title.isbn;
                gotoxy(edge+15, first+2);
                std::cout << title.name;
                gotoxy(edge+15, first+4);
                std::cout << title.author;
                gotoxy(edge+15, first+6);
                std::cout << title.genre;
                gotoxy(edge+15, first+8);
                std::cout << title.years;
                gotoxy(edge+15, first+10);
                std::cout << title.pages;
                gotoxy(edge+15, first+12);
                std::cout << bookcount;
                gotoxy(edge+15, first+14);
                std::cout << position;
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }

                        if (pointer == -1) {
                                return;
                        }
                        else if (pointer == 0) {
                                prepointer = 0;
                                getInput(pointer, menu_count, edge+15, first, 50, title.isbn);
                                break;
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                getInput(pointer, menu_count, edge+15, first+2, 50, title.name);
                                break;
                        }
                        else if (pointer == 2) {
                                prepointer = 2;
                                getInput(pointer, menu_count, edge+15, first+4, 50, title.author);
                                break;
                        }
                        else if (pointer == 3) {
                                prepointer = 3;
                                getInput(pointer, menu_count, edge+15, first+6, 50, title.genre);
                                break;
                        }
                        else if (pointer == 4) {
                                prepointer = 4;
                                getNumInput(pointer, menu_count, edge+15, first+8, 50, title.years);
                                break;
                        }
                        else if (pointer == 5) {
                                prepointer = 5;
                                getNumInput(pointer, menu_count, edge+15, first+10, 50, title.pages);
                                break;
                        }
                        else if (pointer == 6) {
                                prepointer = 6;
                                getNumInput(pointer, menu_count, edge+15, first+12, 50, bookcount);
                                break;
                        }
                        else if (pointer == 7) {
                                prepointer = 7;
                                getInput(pointer, menu_count, edge+15, first+14, 50, position);
                                break;
                        }
                        else if (pointer == 8) {
                                prepointer = 8;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        json data;
                                        std::ifstream fl ("Data/BookTitle.json");
                                        if (fl.peek() != std::ifstream::traits_type::eof()) {
                                                fl >> data;
                                        }
                                        data += {
                                                {"isbn", title.isbn},
                                                {"name", title.name},
                                                {"author", title.author},
                                                {"pages", title.pages},
                                                {"years", title.pages},
                                                {"genre", title.genre},
                                                {"borrow", title.borrow}
                                        };
                                        fl.close();
                                        std::ofstream ofl ("Data/BookTitle.json");
                                        ofl << std::setw(4) << data << std::endl;
                                        ofl.close();
                                        json bdata;
                                        for (int i = 0; i < bookcount; i++) {
                                                bdata += {
                                                        {"id", title.name + std::to_string(i)},
                                                        {"status", 0},
                                                        {"position", position}
                                                };
                                        }
                                        std::ofstream output("Data/Book/" + title.name + ".json");
                                        output << std::setw(4) << bdata << std::endl;
                                        int return_pointer = 0;
                                        Menu_Box(rows, columns);
                                        gotoxy(columns/2-12, rows/2);
                                        std::cout << "Tiep tuc them sach moi?";
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
                                                                return;
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
                                                                return;
                                                        }
                                                }
                                        }

                                        break;
                                }

                        }
                }
                Sleep(125);
        }
}

void Menu_Book (){
        const int menu_count = 3;
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
                                        Menu_Add_Title();
                                        Menu_Book();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 1) {
                                        Menu_Listbook();
                                        Menu_Box(rows, columns);
                                        printMenu(Menu, menu_count, rows, columns);
                                        highLightChoose(Menu[pointer], newChoosePos, columns);
                                        break;
                                }
                                else if (pointer == 2) {
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

void Visitor_Borrow (Book::ListPtr &title, std::string bid){
    int menu_count = 3, ID=0;
        int pointer=0, prepointer=0, rows, columns, first;
        Visitor::nodeavl root = JsonToVisitor();

        std::string Menu[menu_count] = {"Ma the   :                                                        |",
                                        "                          Xac nhan                                 ",
                                        "                          Quay lai                                 "};

        getWindowsSize(rows, columns);
        int edge = getEdge(columns, 67);
        first = getEdge(rows, menu_count);
        Menu_Box(rows, columns);
        printMenu(Menu, menu_count, rows, columns);

        while (true) {
                int oldChoosePos = first+prepointer*2;
                int newChoosePos = first+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns);
                highLightChoose(Menu[pointer], newChoosePos, columns);
                while (true) {
                        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                return;
                        }

                        if (pointer == -1) {
                                return;
                        }
                        else if (pointer == 0) {
                                prepointer = 0;
                                getNumInput(pointer, menu_count, edge+15, first, 10, ID);
                        }
                        else if (pointer == 1) {
                                prepointer = 1;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                        pointer++;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        regBorrow(root, ID, title, bid);
                                        int return_pointer = 0;
                                        Menu_Box(rows, columns);
                                        gotoxy(columns/2-12, rows/2);
                                        std::cout << "Tiep tuc xoa?";
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
                                                                return;
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
                                                                return;
                                                        }
                                                }
                                        }

                                        break;
                                }

                        }
                        else if (pointer == 2) {
                                prepointer = 2;
                                if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                        pointer--;
                                        break;
                                }
                                else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                        Sleep(125);
                                        return;
                                }
                        }
                }
                Sleep(125);
        }
}

void Show_Book (Book::ListPtr &book){
        int page=0, titlecount=0;
        int pointer=0, prepointer=0, rows, columns;
        getWindowsSize(rows, columns);
        Menu_Box(rows, columns, "DANH MUC SACH");
        std::string Menu[10];
        std::string bid[10];
        foundBook(Menu, bid, book, 1);
        printTitle(Menu, 10);

        while (true) {

                int oldChoosePos = 8+prepointer*2;
                int newChoosePos = 8+pointer*2;
                deHighLightChoose(Menu[prepointer], oldChoosePos, columns, 1);
                highLightChoose(Menu[pointer], newChoosePos, columns, 1);

                while (true) {
                        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                Visitor_Borrow(book, bid[pointer]);
                                Menu_Box(rows, columns, "DANH MUC SACH");
                                printTitle(Menu, 10);
                                break;
                        }
                        else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                if (pointer > 0) {
                                        prepointer = pointer;
                                        pointer--;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                if (pointer < 9) {
                                        prepointer = pointer;
                                        pointer++;
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                if (page > 0) {
                                        page--;
                                        clearpage(Menu, 10);
                                        printTitle(Menu, 10);
                                        break;
                                }
                        }
                        else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                if (page < (titlecount/10)) {
                                        page++;
                                        clearpage(Menu, 10);
                                        printTitle(Menu, 10);
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

void Find_Book () {
        const int menu_count = 2;
        int tcount, fcount=0, out_pointer=0, rows, columns;
        getWindowsSize(rows, columns);
        int firstMenuPosition = getEdge(rows, 8);
        Menu_Box(rows, columns, "          TIM SACH");
        Book::TitlePtr title;
        JsonToTitle(title, tcount);
        Book::TitlePtr found;
        std::string name;

        while (true) {
                if (out_pointer == -1){
                    break;
                }
                else if (out_pointer == 0) {
                        gotoxy(5, firstMenuPosition-4);
                        std::cout << "Nhap ten sach: ";
                        getInput(out_pointer, menu_count, 20, firstMenuPosition-4, 256, name, 15);
                        found = Book::getBookData(title, tcount, name, fcount);
                }
                else if (out_pointer == 1) {
                        if (fcount == 0 ) {
                                gotoxy(getEdge(columns, 24), firstMenuPosition+5);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                                std::cout << "Khong tim thay sach nay!";
                                out_pointer--;
                                continue;
                        }
                        else {
                                gotoxy(getEdge(columns, 24), firstMenuPosition+5);
                                std::cout << "                        ";
                                int page=0, titlecount=0;
                                int pointer=0, prepointer=0;
                                std::string Menu[10];
                                FoundTitleToStr(Menu, found, fcount, page);
                                printTitle(Menu, 10);
                                while (true) {
                                        if (out_pointer != 1) break;
                                        int oldChoosePos = 8+prepointer*2;
                                        int newChoosePos = 8+pointer*2;
                                        deHighLightChoose(Menu[prepointer], oldChoosePos, columns, 1);
                                        highLightChoose(Menu[pointer], newChoosePos, columns, 1);

                                        while (true) {
                                                if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                                                        Show_Book(found[pointer].BookList);
                                                        TitleToJson(title, tcount);
                                                        Menu_Box(rows, columns, "          TIM SACH");
                                                        break;
                                                }
                                                else if (GetAsyncKeyState(VK_UP) & 0x8000) {
                                                        if (pointer > 0) {
                                                                prepointer = pointer;
                                                                pointer--;
                                                                break;
                                                        }
                                                }
                                                else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
                                                        if (pointer < fcount) {
                                                                prepointer = pointer;
                                                                pointer++;
                                                                break;
                                                        }
                                                }
                                                else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
                                                        if (page > 0) {
                                                                page--;
                                                                clearpage(Menu, 10);
                                                                TitleToStr(Menu, title, titlecount, page);
                                                                printTitle(Menu, 10);
                                                                break;
                                                        }
                                                }
                                                else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
                                                        if (page < (titlecount/10)) {
                                                                page++;
                                                                clearpage(Menu, 10);
                                                                TitleToStr(Menu, title, titlecount, page);
                                                                printTitle(Menu, 10);
                                                                break;
                                                        }
                                                }
                                                else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
                                                        out_pointer--;
                                                        break;
                                                }
                                        }
                                        Sleep(125);
                                }

                        }
                }


        }


}

void Menu_Borrow (){
        const int menu_count = 4;
        int pointer=0, prepointer=0, rows, columns;
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
                                        Find_Book();
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
        TopTitle();

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


#endif
