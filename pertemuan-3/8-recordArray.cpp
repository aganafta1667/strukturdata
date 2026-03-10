#include <iostream>
using namespace std;

struct mahasiswa {
    string nama, nrp, jurusan, asal;
    int umur;
    string hobi[2];
};

int main() {
    mahasiswa mhs[100];
    int n;
    cout << "Total Mahasiswa : ";
    cin >> n;

    for (int i=0; i<n; i++) {
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "NRP     : ";
        cin >> mhs[i].nrp;
        cout << "Nama    : ";
        cin >> mhs[i].nama;
        cout << "Jurusan : ";
        cin >> mhs[i].jurusan;
        cout << "Asal    : ";
        cin >> mhs[i].asal;
        cout << "Usia    : ";
        cin >> mhs[i].umur;
        cout << "Masukkan 2 Hobi : " << endl;
        for (int j=0; j<2; j++) {
            cout << "Hobi ke-" << j+1 << " : ";
            cin >> mhs[i].hobi[j];
        }
    }

    cout << endl;

    for (int i=0; i<n; i++) {
        cout << "========= Data Mahasiswa ke-" << i+1 << " =========" << endl;
        cout << "NRP      : " << mhs[i].nrp << endl;
        cout << "Nama     : " << mhs[i].nama << endl;
        cout << "Jurusan  : " << mhs[i].jurusan << endl;
        cout << "Asal     : " << mhs[i].asal << endl;
        cout << "Usia     : " << mhs[i].umur << endl;
        cout << "Hobi     : " << mhs[i].hobi[0] << " dan " << mhs[i].hobi[1];
        cout << endl << endl;
    }

    return 0;
}

