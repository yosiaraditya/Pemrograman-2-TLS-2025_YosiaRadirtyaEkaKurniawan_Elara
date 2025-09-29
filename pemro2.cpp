#include <iostream>
#include <string>
using namespace std;

bool cekVokal(char huruf) {
    huruf = tolower(huruf);
    return (huruf == 'a' || huruf == 'i' || huruf == 'u' || huruf == 'e' || huruf == 'o');
}

// Fungsi untuk membalik string tanpa reverse()
string balikKata(const string &teks) {
    string hasilBalik = "";
    for (int i = teks.length() - 1; i >= 0; i--) {
        hasilBalik += teks[i];
    }
    return hasilBalik;
}

int main() {
    string sandi;
    cout << "Masukkan sandi: ";
    cin >> sandi;

    // Cari posisi angka ASCII di tengah
    int idx = 0;
    while (idx < sandi.size() && !isdigit(sandi[idx])) idx++;

    // Ambil angka ASCII
    string kodeAsciiStr = "";
    while (idx < sandi.size() && isdigit(sandi[idx])) {
        kodeAsciiStr += sandi[idx];
        idx++;
    }

    int kodeAscii = stoi(kodeAsciiStr);
    char hurufAwal = char(kodeAscii);

    // Gabungkan string tanpa angka ASCII
    string tanpaKode = sandi.substr(0, sandi.find(kodeAsciiStr)) 
                     + sandi.substr(sandi.find(kodeAsciiStr) + kodeAsciiStr.length());

    // Balik string pakai loop
    tanpaKode = balikKata(tanpaKode);

    // Jika huruf pertama (ASCII) adalah vokal → taruh di belakang
    if (cekVokal(hurufAwal)) {
        tanpaKode += hurufAwal;
    }

    cout << "\nSandi: " << sandi << endl;
    cout << "Kode ASCII: " << kodeAscii << " = " << hurufAwal << endl;
    cout << "Kata tanpa vokal: " << tanpaKode << endl;

    return 0;
}
