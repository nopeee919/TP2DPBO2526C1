public class MobilRental extends KendaraanDarat {
    // Atribut khusus mobil rental
    private String nomorPlat;
    private int kapasitasPenumpang;
    private double hargaSewaPerHari;

    public MobilRental(
            String idKendaraan,
            String merk,
            int tahunProduksi,
            double harga,
            int jumlahRoda,
            String jenisBahanBakar,
            String transmisi,
            String nomorPlat,
            int kapasitasPenumpang,
            double hargaSewaPerHari) {

        super(
            idKendaraan,
            merk,
            tahunProduksi,
            harga,
            jumlahRoda,
            jenisBahanBakar,
            transmisi
        );

        this.nomorPlat = nomorPlat;
        this.kapasitasPenumpang = kapasitasPenumpang;
        this.hargaSewaPerHari = hargaSewaPerHari;
    }

    public double hitungBiayaSewa(int jumlahHari) {
        return hargaSewaPerHari * jumlahHari;
    }

    public void tampilkanDetailRental() {
        tampilkanInfo();
        System.out.println("Nomor Plat   : " + nomorPlat);
        System.out.println("Kapasitas    : " + kapasitasPenumpang + " orang");
        System.out.println("Sewa/Hari    : Rp " + hargaSewaPerHari);
    }

    // Getter untuk kebutuhan tabel
    public String getIdKendaraan() {
        return idKendaraan;
    }

    public String getMerk() {
        return merk;
    }

    public int getTahunProduksi() {
        return tahunProduksi;
    }

    public double getHarga() {
        return harga;
    }

    public int getJumlahRoda() {
        return jumlahRoda;
    }

    public String getJenisBahanBakar() {
        return jenisBahanBakar;
    }

    public String getTransmisi() {
        return transmisi;
    }

    public String getNomorPlat() {
        return nomorPlat;
    }

    public int getKapasitasPenumpang() {
        return kapasitasPenumpang;
    }

    public double getHargaSewaPerHari() {
        return hargaSewaPerHari;
    }
}
