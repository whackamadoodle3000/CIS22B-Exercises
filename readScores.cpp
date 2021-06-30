/******************************************************************************
CIS22B Read grades from user and count how many there are of each
File name: readScores.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>

using namespace std;

/**
    Updates grade counts based on user input
    @param A,B,C,D,F The grades counts to be updated
*/
void readScores(int &A, int &B, int &C, int &D, int &F);

int main(){
    //test program with starting counts of 0.
    int A=0, B=0, C=0, D=0, F=0;
    readScores(A, B, C, D, F);
    //sequentially prints each grade count on a different line
    cout << endl << A << endl << B << endl << C << endl << D << endl << F;
    return 0;
}

//Updates grade counts based on user input
void readScores(int &A, int &B, int &C, int &D, int &F){
    int A=0, B=0, C=0, D=0, F=0;
    int grade;
    cout << "Enter grade (-1 to stop): ";
    cin >> grade;
    while (grade!=-1){
        if (grade>=90){
            A++;
        }
        else if (grade>=80){
            B++;
        }
        else if (grade>=70){
            C++;
        }
        else if (grade>=60){
            D++;
        }
        else if (grade>=0 && grade<=59){
            F++;
        }
        else if (grade<0){
            cout << "Invalid and less than 0, try again\n";
        }
        else {
            cout << "Something went very wrong, try again\n";
        }
        cout << "Enter grade (-1 to stop): ";
        cin >> grade;
    }
    
}
