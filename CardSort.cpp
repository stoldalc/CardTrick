#include <iostream>

using namespace std;

const int ROW_SIZE = 3;
const int COL_SIZE = 7;
const int NUMBERS[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

void printArray(int deck[ROW_SIZE][COL_SIZE]);
void intCpy(int *src,int *dest);
void sort(int deck[ROW_SIZE][COL_SIZE]);



int main()
{

    int cards[3][7];
    int adjCnt = 0;

    for (size_t i = 0; i < COL_SIZE; i++)
    {
        for (size_t j = 0; j < ROW_SIZE; j++)
        {
            cards[j][i] = NUMBERS[adjCnt];
            adjCnt++;
        }
    }

    sort(cards);

return 0;
}

void printArray(int deck[ROW_SIZE][COL_SIZE])
{

    for (size_t i = 0; i < COL_SIZE; i++) {
        for (size_t j = 0; j < ROW_SIZE; j++) {

        }
        cout << endl;
    }


}
void intCpy(int *src, int *dest)
{



    for (size_t i = 0; i < 7; i++)
    {
        dest[i] = src[i];
    }


}
void sort(int deck[ROW_SIZE][COL_SIZE])
{
    int colSelection = 0;
    int emptyTest[7] = {0};
    int CorrectNumber[7];
    int Row1[7];
    int Row3[7];
    int tempStack[21];
    int cnt = 0;
    int arrayCnt = 0;
    int adjCnt = 0;
    int ans;

    printArray(deck);
    for (size_t i = 0; i < 3; i++)
    {

        cout << "Pick a number" << endl;
        cout << "What col is your number in:" << endl;
        cout << "Cols numbered 1-3 left to right" << endl;
        cin >> colSelection;
//If item is in first row
        if (colSelection == 1) {
            //cout << 1 << endl;

            //COPING INFO TO CORRECT TEMP ARRAYS
//Swaping the items into temp arrays
        //Array where correct number is
            intCpy(deck[colSelection-1],CorrectNumber);
        //Other two arrays
            intCpy(deck[1],Row1);
            intCpy(deck[2],Row3);


            //COPYING TEMP ARRAYS TO 1D STACK
//Very poorly written process for copying 2D array into 3D array for some reason???
/*
 if (i%7) reset count;
*/
            while (cnt < 7) {

                tempStack[cnt] = Row1[cnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 14) {

                tempStack[cnt] = CorrectNumber[arrayCnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 21) {

                tempStack[cnt] = Row3[arrayCnt];
                //cout << Row3[arrayCnt3] << endl;

                arrayCnt++;
                cnt++;
            }

//refilling the deck from 1D array
            for (size_t i = 0; i < COL_SIZE; i++)
            {
                for (size_t j = 0; j < ROW_SIZE; j++)
                {
                    deck[j][i] = tempStack[adjCnt];
                    adjCnt++;
                }
            }
            cnt = 0;
            adjCnt = 0;
            arrayCnt = 0;

            printArray(deck);

        }
//If item is in second row
        else if (colSelection == 2) {
            //cout << 2 << endl;
            //COPING INFO TO CORRECT TEMP ARRAYS
            intCpy(deck[colSelection-1],CorrectNumber);
            intCpy(deck[0],Row1);
            intCpy(deck[2],Row3);


            //COPYING TEMP ARRAYS TO 1D STACK

            while (cnt < 7) {

                tempStack[cnt] = Row1[cnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 14) {
                int arrayCnt2 = 0;
                tempStack[cnt] = CorrectNumber[arrayCnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 21) {

                tempStack[cnt] = Row3[arrayCnt];
                //cout << Row3[arrayCnt3] << endl;

                arrayCnt++;
                cnt++;
            }
            for (size_t i = 0; i < COL_SIZE; i++)
            {
                for (size_t j = 0; j < ROW_SIZE; j++)
                {
                    deck[j][i] = tempStack[adjCnt];
                    adjCnt++;
                }
            }
                cnt = 0;
                adjCnt = 0;
                arrayCnt = 0;

            printArray(deck);
        }
//If selection is in 3rd row
        else if (colSelection == 3) {
            //cout << 3 << endl;
            //COPING INFO TO CORRECT TEMP ARRAYS
            intCpy(deck[colSelection-1],CorrectNumber);
            intCpy(deck[0],Row1);
            intCpy(deck[1],Row3);


            //COPYING TEMP ARRAYS TO 1D STACK

            while (cnt < 7) {

                tempStack[cnt] = Row1[cnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 14) {
                int arrayCnt2 = 0;
                tempStack[cnt] = CorrectNumber[arrayCnt];

                cnt++;
                arrayCnt++;
            }
            arrayCnt = 0;
            while (cnt < 21) {

                tempStack[cnt] = Row3[arrayCnt];
                //cout << Row3[arrayCnt3] << endl;

                arrayCnt++;
                cnt++;
            }
            for (size_t i = 0; i < COL_SIZE; i++)
            {
                for (size_t j = 0; j < ROW_SIZE; j++)
                {
                    deck[j][i] = tempStack[adjCnt];
                    adjCnt++;
                }
            }
                cnt = 0;
                adjCnt = 0;
                arrayCnt = 0;

            printArray(deck);

        }

    }
// eleventh item is slected
        for (size_t i = 0; i < COL_SIZE; i++)
        {
            for (size_t j = 0; j < ROW_SIZE; j++)
            {
                if (adjCnt == 10)
                {
                    ans = deck[j][i];
                }
                adjCnt++;
            }
        }

        cout << "Your number was: " << ans << endl;
}
