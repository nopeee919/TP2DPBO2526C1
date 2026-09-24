<?php

require_once 'Kendaraan.php';

class KendaraanDarat extends Kendaraan
{
    protected int $jumlahRoda;
    protected string $jenisBahanBakar;
    protected string $transmisi;

    public function __construct(
        string $idKendaraan,
        string $merk,
        int $tahunProduksi,
        float $harga,
        int $jumlahRoda,
        string $jenisBahanBakar,
        string $transmisi
    ) {
        parent::__construct(
            $idKendaraan,
            $merk,
            $tahunProduksi,
            $harga
        );

        $this->jumlahRoda = $jumlahRoda;
        $this->jenisBahanBakar = $jenisBahanBakar;
        $this->transmisi = $transmisi;
    }

    public function cekKelayakanBerkendara(): bool
    {
        return $this->jumlahRoda >= 4 && $this->tahunProduksi >= 2000;
    }

    public function tampilkanInfo(): void
    {
        parent::tampilkanInfo();

        echo "Jumlah Roda  : {$this->jumlahRoda}<br>";
        echo "Bahan Bakar  : {$this->jenisBahanBakar}<br>";
        echo "Transmisi    : {$this->transmisi}<br>";
    }
}
?>
