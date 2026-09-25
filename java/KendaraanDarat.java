public class KendaraanDarat extends Kendaraan {
  private int jumlahRoda;
  private String jenisBahanBakar;
  private String transmisi;

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
    return jumlahRoda >= 4 && getTahunProduksi() >= 2000;
  }

  public void tampilkanInfo() {
    super.tampilkanInfo();

    System.out.println("Jumlah Roda  : " + jumlahRoda);
    System.out.println("Bahan Bakar  : " + jenisBahanBakar);
    System.out.println("Transmisi    : " + transmisi);
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
}