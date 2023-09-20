#include <stdio.h>
#include <time.h>
#include <math.h>
//#include <dir.h>
#include <string> // for string type
#define LIMIT 255 // предел имени файла/директории

using std::string;

string NameGenerate(int i, string Alphabet) {
    string result = "";
    int CursorValue = Alphabet.length()%i;
    char Cursor = Alphabet[CursorValue];
    for(int j =0; j < CursorValue; j++) {
        result += Alphabet[j]; 
    }
    for (int j = 0;j < 250-(Alphabet.length()-CursorValue); j++) {
        result += Cursor;
    }
    for(int j = 0; j < Alphabet.length()-CursorValue; j++) {
        result += Alphabet[j];
    }
    return result;
}
void FolderCreate(int Count, string Alphabet) {
    FILE *Log = fopen("LOG.log", "wa");
    string NameFolder;
    time_t tm;
    for(int i = 0; i < Count; i++) {
        NameFolder = NameGenerate(i, Alphabet);
        //mkdir(NameFolder);
        tm = time(NULL);
        fprintf(Log, "Folder %s create on %s\n", (char*)NameFolder.c_str(), ctime(&tm));
    }
}
void FileCreate(int Count, string Alphabet) {
    
}
int main() {
    int CountOfFolders, CountOfFiles;
    char FoldersAlphabet[LIMIT-4]; 
    char FilesAlphabet[LIMIT-4];
    string StFoldersAlphabet = "", StFilesAlphabet = ""; // string
    bool IsCorrectEnter = false;
    do {
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
    do {
        printf("Enter Folders count: ");
        if (scanf("%i", &CountOfFolders) > 0 && CountOfFolders < tgamma(StFoldersAlphabet.length())*LIMIT) {
            IsCorrectEnter = true;
        }else printf("Invalid enter!\n");
        scanf("%*[^\n]");
    }while(!IsCorrectEnter);
    
    return 0;
}
