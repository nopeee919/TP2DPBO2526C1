#include <iostream>
#include <string>

using namespace std;

class Kendaraan
{
private:
    string idKendaraan;
    string merk;
    int tahunProduksi;
    double harga;

public:
    Kendaraan(string idKendaraan, string merk, int tahunProduksi, double harga)
    {
        this->idKendaraan = idKendaraan;
        this->merk = merk;
        this->tahunProduksi = tahunProduksi;
        this->harga = harga;
    }

    void tampilkanInfo()
    {
        cout << "ID Kendaraan : " << idKendaraan << "\n";
        cout << "Merk         : " << merk << "\n";
        cout << "Tahun        : " << tahunProduksi << "\n";
        cout << "Harga        : Rp " << harga << "\n";
    }

    string getIdKendaraan()
    {
        return idKendaraan;
    }

    string getMerk()
    {
        return merk;
    }

    int getTahunProduksi()
    {
        return tahunProduksi;
    }

    double getHarga()
    {
        return harga;
    }
};