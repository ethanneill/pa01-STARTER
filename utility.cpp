//utility.cpp
//Author: Ethan Neill
//Implementation of the classes defined in utility.h

#include "utility.h"
#include <iostream>
using std::cout;

int assignValue(string card){
    int value = 0;
    char suit = card[0];
    char num = card[2];

    if(suit == 'c'){
        value += 100;
    }
    else if(suit == 'd'){
        value += 200;
    }
    else if(suit == 's'){
        value += 300;
    }
    else{
        value += 400;
    }

    if(card.length() == 4){
        value += 10;
    }
    else{
        if(num == '1'){
            value += 1;
        }
        if(num == '2'){
            value += 2;
        }
        if(num == '3'){
            value += 3;
        }
        if(num == '4'){
            value += 4;
        }
        if(num == '5'){
            value += 5;
        }
        if(num == '6'){
            value += 6;
        }
        if(num == '7'){
            value += 7;
        }
        if(num == '8'){
            value += 8;
        }
        if(num == '9'){
            value += 9;
        }
        if(num == 'j'){
            value += 11;
        }
        if(num == 'q'){
            value += 12;
        }
        if(num == 'k'){
            value += 13;
        }
    }
    return value;
}