
/******************************************************************************
CIS22B detects if first three and last three chars of c string are same
File name: areFirstThreeTheSameAsLastThreeChars.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**
    detects if first three and last three chars of c string are same
    @param cString the cstring to process
    @return whether the first three and last three chars are the same
*/
bool areFirstThreeTheSameAsLastThreeChars(char cString[]);

/**
    tests the above function with a string and prints result
    @param string to process
*/
void testFunction(char text[]);

int main(){
    // test areFirstThreeTheSameAsLastThreeChars with different conditions
    char cstring[] = "";
    testFunction(cstring);
    
    char cstring1[] = "A";
    testFunction(cstring1);
    
    char cstring2[] = "AB";
    testFunction(cstring2);
    
    char cstring3[] = "ABBA";
    testFunction(cstring3);
    
    char cstring4[] = "ABAB";
    testFunction(cstring4);
    
    char cstring5[] = "ABCCBA";
    testFunction(cstring5);
    
    char cstring6[] = "ABABA";
    testFunction(cstring6);
    
    char cstring7[] = "ABC";
    testFunction(cstring7);
    
    char cstring8[] = "ABCABC";
    testFunction(cstring8);

    return 0;
}

void testFunction(char text[]){
    for (int i=0; i<strlen(text); i++){
        cout << text[i] << ",";
    }
    cout << endl;
    cout << (areFirstThreeTheSameAsLastThreeChars(text)?"true":"false") << endl;
}

//detects if first three and last three chars of c string are same
bool areFirstThreeTheSameAsLastThreeChars(char cString[]){
    int length = strlen(cString);
    return length>2 && cString[0]==cString[length-3] && cString[1]==cString[length-2] && cString[2]==cString[length-1];
}
