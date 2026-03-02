#include <iostream>
using namespace std;    

void Findmin (int arr[], int n){
    int nilaimin = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < nilaimin){
            nilaimin = arr[i];
            index = i;
        }
    }
    cout << "nilai minimumnya adalah: "<< nilaimin << endl;
    cout << "index dari nilai minimum adalah: " << index << endl;

}
int main (){
    int fibonaci[8] = {1, 1, 2, 3, 5, 8, 13, 21};

    cout << "nilai fibonaci adalah: ";
    for (int i = 0; i < 8; i++){
        cout << fibonaci[i] << " ";
    }
    cout << endl;
    Findmin(fibonaci, 8);   

    return 0;

}


/*
kompleksitas waktu

===================================
pseudecode         cost  Tmin  Tmax
===================================
procedure FindMax   C1    1     1
max ← A[0]          C2    1     1
for i ← 1 to n − 1  C3    n     n
if A[i] > max       C4   n-1   n-1
max ← A[i]          C5    0    n-1
end if              C6   n-1   n-1
end for             C7    n     n
return max          C8    1     1
end procedure       C9    1     1
Total waktu(Tn)          O(n) O(n)
===================================

BEST CASE   = C1+C2+C3n+C4(n-1)+0+C6(n-1)+C7n+C8+C9
            = C1+C2+C3n+C4n-C4+0+C6n-C6+C7n+C8+C9
            = (C3+C4+C6+C7)n + (C1+C2+C8+C9-C4-C6)
            = (1+1+1+1)n + (1+1+1+1-1-1)
            = 4n + 2 (linear)
            Big-O => O(n)

WORST CASE  = C1+C2+C3n+C4(n-1)+C5(n-1)+C6(n-1)+C7n+C8+C9
            = C1+C2+C3n+C4n-C4+C5n-C5+C6n-C6+C7n+C8+C9
            = (C3+C4+C5+C6+C7)n + (C1+C2+C8+C9-C4-C5-C6)
            = (1+1+1+1+1)n + (1+1+1+1-1-1-1)
            = 5n + 1 (linear)
            Big-O => O(n)
            

BEST CASE = Big-O => O(n)
WORST CASE = Big-O => O(n)

Hasil dari best case dan worst case dari keduanya sama sama membentuk fungsi linear
jadi dapat disimpulkan bahwa kompleksitas waktunya adalah O(n)

Nama = Intan Indah Sari
Nim = 2509106088
kelas = B 2025
*/