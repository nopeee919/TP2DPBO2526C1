#ifndef KENDARAAN_H
#define KENDARAAN_H

#include <string>

class Kendaraan {
protected:
    std::string idKendaraan;
    std::string merk;
    int tahunProduksi;
    double harga;

public:
    Kendaraan(std::string idKendaraan, std::string merk, int tahunProduksi, double harga);
    virtual ~Kendaraan() = default;

    virtual void tampilkanInfo() const;
    double hitungNilaiDepresiasi() const;

    std::string getIdKendaraan() const;
    std::string getMerk() const;
    int getTahunProduksi() const;
    double getHarga() const;
};

#endif
