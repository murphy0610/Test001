#include"rule.h"

void unknown::drawACard(int cardNum){
    if(deck.empty()){
        return;
    }

    auto& hand = handDeck[currentPlayer];
    auto item = find(hand.begin(), hand.end(), hand);
    hand.erase(item);

    handDeck[currentPlayer].push_back(cardIndex++);
}//可視為最後一個動作 接著輪下一個
//要先判斷贏了沒

void unknown::findNextPlayer(){
    if(direction){
        currentPlayer++; //也許錯
    }else currentPlayer += (playerNum - 1);

    if(currentPlayer < 0) cout << "Error3! " << endl;
    
    currentPlayer %= playerNum;
}

void unknown::playCards(int cardNum){

    if(cardNum == 39){
        midPoint = 0;
    }
    else if(playerNum == 4 && cardNum % 13 == 3){
        direction = !direction;
    }
    else if(cardNum % 13 == 8 || cardNum % 13 == 7 || cardNum % 13 == 6 || cardNum % 13 == 5 || cardNum % 13 == 3 || cardNum % 13 == 2 || cardNum % 13 == 1 || cardNum % 13 == 0){
        midPoint += (cardNum % 13 + 1);
    }
    else if(cardNum % 13 == 4){

        if(currentPlayer == 0){
            cout << "Which player u want to turn to?" << endl;
            cin >> currentPlayer;
            if(direction){
                currentPlayer += (playerNum - 1);
            }else currentPlayer++;
        }
        else{
            int randomIndex = (deck[cardIndex] % playerNum);
            cout << "Computer chooses Player" << randomIndex + 1 << "." << endl;
            if(direction){
                currentPlayer += (playerNum - 1 + randomIndex);
            }else currentPlayer = randomIndex + 1;
        }
    }
    else if(cardNum % 13 == 9){
        cout << "print 1 to plus 10, 2 to minus 10." << endl;
        int choose; cin >> choose;
        if(choose == 1) midPoint += 10;
        else if(choose == 2) midPoint -= 10;
        else cout << "Error 1!" << endl;
    }
    else if(cardNum % 13 == 10){
        cout << "Pass! " << endl;
    }
    else if(cardNum % 13 == 11){
        cout << "print 1 to plus 20, 2 to minus 20." << endl;
        int choose; cin >> choose;
        if(choose == 1) midPoint += 20;
        else if(choose == 2) midPoint -= 20;
        else cout << "Error 2!" << endl;
    }
    else if(cardNum % 13 == 12){
        midPoint = 99;
    }
    else{
        cout << "Error!" << endl;
    }
    drawACard(cardNum);
}

bool unknown::canPlayOrNot(int cardNum){

    if(cardNum == 39 || cardNum % 13 == 4 || cardNum % 13 == 9 || cardNum % 13 == 10 || cardNum % 13 == 11 || cardNum % 13 == 12){
        return true;
    }
    else if(playerNum == 4 && cardNum % 13 == 3){
        return true;
    }
    else if(cardNum % 13 == 8 || cardNum % 13 == 7 || cardNum % 13 == 6 || cardNum % 13 == 5 || cardNum % 13 == 3 || cardNum % 13 == 2 || cardNum % 13 == 1 || cardNum % 13 == 0){
        if(midPoint += (cardNum % 13 + 1) < 100){
            return true;
        }else return false;
    }
    else{
        cout << "Error 4!" << endl; 
        return true;
    } 
}

/*
0
13 26 39 +1
%13 = 1 / 2/ 5/ 6/ 7/ 8 +(n+1)
if(playerNum < 4) = %13 = 3 = +5
if(playerNum = 4) turn
%13 = 4 
*/

int unknown::playWhichCard(){

    for(int i = 8; i >= 0; i--){
        if(i == 3 || i == 4){
            continue;
        }

        for(int j = 0; j < 5; j++){
            if((handDeck[currentPlayer][j]) % 13 == i && canPlayOrNot(handDeck[currentPlayer][j])){
                if(handDeck[currentPlayer][j] == 39){
                    continue;
                }
                return handDeck[currentPlayer][j];
            }
        }
    }

    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 11){
            return handDeck[currentPlayer][i];
        } 
    }
    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 9){
            return handDeck[currentPlayer][i];
        } 
    }
    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 12){
            return handDeck[currentPlayer][i];
        } 
    }
    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 10){
            return handDeck[currentPlayer][i];
        } 
    }
    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 4){
            return handDeck[currentPlayer][i];
        } 
    }
    for(int i = 0; i < 5; i++){
        if((handDeck[currentPlayer][i]) % 13 == 3){
            return handDeck[currentPlayer][i];
        } 
    }
}