#include "NhanVien.h"
#include "Menu.h"
#include "DocFileCSV.h"
#include "GhiFileCSV.h"
#include "XuatDS.h"
#include "Modify.h"
#include "SAPXEP.h"
#include "ThongKe.h"

vector <NhanVien*> DanhSachNhanVien;

void Menu::MenuChinh()
{
	int choice, choose, tanggiam;
	do
	{
		cout << "==================== QUAN LY NHAN VIEN ====================" << '\n';
		cout << "1. Doc du lieu tu file CSV" << '\n';
		cout << "2. Xuat danh sach nhan vien" << '\n';
		cout << "3. Chinh sua nhan vien" << '\n';
		cout << "4. Them nhan vien" << '\n';
		cout << "5. Xoa nhan vien" << '\n';
		cout << "6. Sap xep danh sach nhan vien" << '\n';
		cout << "7. Thong ke" << '\n';
		cout << "0. Thoat" << '\n';
		cout << "============================================================" << '\n';
		cout << "Nhap lua chon: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			DocFileCSV::DocFile();
			break;
		case 2:
			XuatDS::Xuat();
			break;
		case 3:
			Modify::ChinhSua();
			break;
		case 4:
			Modify::Them();
			break;
		case 5:
			Modify::Xoa();
			break;
		case 6:
			cout << "1. Sap xep theo ID" << '\n';
			cout << "2. Sap xep theo Ngay Lam Viec" << '\n';
			cout << "3. Sap xep theo Ngay Nghi Co Phep" << '\n';
			cout << "4. Sap xep theo Ngay Nghi Khong Phep" << '\n';
			cout << "5. Sap xep theo Luong" << '\n';
			cout << "6. Sap xep theo Danh Gia" << '\n';
			cout << "Nhap lua chon: " << '\n';
			cin >> choose;

			cout << "1. Sap xep tang dan" << '\n';
			cout << "2. Sap xep giam dan" << '\n';
			cout << "Nhap lua chon: " << '\n';
			cin >> tanggiam;

			SAPXEP::SapXepDSNV(DanhSachNhanVien, choose, tanggiam);
			break;
		case 7:
			DanhSachNhanVien = ThongKe::Options(DanhSachNhanVien);
			XuatDS::Xuat();
			break;
		}

		GhiFileCSV::GhiFile();
	} while (choice != 0);
}

int main()
{
	Menu::MenuChinh();
	return 0;
}