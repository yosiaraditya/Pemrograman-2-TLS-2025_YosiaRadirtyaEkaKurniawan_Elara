#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk menentukan warna lampu berdasarkan detik
string warnaLampu(int detik) {
    int awalSiklus = 25;        // awal siklus (detik 25 = hijau mulai)
    int panjangSiklus = 103;    // total panjang satu siklus

    int selisih = detik - awalSiklus;
    int posisi = selisih % panjangSiklus;
    if (posisi < 0) posisi += panjangSiklus; // antisipasi kalau detik < 25

    if (posisi >= 0 && posisi <= 19) return "Hijau";
    else if (posisi >= 20 && posisi <= 22) return "Kuning";
    else return "Merah";
}

int main() {
    int daftarDetik[] = {80, 135, 150, 212};
    int jumlah = sizeof(daftarDetik) / sizeof(daftarDetik[0]);

    for (int i = 0; i < jumlah; i++) {
        cout << "Detik " << daftarDetik[i] << " -> " 
             << warnaLampu(daftarDetik[i]) << endl;
    }

    return 0;
}
