#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
protected:
	int ID;
	string HoTen;
	string NgaySinh;
	int NgayLamViec;
	int NgayNghiCoPhep;
	int NgayNghiKhongPhep;
public:
	NhanVien();
	NhanVien(int, string, string, int, int, int);
	~NhanVien();

	void setID(int);
	int getID() const;

	void setHoTen(string);
	string getHoTen() const;

	void setNgaySinh(string);
	string getNgaySinh() const;

	void setNgayLamViec(int);
	int getNgayLamViec() const;

	void setNgayNghiCoPhep(int);
	int getNgayNghiCoPhep() const;

	void setNgayNghiKhongPhep(int);
	int getNgayNghiKhongPhep() const;

	string DanhGia(int, int, int) const;
};

class ChucVuNhanVien : public NhanVien
{
private:
	string ChucVu;
	int HeSoLuong;
	int LuongCoBan;
	int PhuCap;
public:
	ChucVuNhanVien();
	ChucVuNhanVien(int, string, string, string, int, int, int, int, int, int);
	~ChucVuNhanVien();

	float TinhLuong(int, int, int, int, int, int) const;
};

#endif