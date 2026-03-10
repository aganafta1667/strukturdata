#include <iostream>
using namespace std;

int main () {
    int nilai[100];
    float n, total = 0;
    cout << "Masukkan total data nilai : ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-"<<i+1<<" : ";
        cin >> nilai[i];
        total += nilai[i];
    }

    float rata = total/n;

    cout << "Total nilai  : " << total << endl;
    cout << "Rata-rata    : " << rata << endl;

    return 0;
}

