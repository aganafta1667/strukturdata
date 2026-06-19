#include <bits/stdc++.h>
using namespace std;

struct FolderNode {
    string nama;
    vector<FolderNode*> subFolders;
    
    FolderNode(string n) : nama(n) {}
};

class FileSystem {
public:
    FolderNode* root;

    FileSystem() {
        root = new FolderNode("C:");
    }

    void tambahFolder(FolderNode* parent, string namaFolder) {
        parent->subFolders.push_back(new FolderNode(namaFolder));
    }

    void tampilkan(FolderNode* node, string prefix = "") {
        if (!node) return;
        cout << prefix << "|-- " << node->nama << endl;
        for (auto sub : node->subFolders) {
            tampilkan(sub, prefix + "    ");
        }
    }
};

int main() {
    FileSystem fs;
    cout << "SIMULASI FILE SYSTEM" << endl;
    
    fs.tambahFolder(fs.root, "Dokumen");
    fs.tambahFolder(fs.root, "Gambar");
    
    FolderNode* dokumen = fs.root->subFolders[0];
    fs.tambahFolder(dokumen, "Tugas Kuliah");
    fs.tambahFolder(dokumen, "Skripsi");
    
    fs.tampilkan(fs.root);
    return 0;
}