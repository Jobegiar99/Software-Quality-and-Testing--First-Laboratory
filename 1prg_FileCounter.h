#include <vector>
#include <iostream>
#include <ctype.h>
#include <string>

using namespace std;

class FileCounter{
    public: 
        FileCounter( vector<string> fileVectorRepresentation );
        void lineCounter();
        void printFileCounter( string inputFileName );

    private:
        vector<string> fileVectorRepresentation;
        int totalLines;
        int commentLines;
        int spaceLines;
        int codeLines;
};

FileCounter::FileCounter( vector<string> fileVectorRepresentation ){

    this -> fileVectorRepresentation = fileVectorRepresentation;

    this -> totalLines = fileVectorRepresentation.size();

    this -> commentLines = 0;
    
    this -> spaceLines = 0;

    this -> codeLines = 0;

}

void FileCounter::lineCounter(){

    bool multiLineComment = false;

    for(int index = 0 ; index < this -> fileVectorRepresentation.size() ; index++ ){

        string currentLine = this -> fileVectorRepresentation[ index ];

        if ( currentLine.size() == 0 ){
            this -> spaceLines++;

        }else if ( currentLine.find("//") != string::npos){
            this -> commentLines++;

        }else if( currentLine.find("/*") != string::npos && !multiLineComment){
            this -> commentLines++;
            multiLineComment = true;

        } else if ( currentLine.find('*') != string::npos && multiLineComment){

            this -> commentLines++;

        } else if ( currentLine.find("*/") != string::npos && multiLineComment){

            this -> commentLines++;
            multiLineComment = false;

        }else if ( !isspace( currentLine[ 0 ]) ){
            this -> codeLines++;

        }else{

            bool isEmpty = true;

            for( int charIndex = 0; charIndex < currentLine.size(); charIndex++ ){

                if( !isspace( currentLine[ charIndex ] )){
                    isEmpty = false;
                    break;
                }

            }

            if( isEmpty ){
                this -> spaceLines++;
            
            }else{
                this -> codeLines++;
            }

        }

    }
}

void FileCounter::printFileCounter( string inputFileName ){

    cout<< "Nombre del archivo: " << inputFileName << endl;
    cout<< "--------------------------------------------" << endl;
    cout<< "Cantidad de lineas en blanco: " << to_string( this -> spaceLines ) << endl;
    cout<< "Cantidad de lineas con comentarios: " << to_string( this -> commentLines ) << endl;
    cout<< "Cantidad de lineas con codigo: " << to_string( this -> codeLines ) << endl;
    cout<< "--------------------------------------------" <<endl;
    cout<< "Cantidad total de lineas: " << to_string( this -> totalLines ) << endl;

}