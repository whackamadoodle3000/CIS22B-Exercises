
/******************************************************************************
CIS22B 
File name: day4.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

/**
    Shift the contents of each element in the array whenever a zero element is deleted
    @param array The array to process
    @param size Size of the array
    @return how many 0s it swapped
*/
int deleteZeros(int array[], int size);

/**
    Reverse the case of the cstring
    @param letters the c string
*/
int reverseCase(char letters[]);


getNumList
int main(){
    // test deleteZeros
    int test[] = {10, 0,  20, 30, 40, 0, 50};
    
    cout << (deleteZeros(test, 6)) << endl;
    
    for (int num:test){
        cout << num << ",";
    }
    cout << endl << endl;
    
    //test reverseCase
    char letters[] = "  Hello, World!  ";
    cout << "Letters reversed: " << reverseCase(letters) << endl;
    for (char letter:letters){
        cout << letter;
    }
    cout << endl;
    return 0;
}

//Shift the contents of each element in the array whenever a zero element is deleted
int deleteZeros(int array[], int size){
    int zeroes = 0;
    for (int i=0;i<size-1;i++){
        if (array[i]==0){
            for (int j=i; j<size;j++){
                array[j] = array[j+1];
            }
            zeroes++;
        }
    }
    return zeroes;
    
}

//Reverse the case of the cstring
int reverseCase(char letters[]){
    int numberChanged = 0;
    for (int i=0; i<strlen(letters); i++){
        if (islower(letters[i])){
            letters[i] = toupper(letters[i]);
            numberChanged++;
        }
        else if (isupper(letters[i])){
            letters[i] = tolower(letters[i]);
            numberChanged++;
        }
    }
    return numberChanged;
}

















