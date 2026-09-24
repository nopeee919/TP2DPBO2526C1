<?php

require_once 'KendaraanDarat.php';

class MobilRental extends KendaraanDarat
{
    private string $nomorPlat;
    private int $kapasitasPenumpang;
    private float $hargaSewaPerHari;

    // Atribut khusus PHP sesuai requirement tugas.
    private string $fotoProduk;

    public function __construct(
        string $idKendaraan,
        string $merk,
        int $tahunProduksi,
        float $harga,
        int $jumlahRoda,
        string $jenisBahanBakar,
        string $transmisi,
        string $nomorPlat,
        int $kapasitasPenumpang,
        float $hargaSewaPerHari,
        string $fotoProduk
    ) {
        parent::__construct(
            $idKendaraan,
            $merk,
            $tahunProduksi,
            $harga,
            $jumlahRoda,
            $jenisBahanBakar,
            $transmisi
        );

        $this->nomorPlat = $nomorPlat;
        $this->kapasitasPenumpang = $kapasitasPenumpang;
        $this->hargaSewaPerHari = $hargaSewaPerHari;
        $this->fotoProduk = $fotoProduk;
    }

    public function hitungBiayaSewa(int $jumlahHari): float
    {
        return $this->hargaSewaPerHari * $jumlahHari;
    }

    public function tampilkanDetailRental(): void
    {
        $this->tampilkanInfo();

        echo "Nomor Plat   : {$this->nomorPlat}<br>";
        echo "Kapasitas    : {$this->kapasitasPenumpang} orang<br>";
        echo "Sewa/Hari    : " . formatRupiah($this->hargaSewaPerHari) . "<br>";
        echo "Foto Produk  : {$this->fotoProduk}<br>";
    }

    public function getIdKendaraan(): string
    {
        return $this->idKendaraan;
    }

    public function getMerk(): string
    {
        return $this->merk;
    }

    public function getTahunProduksi(): int
    {
        return $this->tahunProduksi;
    }

    public function getHarga(): float
    {
        return $this->harga;
    }

    public function getJumlahRoda(): int
    {
        return $this->jumlahRoda;
    }

    public function getJenisBahanBakar(): string
    {
        return $this->jenisBahanBakar;
    }

    public function getTransmisi(): string
    {
        return $this->transmisi;
    }

    public function getNomorPlat(): string
    {
        return $this->nomorPlat;
    }

    public function getKapasitasPenumpang(): int
    {
        return $this->kapasitasPenumpang;
    }

    public function getHargaSewaPerHari(): float
    {
        return $this->hargaSewaPerHari;
    }

    public function getFotoProduk(): string
    {
        return $this->fotoProduk;
    }
}
?>
