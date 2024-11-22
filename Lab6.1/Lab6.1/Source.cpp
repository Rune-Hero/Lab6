#include <fstream>
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;

template <typename T>
class FileManager {
private:
    fstream file;
    ios::openmode mode;
public:
    FileManager(string filename, ios::openmode mode) : mode(mode) {
        file.open(filename, mode);
        if (!file.is_open()) {
            throw runtime_error("Не вдалося відкрити файл: " + filename);
        }
    }

    ~FileManager() {
        if (file.is_open()) {
            file.close();
        }
    }

    void write(vector<T>& data) {

        for (auto item : data) {
            file << item << '\n';
        }
        file.close();
    }

    void read(vector<T>& data) {

        T item;
        while (file >> item) {
            data.push_back(item);
        }
        file.close();
    }


};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {

        vector<int> intData = { 1, 3, 5, 7, 12, 45, 46, 6, 34, 66, -4 };
        FileManager<int> intFileManager("D:/numbers.txt", ios::out);
        intFileManager.write(intData);

        vector<int> readData;
        FileManager<int> intFileReader("D:/numbers.txt", ios::in);
        intFileReader.read(readData);

        if (readData.empty()) {
            cout << "Файл порожній або дані не були зчитані!" << endl;
        }
        else {
            cout << "Зчитані дані: ";
            for (auto item : readData) {
                cout << item << " ";
            }
            cout << endl;
        }

        vector<string> stringData = { "apple", "banana", "apricot", "cherry", "blackberry" };
        FileManager<string> stringFileManager("D:/stringData.txt", ios::out);
        stringFileManager.write(stringData);

        vector<string> readStrings;
        FileManager<string> stringFileReader("D:/stringData.txt", ios::in);
        stringFileReader.read(readStrings);

        if (readStrings.empty()) {
            cout << "Файл порожній або дані не були зчитані!" << endl;
        }
        else {
            cout << "Зчитані рядки: ";
            for (auto item : readStrings) {
                cout << item << " ";
            }
            cout << endl;
        }

    }
    catch (exception e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}