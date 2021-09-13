#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class FileReader{
    public:
        FileReader( string inputFileName );
        vector<string> fileToVector();
        fstream fileReaderStream;
    
    private:
        string inputFileName;
};

FileReader::FileReader( string inputFileName){
    this -> fileReaderStream.open( inputFileName );
    this -> inputFileName = inputFileName;
}

vector<string> FileReader::fileToVector(){
    vector<string> fileLines;
    string fileLine;
    
    while( ! this->fileReaderStream.eof()){
        getline( this -> fileReaderStream, fileLine);

        fileLines.push_back( fileLine );

    }
    
    return fileLines;
}