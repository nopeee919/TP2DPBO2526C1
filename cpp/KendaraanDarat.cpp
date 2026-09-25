#include "Kendaraan.cpp"
#include <iostream>
#include <string>

using namespace std;

class KendaraanDarat : public Kendaraan
{
private:
    int jumlahRoda;
    string jenisBahanBakar;
    string transmisi;

public:
    KendaraanDarat(
        string idKendaraan,
        string merk,
        int tahunProduksi,
        double harga,
        int jumlahRoda,
        string jenisBahanBakar,
        string transmisi) : Kendaraan(idKendaraan, merk, tahunProduksi, harga)
    {

        this->jumlahRoda = jumlahRoda;
        this->jenisBahanBakar = jenisBahanBakar;
        this->transmisi = transmisi;
    }

    bool cekKelayakanBerkendara()
    {
        return jumlahRoda >= 4 && getTahunProduksi() >= 2000;
    }

    void tampilkanInfoDarat()
    {
        tampilkanInfo();

        cout << "Jumlah Roda  : " << jumlahRoda << "\n";
        cout << "Bahan Bakar  : " << jenisBahanBakar << "\n";
        cout << "Transmisi    : " << transmisi << "\n";
    }

    int getJumlahRoda()
    {
        return jumlahRoda;
    }

    string getJenisBahanBakar()
    {
        return jenisBahanBakar;
    }

    string getTransmisi()
    {
        return transmisi;
    }
};