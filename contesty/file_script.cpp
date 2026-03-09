#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;

int main() {
    int i;
    string folder;
    // sprawdzamy jaki folder trzeba stworzyc
    for (i = 0; i < 200; i++) {
        if (!filesystem::exists(to_string(i))) {
            folder = to_string(i);
            break;
        }
    }

    // tworze folder
    filesystem::create_directory(folder);

    // tworze pliki
    ofstream(filesystem::path(folder) / "A.cpp");
    ofstream(filesystem::path(folder) / "B.cpp");
    ofstream(filesystem::path(folder) / "C.cpp");
    ofstream(filesystem::path(folder) / "D.cpp");
    ofstream(filesystem::path(folder) / "E.cpp");
}

/*

kompilacja:

g++ -std=c++17 file_script.cpp -o file_script
.\file_script

*/
