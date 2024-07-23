#include <iostream>
#include <vector>
#include <random>

/* 
1 player must input how many players there are
2: randomly generate a number
3: show the range available
4: check if the number is correct 
5: if not if the number is above the given number have etc 
6: this is not a school project just wing it 
*/

class game {

    public:

    int randomNumber;
    int numberOfPlayers;
    int chosenNumber; // the number the player chooses
    std :: vector <int> players;
    int max = 100; 
    int min = 0;
    bool hit;

    void chooseNumberPlayers(int &nOP){

        int x;

        std :: cout << "How many is playing? \n";
        std :: cin >> x;

        nOP = x;

    }

    void randNumber(int &random){
        int a = rand() %100 + 1;
        random = a;
    }

    void choosingNumber(int &chosenNumber){

        int x;
        std :: cout << "Choose your number between " << min << " and " << max;
        std :: cin >> x;

        chosenNumber = x;

    }

    void checkNumber(int chosenNumber, bool &hit, int &min, int &max){

        if (chosenNumber == randomNumber){

            std :: cout << "The Bomb Explodes! You Lose! \n";
            hit = false;

        }

        else {
            calculateRange(chosenNumber, min, max);
            hit = true;
        }
    }

    void calculateRange(int &chosenNumber, int &min, int &max){

        if (chosenNumber < randomNumber){
            chosenNumber = min;
        }
        else {
            
            chosenNumber = max;
        }

    }


};

void promptGamePlay (){

    game gm1;

    gm1.chooseNumberPlayers(gm1.numberOfPlayers);
    gm1.randNumber(gm1.randomNumber);

    bool playing = true;

    while (playing){

    // for checking

    std :: cout << gm1.randomNumber;
    gm1.choosingNumber(gm1.chosenNumber);
    gm1.checkNumber(gm1.chosenNumber, playing, gm1.min, gm1.max);
    gm1.calculateRange(gm1.chosenNumber, gm1.min, gm1.max);

    }

    std:: cout << "game over! \n";

};



int main () {

    promptGamePlay();


}