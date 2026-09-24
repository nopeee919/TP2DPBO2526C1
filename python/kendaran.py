class Kendaraan:
    """Class dasar yang merepresentasikan kendaraan secara umum."""

    def __init__(self, id_kendaraan, merk, tahun_produksi, harga):
        self.id_kendaraan = id_kendaraan
        self.merk = merk
        self.tahun_produksi = tahun_produksi
        self.harga = harga

    def hitung_nilai_depresiasi(self):
        """Menghitung estimasi depresiasi 5% per tahun."""
        from datetime import datetime

        tahun_sekarang = datetime.now().year
        umur = tahun_sekarang - self.tahun_produksi

        if umur <= 0:
            return 0

        return self.harga * 0.05 * umur

    def tampilkan_info(self):
        print(f"ID Kendaraan : {self.id_kendaraan}")
        print(f"Merk         : {self.merk}")
        print(f"Tahun        : {self.tahun_produksi}")
        print(f"Harga        : Rp {self.harga:,.0f}")
