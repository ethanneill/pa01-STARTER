#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"
#include "utility.h"

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  IntBST cardBST1, cardBST2;
  int amountOfCards = 0;

  //Read each file
  while (getline (cardFile1, line) && (line.length() > 0)){
    int cardValue = assignValue(line);
    cardBST1.insert(cardValue, line);
    amountOfCards++;
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
    int cardValue = assignValue(line);
    cardBST2.insert(cardValue, line);
  }
  cardFile2.close();

  int alice = cardBST1.getSmallest();
  int aliceNext;
  int bob = cardBST2.getLargest();
  int bobNext;
  int pointer = alice;
  int matches = 0;

  for(int i = 0; i < amountOfCards; i++){
    if((cardBST1.contains(pointer)) && (cardBST2.contains(pointer))){
      matches++;
    }
    pointer = cardBST1.getSuccessor(pointer);
  }
  matches = matches;
  
  while(matches != 0){
    int count = 0;
    while((count == 0) && (matches != 0)){
      if(cardBST2.contains(alice)){
        cout<<"Alice picked matching card ";
        cardBST1.printCard(alice);
        cout<<endl;
        aliceNext = cardBST1.getSuccessor(alice);
        cardBST1.remove(alice);
        cardBST2.remove(alice);
        alice = aliceNext;
        count++;
	matches--;
        break;
      }
      alice = cardBST1.getSuccessor(alice);
    }

    count--;
    while((count == 0) && (matches != 0)){
      if(cardBST1.contains(bob)){
        cout<<"Bob picked matching card ";
        cardBST2.printCard(bob);
        cout<<endl;
        bobNext = cardBST2.getPredecessor(bob);
        cardBST1.remove(bob);
        cardBST2.remove(bob);
        bob = bobNext;
        count++;
	matches--;
        break;
      }
      bob = cardBST2.getPredecessor(bob);
    }
  }

  cout<<endl;
  cout<<"Alice's cards:"<<endl;
  cardBST1.printInOrder();
  
  cout<<endl;
  cout<<"Bob's cards:"<<endl;
  cardBST2.printInOrder();
  
  return 0;
}

