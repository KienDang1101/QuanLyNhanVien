#include"ThongKe.h"
#include"XuatDS.h" 

vector <NhanVien*> ThongKe::List_DanhGia(vector<NhanVien*> DanhSach, string BacDanhGia) {
	vector <NhanVien*> ThongKeNV;
	for (NhanVien* NV : DanhSach) {
		if (NV->DanhGia() == BacDanhGia)
			ThongKeNV.push_back(NV);
	}
	return ThongKeNV;
}

vector <NhanVien*> ThongKe::List_NgayNghi(vector <NhanVien*> DanhSach, int Max) {
	vector <NhanVien*> ThongKeNV;
	for (NhanVien* NV : DanhSach) {
		if (NV->getNgayPhepTichLuy() <= Max)
			ThongKeNV.push_back(NV);
	}
	return ThongKeNV;
}

vector <NhanVien*> ThongKe::Options(vector <NhanVien*> DanhSach) {
	unsigned int c, BacDanhGia;
	int Max;
	vector <NhanVien*> List;

	cout << "1. Tim va xuat danh sach nhan vien theo danh gia.\n";
	cout << "2. Tim va xuat danh sach nhan vien co so ngay nghi khong phep.\n";
	cout << "Nhap lua chon: ";
	cin >> c;
	switch (c)
	{
	case 1:
		cout << "-----Tim va xuat danh sach nhan vien theo danh gia-----\n";
		cout << "1. Danh gia tot.\n";
		cout << "2. Danh gia trung binh.\n";
		cout << "3. Danh gia yeu.\n";
		cout << "Nhap lua chon: ";
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
		break;
	case 2:
		cout << "-----Tim va xuat danh sach nhan vien theo so ngay nghi khong phep-----\n";
		cout << "Nhap so ngay nghi khong phep toi da: ";
		cin >> Max;
		List = List_NgayNghi(DanhSach, Max);
		break;
	}
	return List;
}
