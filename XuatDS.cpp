#include "XuatDS.h"

void XuatDS::Xuat()
{
    cout << left << setw(6) << "ID"
         << setw(20) << "Ho Ten"
         << setw(15) << "Chuc Vu"
         << setw(15) << "Ngay Vao"
         << setw(10) << "Ngay LV"
         << setw(10) << "Nghi Phep"
         << setw(10) << "Nghi KP"
         << setw(10) << "LCB"
         << setw(8)  << "He So"
         << setw(12) << "Luong"
         << setw(10) << "Danh Gia"
         << endl;
    for (auto nv : DanhSachNhanVien) 
    {
        cout << left << setw(6) << nv->getID()
             << setw(20) << nv->getHoTen()
             << setw(15) << nv->getChucVu()
             << setw(15) << nv->getNgayLam()
             << setw(10) << nv->getNgayLamViec()
             << setw(10) << nv->getNgayPhepTichLuy()
             << setw(10) << nv->getNgayNghiKhongPhep()
             << setw(10) << nv->getLuongCoBan()
             << setw(8)  << fixed << setprecision(2) << nv->HeSoLuong()
             << setw(12) << fixed << setprecision(2) << nv->TinhLuong()
             << setw(10) << nv->DanhGia()
             << endl;
    }
}
