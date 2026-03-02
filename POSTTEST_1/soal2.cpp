#include <iostream>
using namespace std;

struct mhs
{
    string nama_mhs;
    string nim_mhs;
    float ipk_mhs;
};

int main (){
    int i;
    int ipk_tertinggi = 0;
    mhs data [5];

    for (i = 0; i < 5; i++){
        cout << "data mahasiswa ke " << i + 1 << endl;
        cout << "masukan nama mahasiswa:\n";
        cin >> data[i].nama_mhs;
        cout << "masukan nim mahasiswa:\n";
        cin >> data[i].nim_mhs;
        cout << "masukan ipk mahasiswa:\n";
        cin >> data[i].ipk_mhs;
        cout << endl;
    }
    for (i = 0; i < 5; i++){
        if (data[i].ipk_mhs > data[ipk_tertinggi].ipk_mhs){
            ipk_tertinggi = i;
        }
    }

    cout << "Data mahasiswa dengan ipk tertinggi adalah:\n";
    cout << "nama mahasiswa: " << data[ipk_tertinggi].nama_mhs << endl;
    cout << "nim mahasiswa: " << data[ipk_tertinggi].nim_mhs << endl;
    cout << "ipk mahasiswa: " << data[ipk_tertinggi].ipk_mhs << endl;

    return 0;
}
