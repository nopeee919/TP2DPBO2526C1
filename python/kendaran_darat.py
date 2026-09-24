from kendaran import Kendaraan


class KendaraanDarat(Kendaraan):
    """Kendaraan yang bergerak menggunakan permukaan darat."""

    def __init__(
        self,
        id_kendaraan,
        merk,
        tahun_produksi,
        harga,
        jumlah_roda,
        jenis_bahan_bakar,
        transmisi
    ):
        super().__init__(id_kendaraan, merk, tahun_produksi, harga)

        self.jumlah_roda = jumlah_roda
        self.jenis_bahan_bakar = jenis_bahan_bakar
        self.transmisi = transmisi

    def cek_kelayakan_berkendara(self):
        return self.jumlah_roda >= 4 and self.tahun_produksi >= 2000

    def tampilkan_info(self):
        super().tampilkan_info()
        print(f"Jumlah Roda  : {self.jumlah_roda}")
        print(f"Bahan Bakar  : {self.jenis_bahan_bakar}")
        print(f"Transmisi    : {self.transmisi}")
