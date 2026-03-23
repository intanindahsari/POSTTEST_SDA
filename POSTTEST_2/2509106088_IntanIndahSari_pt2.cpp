#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


struct menejDataKereta 
{
    int nomor_kereta;
    string nama_kereta;
    string tujuan_akhir_kereta;
    string tempat_keberangkatan_kereta;
    int harga_tiket;
};

void swap (menejDataKereta *a, menejDataKereta *b) 
{
    menejDataKereta tempat = *a;
    *a = *b;
    *b = tempat;
}

void tampil_data_kereta (menejDataKereta* ptr, int n){
    cout << "===============================================================================\n";
    cout << "|                   JADWAL KEBERANGKATAN KERETA API INDONESIA                  |\n";
    cout << "===============================================================================\n";
    cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
    cout << "| No | Nomor Kereta |      Nama Kereta       |      Tempat Keberangkatan    |    Tujuan Akhir Kereta    |   Harga   |\n";
    cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
    for (int i = 0; i < n; i++){
        cout << "|" << left << setw(3) << i + 1 << " | ";
        cout << left << setw(12) << (ptr + i) -> nomor_kereta << " | "; 
        cout << left << setw(22) << (ptr + i) -> nama_kereta << " | ";
        cout << left << setw(28) << (ptr + i) -> tempat_keberangkatan_kereta << " | ";
        cout << left << setw(26) << (ptr + i) -> tujuan_akhir_kereta << " | ";
        cout << left << setw(9) << (ptr + i) -> harga_tiket << " |\n";
    }
}

void tambah_data_ManajKereta (menejDataKereta* arr, int &n ){
    menejDataKereta keretaApi;
    cout << "Masukan Nomor Kereta: ", cin >> keretaApi.nomor_kereta;
    cin.ignore();
    cout << "Masukan Nama Kereta: "; getline (cin, keretaApi.nama_kereta);
    cout << "Masukan Tempat Keberangkatan Kereta: "; getline (cin, keretaApi.tempat_keberangkatan_kereta);
    cout << "Masukan Tujuan Akhir Kereta: "; getline (cin, keretaApi.tujuan_akhir_kereta);
    cout << "Masukan Harga Tiket Kereta: "; cin >> keretaApi.harga_tiket;
    arr[n] = keretaApi;
    n++;
    cout << "Data Kereta Berhasil Ditambahkan✅\n";

}

void urutkan_harga (menejDataKereta* arr, int n){
    for (int i = 0; i < n - 1; i++){
        int indeks = i;
        for (int j = i + 1; j < n; j++){
            if ((arr + j)->harga_tiket < (arr + indeks)->harga_tiket) indeks = j;
        }
        if (indeks != i){
            swap((arr + i), (arr + indeks));
        }
    }
}
void urutkan_nama (menejDataKereta* arr, int kiri, int kanan, int tengah){
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    menejDataKereta* Kiri = new menejDataKereta[n1];
    menejDataKereta* Kanan = new menejDataKereta[n2];

    for (int i = 0; i < n1; i++) *(Kiri + i) = *(arr + kiri + i);
    for (int j = 0; j < n2; j++) *(Kanan + j) = *(arr + tengah + 1 + j);

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2){
        if ((Kiri + i) -> nama_kereta <= (Kanan + j) -> nama_kereta){
            *(arr + k) = *(Kiri + i);
            i++;
        }
        else {
            *(arr + k) = *(Kanan + j);
            j++;
        }
        k++;
    }
    while (i < n1) { *(arr + k) = *(Kiri + i); i++; k++; }
    while (j < n2) { *(arr + k) = *(Kanan + j); j++; k++; }
}
void merge_sort_nama (menejDataKereta* arr, int kiri, int kanan){
    if (kiri < kanan){
        int tengah = (kiri + kanan) / 2;
        merge_sort_nama(arr, kiri, tengah);
        merge_sort_nama(arr, tengah + 1, kanan);
        urutkan_nama(arr, kiri, kanan, tengah);
    }
}

void cari_berdasarkan_tujuan (menejDataKereta* arr, int n, string tujuan, string awal_keberangkatan){
    int ketemu = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].tujuan_akhir_kereta == tujuan && arr[i].tempat_keberangkatan_kereta == awal_keberangkatan){
            if (ketemu == 0){
                cout << "Kereta yang anda cari adalah: " << arr[i].nama_kereta << endl;
                cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
                cout << "| No | Nomor Kereta |      Nama Kereta       |      Tempat Keberangkatan    |    Tujuan Akhir Kereta    |   Harga   |\n";
                cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
            }
            ketemu = 1;
            cout << "|" << left << setw(3) << i + 1 << " | ";
            cout << left << setw(12) << (arr + i) -> nomor_kereta << " | "; 
            cout << left << setw(22) << (arr + i) -> nama_kereta << " | ";
            cout << left << setw(28) << (arr + i) -> tempat_keberangkatan_kereta << " | ";
            cout << left << setw(26) << (arr + i) -> tujuan_akhir_kereta << " | ";
            cout << left << setw(9) << (arr + i) -> harga_tiket << " |\n";
        }
    }
    if (ketemu == 1){
        cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
    }
    else {
        cout << "Kereta yang anda cari tidak ditemukan" << endl;
    }
/*1. Buat dulu variabel ketemu yang isinya itu masih 0, jadi ini buat penanda ketemu atau tidak (kalau 0 berarti belum ketemu)
2. Lalu program bakalan mulai lakukan looping dengan mulai buka datanya satu persatu dari nomor satu sampai akhir (sesuai sama datanya yang ada)
3. Kemudian bakalan dilakukan pengecekan data itu apakah tujuan dan awal keberangkatan kereta sama dengan tujuan dan awal keberangkatan kereta yang diinputkan oleh user
4. kalau misalnya datanya cocok bakalan ditampilkan di layarnya
5. Kemudian ketemu diubah jadi 1, karena datanya udah ketemu
6. kalau misalnya data yang di cari itu ttp ga ada bakalan ditampilkan "Kereta yang anda cari tidak ditemukan"*/
}


void cari_nomor_kereta (menejDataKereta* arr, int n, int nomor_kereta){
    int step = (int) sqrt((double) n);
    int prev = 0;

    while ((arr + min(step, n) - 1)->nomor_kereta < nomor_kereta){
        prev = step;
        step = step + (int) sqrt((double) n);
        if (prev >= n){
            cout << "Nomor Kereta Tidak Ditemukan\n" << nomor_kereta << endl;
            return;
        }
    }
    int batas = step;
    int i;
    if (batas > n) batas = n;
    while (prev < batas){
        if ((arr + prev) -> nomor_kereta == nomor_kereta){
            cout << "Nomor Kereta yang anda cari adalah: " << arr[prev].nomor_kereta << endl;
            cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
            cout << "| No | Nomor Kereta |      Nama Kereta       |      Tempat Keberangkatan    |    Tujuan Akhir Kereta    |   Harga   |\n";
            cout << "+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
                cout <<"|" << left << setw(3) << prev + 1 << " | ";
                cout << left << setw(12) << (arr + prev) -> nomor_kereta << " | "; 
                cout << left << setw(22) << (arr + prev) -> nama_kereta << " | ";
                cout << left << setw(28) << (arr + prev) -> tempat_keberangkatan_kereta << " | ";
                cout << left << setw(26) << (arr + prev) -> tujuan_akhir_kereta << " | ";
                cout << left << setw(9) << (arr + prev) -> harga_tiket << " |\n";
                return;
            }
            prev++;
        }
        cout << "Nomor Kereta Tidak Ditemukan\n" << nomor_kereta << endl;
}


int main (){
    int n = 5;
    menejDataKereta keretaApi[100] = {
        { 108, "Argo Bromo Anggrek", "Surabaya", "Bandung", 100000},
        { 123, "Gajayana", "Malang", "Jember", 180000},
        { 435, "Argo Wilis", "Semarang", "Surabaya", 120000},
        { 578, "Bengawan", "Jakarta", "Solo", 20000},
        { 857, "Gajayana", "Yogyakarta", "Jakarta", 190000}
    };
    string pilihan = "7";
    string tujuan,  awal_keberangkatan;
    int nomor_kereta;
    while (true){
        cout << "================================================================================\n";
        cout << "|                          Jadwal Tiket Kereta Api Indonesia                         |\n";
        cout << "================================================================================\n";
        cout << "1. Menampilkan seluruh Jadwal Tiket Kereta Api\n";
        cout << "2. Tambah Jadwal Kereta Tiket Api Baru\n";
        cout << "3. Cari Jadwal Tiket Kereta Api\n";
        cout << "4. Cari Nomor Tiket Kereta Api\n";
        cout << "5. Urutkan Nama Tiket Kereta Api\n";
        cout << "6. Urutkan Harga Tiket Kereta Api\n";
        cout << "7. Keluar\n";
        cout << "================================================================================\n";
        cout << "Pilihan anda: "; cin >> pilihan;

        cin.ignore();

        if (pilihan == "1"){
            tampil_data_kereta (keretaApi, n);
            cout <<"+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
        }
        else if (pilihan == "2"){
            tambah_data_ManajKereta (keretaApi, n);
            cin.ignore(100, '\n');
        }
        else if (pilihan == "3"){
            cout << "Masukan Tujuan Kereta: "; getline (cin, tujuan);
            cout << "Masukan Tempat Keberangkatan Kereta: "; getline (cin, awal_keberangkatan);
            cari_berdasarkan_tujuan (keretaApi, n, tujuan, awal_keberangkatan);
        }
        else if (pilihan == "4"){
            for (int i = 0; i < n - 1; i++){
                for (int j = 0; j < n - 1; j++){
                    if (keretaApi[j].nomor_kereta > keretaApi[j + 1].nomor_kereta){
                        swap(&keretaApi[j], &keretaApi[j + 1]);
                    }
                }
            }
            cout << "Masukan Nomor Kereta: "; cin >> nomor_kereta;
            cari_nomor_kereta (keretaApi, n, nomor_kereta);
            cout <<"+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
            cin.ignore(100, '\n');
        }
        else if (pilihan == "5"){
            merge_sort_nama (keretaApi, 0, n - 1);
            tampil_data_kereta (keretaApi, n);
            cout <<"+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
        }
        else if (pilihan == "6"){
            urutkan_harga (keretaApi, n);
            tampil_data_kereta (keretaApi, n);
            cout <<"+----+--------------+------------------------+------------------------------+---------------------------+-----------+\n";
        }
        else if (pilihan == "7"){
            cout << "Terimakasih telah menggunakan program ini\n";
            break;
        }
        else{
            cout << "Pilihan tidak tersedia\n";
            cout  <<"Masukan pilihan 1-7\n";
        }
        cout << "\n[Tekan ENTER untuk lanjut ke pilihan menu selanjut atau sebelumnya]\n";
        cin.get();    
    }
    return 0;
}
