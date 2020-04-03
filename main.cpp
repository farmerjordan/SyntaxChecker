#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "DelimiterCheck.h"

using namespace std;

int main(int argc, char** argv){

  //Instance of Delimiter Check class
  DelimiterCheck thisCheck;

  if(argc > 1){
    string inputFile = argv[1];
    cout << "File to be checked: " << inputFile << endl;
  }

  thisCheck.Check(inputFile);

  bool doAgain = true;
  string repeat;

  while(doAgain == true){


    cout << " " << endl;
    cout << "Would you like to check another file? Enter 'Y' or 'N'." << endl;
    cin >> repeat;

    if(repeat == "N" || repeat == "n"){
      doAgain = false;
    }else if(repeat == "Y" || repeat == "y"){

      string inputFile;
      string verifyChoice;

      cout << "Enter the name of the file you would like to check the syntax of." << endl;
      cin >> inputFile;
      cout << "You entered: " << inputFile << endl;
      cout << "Is this correct? Enter 'Y' or 'N'." << endl;
      cin >> verifyChoice;

      while(verifyChoice == "N" || verifyChoice == "n"){
        cout << "Enter the name of the file you would like to check the syntax of." << endl;
        cin >> inputFile;
        cout << "You entered: " << inputFile << endl;
        cout << "Is this correct? Enter 'Y' or 'N'." << endl;
        cin >> verifyChoice;

        thisCheck.Check(inputFile);
      }
    }else{
      cout << "That wasn't a valid option." << endl;
    }
  }

}
