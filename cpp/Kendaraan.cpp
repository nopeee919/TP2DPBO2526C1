#include "Kendaraan.h"
#include <iostream>
#include <ctime>

Kendaraan::Kendaraan(std::string idKendaraan, std::string merk, int tahunProduksi, double harga)
    : idKendaraan(idKendaraan),
      merk(merk),
      tahunProduksi(tahunProduksi),
      harga(harga) {}

void Kendaraan::tampilkanInfo() const {
    std::cout << "ID Kendaraan : " << idKendaraan << "\n";
    std::cout << "Merk         : " << merk << "\n";
    std::cout << "Tahun        : " << tahunProduksi << "\n";
    std::cout << "Harga        : Rp " << harga << "\n";
}

double Kendaraan::hitungNilaiDepresiasi() const {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    int tahunSekarang = now->tm_year + 1900;

    int umur = tahunSekarang - tahunProduksi;

    if (umur <= 0) {
        return 0;
    }

    // Estimasi depresiasi 5% per tahun.
    return harga * 0.05 * umur;
}

std::string Kendaraan::getIdKendaraan() const {
    return idKendaraan;
}

std::string Kendaraan::getMerk() const {
    return merk;
}

int Kendaraan::getTahunProduksi() const {
    return tahunProduksi;
}

double Kendaraan::getHarga() const {
    return harga;
}
