#include <iostream>
#include "FileCounter.h"
#include "FileReader.h"
#include <locale>


using namespace std;


int main(){

    setlocale(LC_ALL, "es_ES");
   
    string inputFileName;
    cout<<" Ingrese el nombre del archivo junto a su extension" <<endl;
    getline( cin, inputFileName );

    FileReader fileReader( inputFileName );

    if( ! fileReader.fileReaderStream.is_open() ){

        cout << "Error: You tried to read a file that does not exists in this directory" <<endl;

    } else {

        vector<string> fileVectorRepresentation = fileReader.fileToVector();

        if( fileVectorRepresentation.size() == 0 || ( fileVectorRepresentation.size() == 1 && fileVectorRepresentation[0].size() == 0)){

            cout << "Error: You tried to read an empty file" << endl;

        } else {

            FileCounter fileCounter( fileVectorRepresentation );

            fileCounter.lineCounter();

            fileCounter.printFileCounter( inputFileName );

        }
    }
    getline(cin,inputFileName);
    return 0;
}