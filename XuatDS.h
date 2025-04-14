#ifndef XUATDS_H
#define XUATDS_H

#include "NhanVien.h"
#include <iomanip>

using namespace std;

class XuatDS
{
private:
   vector<NhanVien*> danhSachNhanVien;
public:
   static void Xuat();
};
