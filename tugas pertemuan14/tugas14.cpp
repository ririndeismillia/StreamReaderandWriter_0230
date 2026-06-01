#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>

using namespace std;

// =========================
// KELAS TOKO ELEKTRONIK
// =========================
class TokoElektronik {
private:
    array<string, 3> etalase; // enkapsulasi

public:
    // Constructor
    TokoElektronik() {
        etalase[0] = "Laptop";
        etalase[1] = "Smartphone";
        etalase[2] = "Printer";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) {
            throw string("Gagal Mengambil Barang : Rak nomor " +
                         to_string(nomorRak) +
                         " kosong atau tidak tersedia!");
        }
    }
};

// =========================
// FUNGSI CRUD FILE
// =========================

const string NAMA_FILE = "gudang.txt";

// READ
void tampilkanBarang() {
    ifstream file(NAMA_FILE);

    cout << "\n===== DATA GUDANG =====\n";

    string barang;
    int nomor = 1;

    while (getline(file, barang)) {
        cout << nomor++ << ". " << barang << endl;
    }

    if (nomor == 1) {
        cout << "Gudang masih kosong.\n";
    }

    cout << "=======================\n";
    file.close();
}

// CREATE
void tambahBarang() {
    ofstream file(NAMA_FILE, ios::app);

    string barang;

    cin.ignore();
    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan.\n";
}

// UPDATE
void updateBarang() {
    vector<string> data;
    string barang;

    ifstream file(NAMA_FILE);

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Tidak ada data untuk diupdate.\n";
        return;
    }

    tampilkanBarang();

    int index;
    cout << "Pilih nomor barang yang ingin diubah: ";
    cin >> index;

    if (index < 1 || index > data.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    cin.ignore();

    cout << "Masukkan nama barang baru: ";
    getline(cin, data[index - 1]);

    ofstream outFile(NAMA_FILE);

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil diperbarui.\n";
}

// DELETE
void hapusBarang() {
    vector<string> data;
    string barang;

    ifstream file(NAMA_FILE);

    while (getline(file, barang)) {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    tampilkanBarang();

    int index;
    cout << "Pilih nomor barang yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > data.size()) {
        cout << "Nomor tidak valid.\n";
        return;
    }

    data.erase(data.begin() + (index - 1));

    ofstream outFile(NAMA_FILE);

    for (string item : data) {
        outFile << item << endl;
    }

    outFile.close();

    cout << "Data berhasil dihapus.\n";
}

// =========================
// SIMULASI ETALASE
// =========================
void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    // Skenario 1
    try {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang: " << toko.ambilProduk(1) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    // Skenario 2
    try {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang: " << toko.ambilProduk(5) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    cout << "============================\n";
}

// =========================
// MAIN PROGRAM
// =========================
int main() {

    int pilihan;

    do {
        tampilkanBarang();

        cout << "\n===== MENU TOKO GIBRAN JAYA =====\n";
        cout << "1. Tambah Barang (Create)\n";
        cout << "2. Lihat Barang (Read)\n";
        cout << "3. Update Barang (Update)\n";
        cout << "4. Hapus Barang (Delete)\n";
        cout << "5. Simulasi Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilkanBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            simulasiEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}