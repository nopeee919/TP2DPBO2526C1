#include "KendaraanDarat.h"
#include <iostream>

KendaraanDarat::KendaraanDarat(
    std::string idKendaraan,
    std::string merk,
    int tahunProduksi,
    double harga,
    int jumlahRoda,
    std::string jenisBahanBakar,
    std::string transmisi
)
    : Kendaraan(idKendaraan, merk, tahunProduksi, harga),
      jumlahRoda(jumlahRoda),
      jenisBahanBakar(jenisBahanBakar),
      transmisi(transmisi) {}

bool KendaraanDarat::cekKelayakanBerkendara() const {
    return jumlahRoda >= 4 && tahunProduksi >= 2000;
}

void KendaraanDarat::tampilkanInfo() const {
    Kendaraan::tampilkanInfo();
    std::cout << "Jumlah Roda  : " << jumlahRoda << "\n";
    std::cout << "Bahan Bakar  : " << jenisBahanBakar << "\n";
    std::cout << "Transmisi    : " << transmisi << "\n";
}

int KendaraanDarat::getJumlahRoda() const {
    return jumlahRoda;
}

std::string KendaraanDarat::getJenisBahanBakar() const {
    return jenisBahanBakar;
}

std::string KendaraanDarat::getTransmisi() const {
    return transmisi;
}
