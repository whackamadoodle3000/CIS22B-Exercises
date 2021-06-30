
/******************************************************************************
CIS22B Swap first negative of an array with last positive of an array
File name: swapTheFirstNegativeWithTheLastPositive.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>

using namespace std;

/**
    Swap first negative of an array with last positive of an array
    @param array The list to get info for
    @param size Size of the array
    @return whether it swapped anything
*/
bool swapTheFirstNegativeWithTheLastPositive(int array[], int size);

int main(){
    // test swapTheFirstNegativeWithTheLastPositive with different conditions
    int test[6] = {-10, -20, -30, 10, 20, 30};
    cout << (swapTheFirstNegativeWithTheLastPositive(test, 6)?"true":"false") << endl;
    for (int num:test){
        cout << num << ",";
    }
    cout << endl;
    
    int test1[4] = {10, -20, 30, -40} ;
    cout << (swapTheFirstNegativeWithTheLastPositive(test1, 4)?"true":"false") << endl;
    for (int num:test1){
        cout << num << ",";
    }
    cout << endl;
    
    int test2[3] = {-10, -20, -30} ;
    cout << (swapTheFirstNegativeWithTheLastPositive(test2, 3)?"true":"false") << endl;
    for (int num:test2){
        cout << num << ",";
    }
    cout << endl;

    return 0;
}

//Swap first negative of an array with last positive of an array
bool swapTheFirstNegativeWithTheLastPositive(int array[], int size){
    int tempNum;
    int firstNegativeIndex = -1;
    int lastPositiveIndex = -1;
    int currentIndex = 0;
    bool swapped;
    while (currentIndex<size){
        if (firstNegativeIndex==-1 && array[currentIndex]<0){
            firstNegativeIndex=currentIndex;
        }
        if (lastPositiveIndex==-1 && array[size-currentIndex-1]>0){
            lastPositiveIndex=size-currentIndex-1;
        }
        currentIndex++;
    }
    swapped = firstNegativeIndex!=-1 && lastPositiveIndex!=-1;
    if (swapped){
        tempNum = array[firstNegativeIndex];
        array[firstNegativeIndex] = array[lastPositiveIndex];
        array[lastPositiveIndex] = tempNum;
        
    }
    return swapped;
}
