#include <bits/stdc++.h>
using namespace std;

struct BSTNode {
    int nim;
    string nama;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int id, string n) : nim(id), nama(n), left(nullptr), right(nullptr) {}
};

class DataMahasiswaBST {
public:
    BSTNode* insert(BSTNode* root, int nim, string nama) {
        if (!root) return new BSTNode(nim, nama);
        
        if (nim < root->nim) root->left = insert(root->left, nim, nama);
        else if (nim > root->nim) root->right = insert(root->right, nim, nama);
        
        return root;
    }

    void search(BSTNode* root, int nim) {
        if (!root) {
            cout << "Pencarian NIM " << nim << " -> TIDAK DITEMUKAN" << endl;
            return;
        }
        
        if (root->nim == nim) {
            cout << "Pencarian NIM " << nim << " -> DITEMUKAN Nama: " << root->nama << endl;
        } 
        else if (nim < root->nim) search(root->left, nim);
        else search(root->right, nim);
    }

    void tampilkanTerurut(BSTNode* root) {
        if (!root) return;
        tampilkanTerurut(root->left);
        cout << "NIM: " << root->nim << " - Nama: " << root->nama << endl;
        tampilkanTerurut(root->right);
    }
};

int main() {
    DataMahasiswaBST bst;
    BSTNode* root = nullptr;
    
    cout << "SIMULASI PENCARIAN MAHASISWA (BST)" << endl;
    
    root = bst.insert(root, 50, "Budi (Root)");
    root = bst.insert(root, 30, "Andi");
    root = bst.insert(root, 70, "Citra");
    root = bst.insert(root, 20, "Ahmad");
    root = bst.insert(root, 40, "Dewi");
    root = bst.insert(root, 60, "Eko");
    root = bst.insert(root, 80, "Faris");
    
    bst.tampilkanTerurut(root);
    
    bst.search(root, 40);
    bst.search(root, 70);
    bst.search(root, 99); 
    
    return 0;
}