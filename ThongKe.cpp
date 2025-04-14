#include"ThongKe.h"

vector <NhanVien*> ThongKe::List_DanhGia(vector<NhanVien*> DanhSach, string BacDanhGia) {
	vector <NhanVien*> ThongKeNV;
	for (NhanVien* NV : DanhSach) {
		if (NV->DanhGia() == BacDanhGia)
			ThongKeNV.push_back(NV);
	}
	return ThongKeNV;
}

vector <NhanVien*> ThongKe::Options(vector <NhanVien*> DanhSach) {
	unsigned int BacDanhGia;
	vector <NhanVien*> List;
	cout << "-----Tim va xuat danh sach nhan vien theo danh gia-----\n";
	cout << "1. Danh gia tot.\n";
	cout << "2. Danh gia trung binh.\n";
	cout << "3. Danh gia yeu.\n";
	cout << "nhap lua chon: ";
	cin >> BacDanhGia;
	switch (BacDanhGia)
	{
	case 1:
		List = List_DanhGia(DanhSach, "Tot");
		break;
	case 2:
		List = List_DanhGia(DanhSach, "TrungBinh");
		break;
	case 3:
		List = List_DanhGia(DanhSach, "Yeu");
		break;
	}
	return List;
}