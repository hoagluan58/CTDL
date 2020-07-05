#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<iomanip>
#include<fstream>

using namespace std; 

void MENU(){
std::cout<<"***********************************************************"<<endl;
std::cout<< "  1.Quan Ly Lop Tin Chi " <<endl; 
std::cout<< "  2.Quan Ly Lop Hoc     " <<endl;
std::cout<< "  3.Quan Ly Sinh Vien   " <<endl;
std::cout<< "  4.Quan Ly Mon Hoc     " <<endl;
std::cout<< "  5.Quan Ly Dang Ki     " <<endl;
std::cout<< "  6.Thoat               " <<endl;
std::cout<<" "<<endl;
cout<<"***********************************************************"<<endl;
}
void MENUloptc()
{ 
std::cout<<"***********************************************************"<<endl;
std::cout<< "  1. Nhap Danh Sach Lop Tin Chi " <<endl;
std::cout<< "  2. Xem Danh Sach Lop Tin Chi  "<<endl;
std::cout<< "  3. Xem Diem Lop Tin Chi       "<<endl;
std::cout<< "  4. Thoat               "<<endl;
std::cout<<" "<<endl;
std::cout<<"***********************************************************"<<endl;
}
void MENULop()
{ 
std::cout<<"***********************************************************"<<endl;
std::cout<< "  1. Nhap Danh Sach Lop         " <<endl;
std::cout<< "  2. Xem Danh Sach Lop          "<<endl;
std::cout<< "  3. Xem diem Trung Binh        "<<endl;
std::cout<< "  4. Xem diem Ca lop            "<<endl;
std::cout<< "  4. Thoat               "<<endl;
std::cout<<" "<<endl;
std::cout<<"***********************************************************"<<endl;
}
void MENUSinhVien()
{ 
std::cout<<"***********************************************************"<<endl;
std::cout<< "  1. Nhap Danh Sach Sinh Vien         " <<endl;
std::cout<< "  2.std:: Xem Danh Sach Sinh Vien          "<<endl;
std::cout<< "  3. Xem diem Sinh Vien        "<<endl;
std::cout<< "  4. Thoat               "<<endl;
std::cout<<" "<<endl;
std::cout<<"***********************************************************"<<endl;
}
void MENUMonHoc()
{ 
std::cout<<"***********************************************************"<<endl;
std::cout<< "  2. Xem Danh Sach Mon Hoc          "<<endl;
std::cout<< "  4. Thoat               "<<endl;
std::cout<<" "<<endl;
std::cout<<"***********************************************************"<<endl;
}
void MENUDangKi()
{ 
std::cout<<"***********************************************************"<<endl;
std::cout<< "  1. Dang ki lop tin chi        " <<endl;
std::cout<< "  2. Xem Danh Sach Dang Ki          "<<endl;
std::cout<< "  3. Nhap Diem        "<<endl;
std::cout<< "  4. Thoat               "<<endl;
std::cout<<" "<<endl;
std::cout<<"***********************************************************"<<endl;
}
void ShowmenuCHINH(){
 int key;
 MENU();
 std::cout << "Hay chon cong viec ban muon lam: ";
 std::cin >> key;
 menu:do{
	system("cls"); 
 	switch (key){
		case 1:	MENUloptc(); break; 
		case 2: MENULop(); break; 
		case 3: MENUSinhVien();break; 
		case 4: MENUMonHoc();break; 
		case 5: MENUDangKi();break; 
		case 6: system ("pause");
	} 
  }while (key !=0 || key >6);
} 
int main (){
	ShowmenuCHINH();
} 
