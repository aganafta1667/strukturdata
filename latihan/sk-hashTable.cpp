#include <bits/stdc++.h>
using namespace std;

class SistemLogin {
private:
    unordered_map<string, string> databaseUser;

public:
    void registerUser(string user, string pass) {
        databaseUser[user] = pass;
    }

    bool login(string user, string pass) {
        if (databaseUser.find(user) != databaseUser.end() && databaseUser[user] == pass) {
            cout << "Login sukses!\n";
            return true;
        }
        cout << "Username atau password salah" << endl;
        return false;
    }
};

int main() {
    SistemLogin sistem;
    cout << "SIMULASI LOGIN SYSTEM" << endl;
    
    sistem.registerUser("aga123", "strukdatjosjis");
    sistem.registerUser("nafta456", "ipk4");
    
    sistem.login("aga123", "strukdatkeren");
    sistem.login("aga123", "strukdatjosjis");
    return 0;
}