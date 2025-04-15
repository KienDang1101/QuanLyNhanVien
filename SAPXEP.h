#ifndef SAPXEP_H
#define SAPXEP_H

#include "NhanVien.h"
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


class SAPXEP
{
public:
	static int convertDanhGia( const string ) ;
// choose theo thu tu 1 - 6 : ID, NgayLamViec, NghiCoPhep, NghiKhongPhep, Luong, DanhGia
// tanggiam : 1 la tang dan , 2 la giam dan
	static void SapXepDSNV(vector<NhanVien*>&,int , int ) ;
};

#endif
