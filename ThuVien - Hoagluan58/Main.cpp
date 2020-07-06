#include <iostream>

void QuanLyDocGia()
{
    system("cls");
    char ch2;
    std::cout << "\n\n\n\tQUAN LY DOC GIA ";
    std::cout << "\n\n\t1.DANG KY DOC GIA";
    std::cout << "\n\n\t2.XOA DOC GIA";
    std::cout << "\n\n\t3.SUA DOC GIA";
    std::cout << "\n\n\t4.DANH SACH DOC GIA";
    std::cout << "\n\n\t5.LIET KE SACH DOC GIA DANG MUON";
    std::cout << "\n\n\t6.QUAY VE MENU CHINH";
    std::cout << "\n\n\tVUI LONG NHAP LUA CHON (1-6): ";
    ch2 = getchar();
    switch (ch2) {
        case '1':
            system("cls");
            break;
        case '2':
            system("cls");
            break;
        case '3':
            system("cls");
            break;
        case '4':
            system("cls");
            break;
        case '5':
            system("cls");
            break;
        case '6':
            system("cls");
            break;
    }
}

void QuanLySach()
{
    system("cls");
    char ch3;
    std::cout << "\n\n\n\tQUAN LY SACH ";
    std::cout << "\n\n\t1.THEM SACH";
    std::cout << "\n\n\t2.MUON SACH";
    std::cout << "\n\n\t3.TRA SACH";
    std::cout << "\n\n\t4.XOA SACH";
    std::cout << "\n\n\t5.SUA SACH";
    std::cout << "\n\n\t6.TIM KIEM";
    std::cout << "\n\n\t7.DANH SACH SACH";
    std::cout << "\n\n\t8.QUAY VE MENU CHINH";
    std::cout << "\n\n\tVUI LONG NHAP LUA CHON (1-8): ";
    ch3 = getchar();
    switch (ch3) {
        case '1':
            system("cls");
            break;
        case '2':
            system("cls");
            break;
        case '3':
            system("cls");
            break;
        case '4':
            system("cls");
            break;
        case '5':
            system("cls");
            break;
        case '6':
            system("cls");
            break;
        case '7':
            system("cls");
            break;
        case '8':
            system("cls");
            break;
    }
}

void ThongKe()
{
    system("cls");
    char ch4;
    std::cout << "\n\n\n\tTHONG KE ";
    std::cout << "\n\n\t1.DANH SACH DOC GIA MUON SACH QUA HAN";
    std::cout << "\n\n\t2.10 SACH CO SO LUOT MUON NHIEU NHAT";
    std::cout << "\n\n\t3.QUAY VE MENU CHINH";
    ch4 = getchar();
    switch (ch4) {
        case '1':
            system("cls");
            break;
        case '2':
            system("cls");
            break;
        case '3':
            system("cls");
            break;
    }
}

void main() {
    system("cls");
    char ch;
    system("cls");
    std::cout << "\n\n\n\tQUAN LY THU VIEN ";
    std::cout << "\n\n\t1.QUAN LY DOC GIA";
    std::cout << "\n\n\t2.QUAN LY SACH";
    std::cout << "\n\n\t3.THONG KE";
    std::cout << "\n\n\t4.THOAT";
    std::cout << "\n\n\tVUI LONG NHAP LUA CHON (1-4): ";
    ch = getchar();
    switch (ch) {
        case '1':
            system("cls");
            QuanLyDocGia();
            break;
        case '2':
            system("cls");
            QuanLySach();
            break;
        case '3':
            system("cls");
            ThongKe();
            break;
        case '4': exit(0);
        default: std::cout << "\a";
    }
}