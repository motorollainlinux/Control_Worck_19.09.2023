#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "DIR.h"
#define LIMIT 255

using std::cout;
using std::cin;
using std::string;
using std::ofstream;
using std::vector;

class NameGenerate {
    public:
    NameGenerate() {}
    string Generate(string Alphabet) {
        vector<int> CountSumbols(Alphabet.length());
        string result  = "";
        static string Lastreturn;
        int cursor = 0;
        if(Lastreturn == "") {
            Lastreturn = Alphabet;
            return Alphabet;
        } else if(Lastreturn.length() < LIMIT-4) {
            for(int i = 0; i < Lastreturn.length(); i++) {
                for(int j = 0; j < Alphabet.length(); j++) {
                    if(Lastreturn[i] == Alphabet[j]) {
                        CountSumbols[j]++;
                        if(CountSumbols[j] > 1 && j > cursor) {
                            cursor = j;
                        }
                    }
                }
            }
            CountSumbols[cursor]++;
            for(int i = 0; i < Alphabet.length(); i++) {
                for(int j = 0; j < CountSumbols[i]; j++) {
                    result += Alphabet[i];
                }
            }
            Lastreturn = result;
            return result;
        } else {
            for(int i = 0; i < Lastreturn.length(); i++) {
                for(int j = 0; j < Alphabet.length(); j++) {
                    if(Lastreturn[i] == Alphabet[j]) {
                        CountSumbols[j]++;
                        if(CountSumbols[j] > 1 && j > cursor) {
                            cursor = j;
                        }
                    }
                }
            }
            if(cursor < Alphabet.length()-1) {
                CountSumbols[cursor] = 1;
                CountSumbols[cursor+1]++;
            } else return NULL;
            for(int i = 0; i < Alphabet.length(); i++) {
                for(int j = 0; j < CountSumbols[i]; j++) {
                    result += Alphabet[i];
                }
            }
            Lastreturn = result;
            return result;
        }
    }
};
class FoldersCreate {
    public:
    ofstream LOG;
    string Alphabet;
    int countFolders;
    NameGenerate name;
    time_t t;
    FoldersCreate() {}
    void CreateFolder() {
        string Name;
        LOG.open("log.txt", std::ios::app);
        for(;countFolders >= 0; countFolders--) {
            Name = name.Generate(Alphabet);
            mkdir(Name.c_str());
            t = time(NULL);
            LOG << t << " |Folder generate whis name:\n" << Name << "\n";
        }
        LOG.close();
    }
    void UserGui() {
        bool IsCorrectEnter = false;
        string Enter;
        do {
            cout << "Enter folders alphabet: ";
            cin >> Enter;
            cin.clear();
            if(Enter.length() > 0) {
                IsCorrectEnter = true;
                for(int i = 0; i < Enter.length(); i++) {
                    if(Enter[i] >= '0' && Enter[i] <= '9')
                    IsCorrectEnter = false;
                }
                if(!IsCorrectEnter)
                cout << "Invalid Enter!\n";
                else Alphabet = Enter;
            } else cout << "Invalid Enter!\n";
        }while(!IsCorrectEnter);
        IsCorrectEnter = false;
        do {
            cout << "Enter folders count: ";
            cin >> Enter;
            if(Enter.length() > 0) {
                IsCorrectEnter = true;
                for(int i = 0; i < Enter.length(); i++) {
                    if(Enter[i] <= '0' && Enter[i] >= '9')
                    IsCorrectEnter = false;
                }
                if(!IsCorrectEnter)
                cout << "Invalid Enter!\n";
                else countFolders = std::stoi(Enter);
            } else cout << "Invalid Enter!\n";
        }while(!IsCorrectEnter);
    }
};
class FilesCreate {
    public:
    int FilesCount;
    string Alphabet, Name;
    ofstream LOG;
    NameGenerate name;
    time_t t;
    FilesCreate() {}
    void CreateFiles() {
        LOG.open("log.txt");
        ofstream file;
        for(;FilesCount >= 0; FilesCount--) {
            Name = name.Generate(Alphabet);
            file.open(Name);
            file.close();
            t = time(NULL);
            LOG << t << " | File created whis name:\n" << Name << "\n";
        }
        LOG.close();
    }
    void UserGui() {
        bool IsCorrectEnter = false;
        string Enter;
        do {
            cout << "Enter files alphabet: ";
            cin >> Enter;
            cin.clear();
            if(Enter.length() > 0) {
                IsCorrectEnter = true;
                for(int i = 0; i < Enter.length(); i++) {
                    if(Enter[i] >= '0' && Enter[i] <= '9')
                    IsCorrectEnter = false;
                }
                if(!IsCorrectEnter)
                cout << "Invalid Enter!\n";
                else Alphabet = Enter;
            } else cout << "Invalid Enter!\n";
        }while(!IsCorrectEnter);
        IsCorrectEnter = false;
        do {
            cout << "Enter files count: ";
            cin >> Enter;
            if(Enter.length() > 0) {
                IsCorrectEnter = true;
                for(int i = 0; i < Enter.length(); i++) {
                    if(Enter[i] < '0' && Enter[i] > '9')
                    IsCorrectEnter = false;
                }
                if(!IsCorrectEnter)
                cout << "Invalid Enter!\n";
                else FilesCount = std::stoi(Enter);
            } else cout << "Invalid Enter!\n";
        }while(!IsCorrectEnter);
    }
};
int main() {
    FoldersCreate foc;
    FilesCreate fic;
    foc.UserGui();
    fic.UserGui();
    foc.CreateFolder();
    fic.CreateFiles();
    return 0;
}
