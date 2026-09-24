public class Kendaraan {
    // Atribut dasar Kendaraan
    protected String idKendaraan;
    protected String merk;
    protected int tahunProduksi;
    protected double harga;

    public Kendaraan(String idKendaraan, String merk, int tahunProduksi, double harga) {
        this.idKendaraan = idKendaraan;
        this.merk = merk;
        this.tahunProduksi = tahunProduksi;
        this.harga = harga;
    }

    public double hitungNilaiDepresiasi() {
        int umur = java.time.Year.now().getValue() - tahunProduksi;
        if (umur <= 0) {
            return 0;
        }

        // Estimasi depresiasi 5% per tahun
        return harga * 0.05 * umur;
    }

    public void tampilkanInfo() {
        System.out.println("ID Kendaraan : " + idKendaraan);
        System.out.println("Merk         : " + merk);
        System.out.println("Tahun        : " + tahunProduksi);
        System.out.println("Harga        : Rp " + harga);
    }
}
