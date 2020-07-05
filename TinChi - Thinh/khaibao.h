#include <iostream>

//KHAI BAO DANH DACH LIEN KET

// Danh sach sinh vien (Danh sach lien ket don)
struct NodeSV {
	char mssv[11]; 	//ma sinh vien
	char ho[21]; 	//ho sinh vien
	char ten[11];	//ten sinh vien
	char phai[4]; 	// gioi tinh
	char sdt[12]; 	// so dien thoai
};
struct dssv {
	NodeSV data;
	dssv *next;
};
typedef dssv *PTRSV;

// Danh sach dang ki (Danh sach lien ket don)
struct NodeDK {
	char mssv[11]; //ma sinh vien
	char diem[4] = "0"; 	//diem
};
struct dsdk {
	NodeDK data;
	dsdk *next;
};
typedef dsdk *PTRDK;

// Danh dach Lop Tin Chi ( Cay nhi phan tim kim)
struct NodeLopTC{
	int  malopTc; 		//ma lop
	char mmh[11];		//ma mon hoc
	char nienkhoa[5];		// nien khoa
	char  hocki[2]; 		// hoc ki
	char  nhom[2]; 			//nhom
	char  nsvmax[4];
    char  nsvmin[4];
	PTRDK DSDK = NULL; // con tro tro den danh sach sv dang ki lop tin chi 
	struct NodeLopTC *left, *right;
};
typedef struct NodeLopTC PTRLTC;

// Danh dach mon hoc (Mang con tro)
const int MAXLIST =300;
struct NodeMonHoc {
  	char mmh[11];	//ma mon hoc
    char tmh[36];	// ten mon hoc
	char stclt[2];		// so tinh chi li thuyet
	char stcth[2];		// so tinh chi thuc hanh
};

struct dsmh {
  int n;
  NodeMonHoc *nodes [MAXLIST];
};
typedef struct dsmh PTRMH; 

