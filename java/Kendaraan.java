public class Kendaraan {
  private String idKendaraan;
  private String merk;
  private int tahunProduksi;
  private double harga;

  public Kendaraan(String idKendaraan, String merk, int tahunProduksi, double harga) {
    this.idKendaraan = idKendaraan;
    this.merk = merk;
    this.tahunProduksi = tahunProduksi;
    this.harga = harga;
  }

  public double hitungNilaiDepresiasi() {
    return 0;
  }

  public void tampilkanInfo() {
    System.out.println("ID Kendaraan : " + idKendaraan);
    System.out.println("Merk         : " + merk);
    System.out.println("Tahun        : " + tahunProduksi);
    System.out.println("Harga        : Rp " + harga);
  }

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
}