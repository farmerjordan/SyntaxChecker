#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "DelimiterCheck.h"
using namespace std;

void DelimiterCheck::Check(string inputFile){

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
        cout << "This file has " << lineCount << " lines." << endl;
    }

    //Instance of GenStack class to use the methods
    GenStack<char> myStack(lineCount);

    //Resetting line count
    lineCount = 0;

    //Returning to top of file to do actual delimiter checking
    checkFile.clear();
    checkFile.seekg(0, ios::beg);


    while(!checkFile.eof()){
      getline(checkFile, currentLine);
      lineCount++;

      for(int i = 0; i < lineCount; ++i){

        if(currentLine[i] == '(' || currentLine[i] == '{' || currentLine[i] == '['){
          myStack.push(currentLine[i]);
        }else if(currentLine[i] == ')' || currentLine[i] == '}' || currentLine[i] == ']'){

          char openingDelim = myStack.pop();
          char closingDelim = currentLine[i];

          //Checking that delimiters match
          if(!((openingDelim == '(' && closingDelim == ')') || (openingDelim == '{' && closingDelim == '}') || (openingDelim == '[' && closingDelim == ']'))){
            if(openingDelim == '('){
              cout << "Delimiter mismatch. Expected ')' but found " << closingDelim << "instead. Error at line number " << currentLine << endl;
            }else if(openingDelim == '{'){
              cout << "Delimiter mismatch. Expected '}' but found " << closingDelim << "instead. Error at line number " << currentLine << endl;
            }else{
              cout << "Delimiter mismatch. Expected ']' but found " << closingDelim << "instead. Error at line number " << currentLine << endl;
            }
          }

          //Exiting to allow user to fix issues
          exit(1);
        }


      }

    }

    //Checking if the file needs more delimiters at the end
    if(!(myStack.isEmpty())){
      //Stack still has something in it
      char remainingDelim = myStack.pop();
      if(remainingDelim == '('){
        cout << "Reached end of file. Expected ')'." << endl;
      }else if(remainingDelim == '{'){
        cout << "Reached end of file. Expected '}'." << endl;
      }else{
        cout << "Reached end of file. Expected ']'." << endl;
      }

      //Exiting to allow user to fix issues
      exit(1);
    }else{
      cout << "File looks good. No delimiter errors found." << endl;
    }


}
