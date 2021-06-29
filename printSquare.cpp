/******************************************************************************
CIS22B Print a square with certain dimensions
File name: printSquare.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>

using namespace std;

void printSquare(char character, int size);

int main(){
    printSquare('*', 5);
    printSquare('@', 3);
    printSquare('*', 1);
    return 0;
}

void printSquare(char character, int size){
    for (int i=0; i<size; i++){
        if (i==0 or i==(size-1)){
            for (int i=0; i<size; i++){
                cout << character;
            }
        }
        else{
            cout << character;
            for (int i=0; i<size-2; i++){
                cout << ' ';
            }
            cout << character;
        }
        cout << endl;
    }
}
