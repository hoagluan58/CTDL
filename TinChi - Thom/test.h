#include <iostream>
// danh sach mon hoc mang con tro 
struct mon_hoc
{
	char  mamonhoc[10];
	char  tenmonhoc[30];
	int  STCLT;
	int  STCTH;
};
typedef struct mon_hoc Mon_Hoc;
struct ds_mon_hoc
{
	Mon_Hoc *ds[300];
	int sl = 0;
};
typedef struct ds_mon_hoc DS_Mon_Hoc;


//danh sach lop tin chi cay nhi phan tim kiem
struct tin_chi{
	int maloptc;
	char mamonhoc[10];
	int nienkhoa;
	int hocki;
	int nhom;
	int svmax;
	int svmin;
	DSSV Danh_Sach_Sinh_Vien; //con tro tro toi
};

struct danh_sach_tin_chi{
	tin_chi data;
	danh_sach_tin_chi *left;
	danh_sach_tin_chi *right;
};
typedef danh_sach_tin_chi *DSTC;

// danh sach sinh vien lien ket don
struct sinh_vien {
	char mssv[12]; 	//ma sinh vien
	char ho[21]; 	//ho sinh vien
	char ten[11];	//ten sinh vien
	char phai[4]; 	// gioi tinh
	char sdt[12]; 	// so dien thoai
	char malop[15];
};
struct danh_sach_sinh_vien {
	sinh_vien data;
	danh_sach_sinh_vien *next;
};
typedef dssv *DSSV;
// danh sach dang ki lop
struct dang_ki {
	char mssv[12]; //ma sinh vien
	float diem; 	//diem
};
struct danh_sach_dang_ki {
	dang_ki data;
	danh_sach_dang_ki *next;
};
typedef danh_sach_dang_ki *DSDK;









