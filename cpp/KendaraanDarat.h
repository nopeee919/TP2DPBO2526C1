#ifndef KENDARAAN_DARAT_H
#define KENDARAAN_DARAT_H

#include "Kendaraan.h"
#include <string>

class KendaraanDarat : public Kendaraan {
protected:
    int jumlahRoda;
    std::string jenisBahanBakar;
    std::string transmisi;

public:
    KendaraanDarat(
        std::string idKendaraan,
        std::string merk,
        int tahunProduksi,
        double harga,
        int jumlahRoda,
        std::string jenisBahanBakar,
        std::string transmisi
    );

    bool cekKelayakanBerkendara() const;
    void tampilkanInfo() const override;

    int getJumlahRoda() const;
    std::string getJenisBahanBakar() const;
    std::string getTransmisi() const;
};

#endif
