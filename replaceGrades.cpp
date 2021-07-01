
/******************************************************************************
CIS22B checks validity of grades and replaces invalid ones
File name: replaceGrades.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/**
     checks validity of grades and replaces invalid ones
    @param grades the cstring to process
    @return how many invalid grades there are
*/
int replaceGrades(char grades[]);

/**
    tests the above function with a string and prints result
    @param string to process
*/
void testFunction(char gradeslist[]);

int main(){
    // test replaceGrades with different conditions
    char grades0[] = {'A', 'B', 'X', 'C', '\0'};
    testFunction(grades0);
    
    char grades1[] = {'A','\0'};
    
    testFunction(grades1);
    
    char grades2[] = {'A', 'B', 'C', 'A', '\0'};
    testFunction(grades2);
    
    char grades3[] = {'X', 'Y', 'Z', '\0'};
    testFunction(grades3);
    
    return 0;
}

void testFunction(char gradeslist[]){
    for (int i=0; i<strlen(gradeslist); i++){
        cout << gradeslist[i] << ",";
    }
    cout << endl;
    cout << "Replacing " << (replaceGrades(gradeslist)) << " invalid grades" << endl;
    
    for (int i=0; i<strlen(gradeslist); i++){
        cout << gradeslist[i] << ",";
    }
    
    cout << endl << endl;
}

// checks validity of grades and replaces invalid ones
int replaceGrades(char grades[]){
    char validGrades[] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'F', 'f'};
    int invalidGrades = 0;
    int gradesLength = strlen(grades);
    bool valid = false;
    for (int i=0; i<gradesLength; i++){
        valid=false;
        for (char grade:validGrades){
            if (grades[i]==grade){
                valid=true;
            }
        }
        if (!valid){
            grades[i] = 'I';
        }
        invalidGrades += !valid;
    }
    return invalidGrades;
}
