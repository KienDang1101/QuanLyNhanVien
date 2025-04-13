#include "SAPXEP.h"

int SAPXEP::convertDanhGia( const string DanhGia ) {
    if (DanhGia == "Yeu")       return 1 ;
    if (DanhGia == "TrungBinh") return 2 ;
    if (DanhGia == "Tot")       return 3 ;
    return -1 ;
}

// choose theo thu tu 1 - 6 : ID, NgayLamViec, NghiCoPhep, NghiKhongPhep, Luong, DanhGia
// tanggiam : 1 la tang dan , 2 la giam dan
void SAPXEP::SapXepDSNV( vector<NhanVien*>& DanhSachNhanVien , int choose , int tanggiam )
{
    if (  ( choose < 1 || 6 < choose ) || ( tanggiam < 1  || 2 < tanggiam) )
    {
        cout << "\nLua chon khong hop le. Danh sach nhan vien giu nguyen\n" ;
        return ;
    }

    sort( DanhSachNhanVien.begin(), DanhSachNhanVien.end(),
        [=]( NhanVien* a, NhanVien* b )
        {
            if ( choose == 1 ) return ( tanggiam == 1 ) ? ( a -> getID() < b -> getID() ) : ( a -> getID() > b -> getID() ) ;
            if ( choose == 2 ) return ( tanggiam == 1 ) ? ( a -> getNgayLamViec() < b -> getNgayLamViec() ) : ( a -> getNgayLamViec() > b -> getNgayLamViec() ) ;
            if ( choose == 3 ) return ( tanggiam == 1 ) ? ( a -> getNgayPhepTichLuy() < b -> getNgayPhepTichLuy() ) : ( a -> getNgayPhepTichLuy() > b -> getNgayPhepTichLuy() ) ;
            if ( choose == 4 ) return ( tanggiam == 1 ) ? ( a -> getNgayNghiKhongPhep() < b -> getNgayNghiKhongPhep() ) : ( a -> getNgayNghiKhongPhep() > b -> getNgayNghiKhongPhep() ) ;
            if ( choose == 5 ) return ( tanggiam == 1 ) ? ( a -> TinhLuong() < b -> TinhLuong() ) : ( a -> TinhLuong() > b -> TinhLuong() ) ;

            int tempDanhGia_a = convertDanhGia(a -> DanhGia()) ;
            int tempDanhGia_b = convertDanhGia(b -> DanhGia()) ;
            if ( choose == 6 ) return ( tanggiam == 1 ) ? ( tempDanhGia_a < tempDanhGia_b ) : ( tempDanhGia_a > tempDanhGia_b ) ;

            return false ;
        } ) ;
}





// int QuickSort::partition(vector<SinhVien*>& ds, int low, int high, int choose, char tanggiam)
// {
//     float pivot = 0.0f;
//     int pivotMSSV = 0;

//     if (choose == 1)
//         pivotMSSV = ds[high]->getMSSV();
//     else if (choose >= 2 && choose <= 10)
//     {
//         if (choose == 2)
//             pivot = stof(ds[high]->getOOP());
//         else if (choose == 3)
//             pivot = stof(ds[high]->getVDK());
//         else if (choose == 4)
//             pivot = stof(ds[high]->getKTMT());
//         else if (choose == 10)
//             pivot = ds[high]->DiemTB();
//         else
//         {
//             if (ds[high]->getHe() == "CLC")
//             {
//                 ChatLuongCao* clc = dynamic_cast<ChatLuongCao*>(ds[high]);
//                 if (clc)
//                 {
//                     if (choose == 5)
//                         pivot = stof(clc->getMatlab());
//                     else if (choose == 6)
//                         pivot = stof(clc->getDSP());
//                     else if (choose == 7)
//                         pivot = stof(clc->getTTS());
//                 }
//             }
//             else if (ds[high]->getHe() == "DT")
//             {
//                 DaiTra* dt = dynamic_cast<DaiTra*>(ds[high]);
//                 if (dt)
//                 {
//                     if (choose == 8)
//                         pivot = stof(dt->getJava());
//                     else if (choose == 9)
//                         pivot = stof(dt->getCSDL());
//                 }
//             }
//         }
//     }

//     int i = low - 1;
//     for (int j = low; j <= high - 1; j++) {
//         float current = 0.0f;
//         bool shouldSwap = false;

//         if (choose == 1) {
//             current = ds[j]->getMSSV();
//             shouldSwap = (tanggiam == '1') ? (current < pivotMSSV) : (current > pivotMSSV);
//         }
//         else
//         {
//             if (choose == 2)
//                 current = stof(ds[j]->getOOP());
//             else if (choose == 3)
//                 current = stof(ds[j]->getVDK());
//             else if (choose == 4)
//                 current = stof(ds[j]->getKTMT());
//             else if (choose == 10)
//                 current = ds[j]->DiemTB();
//             else
//             {
//                 if (ds[j]->getHe() == "CLC")
//                 {
//                     ChatLuongCao* clc = dynamic_cast<ChatLuongCao*>(ds[j]);
//                     if (clc)
//                     {
//                         if (choose == 5)
//                             current = stof(clc->getMatlab());
//                         else if (choose == 6)
//                             current = stof(clc->getDSP());
//                         else if (choose == 7)
//                             current = stof(clc->getTTS());
//                     }
//                 }
//                 else if (ds[j]->getHe() == "DT")
//                 {
//                     DaiTra* dt = dynamic_cast<DaiTra*>(ds[j]);
//                     if (dt)
//                     {
//                         if (choose == 8) current = stof(dt->getJava());
//                         else if (choose == 9) current = stof(dt->getCSDL());
//                     }
//                 }
//             }
//             shouldSwap = (tanggiam == '1') ? (current < pivot) : (current > pivot);
//         }

//         if (shouldSwap) {
//             i++;
//             swap(ds[i], ds[j]);
//         }
//     }
//     swap(ds[i + 1], ds[high]);
//     return i + 1;
// }