#include <bits/stdc++.h>
using namespace std;

class TextEditor {
private:
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void ketik(string teks) {
        undoStack.push(teks);
        while(!redoStack.empty()) redoStack.pop(); 
        cout << "Add: " << teks << endl;
    }

    void undo() {
        if (!undoStack.empty()) {
            string teks = undoStack.top();
            undoStack.pop();
            redoStack.push(teks);
            cout << "Undo: " << teks << endl;
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            string teks = redoStack.top();
            redoStack.pop();
            undoStack.push(teks);
            cout << "Redo: " << teks << endl;
        }
    }
};

int main() {
    TextEditor editor;
    cout << "SIMULASI TEXT EDITOR" << endl;
    editor.ketik("Halo");
    editor.ketik("Saya Aga Nafta");
    editor.ketik("Mahasiwa Teknik Informatika");
    
    editor.undo();
    editor.undo();
    editor.redo();

    return 0;
}