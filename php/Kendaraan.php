<?php

class Kendaraan
{
    protected string $idKendaraan;
    protected string $merk;
    protected int $tahunProduksi;
    protected float $harga;

    public function __construct(
        string $idKendaraan,
        string $merk,
        int $tahunProduksi,
        float $harga
    ) {
        $this->idKendaraan = $idKendaraan;
        $this->merk = $merk;
        $this->tahunProduksi = $tahunProduksi;
        $this->harga = $harga;
    }

    public function hitungNilaiDepresiasi(): float
    {
        $tahunSekarang = (int) date('Y');
        $umur = $tahunSekarang - $this->tahunProduksi;

        if ($umur <= 0) {
            return 0;
        }

        return $this->harga * 0.05 * $umur;
    }

    public function tampilkanInfo(): void
    {
        echo "ID Kendaraan : {$this->idKendaraan}<br>";
        echo "Merk         : {$this->merk}<br>";
        echo "Tahun        : {$this->tahunProduksi}<br>";
        echo "Harga        : " . formatRupiah($this->harga) . "<br>";
    }
}
?>
