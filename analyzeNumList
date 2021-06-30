
/******************************************************************************
CIS22B Find info about a list of numbers
File name: analyzeNumList.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>

using namespace std;

/**
    Gives info about a list
    @param array The list to get info for
    @param size Size of the array
    @param positives Variable to put positive count in
    @param negatives Variable to put negatives count in
    @param positives Variable to put positive count in
    @param zeroes Variable to put zeroes count in
    @param largest Variable to put largest num in
    @param smallest Variable to put smallest num in
*/
void analyzeNumList(int array[], int size, int &positives, int &negatives, int &zeroes, int &largest, int &smallest);

int main(){
    // test analyzeNumList with various cases
    int test[7] = {10, 20, -30, -40, 50, 0, 60};
    int positives, negatives, zeroes, largest, smallest;
    
    analyzeNumList(test, 7, positives, negatives, zeroes, largest, smallest);
    
    cout << "positives: " << positives << endl;
    cout << "negatives: " << negatives << endl;
    cout << "zeroes: " << zeroes << endl;
    cout << "largest: " << largest << endl;
    cout << "smallest: " << smallest << endl;
    
    return 0;
}

//Gives info about a list
void analyzeNumList(int array[], int size, int &positives, int &negatives, int &zeroes, int &largest, int &smallest){
    if (size>0){
        positives = 0;
        negatives = 0;
        zeroes = 0;
        largest = array[0];
        smallest = array[0];
        
        for (int i=0; i<size; i++){
            positives += array[i]>0;
            negatives += array[i]<0;
            zeroes += array[i]==0;
            if (array[i]>largest){
                largest = array[i];
            }
            if (array[i]<smallest){
                smallest = array[i];
            }
        }
    }
}
