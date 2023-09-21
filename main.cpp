#include <stdio.h>
#include <time.h>
#include <math.h>
//#include <dir.h>
#include <string> // for string type
#include <stdlib.h>
#define LIMIT 255 // предел имени файла/директории

// #include <iostream>
// using std::cout;
using std::string;

string NameGenerate(int iterrator, string Alphabet) {
    string result = "";
    int LengthStr = (int)Alphabet.length();
    int CursorValue = 0;
    CursorValue = LengthStr/(iterrator+1);
    char Cursor = Alphabet[CursorValue];
    srand(time(NULL));
    int random;
    for (int i = 0; i < LengthStr; i++) {
        random = (rand()/((LIMIT-4)/LengthStr)) + 2;
        for (int j = 0; j < random; j++) {
            result += Alphabet[i];
        }
    }
}
void FolderCreate(int Count, string Alphabet) {
    FILE *Log = fopen("LOG.txt", "a");
    string NameFolder;
    time_t tm;
    for(int i = 0; i < Count; i++) {
        NameFolder = NameGenerate(i, Alphabet);
        //mkdir(NameFolder);
        tm = time(NULL);
        fprintf(Log, "Folder %s create on %s\n", (char*)NameFolder.c_str(), ctime(&tm));
    }
    fclose(Log);
}
void FileCreate(int Count, string Alphabet) {
    FILE *Log = fopen("LOG.txt", "a");
    FILE *newF;
    string NameFile;
    string FullNameFile;
    time_t tm;
    for(int i = 0; i < Count; i++) {
        NameFile = NameGenerate(i, Alphabet);
        FullNameFile = Alphabet[0] + NameFile + ".txt";printf("test: %s", NameFile.c_str());
        newF = fopen((char*)FullNameFile.c_str(), "w");
        fprintf(newF, "test\n");printf(" 2...\n");
        fclose(newF);
        tm = time(NULL);
        
        fprintf(Log, "File %s create on %s\n", (char*)NameFile.c_str(), ctime(&tm));
    }
}
int main() {
    int CountOfFolders, CountOfFiles;
    char FoldersAlphabet[LIMIT-4]; 
    char FilesAlphabet[LIMIT-4];
    string StFoldersAlphabet = "", StFilesAlphabet = ""; // string
    bool IsCorrectEnter = false;
    do {   //FoldersAlphabet
        printf("Enter folders alphabet: ");
        scanf("%s", FoldersAlphabet);
        StFoldersAlphabet = FoldersAlphabet;
        IsCorrectEnter = true;
        for (int i = 0; i < StFoldersAlphabet.length(); i++) {
            if (StFoldersAlphabet[i] >= '0' && StFoldersAlphabet[i] <= '9' || StFoldersAlphabet[i] == ' ') {
                IsCorrectEnter = false;
            }
        }
        if(!IsCorrectEnter) {
            printf("Invalid enter!\n");
        }
        scanf("%*[^\n]");
    }while(!IsCorrectEnter);
    IsCorrectEnter = false;
    do { // CountOfFolders
        printf("Enter Folders count: ");
        if (scanf("%i", &CountOfFolders) > 0 && CountOfFolders < tgamma(StFoldersAlphabet.length())*LIMIT) {
            IsCorrectEnter = true;
        }else printf("Invalid enter!\n");
        scanf("%*[^\n]");
    }while(!IsCorrectEnter);
    FolderCreate(CountOfFolders, StFoldersAlphabet);
    do { // FilesAlphabet
        printf("Enter files alphabet: ");
        scanf("%s", FilesAlphabet);
        StFilesAlphabet = FilesAlphabet;
        IsCorrectEnter = true;
        for (int i = 0; i < StFilesAlphabet.length(); i++) {
            if (StFilesAlphabet[i] >= '0' && StFilesAlphabet[i] <= '9' || StFilesAlphabet[i] == ' ') {
                IsCorrectEnter = false;
            }
        }
        if(!IsCorrectEnter) {
            printf("Invalid enter!\n");
        }
        scanf("%*[^\n]");
    }while(!IsCorrectEnter);
    IsCorrectEnter = false;
    do {  // CountOfFiles
        printf("Enter Files count: ");
        if (scanf("%i", &CountOfFiles) > 0 && CountOfFiles < tgamma(StFilesAlphabet.length())*LIMIT) {
            IsCorrectEnter = true;
        }else printf("Invalid enter!\n");
        scanf("%*[^\n]");
    }while(!IsCorrectEnter);
    printf("tess: %d\n", CountOfFiles);
    FileCreate(CountOfFiles, FilesAlphabet);
    return 0;
}
