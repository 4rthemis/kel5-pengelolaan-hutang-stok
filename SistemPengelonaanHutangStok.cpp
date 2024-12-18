#include <iostream>
#include <string>
using namespace std;

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
int stokProduk[maxProduk];
int stokMinimalProduk[maxProduk];
int stokMaksimalProduk[maxProduk]; 
int hargaModalProduk[maxProduk];
int hargaJualProduk[maxProduk];
int totalProduk = 0;

// Fungsi Login
void login();

// Fungsi Admin
void menuAdmin();
void tambahPembeli();
void lihatPembeli();
void tambahProduk();
void lihatRestock();

int main() {
    login();
    return 0;
}

// Fungsi Login
void login() {
    string username, password;

    cout << "=== Kelompok 5 - Pengelolaan Hutang dan Stok ===\n";
    cout << "Nama Pengguna : ";
    cin >> username;
    cout << "Kata Sandi : ";
    cin >> password;

    if (username == "admin" && password == "admin123") {
        cout << "Login berhasil sebagai Admin.\n";
        menuAdmin();
    } else if (username == "kasir" && password == "kasir123") {
        cout << "Login berhasil sebagai Kasir.\n";
        // Menu Kasir
    } else {
        cout << "Nama Pengguna atau Kata Sandi salah! Silakan coba lagi.\n";
        login();
    }
}

void menuAdmin() {
    int pilihan;
    do {
        cout << "\n=== Menu Admin ===\n";
        cout << "1. Tambah Pembeli\n2. Lihat Daftar Pembeli\n3. Tambah Produk\n4. Lihat Produk Perlu Restock\n0. Logout\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPembeli(); break;
            case 2: lihatPembeli(); break;
            case 3: tambahProduk(); break;
            case 4: lihatRestock(); break;
            case 0: cout << "Logout berhasil.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
}

void tambahPembeli() {
    if (totalPembeli < maxPembeli) {
        cout << "\n=== Tambah Pembeli ===\n";
        cout << "ID Pembeli: ";
        cin >> idPembeli[totalPembeli];
        cout << "Nama Pembeli: ";
        cin >> namaPembeli[totalPembeli];
        cout << "Alamat: ";
        cin.ignore(); // Membersihkan buffer input
        getline(cin, alamatPembeli[totalPembeli]);
        cout << "Nomor Telepon: ";
        cin >> noTelpPembeli[totalPembeli];
        cout << "Limit Hutang: ";
        cin >> limitHutangPembeli[totalPembeli];
        hutangPembeli[totalPembeli] = 0; // Hutang awal adalah 0
        statusPembeli[totalPembeli] = "Aktif";

        totalPembeli++;
        cout << "Pembeli berhasil ditambahkan!\n";
    } else {
        cout << "Data penuh, tidak bisa menambah pembeli lagi.\n";
    }
}

void lihatPembeli() {
    cout << "\n=== Daftar Pembeli ===\n";
    for (int i = 0; i < totalPembeli; i++) {
        cout << "ID: " << idPembeli[i]
             << ", Nama: " << namaPembeli[i]
             << ", Status: " << statusPembeli[i] << endl;
    }
}

void tambahProduk() {
    if (totalProduk < maxProduk) {
        cout << "\n=== Tambah Produk ===\n";
        cout << "Kode Produk: ";
        cin >> kodeProduk[totalProduk];
        cout << "Nama Produk: ";
        cin >> namaProduk[totalProduk];
        cout << "Harga Modal: ";
        cin >> hargaModalProduk[totalProduk];
        cout << "Harga Jual: ";
        cin >> hargaJualProduk[totalProduk];
        cout << "Stok Minimal: ";
        cin >> stokMinimalProduk[totalProduk];
        cout << "Stok Maksimal: ";
        cin >> stokMaksimalProduk[totalProduk];

        int stokAwal;
        do {
            cout << "Stok Awal (maksimal " << stokMaksimalProduk[totalProduk] << "): ";
            cin >> stokAwal;
            if (stokAwal > stokMaksimalProduk[totalProduk]) {
                cout << "Error: Stok melebihi batas maksimal!\n";
            }
        } while (stokAwal > stokMaksimalProduk[totalProduk]);

        stokProduk[totalProduk] = stokAwal;

        totalProduk++;
        cout << "Produk berhasil ditambahkan!\n";
    } else {
        cout << "Data penuh, tidak bisa menambah produk lagi.\n";
    }
}

void lihatRestock() {
    cout << "\n=== Produk Perlu Restock ===\n";
    for (int i = 0; i < totalProduk; i++) {
        if (stokProduk[i] <= stokMinimalProduk[i]) {
            cout << "Kode: " << kodeProduk[i] 
                 << ", Nama: " << namaProduk[i] 
                 << ", Stok: " << stokProduk[i] << endl;
        }
    }
}
