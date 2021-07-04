
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
    @return number of letters changed
*/
int reverseCase(char letters[]);


/**
    Creates an array of numofnums numbers
    @param numofnums number of integers to read
    @return address of array of numbers
*/
int* getNumList(int size);

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
    cout << endl << endl;
    
    //test getNumList
    int* pointer;
    pointer = getNumList(3);
    
    for (int i=0; i<3; i++, pointer++){
        cout << *(&pointer) << ",";
    }
    cout << endl << endl;
    
    return 0;
}

//Shift the contents of each element in the array whenever a zero element is deleted
int deleteZeros(int array[], int size){
    int zeroes = 0;
    int* pointerOuter = array;
    int* pointerInner;
    for (int i=0;i<size-1;i++,pointerOuter++){
        if (*pointerOuter==0){
            pointerInner = pointerOuter;
            for (int j=i; j<size;j++,pointerInner++){
                array[j] = *(pointerInner+1);
            }
            zeroes++;
        }
    }
    return zeroes;
    
}

//Reverse the case of the cstring
int reverseCase(char letters[]){
    int numberChanged = 0;
    char* letterPointer = letters;
    for (int i=0; i<strlen(letters); i++, letterPointer++){
        if (islower(letters[i])){
            letters[i] = toupper(*letterPointer);
            numberChanged++;
        }
        else if (isupper(letters[i])){
            letters[i] = tolower(*letterPointer);
            numberChanged++;
        }
    }
    return numberChanged;
}

int* getNumList(int size){
    int numlist[size];
    int* pointer = numlist;
    int tempNum;
    for (int i = 0; i<size; i++, pointer++){
        cout << "Enter an Integer: ";
        cin >> numlist[i];
    }
    return &(numlist[0]);
}















