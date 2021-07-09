/******************************************************************************
CIS22B Expenses manager
nsions
File name: ManageListOfExpenses.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * adds to data
    @param desc description list
    @param cost cost list
    @return void
*/
int add(string desc[], double cost[], int currentExpenses);


/**
 * lists data
    @param desc description list
    @param cost cost list
    @return void
*/
void list(string desc[], double cost[], int currentExpenses);

/**
    @param desc description list
    @param cost cost list
    @param amount smallest amount of cost
    @return void
*/
void amount(string desc[], double cost[], double amount, int currentExpenses);

/**
    @param desc description list
    @param cost cost list
    @param keywork word to search for
    @return void
*/
void search(string desc[], double cost[], string keyword, int currentExpenses);

int getDataFromFile(ifstream& expenses, double costs[], string descriptions[], int currentExpenses);

bool checkValidDesc(string desc);

bool checkValidCost(double cost);

void printExpense(string desc[], double cost[], int expenseNumber);

int main(int argc, char * agrv[]){
    string currentCommand;
    int const MAX_EXPENSES = 1000;
    int currentExpenses = 0;
    double costs[MAX_EXPENSES];
    string descriptions[MAX_EXPENSES];

    if (argc==2){
        ifstream expenses(agrv[1]);
        if (expenses.is_open()){
            currentExpenses = getDataFromFile(expenses, costs, descriptions, currentExpenses);
            cout << "Welcome to managing a list of expenses.\nPlease enter command and 'exit' to end:\n";
        }
        else{
            cout << "Can't open data file" << endl;
        }
        
    }
    else{
        cout << "Invalid usage. Please give the expense data file name in the command line argument.\n\nSyntax:   ManageListOfExpenses  <expense-data-file-name>";
        currentCommand = "exit";
    } 

    
    while (currentCommand!="exit"){
        getline(cin, currentCommand);
        stringstream command(currentCommand);
        getline(command, currentCommand, ' ');
        //currentCommand = currentCommand.substr(0, currentCommand.find(" "));
        if (currentCommand=="help"){
            cout << "Available commands:\nadd -- add a new expense entry\nlist -- list all expenses\namount>= <amount>  -- list all expenses with amount >= given amount\nsearch <srch>  -- list all expenses with description containing the given srch string\nhelp -- display this help info\nexit -- end this program\n";
        }
        else if (currentCommand=="add"){
            currentExpenses = add(descriptions, costs, currentExpenses);
        }
        else if (currentCommand=="list"){
            list(descriptions, costs, currentExpenses);
        }
        else if (currentCommand=="search"){
            string searchString;
            getline(command, searchString);
            search(descriptions, costs, searchString, currentExpenses);
        } 
        else if (currentCommand=="amount>="){
            double minNum;
            command >> minNum;
            amount(descriptions, costs, minNum, currentExpenses);
        }
        else if (currentCommand == "exit"){
            cout << "Thank you for using my program.\n";
        }
        else {
            cout << "Unsupported command.\n";
        }
        
    }

    return 0;
}




int add(string desc[], double cost[], int currentExpenses){
    double costAmount;
    string description; 
    cout << "Please enter the expense's amount: ";
    cin >> costAmount;
    while (!checkValidCost(costAmount)){
        cout << "Invalid price. Amount cannot be negative. Please try it again." << endl;
        cout << "Please enter the expense's amount: ";
        cin >> costAmount;
    }

    
    cin.ignore();
    cout << "Please enter expense's description:";
    getline(cin, description);
    while (!checkValidDesc(description)){
        cout << "Invalid description. Description cannot be blank or empty." << endl;
        cout << "Please enter expense's description: ";
        getline(cin, description);
    }

    currentExpenses++;
    desc[currentExpenses] = description;
    cost[currentExpenses] = costAmount;

    printExpense(desc, cost, currentExpenses);

    return currentExpenses;
}


void list(string desc[], double cost[], int currentExpenses){
    for (int i=0; i<currentExpenses; i++){
        printExpense(desc, cost, i);
    }
}


void amount(string desc[], double cost[], double amount, int currentExpenses){

}


void search(string desc[], double cost[], string keyword, int currentExpenses){

}

bool checkValidDesc(string desc){
    bool validDesc = false;
    for (char& character:desc){
        if (character!=' '){
            validDesc = true;
        }
    }
    return validDesc;
}

bool checkValidCost(double cost){
    return cost>=0;
}

void printExpense(string desc[], double cost[], int expenseNumber){
    cout << showpoint << fixed << setprecision(2) << " AMOUNT($" << cost[expenseNumber] << ")" << setw(15) << setfill(' ') << "DESC(" << desc[expenseNumber] << ")" << endl;
}
int getDataFromFile(ifstream& expenses, double costs[], string descriptions[], int currentExpenses){
    string currentExpense;
    string currentDescription;
    double currentCost;
    bool valid;
    bool stillGoing = true;

    
    while (expenses >> currentCost){
        getline(expenses >> ws, currentDescription, '\r');

        valid=true;

        if (!checkValidDesc(currentDescription)){
            cout << "Invalid description for expense number " << currentExpenses << ". Description cannot be blank or empty.";
            valid=false;
        }

        
        if (!checkValidCost(currentCost)){
            cout << "Invalid price for expense number" << currentExpenses << ". Amount cannot be negative.";
            valid=false;
        }

        if (valid){
            costs[currentExpenses] = currentCost;
            descriptions[currentExpenses] = currentDescription;
            currentExpenses++;
        }
        
    }
    expenses.close();
    return currentExpenses;
}