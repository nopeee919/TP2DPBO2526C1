#include "MobilRental.h"
#include <iostream>

MobilRental::MobilRental(
    std::string idKendaraan,
    std::string merk,
    int tahunProduksi,
    double harga,
    int jumlahRoda,
    std::string jenisBahanBakar,
    std::string transmisi,
    std::string nomorPlat,
    int kapasitasPenumpang,
    double hargaSewaPerHari
)
    : KendaraanDarat(
        idKendaraan,
        merk,
        tahunProduksi,
        harga,
        jumlahRoda,
        jenisBahanBakar,
        transmisi
      ),
      nomorPlat(nomorPlat),
      kapasitasPenumpang(kapasitasPenumpang),
      hargaSewaPerHari(hargaSewaPerHari) {}

double MobilRental::hitungBiayaSewa(int jumlahHari) const {
    return hargaSewaPerHari * jumlahHari;
}

void MobilRental::tampilkanDetailRental() const {
    tampilkanInfo();
    std::cout << "Nomor Plat   : " << nomorPlat << "\n";
    std::cout << "Kapasitas    : " << kapasitasPenumpang << " orang\n";
    std::cout << "Sewa/Hari    : Rp " << hargaSewaPerHari << "\n";
}

std::string MobilRental::getNomorPlat() const {
    return nomorPlat;
}

int MobilRental::getKapasitasPenumpang() const {
    return kapasitasPenumpang;
}

double MobilRental::getHargaSewaPerHari() const {
    return hargaSewaPerHari;
}
