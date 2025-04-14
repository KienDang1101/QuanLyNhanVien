#include "Modify.h"

void Modify::Them(){
    int id, ngaylamviec, ngayphep, nghikp, luongcb;
    string hoten, ngaylam, chucvu;

    cout << "Nhap ID: "; cin >> id;
    cin.ignore();
    cout << "Nhap ho ten: "; getline(cin, hoten);
    cout << "Nhap chuc vu (Nhan vien / Pho phong / Truong phong): "; getline(cin, chucvu);
    cout << "Nhap ngay bat dau lam: "; getline(cin, ngaylam);
    cout << "Nhap so ngay lam viec: "; cin >> ngaylamviec;
    cout << "Nhap so ngay nghi phep tich luy: "; cin >> ngayphep;
    cout << "Nhap so ngay nghi khong phep: "; cin >> nghikp;
    cout << "Nhap luong co ban: "; cin >> luongcb;

    NhanVien* nv = nullptr;
    if (chucvu == "Nhan vien") nv = new NhanVienVanPhong();
    else if (chucvu == "Pho phong") nv = new PhoPhong();
    else if (chucvu == "Truong phong") nv = new TruongPhong();
    else {
        cout << "Chuc vu khong hop le!\n";
        return;
    }

    nv->setID(id);
    nv->setHoTen(hoten);
    nv->setChucVu(chucvu);
    nv->setNgayLam(ngaylam);
    nv->setNgayLamViec(ngaylamviec);
    nv->setNgayPhepTichLuy(ngayphep);
    nv->setNgayNghikhongPhep(nghikp);

    if (NhanVienVanPhong* vp = dynamic_cast<NhanVienVanPhong*>(nv))
        vp->setLuongCoBan(luongcb);
    else if (PhoPhong* pp = dynamic_cast<PhoPhong*>(nv))
        pp->setLuongCoBan(luongcb);
    else if (TruongPhong* tp = dynamic_cast<TruongPhong*>(nv))
        tp->setLuongCoBan(luongcb);

    danhSachNhanVien.push_back(nv);

    cout << "Them nhan vien thanh cong!\n";
}

void Modify::Xoa(){
    cin.ignore();
    string keyword;
    cout << "Nhap ID hoac Ten de xoa: ";
    getline(cin, keyword);

    bool isNumber = all_of(keyword.begin(), keyword.end(), ::isdigit);
    bool found = false;

    auto it = danhSachNhanVien.begin();
    while (it != danhSachNhanVien.end()) {
        NhanVien* nv = *it;
        if ((isNumber && nv->getID() == stoi(keyword)) || (!isNumber && nv->getHoTen() == keyword)) {
            delete nv;
            it = danhSachNhanVien.erase(it);
            found = true;
            cout << "Xoa nhan vien thanh cong!\n";
        }
        else {
            ++it;
        }
    }

    if (!found) {
        cout << "Khong tim thay nhan vien phu hop!\n";
    }
}

void Modify::ChinhSua(){
    cin.ignore();
    string keyword;
    cout << "Nhap ID hoac Ten cua nhan vien can chinh sua: ";
    getline(cin, keyword);

    for (auto& nv : danhSachNhanVien) {
        if (to_string(nv->getID()) == keyword || nv->getHoTen() == keyword) {
            int ngaylamviec, ngayphep, nghikp, luongcb;
            string hoten, ngaylam;

            cout << "Nhap ho ten moi: "; getline(cin, hoten);
            cout << "Nhap ngay bat dau lam moi: "; getline(cin, ngaylam);
            cout << "Nhap so ngay lam viec moi: "; cin >> ngaylamviec;
            cout << "Nhap so ngay nghi phep tich luy moi: "; cin >> ngayphep;
            cout << "Nhap so ngay nghi khong phep moi: "; cin >> nghikp;
            cout << "Nhap luong co ban moi: "; cin >> luongcb;

            nv->setHoTen(hoten);
            nv->setNgayLam(ngaylam);
            nv->setNgayLamViec(ngaylamviec);
            nv->setNgayPhepTichLuy(ngayphep);
            nv->setNgayNghiKhongPhep(nghikp);

            if (NhanVienVanPhong* vp = dynamic_cast<NhanVienVanPhong*>(nv))
                vp->setLuongCoBan(luongcb);
            else if (PhoPhong* pp = dynamic_cast<PhoPhong*>(nv))
                pp->setLuongCoBan(luongcb);
            else if (TruongPhong* tp = dynamic_cast<TruongPhong*>(nv))
                tp->setLuongCoBan(luongcb);

            cout << "Chinh sua thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay nhan vien!\n";
}
