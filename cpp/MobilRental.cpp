#include "KendaraanDarat.cpp"
#include <iostream>
#include <string>

using namespace std;

class MobilRental : public KendaraanDarat
{
private:
    string nomorPlat;
    int kapasitasPenumpang;
    double hargaSewaPerHari;

public:
    MobilRental(
        string idKendaraan,
        string merk,
        int tahunProduksi,
        double harga,
        int jumlahRoda,
        string jenisBahanBakar,
        string transmisi,
        string nomorPlat,
        int kapasitasPenumpang,
        double hargaSewaPerHari) : KendaraanDarat(idKendaraan,
                                                  merk,
                                                  tahunProduksi,
                                                  harga,
                                                  jumlahRoda,
                                                  jenisBahanBakar,
                                                  transmisi)
    {

        this->nomorPlat = nomorPlat;
        this->kapasitasPenumpang = kapasitasPenumpang;
        this->hargaSewaPerHari = hargaSewaPerHari;
    }

    double hitungBiayaSewa(int jumlahHari)
    {
        return hargaSewaPerHari * jumlahHari;
    }

    void tampilkanDetailRental()
    {
        tampilkanInfoDarat();

        cout << "Nomor Plat   : " << nomorPlat << "\n";
        cout << "Kapasitas    : " << kapasitasPenumpang << " orang\n";
        cout << "Sewa/Hari    : Rp " << hargaSewaPerHari << "\n";
    }

    string getNomorPlat()
    {
        return nomorPlat;
    }

    int getKapasitasPenumpang()
    {
        return kapasitasPenumpang;
    }

    double getHargaSewaPerHari()
    {
        return hargaSewaPerHari;
    }
};