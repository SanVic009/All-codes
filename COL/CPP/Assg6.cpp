#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

class FileHandler {
public:
    void writeToFile() {
        ofstream outFile("BOOK.txt");
        if (!outFile) {
            cerr << "File could not be opened!" << endl;
            return;
        }
        outFile << "This is the test FILE WHICH WILL BE READ\nWelcome to File Handling!\nIt is fun.\n";
        outFile.close();
        cout << "Data written to file successfully!" << endl;
    }

    void readFromFile() {
        ifstream inFile("BOOK.txt");
        if (!inFile) {
            cerr << "File could not be opened!" << endl;
            return;
        }
        string line;
        cout << "\nContent of BOOK.txt:" << endl;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    int countUppercase() {
        ifstream file("BOOK.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return -1;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isupper(ch)) {
                count++;
            }
        }
        file.close();
        return count;
    }

    int countLetters() {
        ifstream file("BOOK.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return -1;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isalpha(ch)) {
                count++;
            }
        }
        file.close();
        return count;
    }

    int countDigits() {
        ifstream file("BOOK.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return -1;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isdigit(ch)) {
                count++;
            }
        }
        file.close();
        return count;
    }

    int countWhiteSpaces() {
        ifstream file("BOOK.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return -1;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            if (isspace(ch)) {
                count++;
            }
        }
        file.close();
        return count;
    }

    int countVowels() {
        ifstream file("BOOK.txt");
        if (!file) {
            cerr << "File could not be opened!" << endl;
            return -1;
        }
        char ch;
        int count = 0;
        while (file.get(ch)) {
            ch = tolower(ch); 
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }
        file.close();
        return count;
    }
};

int main() {
    FileHandler fh;

    fh.writeToFile();
    fh.readFromFile();
    cout << "\nUppercase letters: " << fh.countUppercase() << endl;

    cout << "Total letters: " << fh.countLetters() << endl;

    cout << "Digits: " << fh.countDigits() << endl;

    cout << "White spaces: " << fh.countWhiteSpaces() << endl;

    cout << "Vowels: " << fh.countVowels() << endl;

    return 0;
}
