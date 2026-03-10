#include <iostream>
using namespace std;

int main() {
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Isi Array :" << endl;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Elemen pada baris 1 kolom 2: ";
    cout << array[1][2] << endl;
    cout << "Elemen pada baris 0 kolom 1: ";
    cout << array[0][1] << endl;
    return 0;
}
