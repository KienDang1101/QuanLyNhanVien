#include "NhapXuat.h"

NhanVien* NhapXuat::NhapNV() {
    int ID, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep;
    string HoTen, NgayLam, ChucVu;
    float LuongCoBan;

    cout << "Nhap ID: ";
    cin >> ID;
    cin.ignore();

    cout << "Nhap Ho ten:\n";
    getline(cin, HoTen);

    cout << "Nhap Ngay bat dau lam:\n";
    getline(cin, NgayLam);

    cout << "Nhap chuc vu:\n";
    getline(cin, ChucVu);

    cout << "Nhap so ngay lam viec: ";
    cin >> NgayLamViec;

    cout << "Nhap so ngay nghi co phep: ";
    cin >> NgayPhepTichLuy;

    cout << "Nhap so ngay nghi khong phep: ";
    cin >> NgayNghiKhongPhep;

    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
    cin.ignore();

    NhanVien* NV;
    if (ChucVu == "Nhân viên")
        NV = new NhanVienVanPhong(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep, LuongCoBan);
    else if (ChucVu == "Phó phòng")
        NV = new PhoPhong(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep, LuongCoBan);
    else
        NV = new TruongPhong(ID, HoTen, NgayLam, ChucVu, NgayLamViec, NgayPhepTichLuy, NgayNghiKhongPhep, LuongCoBan);
    return NV;
}

vector <NhanVien*> NhapXuat::NhapDS() {
    int n;
    vector <NhanVien*> DS;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
        DS.push_back(NhapNV());
    return DS;
}