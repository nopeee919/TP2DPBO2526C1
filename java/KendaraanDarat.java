public class KendaraanDarat extends Kendaraan {
    // Atribut khusus kendaraan darat
    protected int jumlahRoda;
    protected String jenisBahanBakar;
    protected String transmisi;

    public KendaraanDarat(
            String idKendaraan,
            String merk,
            int tahunProduksi,
            double harga,
            int jumlahRoda,
            String jenisBahanBakar,
            String transmisi) {

        super(idKendaraan, merk, tahunProduksi, harga);
        this.jumlahRoda = jumlahRoda;
        this.jenisBahanBakar = jenisBahanBakar;
        this.transmisi = transmisi;
    }

    public boolean cekKelayakanBerkendara() {
        return jumlahRoda >= 4 && tahunProduksi >= 2000;
    }

    @Override
    public void tampilkanInfo() {
        super.tampilkanInfo();
        System.out.println("Jumlah Roda  : " + jumlahRoda);
        System.out.println("Bahan Bakar  : " + jenisBahanBakar);
        System.out.println("Transmisi    : " + transmisi);
    }
}
