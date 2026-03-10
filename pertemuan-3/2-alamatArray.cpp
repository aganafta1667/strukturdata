#include <iostream>
using namespace std;

int main () {
    int myarray [ ] = {1,3,5,2,4,6};
    for (int i=0; i<6; i++) {
        cout << myarray [i] << endl;
        cout << "id : " << &myarray[i] << endl;
    }
    cout << endl;
    return 0;
}


