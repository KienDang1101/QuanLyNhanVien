#include "SAPXEP.h"

int SAPXEP::convertDanhGia(const string DanhGia) {
    if (DanhGia == "Yeu")       return 1;
    if (DanhGia == "Trung Binh") return 2;
    if (DanhGia == "Tot")       return 3;
    return -1;
}

// Updated usage of convertDanhGia
void SAPXEP::SapXepDSNV(vector<NhanVien*>& DanhSachNhanVien, int choose, int tanggiam)
{
    if ((choose < 1 || 6 < choose) || (tanggiam < 1 || 2 < tanggiam))
    {
        cout << "\nLua chon khong hop le. Danh sach nhan vien giu nguyen\n";
        return;
    }

    sort(DanhSachNhanVien.begin(), DanhSachNhanVien.end(),
        [=](NhanVien* a, NhanVien* b)
        {
            if (choose == 1) return (tanggiam == 1) ? (a->getID() < b->getID()) : (a->getID() > b->getID());
            if (choose == 2) return (tanggiam == 1) ? (a->getNgayLamViec() < b->getNgayLamViec()) : (a->getNgayLamViec() > b->getNgayLamViec());
            if (choose == 3) return (tanggiam == 1) ? (a->getNgayPhepTichLuy() < b->getNgayPhepTichLuy()) : (a->getNgayPhepTichLuy() > b->getNgayPhepTichLuy());
            if (choose == 4) return (tanggiam == 1) ? (a->getNgayNghiKhongPhep() < b->getNgayNghiKhongPhep()) : (a->getNgayNghiKhongPhep() > b->getNgayNghiKhongPhep());
            if (choose == 5) return (tanggiam == 1) ? (a->TinhLuong() < b->TinhLuong()) : (a->TinhLuong() > b->TinhLuong());

            int tempDanhGia_a = SAPXEP::convertDanhGia(a->DanhGia()); 
            int tempDanhGia_b = SAPXEP::convertDanhGia(b->DanhGia()); 
            if (choose == 6) return (tanggiam == 1) ? (tempDanhGia_a < tempDanhGia_b) : (tempDanhGia_a > tempDanhGia_b);

            return false;
        });
}
