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
	string NgayLam;
	string ChucVu;
	int NgayLamViec;
	int NgayPhepTichLuy;
	int NgayNghiKhongPhep;
public:
	NhanVien();
	NhanVien(int, string, string, string, int, int, int);
	~NhanVien();

	void setID(int);
	int getID() const;

	void setHoTen(string);
	string getHoTen() const;

	void setNgayLam(string);
	string getNgayLam() const;

	void setChucVu(string);
	string getChucVu() const;

	void setNgayLamViec(int);
	int getNgayLamViec() const;

	void setNgayPhepTichLuy(int);
	int getNgayPhepTichLuy() const;

	void setNgayNghiKhongPhep(int);
	int getNgayNghiKhongPhep() const;

	string DanhGia();
	float HeSoLuong();
	virtual float TinhLuong();
};

class TruongPhong : public NhanVien
{
private:
	int LuongCoBan;
public:
	TruongPhong();
	TruongPhong(int, string, string, string, int, int, int, int);
	~TruongPhong();

	void setLuongCoBan(int);
	int getLuongCoBan() const;
	float TinhLuong();
};

class PhoPhong : public NhanVien
{
private:
	int LuongCoBan;
public:
	PhoPhong();
	PhoPhong(int, string, string, string, int, int, int, int);
	~PhoPhong();

	void setLuongCoBan(int);
	int getLuongCoBan() const;
	float TinhLuong();
};

class NhanVienVanPhong : public NhanVien
{
private:
	int LuongCoBan;
public:
	NhanVienVanPhong();
	NhanVienVanPhong(int, string, string, string, int, int, int, int);
	~NhanVienVanPhong();

	void setLuongCoBan(int);
	int getLuongCoBan() const;
	float TinhLuong();
};



#endif
