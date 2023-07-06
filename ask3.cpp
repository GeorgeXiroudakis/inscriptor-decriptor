//this programm takes a string from the commant line 
//then at runtime it askes for the mode (incoding, dicoding )
//and the magic number 
//it priints the changed string according to the mugic number


//#include "std_lib_facilities.h"

#include <iostream>
using namespace std;

//this finction is asking for the mode(incode, dicode) and the mugic number 
//after it checks them it incodes or decodes the message 
void in_decoder(char *impute){
    short int mode; //it can only be 1, 2 (to save memmory)
    int n, i;   
    cout << "Please give a mode.\n1: incode\n2: decode\n>";
    do{//exception forinvalid mode
        while( !(cin >> mode) ){ // check if int
            cerr << "The imput was NOT valid.\nPlese give valid imput(integer) as discribed above\n>"; // error mesage
            cin.clear(); //clearing cin
            cin.ignore(100, '\n'); //ignoring previous imputes
        }
        if (!( mode == 1 || mode == 2 )){ //if we have to read again according message
            cout << "Mode can only be 1 or 2 as discribed above please try again\n>";
        }
    }while(!( mode == 1 || mode == 2 )); // check if it is a valid mode(1, 2)
    cout << "\nNow please give the magic number\n>";
    while( !(cin >> n) ){ // check if int
        cerr << "The imput was NOT valid.\nPlease give valid imput(integer).\n>"; // error mesage
        cin.clear(); //clearing cin
        cin.ignore(100, '\n'); // ignoring previous imputes
    }
    int length = 0;
    while ( *impute != '\0'){ // get the length of the string
        length++;
        impute++;
    }
    impute = impute - length; // bring the pointer back to the start of the string
    for (i = 0; i < length; i++){
        impute[i] = mode == 1 ? impute[i] + n : impute[i] - n; //altered the string according to the mode and mugic number
    }
    return;
}


//main checks if the program was called correctly, calls the incode/decode function and the prints the altered message
int main(int argc, char **argv){
    int i = 0;
    if ( argc != 2 ){ //check if the correct number of arguments where giver (one)
        cerr << "Incorect call of [" << argv <<"]. Please give only one string argument along side the program call.\n"; 
        exit(-1);
    }
    in_decoder(argv[1]); //call the function
    cout << "The altered message is: ";
    while (argv[1][i] != '\0' ){ //print the string in the same addres (it was changed by the function)
        cout << argv[1][i];
        i++;
    }
    cout << "\n";

    //system("pause");
    return 0;
}
