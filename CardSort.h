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
  int trick(){
    int colSelection;
    fillDeck();

    printDeck();
    colSelection = prompt();
    sort(colSelection);

    printDeck();
    colSelection = prompt();
    sort(colSelection);

    printDeck();
    colSelection = prompt();
    sort(colSelection);


    cout << "Was your number - " << findAns() << endl;
    return findAns();
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


  void sort(int colSelection){
  ///@param colSelection the col user says their number is in

    vector<int> hCol;
    vector<int> aCol;
    vector<int> bCol;

    if (colSelection == 1) {
      intArrFill(deck[colSelection-1],hCol);
      intArrFill(deck[1],aCol);
      intArrFill(deck[2],bCol);

      pickCardsUp(hCol,aCol,bCol);

    }
    else if(colSelection == 2){
      intArrFill(deck[colSelection-1],hCol);
      intArrFill(deck[0],aCol);
      intArrFill(deck[2],bCol);

      pickCardsUp(hCol,aCol,bCol);
    }
    else if(colSelection == 3){
      intArrFill(deck[colSelection-1],hCol);
      intArrFill(deck[0],aCol);
      intArrFill(deck[1],bCol);

      pickCardsUp(hCol,aCol,bCol);
    }
  };

  int findAns(){
    int adjCnt = 0;

    for (size_t i = 0; i < COL_SIZE; i++)
    {
        for (size_t j = 0; j < ROW_SIZE; j++)
        {
            if (adjCnt == 10)
            {
                return deck[j][i];
            }
            adjCnt++;
        }
    }
    return -1;
  };

  void intArrFill(int src[],vector<int> &dest)
  {

    for (int i = COL_SIZE-1; i >= 0; i--) {
      //cout << "I: " << i << endl;
      dest.push_back(src[i]);
    }
  };

  void pickCardsUp(vector<int> &selectedCol,vector<int> &aCol,vector<int> &bCol){

    int cnt = 0;
    int arrIndex = 0;
    int adjCnt = 0;
    int cardsInHand[21];



    while (cnt < 7) {

        cardsInHand[cnt] = aCol[cnt];

        arrIndex++;
        cnt++;
    }
    arrIndex = 0;
    while (cnt < 14) {

        cardsInHand[cnt] = selectedCol[arrIndex];

        arrIndex++;
        cnt++;
    }
    arrIndex = 0;
    while (cnt < 21) {

        cardsInHand[cnt] = bCol[arrIndex];

        arrIndex++;
        cnt++;
    }

//refilling the deck from 1D array
    for (size_t i = 0; i < COL_SIZE; i++)
    {
        for (size_t j = 0; j < ROW_SIZE; j++)
        {
            deck[j][i] = cardsInHand[adjCnt];
            adjCnt++;
        }
    }
    cnt = 0;
    adjCnt = 0;
    arrIndex = 0;
  }

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

  void printV(vector<int> v)
  {
    for (size_t i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  };

private:

int deck[3][7];

};


#endif
