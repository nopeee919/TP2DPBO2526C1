import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class Main {

    private static final Scanner scanner = new Scanner(System.in);
    private static final ArrayList<MobilRental> daftarMobil = new ArrayList<>();

    public static void main(String[] args) {
        isiDataAwal();

        System.out.println("==============================================================");
        System.out.println("             SISTEM DATA MOBIL RENTAL - JAVA");
        System.out.println("==============================================================");
        System.out.println("\n5 DATA AWAL:");
        tampilkanTabel();

        boolean tambahLagi = true;

        while (tambahLagi) {
            System.out.println("\n--------------------------------------------------------------");
            System.out.println("Tambah Data Mobil Rental");
            System.out.println("--------------------------------------------------------------");

            tambahData();

            System.out.println("\nDATA SETELAH PENAMBAHAN:");
            tampilkanTabel();

            tambahLagi = bacaYaTidak("\nApakah ingin menambahkan data lagi? (y/n): ");
        }

        System.out.println("\nProgram selesai. Terima kasih.");
        scanner.close();
    }

    // Lima objek awal sebelum input user
    private static void isiDataAwal() {
        daftarMobil.add(new MobilRental(
                "MR001", "Toyota", 2022, 250000000,
                4, "Bensin", "Automatic", "B1234AB",
                7, 450000
        ));

        daftarMobil.add(new MobilRental(
                "MR002", "Honda", 2021, 230000000,
                4, "Bensin", "Manual", "B5678CD",
                5, 400000
        ));

        daftarMobil.add(new MobilRental(
                "MR003", "Mitsubishi", 2023, 320000000,
                4, "Diesel", "Automatic", "D1234EF",
                7, 550000
        ));

        daftarMobil.add(new MobilRental(
                "MR004", "Suzuki", 2020, 180000000,
                4, "Bensin", "Manual", "F9876GH",
                7, 350000
        ));

        daftarMobil.add(new MobilRental(
                "MR005", "Daihatsu", 2022, 190000000,
                4, "Bensin", "Automatic", "B2468IJ",
                7, 375000
        ));
    }

    private static void tambahData() {
        String id = bacaString("ID Kendaraan          : ");
        String merk = bacaString("Merk                  : ");
        int tahun = bacaInt("Tahun Produksi        : ");
        double harga = bacaDouble("Harga Kendaraan       : Rp ");
        int roda = bacaInt("Jumlah Roda            : ");
        String bahanBakar = bacaString("Jenis Bahan Bakar     : ");
        String transmisi = bacaString("Transmisi             : ");
        String plat = bacaString("Nomor Plat            : ");
        int kapasitas = bacaInt("Kapasitas Penumpang   : ");
        double hargaSewa = bacaDouble("Harga Sewa per Hari   : Rp ");

        MobilRental mobilBaru = new MobilRental(
                id,
                merk,
                tahun,
                harga,
                roda,
                bahanBakar,
                transmisi,
                plat,
                kapasitas,
                hargaSewa
        );

        daftarMobil.add(mobilBaru);

        System.out.println("\nData berhasil ditambahkan.");
    }

    private static void tampilkanTabel() {
        String format =
                "| %-6s | %-13s | %-6s | %-15s | %-5s | %-10s | %-10s | %-10s | %-10s | %-15s |%n";

        String garis = "+--------+---------------+--------+-----------------+-------+------------+------------+------------+------------+-----------------+";

        System.out.println(garis);
        System.out.printf(format,
                "ID", "Merk", "Tahun", "Harga", "Roda",
                "BBM", "Transmisi", "Plat", "Kapasitas", "Sewa/Hari");
        System.out.println(garis);

        for (MobilRental mobil : daftarMobil) {
            System.out.printf(format,
                    mobil.getIdKendaraan(),
                    potong(mobil.getMerk(), 13),
                    mobil.getTahunProduksi(),
                    formatRupiah(mobil.getHarga()),
                    mobil.getJumlahRoda(),
                    potong(mobil.getJenisBahanBakar(), 10),
                    potong(mobil.getTransmisi(), 10),
                    potong(mobil.getNomorPlat(), 10),
                    mobil.getKapasitasPenumpang() + " org",
                    formatRupiah(mobil.getHargaSewaPerHari())
            );
        }

        System.out.println(garis);
        System.out.println("Total data: " + daftarMobil.size() + " mobil");
    }

    private static String bacaString(String pesan) {
        while (true) {
            System.out.print(pesan);
            String input = scanner.nextLine().trim();

            if (!input.isEmpty()) {
                return input;
            }

            System.out.println("Input tidak boleh kosong.");
        }
    }

    private static int bacaInt(String pesan) {
        while (true) {
            System.out.print(pesan);

            try {
                return Integer.parseInt(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Masukkan angka bulat yang valid.");
            }
        }
    }

    private static double bacaDouble(String pesan) {
        while (true) {
            System.out.print(pesan);

            try {
                return Double.parseDouble(scanner.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("Masukkan angka yang valid.");
            }
        }
    }

    private static boolean bacaYaTidak(String pesan) {
        while (true) {
            System.out.print(pesan);
            String jawaban = scanner.nextLine().trim().toLowerCase();

            if (jawaban.equals("y") || jawaban.equals("ya")) {
                return true;
            }

            if (jawaban.equals("n") || jawaban.equals("tidak")) {
                return false;
            }

            System.out.println("Masukkan y/ya atau n/tidak.");
        }
    }

    private static String formatRupiah(double nilai) {
        NumberFormat format = NumberFormat.getCurrencyInstance(new Locale("id", "ID"));
        return format.format(nilai).replace(",00", "");
    }

    private static String potong(String teks, int panjang) {
        if (teks.length() <= panjang) {
            return teks;
        }

        return teks.substring(0, panjang - 3) + "...";
    }
}
