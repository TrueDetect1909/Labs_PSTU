#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename = "example.txt";
    string search_word = "hello";
    string replace_word = "world";

    ifstream file_in(filename);
    ofstream file_out("temp.txt");

    if (!file_in.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(file_in, line)) {
        size_t pos = line.find(search_word);
        while (pos != string::npos) {
            line.replace(pos, search_word.length(), replace_word);
            pos = line.find(search_word, pos + replace_word.length());
        }
        file_out << line << endl;
    }

    file_in.close();
    file_out.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Word replaced successfully." << endl;

    return 0;
}
