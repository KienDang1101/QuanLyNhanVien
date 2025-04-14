#include "DocFileCSV.h"


void DocFileCSV::DocFile()
{
    for (auto nv : DanhSachNhanVien) delete nv;
        DanhSachNhanVien.clear();

        ifstream myFile("DanhSach.csv");

        if (myFile.is_open()) {
            string line;
            getline(myFile, line);

            while (getline(myFile, line)) {
                stringstream ss(line);
                string tempString;
                string chucvu,hoten,ngaylam;
                NhanVien* nv = nullptr;

                getline(ss, tempString, ','); int id = stoi(tempString);
                getline(ss, hoten, ',');
                getline(ss, chucvu, ',');
                getline(ss, ngaylam, ',');
                getline(ss, tempString, ','); int ngaylamviec = stoi(tempString);
                getline(ss, tempString, ','); int ngayphep = stoi(tempString);
                getline(ss, tempString, ','); int nghikp = stoi(tempString);
                getline(ss, tempString, ','); int luongcb = stoi(tempString);

                if (chucvu == "Nhan vien") nv = new NhanVienVanPhong();
                else if (chucvu == "Pho phong") nv = new PhoPhong();
                else if (chucvu == "Truong phong") nv = new TruongPhong();

                if (nv) {
                    nv->setID(id);
                    nv->setHoTen(hoten);
                    nv->setChucVu(chucvu);
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

                    // nv->setHeSoLuong(nv->HeSoLuong());
                    // nv->setLuongThucTe(nv->TinhLuong());
                    // nv->setDanhGia(nv->DanhGia());

                    DanhSachNhanVien.push_back(nv);
                }
            }
            cout << "\nDoc file thanh cong\n";
            myFile.close();
        }
        else {
            cout << "\nKhong mo duoc file\n";
        }
}
