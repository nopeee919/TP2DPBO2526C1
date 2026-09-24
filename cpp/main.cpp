#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "MobilRental.h"

std::vector<MobilRental> daftarMobil;

std::string formatRupiah(double nilai) {
    std::ostringstream hasil;
    hasil << std::fixed << std::setprecision(0) << nilai;

    std::string angka = hasil.str();
    int posisi = static_cast<int>(angka.length()) - 3;

    while (posisi > 0) {
        angka.insert(posisi, ".");
        posisi -= 3;
    }

    return "Rp " + angka;
}

std::string potong(const std::string& teks, int panjang) {
    if (static_cast<int>(teks.length()) <= panjang) {
        return teks;
    }

    if (panjang <= 3) {
        return teks.substr(0, panjang);
    }

    return teks.substr(0, panjang - 3) + "...";
}

void tampilkanTabel() {
    const std::string garis =
        "+--------+---------------+--------+-----------------+-------+------------+------------+------------+------------+-----------------+";

    std::cout << "\n" << garis << "\n";

    std::cout << "| "
              << std::left << std::setw(6) << "ID" << " | "
              << std::setw(13) << "Merk" << " | "
              << std::setw(6) << "Tahun" << " | "
              << std::setw(15) << "Harga" << " | "
              << std::setw(5) << "Roda" << " | "
              << std::setw(10) << "BBM" << " | "
              << std::setw(10) << "Transmisi" << " | "
              << std::setw(10) << "Plat" << " | "
              << std::setw(10) << "Kapasitas" << " | "
              << std::setw(15) << "Sewa/Hari" << " |\n";

    std::cout << garis << "\n";

    for (const MobilRental& mobil : daftarMobil) {
        std::cout << "| "
                  << std::left << std::setw(6) << potong(mobil.getIdKendaraan(), 6) << " | "
                  << std::setw(13) << potong(mobil.getMerk(), 13) << " | "
                  << std::setw(6) << mobil.getTahunProduksi() << " | "
                  << std::setw(15) << potong(formatRupiah(mobil.getHarga()), 15) << " | "
                  << std::setw(5) << mobil.getJumlahRoda() << " | "
                  << std::setw(10) << potong(mobil.getJenisBahanBakar(), 10) << " | "
                  << std::setw(10) << potong(mobil.getTransmisi(), 10) << " | "
                  << std::setw(10) << potong(mobil.getNomorPlat(), 10) << " | "
                  << std::setw(10) << (std::to_string(mobil.getKapasitasPenumpang()) + " org") << " | "
                  << std::setw(15) << potong(formatRupiah(mobil.getHargaSewaPerHari()), 15) << " |\n";
    }

    std::cout << garis << "\n";
    std::cout << "Total data: " << daftarMobil.size() << " mobil\n";
}

int bacaInt(const std::string& pesan) {
    while (true) {
        std::cout << pesan;

        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        int nilai;
        char sisa;

        if (ss >> nilai && !(ss >> sisa)) {
            return nilai;
        }

        std::cout << "Masukkan angka bulat yang valid.\n";
    }
}

double bacaDouble(const std::string& pesan) {
    while (true) {
        std::cout << pesan;

        std::string input;
        std::getline(std::cin, input);

        std::stringstream ss(input);
        double nilai;
        char sisa;

        if (ss >> nilai && !(ss >> sisa)) {
            return nilai;
        }

        std::cout << "Masukkan angka yang valid.\n";
    }
}

std::string bacaString(const std::string& pesan) {
    while (true) {
        std::cout << pesan;

        std::string input;
        std::getline(std::cin, input);

        if (!input.empty()) {
            return input;
        }

        std::cout << "Input tidak boleh kosong.\n";
    }
}

bool bacaYaTidak(const std::string& pesan) {
    while (true) {
        std::cout << pesan;

        std::string jawaban;
        std::getline(std::cin, jawaban);

        std::transform(jawaban.begin(), jawaban.end(), jawaban.begin(),
                       [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

        if (jawaban == "y" || jawaban == "ya") {
            return true;
        }

        if (jawaban == "n" || jawaban == "tidak") {
            return false;
        }

        std::cout << "Masukkan y/ya atau n/tidak.\n";
    }
}

void isiDataAwal() {
    // Lima objek awal sebelum input user.
    daftarMobil.emplace_back(
        "MR001", "Toyota", 2022, 250000000,
        4, "Bensin", "Automatic", "B1234AB", 7, 450000
    );

    daftarMobil.emplace_back(
        "MR002", "Honda", 2021, 230000000,
        4, "Bensin", "Manual", "B5678CD", 5, 400000
    );

    daftarMobil.emplace_back(
        "MR003", "Mitsubishi", 2023, 320000000,
        4, "Diesel", "Automatic", "D1234EF", 7, 550000
    );

    daftarMobil.emplace_back(
        "MR004", "Suzuki", 2020, 180000000,
        4, "Bensin", "Manual", "F9876GH", 7, 350000
    );

    daftarMobil.emplace_back(
        "MR005", "Daihatsu", 2022, 190000000,
        4, "Bensin", "Automatic", "B2468IJ", 7, 375000
    );
}

void tambahData() {
    std::cout << "\n--------------------------------------------------------------\n";
    std::cout << "Tambah Data Mobil Rental\n";
    std::cout << "--------------------------------------------------------------\n";

    std::string id = bacaString("ID Kendaraan          : ");
    std::string merk = bacaString("Merk                  : ");
    int tahun = bacaInt("Tahun Produksi        : ");
    double harga = bacaDouble("Harga Kendaraan       : Rp ");
    int roda = bacaInt("Jumlah Roda            : ");
    std::string bahanBakar = bacaString("Jenis Bahan Bakar     : ");
    std::string transmisi = bacaString("Transmisi             : ");
    std::string plat = bacaString("Nomor Plat            : ");
    int kapasitas = bacaInt("Kapasitas Penumpang   : ");
    double hargaSewa = bacaDouble("Harga Sewa per Hari   : Rp ");

    daftarMobil.emplace_back(
        id,
        merk,
        tahun,
        harga,
        roda,
        bahanBakar,
        transmisi,
        plat,
        kapasitas,
        hargaSewa
    );

    std::cout << "\nData berhasil ditambahkan.\n";
}

int main() {
    isiDataAwal();

    std::cout << "==============================================================\n";
    std::cout << "             SISTEM DATA MOBIL RENTAL - C++\n";
    std::cout << "==============================================================\n";

    std::cout << "\n5 DATA AWAL:\n";
    tampilkanTabel();

    bool tambahLagi = true;

    while (tambahLagi) {
        tambahData();

        std::cout << "\nDATA SETELAH PENAMBAHAN:\n";
        tampilkanTabel();

        tambahLagi = bacaYaTidak("\nApakah ingin menambahkan data lagi? (y/n): ");
    }

    std::cout << "\nProgram selesai. Terima kasih.\n";

    return 0;
}
