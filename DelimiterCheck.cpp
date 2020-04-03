#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "DelimiterCheck.h"
using namespace std;

void DelimiterChecker::Check(string inputFile){

    //Variables for iteration
    string currentLine;
    int lineCount = 0;

    //Instance of file stream
    ifstream checkFile;



    checkFile.open(inputFile);

    //Determining number of lines in the file, because if someone has good coding practices
    //they wouldn't have more delimiters than number of lines
    while (!checkFile.eof()){
        getline(checkFile, currentLine);
        lineCount++;
        cout << lineCount << endl;
    }

    //Instance of GenStack class to use the methods
    GenStack<int> myStack(lineCount);

    //Returning to top of file to do actual delimiter checking
    checkFile.clear();
    checkFile.seekg(0, ios::beg);


    while(!checkFile.eof()){
      getline(checkFile, currentLine);

    }


}
