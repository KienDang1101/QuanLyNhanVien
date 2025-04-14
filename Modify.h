#ifndef MODIFY_H
#define MODIFY_H

#include "NhanVien.h"
#include <vector>
using namespace std;

class Modify{
private:
    vector<NhanVien*> danhSachNhanVien;
public:
    static void Them();
    static void Xoa();
    static void ChinhSua();
};
#endif
