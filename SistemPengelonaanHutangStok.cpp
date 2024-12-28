#include <iostream>
#include <string>
using namespace std;

// Asumsi sebuah table pada database
const int maxPembeli = 100;
const int maxProduk = 100;

// Variable Pembeli
int idPembeli[maxPembeli];
string namaPembeli[maxPembeli];
string alamatPembeli[maxPembeli];
string noTelpPembeli[maxPembeli];
float limitHutangPembeli[maxPembeli];
string statusPembeli[maxPembeli];
float hutangPembeli[maxPembeli];
int totalPembeli = 0;

// Variable Produk
string kodeProduk[maxProduk];
string namaProduk[maxProduk];
string kategoriProduk[maxProduk];
int stokProduk[maxProduk];
int stokMinimalProduk[maxProduk];
int stokMaksimalProduk[maxProduk];
int hargaModalProduk[maxProduk];
int hargaJualProduk[maxProduk];
int totalProduk = 0;

// Fungsi Login
void login();

// ======== Fungsi Admin =========
void menuAdmin();
void manajemenPembelidenganHutang();
void manajemenProduk();
// A. Manajemen Pembeli dengan Hutang
void tambahPembeli();
void riwayatPembelian();
void lihatPembeliJatuhTempo();
void blacklistPembeli();

// B. Manajemen Produk
void tambahProduk();
void aturMarginKeuntungan();
void lihatRestock();

// ======== Fungsi Kasir =========
void menuKasir();
void manajemenTransaksiHutang();
void manajemenStok();
// A. Transaksi Hutang
void tambahTransaksiHutang();
void tambahPembayaranHutang();
void lihatSisaHutang();

// B. Manajemen Stok
void tambahBarangMasuk();
void lihatStokMenipis();

int main()
{
    login();
    return 0;
}

// Fungsi Login
void login()
{
    string username, password;

    cout << "=== Kelompok 5 - Pengelolaan Hutang dan Stok ===\n";
    cout << "Nama Pengguna : ";
    cin >> username;
    cout << "Kata Sandi : ";
    cin >> password;

    if (username == "admin" && password == "admin123")
    {
        cout << "Masuk berhasil sebagai Admin.\n";
        menuAdmin();
    }
    else if (username == "kasir" && password == "kasir123")
    {
        cout << "Masuk berhasil sebagai Kasir.\n";
        menuKasir();
    }
    else
    {
        cout << "Nama Pengguna atau Kata Sandi salah yang anda masukan salah! Silakan coba lagi.\n";
        login();
    }
}

void menuAdmin()
{
    int pilihan;
    do
    {
        cout << "\n=== Menu Admin ===\n";
        cout << "Pilih Menu : \n";
        cout << "1. Manajemen Pembeli dengan Hutang.\n2. Manajemen Produk.\n3. Kembali ke halaman sebelumnya\n4. Keluar\n";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            manajemenPembelidenganHutang();
            break;
        case 2:
            manajemenProduk();
            break;
        case 3:
            login();
            break;
        case 4:
            cout << "Keluar berhasil.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 4);
}

void manajemenPembelidenganHutang()
{
    int pilihan;
    do
    {
        cout << "\n=== [Admin] Manajemen Pembeli dengan Hutang ===\n";
        cout << "Pilih Menu: \n";
        cout << "1. Tambah Pembeli.\n2. Riwayat Pembelian per Pembeli.\n3. Lihat Pembeli yang Melebihi Jatuh Tempo.\n4. Menetapkan Pembeli ke Status Blacklist.\n5. Kembali ke Menu Admin.\n";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahPembeli();
            break;
        case 2:
            riwayatPembelian();
            break;
        case 3:
            lihatPembeliJatuhTempo();
            break;
        case 4:
            blacklistPembeli();
            break;
        case 5:
            menuAdmin();
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 5);
}

void manajemenProduk()
{
    int pilihan;
    do
    {
        cout << "\n=== [Admin] Manajemen Produk ===\n";
        cout << "Pilih Menu: \n";
        cout << "1. Tambah Produk.\n2. Mengatur Margin Keuntungan per Kategori.\n3. Melihat Produk Perlu Restok.\n4. Kembali ke Menu Admin.\n";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            tambahProduk();
            break;
        case 2:
            aturMarginKeuntungan();
            break;
        case 3:
            lihatRestock();
            break;
        case 4:
            menuAdmin();
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 4);
}
void tambahPembeli()
{
    if (totalPembeli < maxPembeli)
    {
        cout << "\n=== Tambah Pembeli ===\n";
        cout << "ID Pembeli: ";
        cin >> idPembeli[totalPembeli];
        cout << "Nama Pembeli: ";
        cin >> namaPembeli[totalPembeli];
        cout << "Alamat: ";
        cin >> alamatPembeli[totalPembeli];
        cout << "Nomor Telepon: ";
        cin >> noTelpPembeli[totalPembeli];
        cout << "Limit Hutang: ";
        cin >> limitHutangPembeli[totalPembeli];
        hutangPembeli[totalPembeli] = 0;
        statusPembeli[totalPembeli] = "Aktif";

        totalPembeli++;
        cout << "Pembeli berhasil ditambahkan!\n";
    }
    else
    {
        cout << "Data penuh, tidak bisa menambah pembeli lagi.\n";
    }
}

void riwayatPembelian()
{
    int id;
    cout << "\n=== Riwayat Pembelian ===\n";
    cout << "Masukkan ID Pembeli: ";
    cin >> id;

    bool pembeliDitemukan = false;
    for (int i = 0; i < totalPembeli; i++)
    {
        if (idPembeli[i] == id)
        {
            pembeliDitemukan = true;
            cout << "Nama: " << namaPembeli[i] << endl;
            cout << "Alamat: " << alamatPembeli[i] << endl;
            cout << "Hutang: " << hutangPembeli[i] << endl;
            cout << "Belum ada data riwayat pembelian yang tersedia.\n";
            break;
        }
    }
    if (!pembeliDitemukan)
    {
        cout << "Pembeli dengan ID tersebut tidak ditemukan.\n";
    }
}
void lihatPembeliJatuhTempo()
{
    cout << "\n=== Pembeli Melebihi Jatuh Tempo ===\n";
    for (int i = 0; i < totalPembeli; i++)
    {
        if (hutangPembeli[i] >= limitHutangPembeli[i])
        {
            cout << "ID: " << idPembeli[i]
                 << ", Nama: " << namaPembeli[i]
                 << ", Hutang: " << hutangPembeli[i] << endl;
        }
        else
        {
            cout << "Belum ada pembeli melebihi jatuh tempo.\n";
        }
    }
}

void blacklistPembeli()
{
    int id;
    cout << "\n=== Blacklist Pembeli ===\n";
    cout << "Masukkan ID Pembeli: ";
    cin >> id;

    bool pembeliDitemukan = false;
    for (int i = 0; i < totalPembeli; i++)
    {
        if (idPembeli[i] == id)
        {
            pembeliDitemukan = true;
            if (hutangPembeli[i] > limitHutangPembeli[i])
            {
                statusPembeli[i] = "Blacklist";
                cout << "Pembeli dengan ID " << id << " telah di-blacklist.\n";
            }
            else
            {
                cout << "Pembeli tidak memiliki hutang melebihi limit.\n";
            }
            break;
        }
    }
    if (!pembeliDitemukan)
    {
        cout << "Pembeli dengan ID tersebut tidak ditemukan.\n";
    }
}

void aturMarginKeuntungan()
{
    string kategori;
    float margin;
    cout << "\n=== Atur Margin Keuntungan ===\n";
    cout << "Masukkan Kategori Produk: ";
    cin >> kategori;
    cout << "Masukkan Margin Keuntungan (%): ";
    cin >> margin;

    for (int i = 0; i < totalProduk; i++)
    {
        if (kategoriProduk[i] == kategori)
        {
            hargaJualProduk[i] = hargaModalProduk[i] + (hargaModalProduk[i] * margin / 100);
            cout << "Produk: " << namaProduk[i]
                 << " - Harga Jual diperbarui: " << hargaJualProduk[i] << endl;
        }
    }
}

void tambahProduk()
{
    if (totalProduk < maxProduk)
    {
        cout << "\n=== Tambah Produk ===\n";
        cout << "Kode Produk: ";
        cin >> kodeProduk[totalProduk];
        cout << "Nama Produk: ";
        cin >> namaProduk[totalProduk];
        cout << "Harga Modal: ";
        cin >> hargaModalProduk[totalProduk];
        cout << "Harga Jual: ";
        cin >> hargaJualProduk[totalProduk];
        cout << "Kategori Produk: ";
        cin >> kategoriProduk[totalProduk];
        cout << "Stok Minimal: ";
        cin >> stokMinimalProduk[totalProduk];
        cout << "Stok Maksimal: ";
        cin >> stokMaksimalProduk[totalProduk];

        int stokAwal;
        do
        {
            cout << "Stok Awal (maksimal " << stokMaksimalProduk[totalProduk] << "): ";
            cin >> stokAwal;
            if (stokAwal > stokMaksimalProduk[totalProduk])
            {
                cout << "Error: Stok melebihi batas maksimal!\n";
            }
        } while (stokAwal > stokMaksimalProduk[totalProduk]);

        stokProduk[totalProduk] = stokAwal;

        totalProduk++;
        cout << "Produk berhasil ditambahkan!\n";
    }
    else
    {
        cout << "Data penuh, tidak bisa menambah produk lagi.\n";
    }
}

void lihatRestock()
{
    cout << "\n=== Produk Perlu Restock ===\n";
    for (int i = 0; i < totalProduk; i++)
    {
        if (stokProduk[i] <= stokMinimalProduk[i])
        {
            cout << "Kode: " << kodeProduk[i]
                 << ", Nama: " << namaProduk[i]
                 << ", Stok: " << stokProduk[i] << endl;
        }
    }
}

void menuKasir()
{
    int pilihan;
    do
    {
        cout << "\n=== Menu Kasir ===\n";
        cout << "Pilih Menu : \n";
        cout << "1. Manajemen Transaksi Hutang.\n2. Manajemen Stok Produk.\n3. Kembali ke halaman sebelumnya\n4. Keluar\n";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            manajemenTransaksiHutang();
            break;
        case 2:
            manajemenStok();
            break;
        case 3:
            login();
            break;
        case 4:
            cout << "Keluar berhasil.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 4);
}

void manajemenTransaksiHutang()
{
    int pilihan;
    do
    {
        cout << "\n=== [Kasir] Menu Manajemen Transaksi Hutang ===\n";
        cout << "Pilih Menu : \n";
        cout << "1. Tambah Transaksi Hutang.\n2. Tambah Pembayaran Hutang.\n3. Lihat Sisa Hutang.\n4. Kembali ke halaman sebelumnya\n5. Keluar\n";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahTransaksiHutang();
            break;
        case 2:
            tambahPembayaranHutang();
            break;
        case 3:
            lihatSisaHutang();
            break;
        case 4:
            menuKasir();
            break;
        case 5:
            cout << "Keluar berhasil.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 5);
}
void manajemenStok()
{
    int pilihan;
    do
    {
        cout << "\n=== [Kasir] Menu Manajemen Stok ===\n";
        cout << "Pilih Menu : \n";
        cout << "1. Tambah Barang Masuk.\n2. Lihat Stok Menipis.\n3. Kembali ke halaman sebelumnya\n4. Keluar\n";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBarangMasuk();
            break;
        case 2:
            lihatStokMenipis();
            break;
        case 3:
            menuKasir();
            break;
        case 4:
            cout << "Keluar berhasil.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
            break;
        }
    } while (pilihan != 4);
}
void tambahTransaksiHutang()
{
    cout << "\n=== Transaksi Hutang ===\n";
    int id;
    string kode;
    int jumlah;
    int jatuhTempo;

    cout << "ID Pembeli: ";
    cin >> id;
    cout << "Kode Produk: ";
    cin >> kode;
    cout << "Jumlah: ";
    cin >> jumlah;
    cout << "Jatuh Tempo (hari): ";
    cin >> jatuhTempo;

    for (int i = 0; i < totalPembeli; i++)
    {
        if (idPembeli[i] == id)
        {
            hutangPembeli[i] += jumlah * hargaJualProduk[i];
            cout << "Hutang berhasil dicatat untuk " << namaPembeli[i] << endl;
            return;
        }
    }
    cout << "ID Pembeli tidak ditemukan.\n";
}

void tambahPembayaranHutang()
{
    cout << "\n=== Pembayaran Hutang ===\n";
    int id;
    float bayar;

    cout << "ID Pembeli: ";
    cin >> id;
    cout << "Jumlah Pembayaran: ";
    cin >> bayar;

    for (int i = 0; i < totalPembeli; i++)
    {
        if (idPembeli[i] == id)
        {
            if (bayar <= hutangPembeli[i])
            {
                hutangPembeli[i] -= bayar;
                cout << "Pembayaran berhasil untuk " << namaPembeli[i] << endl;
            }
            else
            {
                cout << "Pembayaran melebihi hutang!\n";
            }
            return;
        }
    }
    cout << "ID Pembeli tidak ditemukan.\n";
}
void lihatSisaHutang()
{
    cout << "\n=== Sisa Hutang ===\n";
    int id;

    cout << "ID Pembeli: ";
    cin >> id;

    for (int i = 0; i < totalPembeli; i++)
    {
        if (idPembeli[i] == id)
        {
            cout << "Sisa hutang untuk " << namaPembeli[i] << ": " << hutangPembeli[i] << endl;
            return;
        }
    }
    cout << "ID Pembeli tidak ditemukan.\n";
}
void tambahBarangMasuk()
{
    cout << "\n=== Barang Masuk ===\n";
    string kode;
    int jumlah;

    cout << "Kode Produk: ";
    cin >> kode;
    cout << "Jumlah Masuk: ";
    cin >> jumlah;

    for (int i = 0; i < totalProduk; i++)
    {
        if (kodeProduk[i] == kode)
        {
            stokProduk[i] += jumlah;
            cout << "Barang berhasil ditambahkan ke stok " << namaProduk[i] << endl;
            return;
        }
    }
    cout << "Kode Produk tidak ditemukan.\n";
}
void lihatStokMenipis()
{
    cout << "\n=== Lihat Stok ===\n";
    if (totalProduk == 0)
    {
        cout << "Data stok kosong.\n";
        return;
    }
    for (int i = 0; i < totalProduk; i++)
    {
        cout << "Kode: " << kodeProduk[i]
             << ", Nama: " << namaProduk[i]
             << ", Stok: " << stokProduk[i] << endl;
    }
}
