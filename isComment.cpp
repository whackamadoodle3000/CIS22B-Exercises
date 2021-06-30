/******************************************************************************
CIS22B Check if a string is a comment
File name: isComment.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

bool isComment (string text);

int main (){
  //test isComment for various cases
  cout << isComment("//globgogabgalab") << endl;
  cout << isComment(" //globgogabgalab") << endl;
  cout << isComment(" / /globgogabgalab") << endl;
  cout << isComment(" /g/lobgogabgalab") << endl;
  cout << isComment("globgogabgalab//") << endl;
  cout << isComment("/") << endl;
}

bool isComment(string text) {
  /* check for valid comment */
  
  //find index of first non-space
  int currentCharIndex = 0;
  while (text[currentCharIndex] == ' '){
      currentCharIndex++;
  }
  
  //check if first two non-space chars are /
  //short circuits to false for inputs too small to prevent errors
  return text.length () > 1 && text[currentCharIndex] == '/'
    && text[currentCharIndex + 1] == '/';
}
