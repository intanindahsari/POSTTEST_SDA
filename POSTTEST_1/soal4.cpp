#include <iostream>
using namespace std;

void tukarNilai (int *nilai1, int *nilai2){
    int penyimpanan = *nilai1;
    *nilai1 = *nilai2;
    *nilai2 = penyimpanan;
}

int main(){
    int nilai1, nilai2;
    cout << "Masukan angka pertama:\n";
    cin >> nilai1;
    cout << "Masukan angka kedua:\n";
    cin >> nilai2;

    cout << "Angka sebelum proses penukaran terjadi:\n";
    cout << "angka1 = " << nilai1 << endl;
    cout << "angka2 = " << nilai2 << endl;

    tukarNilai(&nilai1, &nilai2);
    cout << "Angka sesudah proses penukaran terjadi:\n";
    cout << "angka1 = " << nilai1 << endl;
    cout << "angka2 = " << nilai2 << endl;


    return 0;

}

