from kendaran_darat import KendaraanDarat


class MobilRental(KendaraanDarat):
    """Mobil yang digunakan sebagai kendaraan untuk layanan rental."""

    def __init__(
        self,
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
    ):
        super().__init__(
            id_kendaraan,
            merk,
            tahun_produksi,
            harga,
            jumlah_roda,
            jenis_bahan_bakar,
            transmisi
        )

        self.nomor_plat = nomor_plat
        self.kapasitas_penumpang = kapasitas_penumpang
        self.harga_sewa_per_hari = harga_sewa_per_hari

    def hitung_biaya_sewa(self, jumlah_hari):
        return self.harga_sewa_per_hari * jumlah_hari

    def tampilkan_detail_rental(self):
        self.tampilkan_info()
        print(f"Nomor Plat   : {self.nomor_plat}")
        print(f"Kapasitas    : {self.kapasitas_penumpang} orang")
        print(f"Sewa/Hari    : Rp {self.harga_sewa_per_hari:,.0f}")
