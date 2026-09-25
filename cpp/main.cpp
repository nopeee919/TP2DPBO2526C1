#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "MobilRental.cpp"

vector<MobilRental> daftarMobil;

string formatRupiah(double nilai)
{
    long long angka = (long long)nilai;
    string hasil = to_string(angka);

    int posisi = hasil.length() - 3;

    while (posisi > 0)
    {
        hasil.insert(posisi, ".");
        posisi = posisi - 3;
    }

    return "Rp " + hasil;
}

string potong(string teks, int panjang)
{
    if (teks.length() <= panjang)
    {
        return teks;
    }

    if (panjang <= 3)
    {
        return teks.substr(0, panjang);
    }

    return teks.substr(0, panjang - 3) + "...";
}

void tampilkanTabel()
{
    string garis =
        "+--------+---------------+--------+-----------------+-------+------------+------------+------------+------------+-----------------+";

    cout << "\n"
         << garis << "\n";

    cout << "| "
         << "ID     | "
         << "Merk          | "
         << "Tahun  | "
         << "Harga           | "
         << "Roda  | "
         << "BBM        | "
         << "Transmisi  | "
         << "Plat       | "
         << "Kapasitas  | "
         << "Sewa/Hari       |\n";

    cout << garis << "\n";

    for (int i = 0; i < daftarMobil.size(); i++)
    {

        string id = potong(daftarMobil[i].getIdKendaraan(), 6);
        string merk = potong(daftarMobil[i].getMerk(), 13);
        string harga = potong(formatRupiah(daftarMobil[i].getHarga()), 15);
        string bbm = potong(daftarMobil[i].getJenisBahanBakar(), 10);
        string transmisi = potong(daftarMobil[i].getTransmisi(), 10);
        string plat = potong(daftarMobil[i].getNomorPlat(), 10);
        string kapasitas = to_string(daftarMobil[i].getKapasitasPenumpang()) + " org";
        string sewa = potong(formatRupiah(daftarMobil[i].getHargaSewaPerHari()), 15);

        cout << "| ";

        cout << id;
        for (int j = id.length(); j < 6; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << merk;
        for (int j = merk.length(); j < 13; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << daftarMobil[i].getTahunProduksi();
        for (int j = to_string(daftarMobil[i].getTahunProduksi()).length(); j < 6; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << harga;
        for (int j = harga.length(); j < 15; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << daftarMobil[i].getJumlahRoda();
        for (int j = 1; j < 5; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << bbm;
        for (int j = bbm.length(); j < 10; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << transmisi;
        for (int j = transmisi.length(); j < 10; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << plat;
        for (int j = plat.length(); j < 10; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << kapasitas;
        for (int j = kapasitas.length(); j < 10; j++)
        {
            cout << " ";
        }

        cout << " | ";

        cout << sewa;
        for (int j = sewa.length(); j < 15; j++)
        {
            cout << " ";
        }

        cout << " |\n";
    }

    cout << garis << "\n";
    cout << "Total data: " << daftarMobil.size() << " mobil\n";
}

int bacaInt(string pesan)
{
    while (true)
    {
        cout << pesan;

        string input;
        getline(cin, input);

        bool valid = true;

        if (input.empty())
        {
            valid = false;
        }

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
            }
        }

        if (valid)
        {
            return stoi(input);
        }

        cout << "Masukkan angka bulat yang valid.\n";
    }
}

double bacaDouble(string pesan)
{
    while (true)
    {
        cout << pesan;

        string input;
        getline(cin, input);

        bool valid = true;
        int jumlahTitik = 0;

        if (input.empty())
        {
            valid = false;
        }

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '.')
            {
                jumlahTitik++;
            }
            else if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
            }
        }

        if (jumlahTitik > 1)
        {
            valid = false;
        }

        if (valid)
        {
            return stod(input);
        }

        cout << "Masukkan angka yang valid.\n";
    }
}

string bacaString(string pesan)
{
    while (true)
    {
        cout << pesan;

        string input;
        getline(cin, input);

        if (!input.empty())
        {
            return input;
        }

        cout << "Input tidak boleh kosong.\n";
    }
}

bool bacaYaTidak(string pesan)
{
    while (true)
    {
        cout << pesan;

        string jawaban;
        getline(cin, jawaban);

        if (jawaban == "y" || jawaban == "ya" ||
            jawaban == "Y" || jawaban == "YA")
        {
            return true;
        }

        if (jawaban == "n" || jawaban == "tidak" ||
            jawaban == "N" || jawaban == "TIDAK")
        {
            return false;
        }

        cout << "Masukkan y/ya atau n/tidak.\n";
    }
}

void isiDataAwal()
{

    daftarMobil.push_back(
        MobilRental(
            "MR001", "Toyota", 2022, 250000000,
            4, "Bensin", "Automatic", "B1234AB", 7, 450000));

    daftarMobil.push_back(
        MobilRental(
            "MR002", "Honda", 2021, 230000000,
            4, "Bensin", "Manual", "B5678CD", 5, 400000));

    daftarMobil.push_back(
        MobilRental(
            "MR003", "Mitsubishi", 2023, 320000000,
            4, "Diesel", "Automatic", "D1234EF", 7, 550000));

    daftarMobil.push_back(
        MobilRental(
            "MR004", "Suzuki", 2020, 180000000,
            4, "Bensin", "Manual", "F9876GH", 7, 350000));

    daftarMobil.push_back(
        MobilRental(
            "MR005", "Daihatsu", 2022, 190000000,
            4, "Bensin", "Automatic", "B2468IJ", 7, 375000));
}

void tambahData()
{

    cout << "\n--------------------------------------------------------------\n";
    cout << "Tambah Data Mobil Rental\n";
    cout << "--------------------------------------------------------------\n";

    string id = bacaString("ID Kendaraan          : ");
    string merk = bacaString("Merk                  : ");
    int tahun = bacaInt("Tahun Produksi        : ");
    double harga = bacaDouble("Harga Kendaraan       : Rp ");
    int roda = bacaInt("Jumlah Roda           : ");
    string bahanBakar = bacaString("Jenis Bahan Bakar     : ");
    string transmisi = bacaString("Transmisi             : ");
    string plat = bacaString("Nomor Plat            : ");
    int kapasitas = bacaInt("Kapasitas Penumpang   : ");
    double hargaSewa = bacaDouble("Harga Sewa per Hari   : Rp ");

    daftarMobil.push_back(
        MobilRental(
            id,
            merk,
            tahun,
            harga,
            roda,
            bahanBakar,
            transmisi,
            plat,
            kapasitas,
            hargaSewa));

    cout << "\nData berhasil ditambahkan.\n";
}

int main()
{

    isiDataAwal();

    cout << "==============================================================\n";
    cout << "             SISTEM DATA MOBIL RENTAL - C++\n";
    cout << "==============================================================\n";

    cout << "\n5 DATA AWAL:\n";
    tampilkanTabel();

    bool tambahLagi = true;

    while (tambahLagi)
    {

        tambahData();

        cout << "\nDATA SETELAH PENAMBAHAN:\n";
        tampilkanTabel();

        tambahLagi = bacaYaTidak(
            "\nApakah ingin menambahkan data lagi? (y/n): ");
    }

    cout << "\nProgram selesai. Terima kasih.\n";

    return 0;
}