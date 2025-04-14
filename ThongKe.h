#ifndef THONGKE_H
#define THONGKE_H

#include "NhanVien.h"

class ThongKe {
public:
	vector <NhanVien*> List_DanhGia(vector <NhanVien*>, string);

	vector <NhanVien*> List_NgayNghi(vector <NhanVien*>, unsigned int);

	vector <NhanVien*> Options(vector <NhanVien*>);
};

#endif
