public class MobilRental extends KendaraanDarat {
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
        transmisi);

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