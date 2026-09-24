<?php

require_once 'MobilRental.php';

function formatRupiah(float $nilai): string
{
    return 'Rp ' . number_format($nilai, 0, ',', '.');
}

$daftarMobil = [];

// Lima objek awal sebelum user melakukan input.
$daftarMobil[] = new MobilRental(
    'MR001',
    'Toyota',
    2022,
    250000000,
    4,
    'Bensin',
    'Automatic',
    'B1234AB',
    7,
    450000,
    'foto_produk/toyota.jpg'
);

$daftarMobil[] = new MobilRental(
    'MR002',
    'Honda',
    2021,
    230000000,
    4,
    'Bensin',
    'Manual',
    'B5678CD',
    5,
    400000,
    'foto_produk/honda.jpg'
);

$daftarMobil[] = new MobilRental(
    'MR003',
    'Mitsubishi',
    2023,
    320000000,
    4,
    'Diesel',
    'Automatic',
    'D1234EF',
    7,
    550000,
    'foto_produk/mitsubishi.jpg'
);

$daftarMobil[] = new MobilRental(
    'MR004',
    'Suzuki',
    2020,
    180000000,
    4,
    'Bensin',
    'Manual',
    'F9876GH',
    7,
    350000,
    'foto_produk/suzuki.jpg'
);

$daftarMobil[] = new MobilRental(
    'MR005',
    'Daihatsu',
    2022,
    190000000,
    4,
    'Bensin',
    'Automatic',
    'B2468IJ',
    7,
    375000,
    'foto_produk/daihatsu.jpg'
);

// PHP boleh menggunakan hardcode atau interaktif.
// Di sini dibuat interaktif menggunakan form POST.
$pesan = '';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $id = trim($_POST['idKendaraan'] ?? '');
    $merk = trim($_POST['merk'] ?? '');
    $tahun = (int) ($_POST['tahunProduksi'] ?? 0);
    $harga = (float) ($_POST['harga'] ?? 0);
    $roda = (int) ($_POST['jumlahRoda'] ?? 0);
    $bahanBakar = trim($_POST['jenisBahanBakar'] ?? '');
    $transmisi = trim($_POST['transmisi'] ?? '');
    $plat = trim($_POST['nomorPlat'] ?? '');
    $kapasitas = (int) ($_POST['kapasitasPenumpang'] ?? 0);
    $hargaSewa = (float) ($_POST['hargaSewaPerHari'] ?? 0);
    $foto = trim($_POST['fotoProduk'] ?? '');

    if (
        $id !== '' &&
        $merk !== '' &&
        $tahun > 0 &&
        $harga >= 0 &&
        $roda > 0 &&
        $bahanBakar !== '' &&
        $transmisi !== '' &&
        $plat !== '' &&
        $kapasitas > 0 &&
        $hargaSewa >= 0 &&
        $foto !== ''
    ) {
        $daftarMobil[] = new MobilRental(
            $id,
            $merk,
            $tahun,
            $harga,
            $roda,
            $bahanBakar,
            $transmisi,
            $plat,
            $kapasitas,
            $hargaSewa,
            $foto
        );

        $pesan = 'Data berhasil ditambahkan.';
    } else {
        $pesan = 'Data belum ditambahkan. Pastikan semua input diisi dengan benar.';
    }
}
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sistem Data Mobil Rental - PHP</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 30px;
            background: #f5f5f5;
        }

        h1, h2 {
            text-align: center;
        }

        .container {
            max-width: 1500px;
            margin: auto;
        }

        .form-box {
            background: white;
            padding: 20px;
            margin-bottom: 25px;
            border-radius: 8px;
            box-shadow: 0 2px 8px rgba(0,0,0,0.08);
        }

        .form-grid {
            display: grid;
            grid-template-columns: repeat(2, 1fr);
            gap: 12px 20px;
        }

        label {
            font-weight: bold;
        }

        input, select {
            width: 100%;
            padding: 9px;
            margin-top: 5px;
            box-sizing: border-box;
        }

        button {
            margin-top: 18px;
            padding: 10px 20px;
            cursor: pointer;
        }

        .pesan {
            padding: 12px;
            margin-bottom: 15px;
            background: #e8f4ff;
            border: 1px solid #b7dcf8;
        }

        .table-wrapper {
            overflow-x: auto;
            background: white;
            padding: 15px;
            border-radius: 8px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            min-width: 1250px;
        }

        th, td {
            border: 1px solid #999;
            padding: 8px;
            text-align: center;
            white-space: nowrap;
        }

        th {
            background: #eeeeee;
        }

        img {
            width: 80px;
            height: 55px;
            object-fit: cover;
        }

        .total {
            font-weight: bold;
            margin-top: 10px;
        }
    </style>
</head>

<body>

<div class="container">

    <h1>SISTEM DATA MOBIL RENTAL - PHP</h1>

    <div class="form-box">
        <h2>Tambah Data Mobil Rental</h2>

        <?php if ($pesan !== ''): ?>
            <div class="pesan">
                <?= htmlspecialchars($pesan) ?>
            </div>
        <?php endif; ?>

        <form method="POST">
            <div class="form-grid">

                <div>
                    <label>ID Kendaraan</label>
                    <input type="text" name="idKendaraan" required>
                </div>

                <div>
                    <label>Merk</label>
                    <input type="text" name="merk" required>
                </div>

                <div>
                    <label>Tahun Produksi</label>
                    <input type="number" name="tahunProduksi" required>
                </div>

                <div>
                    <label>Harga Kendaraan</label>
                    <input type="number" name="harga" min="0" required>
                </div>

                <div>
                    <label>Jumlah Roda</label>
                    <input type="number" name="jumlahRoda" min="1" required>
                </div>

                <div>
                    <label>Jenis Bahan Bakar</label>
                    <input type="text" name="jenisBahanBakar" required>
                </div>

                <div>
                    <label>Transmisi</label>
                    <input type="text" name="transmisi" required>
                </div>

                <div>
                    <label>Nomor Plat</label>
                    <input type="text" name="nomorPlat" required>
                </div>

                <div>
                    <label>Kapasitas Penumpang</label>
                    <input type="number" name="kapasitasPenumpang" min="1" required>
                </div>

                <div>
                    <label>Harga Sewa per Hari</label>
                    <input type="number" name="hargaSewaPerHari" min="0" required>
                </div>

                <div>
                    <label>Foto Produk</label>
                    <input type="text" name="fotoProduk"
                           placeholder="contoh: foto_produk/mobil.jpg" required>
                </div>

            </div>

            <button type="submit">Tambah Data</button>
        </form>
    </div>

    <h2>Seluruh Data Mobil Rental</h2>

    <div class="table-wrapper">
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Foto Produk</th>
                    <th>Merk</th>
                    <th>Tahun</th>
                    <th>Harga</th>
                    <th>Roda</th>
                    <th>BBM</th>
                    <th>Transmisi</th>
                    <th>Plat</th>
                    <th>Kapasitas</th>
                    <th>Sewa/Hari</th>
                </tr>
            </thead>

            <tbody>
                <?php foreach ($daftarMobil as $mobil): ?>
                    <tr>
                        <td><?= htmlspecialchars($mobil->getIdKendaraan()) ?></td>

                        <td>
                            <?php
                            $foto = $mobil->getFotoProduk();

                            if (file_exists($foto)):
                            ?>
                                <img
                                    src="<?= htmlspecialchars($foto) ?>"
                                    alt="Foto <?= htmlspecialchars($mobil->getMerk()) ?>"
                                >
                            <?php else: ?>
                                <?= htmlspecialchars($foto) ?>
                            <?php endif; ?>
                        </td>

                        <td><?= htmlspecialchars($mobil->getMerk()) ?></td>
                        <td><?= $mobil->getTahunProduksi() ?></td>
                        <td><?= formatRupiah($mobil->getHarga()) ?></td>
                        <td><?= $mobil->getJumlahRoda() ?></td>
                        <td><?= htmlspecialchars($mobil->getJenisBahanBakar()) ?></td>
                        <td><?= htmlspecialchars($mobil->getTransmisi()) ?></td>
                        <td><?= htmlspecialchars($mobil->getNomorPlat()) ?></td>
                        <td><?= $mobil->getKapasitasPenumpang() ?> orang</td>
                        <td><?= formatRupiah($mobil->getHargaSewaPerHari()) ?></td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>

        <div class="total">
            Total data: <?= count($daftarMobil) ?> mobil
        </div>
    </div>

</div>

</body>
</html>
