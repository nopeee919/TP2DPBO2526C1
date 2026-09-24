#ifndef MOBIL_RENTAL_H
#define MOBIL_RENTAL_H

#include "KendaraanDarat.h"
#include <string>

class MobilRental : public KendaraanDarat {
private:
    std::string nomorPlat;
    int kapasitasPenumpang;
    double hargaSewaPerHari;

public:
    MobilRental(
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
    );

    double hitungBiayaSewa(int jumlahHari) const;
    void tampilkanDetailRental() const;

    std::string getNomorPlat() const;
    int getKapasitasPenumpang() const;
    double getHargaSewaPerHari() const;
};

#endif
