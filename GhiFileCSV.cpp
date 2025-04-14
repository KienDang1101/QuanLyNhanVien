#include "GhiFileCSV.h"

vector<NhanVien*> danhSachNhanVien;

void GhiFileCSV::GhiFile(){
    ofstream myFile("DanhSach_out.csv");

    if (myFile.is_open()) {
        myFile << "ID,Ten,Chuc vu,Ngay bat dau lam,Ngay lam viec,Ngay nghi phep tich luy,Ngay nghi khong phep,Luong co ban,He so luong,Luong thuc te,Danh gia\n";

        for (auto nv : danhSachNhanVien) {
            myFile << nv->getID() << "," << nv->getHoTen() << "," << nv->getChuCVu() << "," << nv->getNgayLam() << "," << nv->getNgayLamViec() << ","
                    << nv->getNgayPhepTichLuy() << "," << nv->getNgaynghiKhongPhep() << "," << nv->getLuongCoBan() << ","
                    << nv->HeSoLuong() << "," << nv->TinhLuong() << "," << nv->DanhGia() << "\n";
            }

        myFile.close();
        cout << "\nViet file thanh cong !\n";
    }
    else {
        out << "Khong tao duoc file\n";
    }
}