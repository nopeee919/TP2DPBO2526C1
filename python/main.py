from mobil_rental import MobilRental


daftar_mobil = []


def format_rupiah(nilai):
    """Mengubah angka menjadi format mata uang Rupiah."""
    return f"Rp {nilai:,.0f}".replace(",", ".")


def potong(teks, panjang):
    """Memotong teks jika melebihi lebar kolom tabel."""
    teks = str(teks)

    if len(teks) <= panjang:
        return teks

    if panjang <= 3:
        return teks[:panjang]

    return teks[:panjang - 3] + "..."


def tampilkan_tabel():
    """Menampilkan seluruh data mobil dalam satu tabel."""
    garis = (
        "+--------+---------------+--------+-----------------+-------+"
        "------------+------------+------------+------------+-----------------+"
    )

    print("\n" + garis)

    print(
        f"| {'ID':<6} | "
        f"{'Merk':<13} | "
        f"{'Tahun':<6} | "
        f"{'Harga':<15} | "
        f"{'Roda':<5} | "
        f"{'BBM':<10} | "
        f"{'Transmisi':<10} | "
        f"{'Plat':<10} | "
        f"{'Kapasitas':<10} | "
        f"{'Sewa/Hari':<15} |"
    )

    print(garis)

    for mobil in daftar_mobil:
        print(
            f"| {potong(mobil.id_kendaraan, 6):<6} | "
            f"{potong(mobil.merk, 13):<13} | "
            f"{mobil.tahun_produksi:<6} | "
            f"{potong(format_rupiah(mobil.harga), 15):<15} | "
            f"{mobil.jumlah_roda:<5} | "
            f"{potong(mobil.jenis_bahan_bakar, 10):<10} | "
            f"{potong(mobil.transmisi, 10):<10} | "
            f"{potong(mobil.nomor_plat, 10):<10} | "
            f"{str(mobil.kapasitas_penumpang) + ' org':<10} | "
            f"{potong(format_rupiah(mobil.harga_sewa_per_hari), 15):<15} |"
        )

    print(garis)
    print(f"Total data: {len(daftar_mobil)} mobil")


def baca_string(pesan):
    while True:
        nilai = input(pesan).strip()

        if nilai:
            return nilai

        print("Input tidak boleh kosong.")


def baca_int(pesan):
    while True:
        try:
            return int(input(pesan).strip())
        except ValueError:
            print("Masukkan angka bulat yang valid.")


def baca_float(pesan):
    while True:
        try:
            return float(input(pesan).strip())
        except ValueError:
            print("Masukkan angka yang valid.")


def baca_ya_tidak(pesan):
    while True:
        jawaban = input(pesan).strip().lower()

        if jawaban in ("y", "ya"):
            return True

        if jawaban in ("n", "tidak"):
            return False

        print("Masukkan y/ya atau n/tidak.")


def isi_data_awal():
    """Lima objek awal sebelum user memasukkan data."""
    daftar_mobil.append(
        MobilRental(
            "MR001", "Toyota", 2022, 250000000,
            4, "Bensin", "Automatic", "B1234AB",
            7, 450000
        )
    )

    daftar_mobil.append(
        MobilRental(
            "MR002", "Honda", 2021, 230000000,
            4, "Bensin", "Manual", "B5678CD",
            5, 400000
        )
    )

    daftar_mobil.append(
        MobilRental(
            "MR003", "Mitsubishi", 2023, 320000000,
            4, "Diesel", "Automatic", "D1234EF",
            7, 550000
        )
    )

    daftar_mobil.append(
        MobilRental(
            "MR004", "Suzuki", 2020, 180000000,
            4, "Bensin", "Manual", "F9876GH",
            7, 350000
        )
    )

    daftar_mobil.append(
        MobilRental(
            "MR005", "Daihatsu", 2022, 190000000,
            4, "Bensin", "Automatic", "B2468IJ",
            7, 375000
        )
    )


def tambah_data():
    """Menerima input user untuk menambahkan satu objek MobilRental."""
    print("\n--------------------------------------------------------------")
    print("Tambah Data Mobil Rental")
    print("--------------------------------------------------------------")

    id_kendaraan = baca_string("ID Kendaraan          : ")
    merk = baca_string("Merk                  : ")
    tahun_produksi = baca_int("Tahun Produksi        : ")
    harga = baca_float("Harga Kendaraan       : Rp ")
    jumlah_roda = baca_int("Jumlah Roda           : ")
    jenis_bahan_bakar = baca_string("Jenis Bahan Bakar     : ")
    transmisi = baca_string("Transmisi             : ")
    nomor_plat = baca_string("Nomor Plat            : ")
    kapasitas_penumpang = baca_int("Kapasitas Penumpang   : ")
    harga_sewa_per_hari = baca_float("Harga Sewa per Hari   : Rp ")

    mobil_baru = MobilRental(
        id_kendaraan,
        merk,
        tahun_produksi,
        harga,
        jumlah_roda,
        jenis_bahan_bakar,
        transmisi,
        nomor_plat,
        kapasitas_penumpang,
        harga_sewa_per_hari
    )

    daftar_mobil.append(mobil_baru)

    print("\nData berhasil ditambahkan.")


def main():
    isi_data_awal()

    print("=" * 62)
    print("             SISTEM DATA MOBIL RENTAL - PYTHON")
    print("=" * 62)

    print("\n5 DATA AWAL:")
    tampilkan_tabel()

    tambah_lagi = True

    while tambah_lagi:
        tambah_data()

        print("\nDATA SETELAH PENAMBAHAN:")
        tampilkan_tabel()

        tambah_lagi = baca_ya_tidak(
            "\nApakah ingin menambahkan data lagi? (y/n): "
        )

    print("\nProgram selesai. Terima kasih.")


if __name__ == "__main__":
    main()
