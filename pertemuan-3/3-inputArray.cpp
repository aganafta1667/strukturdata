#include <iostream>
using namespace std;

int main () {
    int nilai[100];
    int n;
    cout << "Masukkan total data nilai : ";
    cin >> n;
    for (int i=0; i<n; i++) {
        cout << "Masukkan nilai ke-"<<i+1<<" : ";
        cin >> nilai[i];
    }

    cout << "Data yang dimasukkan :" << endl;

    for (int i=0; i<n; i++) {
        cout << nilai[i] << endl;
    }
    return 0;
}
