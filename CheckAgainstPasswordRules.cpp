/******************************************************************************
CIS22B Check a password against rules
File name: CheckAgainstPasswordRules.cpp
@author Pranav Tadepalli
@version 1.0 
@since   thisquarter
*******************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool CheckAgainstPasswordRules(string password);

int main(){
    cout << CheckAgainstPasswordRules("ERFGergeaREG32423#@$#@") << endl;
    cout << CheckAgainstPasswordRules("ERFGergeaREG32423") << endl;
    cout << CheckAgainstPasswordRules("erfgergeareg32423#@$#@") << endl;
    cout << CheckAgainstPasswordRules("ERFGERGEAR32423#@$#@") << endl;
    cout << CheckAgainstPasswordRules("ERFGergeaRE G32423#@$#@") << endl;
    cout << CheckAgainstPasswordRules("Re323#") << endl;
    
    return 0;
}

bool CheckAgainstPasswordRules(string password){
    bool lengthMet = false;
    bool uppercaseMet = false;
    bool lowercaseMet = false;
    bool specialcharMet = false;
    bool nospacesMet = true;
    
    lengthMet = password.length()>=8;
    for (int i=0; i<password.length(); i++){
        if (isupper(password[i])){
            uppercaseMet = true;
        }
        if (islower(password[i])){
            lowercaseMet = true;
        }
        if (password[i] == ' '){
            nospacesMet = false;
        }
        if (password[i] == '!' or password[i] == '@' or password[i] == '#'){
            specialcharMet = true;
        }
    }
    return lengthMet && uppercaseMet && lowercaseMet && specialcharMet && nospacesMet;

}
