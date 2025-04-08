#include "NhanVien.h"

NhanVien::NhanVien()
{
	this->ID = 0;
	this->HoTen = "";
	this->NgaySinh = "";
	this->NgayLamViec = 0;
	this->NgayNghiCoPhep = 0;
	this->NgayNghiKhongPhep = 0;
}

NhanVien::NhanVien(int ID, string HoTen, string NgaySinh, int NgayLamViec, int NgayNghiCoPhep, int NgayNghiKhongPhep)
{
	setID(ID);
	setHoTen(HoTen);
	setNgaySinh(NgaySinh);
	setNgayLamViec(NgayLamViec);
	setNgayNghiCoPhep(NgayNghiCoPhep);
	setNgayNghiKhongPhep(NgayNghiKhongPhep);
}

NhanVien::~NhanVien() {}

void NhanVien::setID(int ID)
{
	this->ID = ID;
}
int NhanVien::getID() const
{
	return this->ID;
}

void NhanVien::setHoTen(string HoTen)
{
	this->HoTen = HoTen;
}
string NhanVien::getHoTen() const
{
	return this->HoTen;
}

void NhanVien::setNgaySinh(string NgaySinh)
{
	this->NgaySinh = NgaySinh;
}
string NhanVien::getNgaySinh() const
{
	return this->NgaySinh;
}

void NhanVien::setNgayLamViec(int NgayLamViec)
{
	this->NgayLamViec = NgayLamViec;
}
int NhanVien::getNgayLamViec() const
{
	return this->NgayLamViec;
}

void NhanVien::setNgayNghiCoPhep(int NgayNghiCoPhep)
{
	this->NgayNghiCoPhep = NgayNghiCoPhep;
}
int NhanVien::getNgayNghiCoPhep() const
{
	return this->NgayNghiCoPhep;
}

void NhanVien::setNgayNghiKhongPhep(int NgayNghiKhongPhep)
{
	this->NgayNghiKhongPhep = NgayNghiKhongPhep;
}
int NhanVien::getNgayNghiKhongPhep() const
{
	return this->NgayNghiKhongPhep;
}

string NhanVien::DanhGia(int NgayLamViec, int NgayNghiCoPhep, int NgayNghiKhongPhep) const
{
	if (NgayLamViec > 20 && NgayNghiCoPhep < 5 && NgayNghiKhongPhep < 2)
		return "Tot";
	else if (NgayLamViec > 15 && NgayNghiCoPhep < 10 && NgayNghiKhongPhep < 5)
		return "TrungBinh";
	else
		return "Kem";
}

ChucVuNhanVien::ChucVuNhanVien()
{
	this->ChucVu = "";
	this->HeSoLuong = 0;
	this->LuongCoBan = 0;
	this->PhuCap = 0;
}

ChucVuNhanVien::ChucVuNhanVien(int ID, string HoTen, string NgaySinh, string ChucVu, int HeSoLuong, int LuongCoBan, int PhuCap, int NgayLamViec, int NgayNghiCoPhep, int NgayNghiKhongPhep)
	: NhanVien(ID, HoTen, NgaySinh, NgayLamViec, NgayNghiCoPhep, NgayNghiKhongPhep)
{
	this->ChucVu = ChucVu;
	this->HeSoLuong = HeSoLuong;
	this->LuongCoBan = LuongCoBan;
	this->PhuCap = PhuCap;
}

ChucVuNhanVien::~ChucVuNhanVien() {}

float ChucVuNhanVien::TinhLuong(int NgayLamViec, int NgayNghiCoPhep, int NgayNghiKhongPhep, int HeSoLuong, int LuongCoBan, int PhuCap) const
{
	float Luong = (HeSoLuong * LuongCoBan);
	Luong -= Luong * (NgayNghiCoPhep * 0.02 + NgayNghiKhongPhep * 0.05);
	Luong += PhuCap;
	return max(Luong, 0.0f);
}