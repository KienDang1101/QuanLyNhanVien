#ifndef DOCFILECSV_H
#define DOCFILECSV_H

#include "NhanVien.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

extern vector<NhanVien*> DanhSachNhanVien;

class DocFileCSV
{
public:
	static void DocFile();
};

#endif
