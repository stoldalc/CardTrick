#include <iostream>
#include <vector>

using namespace std;

#ifndef CARDTRICK_H
#define CARDTRICK_H

const int ANSPOSTION = 10;

const int ROW_SIZE = 3;
const int COL_SIZE = 7;
const int NUMBERS[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};


class cardTrick{

public:
  cardTrick(){

  };
  void trick(){

    fillDeck();
    printDeck();
    int colSelection = prompt();
    sort(colSelection);
  }

  void fillDeck(){
    int fIndex = 0;
    for (size_t i = 0; i < COL_SIZE; i++)
    {
        for (size_t j = 0; j < ROW_SIZE; j++)
        {
            deck[j][i] = NUMBERS[fIndex];
            fIndex++;
        }
    }
  };

  void printDeck(){
      for(int i = 0;i <  COL_SIZE;i++){
        for(int j = 0;j < ROW_SIZE;j++){
          cout.width(4);cout << std::right <<deck[j][i] << "  ";
        }
        cout << endl;
      }
  };


  void sort(int selection){
  ///@param colSelection the col user says their number is in
    int colSelection;
    vector<int> hCol[7];
    vector<int> aCol[7];
    vector<int> bCol[7];

    if (colSelection == 1) {
      hCol = deck[colSelection-1];
      aCol = deck[1];
      bCol = deck[2];

    }




  };
  inline void intCpy(){

  };
/// prompt prompts users for input, written into function for readability
  int prompt(){
    int colSelection;
    while(1){
      cout << "Pick a number" << endl;
      cout << "What col is your number in:" << endl;
      cout << "Cols numbered 1-3 left to right" << endl;
      cin >> colSelection;
///Checking if users input is valid
      if ((colSelection <= 3)&&(colSelection >=1)) {
        break;
      }
      else{
        cout << endl << "Please pick a number between 1 and 3" << endl << endl;
      }
    }
    return colSelection;
  };

private:

int deck[3][7];

};


#endif
