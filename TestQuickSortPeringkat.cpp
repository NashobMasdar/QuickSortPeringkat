#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Struktur Data
struct Data {
    int NilaiSiswa;
    string nama;
};

// 2. Fungsi untuk menukar dua elemen
void static swap(Data& a, Data& b) {
    Data temp = a;
    a = b;
    b = temp;
}

// 3. Fungsi Partisi
static int partition(vector<Data>& arr, int low, int high) {
    int pivot = arr[high].NilaiSiswa; // Pivot elemen terbesar
    int i = (low - 1); // Indeks elemen terkecil

    for (int j = low; j <= high - 1; j++) {
        // Bandingkan nomor urut
        if (arr[j].NilaiSiswa > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 4. Fungsi Quick Sort
void static quickSort(vector<Data>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // Kiri
        quickSort(arr, pi + 1, high); // Kanan
    }
}

// 5. Fungsi Cetak
void static cetakData(const vector<Data>& arr) {
    for (const auto& d : arr) {

        cout << " | Nama: " << d.nama << "\t| Nilai siswa : " << d.NilaiSiswa << endl;
    }
}


int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<Data> daftarData(n);

    // Mengisi data
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << endl;
        cout << "  Nama: ";
        cin.ignore(); // Membersihkan buffer
        getline(cin, daftarData[i].nama);
        cout << "  Nilai Siswa: ";
        cin >> daftarData[i].NilaiSiswa;

    }

    // Mengurutkan dengan Quick Sort
    quickSort(daftarData, 0, n - 1);

    cout << "\nPeringkat siswa berdasarkan Nilai tertinggi:\n";
    cetakData(daftarData);

    return 0;
}