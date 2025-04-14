#ifndef THONGKE_H
#define THONGKE_H

#include "NhanVien.h"
#include <vector>

class ThongKe {
public:
	static vector <NhanVien*> List_DanhGia(vector <NhanVien*>, string);

	static vector <NhanVien*> List_NgayNghi(vector <NhanVien*>, int);

	static vector <NhanVien*> Options(vector <NhanVien*>);
};

#endif
