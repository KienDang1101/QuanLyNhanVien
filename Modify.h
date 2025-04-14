#ifndef MODIFY_H
#define MODIFY_H

#include "NhanVien.h"
#include <vector>
#include <algorithm>

using namespace std;

extern vector<NhanVien*> danhSachNhanVien;
class Modify{
public:
    static void Them();
    static void Xoa();
    static void ChinhSua();
};
#endif
