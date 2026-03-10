#include <iostream>
using namespace std;

int main () {
    int nilai[100];
    int n, max;
    cout << "Masukkan total data nilai : ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-"<<i+1<<" : ";
        cin >> nilai[i];
        if (i==0) max = nilai[i];
        if (nilai[i]>max) max = nilai[i];
    }

    cout << "Nilai tertinggi adalah : " << max << endl;

    return 0;
}
