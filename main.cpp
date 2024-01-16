#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Kendaraan {
    string jenis;
    double tarif;
};

void tampilkanPilihanKendaraan() {
    cout <<"=========================\n";
    cout <<"SELAMAT DATANG DI RENTAL\n";
    cout <<"Pilih Jenis Kendaraan:\n1. Mobil\n2. Sepeda Motor\n3. Minibus\n";
    cout <<"=========================\n";
}

int ambilPilihanKendaraan () {
    int pilihan;
    cout <<"Masukan Nomor Jenis Kendaraan: ";
    cin >> pilihan;
    return pilihan;
}

double hitungTotalBiaya(int lamaSewa, const Kendaraan &kendaraan) {
    return kendaraan.tarif * lamaSewa;
}

void tampilkanTotalBiaya(double totalBiaya) {
    cout <<"-------------------------\n";
    cout <<"Total Biaya Peminjaman: Rp" <<fixed << setprecision(2) << totalBiaya << endl;
}

double hitungDenda(int lamaSewa, int waktuPengembalian) {
    return max(0, waktuPengembalian - lamaSewa) * 20000.0;
}
    
void tampilkanTotalBiayaDenganDenda(double totalBiaya, double denda) {
    cout << "   Total Biaya Dengan Denda: Rp" << fixed << setprecision(2) << (totalBiaya + denda) <<endl;
    cout << "================================\n";
}

int main() {
    Kendaraan kendaraan[] = {{"Mobil",30000.0}, {"Sepeda Motor",15000.0}, {"Minibus",50000.0}};

tampilkanPilihanKendaraan();

int pilihanKendaraan = ambilPilihanKendaraan();
if (pilihanKendaraan < 1 || pilihanKendaraan > 3) {
    cout << "Pilihan Tidak Valid. Silahkan Pilih Nomor Yang Benar.";
    return 1;
}

Kendaraan kendaraanTerpilih = kendaraan[pilihanKendaraan - 1];

int lamaSewa;
cout <<"Masukan lama peminjaman (dalam jam): ";
cin >> lamaSewa;

double totalBiaya = hitungTotalBiaya(lamaSewa, kendaraanTerpilih);
tampilkanTotalBiaya(totalBiaya);

int waktuPengembalian;
cout << "Masukan Waktu Pengembalian(total peminjaman ditambah telat,jika ada): ";
cin >> waktuPengembalian;

double denda = hitungDenda(lamaSewa, waktuPengembalian);
tampilkanTotalBiayaDenganDenda(totalBiaya, denda);

cout << "Terimakasih Telah Menggunakan Jasa Kami\n";
cout << "================================\n";

return 0;    
}