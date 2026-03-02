#include <iostream>
using namespace std;

void Balikangka (int *angkaarr, int *n_akhir){
    int wadahpertukaran;
    while (angkaarr <  n_akhir){
        wadahpertukaran = *angkaarr;
        *angkaarr = *n_akhir;
        *n_akhir = wadahpertukaran;
        angkaarr++;
        n_akhir--;
    }

}
int main (){ 
    int n = 7;
    int PrimaArr [7] = {2, 3, 5, 7, 11, 13, 17};
    int *ptr = PrimaArr;
    cout << "bilangan Prima awal sebelum di tukar\n";
    while (ptr < PrimaArr + n ){
        cout << *ptr << " ";
        cout << ptr << " alamat memori setiap elemen" << endl;
        ptr++;
    }
    cout << endl;
    Balikangka (PrimaArr, PrimaArr + (n-1));
    ptr = PrimaArr;
    cout << "bilangan Prima setelah di tukar\n";
    while (ptr < PrimaArr + n){
        cout << *ptr << "  ";
        cout << ptr << " alamat memori setiap elemen" << endl;
        ptr++;
    }

    return 0;

}