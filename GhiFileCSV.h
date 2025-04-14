#ifndef GHIFILECSV_H
#define GHIFILECSV_H

#include "NhanVien.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

extern vector<NhanVien*> DanhSachNhanVien;
using namespace std;

class GhiFileCSV
{
public:
    static void GhiFile();
};

#endif
