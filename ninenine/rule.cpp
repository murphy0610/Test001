#include "rule.h"

void unknown::shuffleDeck(vector<int>& deck){
    deck.clear();
    for (int i = 0; i < 52; i++) deck.push_back(i);
    
    random_device rd;
    mt19937 gen(rd());

    shuffle(deck.begin(), deck.end(), gen);
    cout << "Shuffle Success! " << endl;
}

void unknown::decidePlayerOrder(){
    shuffleDeck(deck);
    int maximum = deck[0];

    for(int i = 0; i < playerNum - 1; i++){
        if(deck[i] < deck[i + 1]){
            maximum = deck[i + 1];
        }
    }
    for(int i = 0; i < playerNum; i++){
        if(deck[i] == maximum){
            currentPlayer = i;
        }
    }

    cout << "First Player is Player " << currentPlayer << "." << endl;
}

void unknown::showcaseGameNumANDEachPlayerPoint(){
    cout << "GAME : " << gameNum + 1 << endl;
    cout << "Point : ";
    for(int i = 0; i < playerNum; i++){
        cout << "Player " << i + 1 << ": " << playerPoint[i] << " ";
    }cout << endl;
}

void unknown::askingPlayerNumANDTotalGameNum(){
    cout << "How many players are there?" << endl;
    cin >> playerNum;
    cout << "How many rounds u want to play?" << endl;
    cin >> totalGameNum;
}

void unknown::announceMidPoint(){
    cout << "MidPoint is " << midPoint << " now." << endl;
}

void unknown::eachGameSetting(){

    showcaseGameNumANDEachPlayerPoint();
    direction = true;
    remainingPlayerNum = playerNum;
    lossingNum = 0;
    winningNum = 0;
    InOrOut.clear();
    for(int i = 0; i < 4; i++) InOrOut.push_back(true);
    midPoint = 0;
    decidePlayerOrder();
    patternOfCards(39);
    cout << endl;

    DealingCards();
}

void unknown::basicSetting(){

    cout << "Start Setting..." << endl;
    askingPlayerNumANDTotalGameNum();

    for(int i = 0; i < playerNum; i++){
        playerPoint.push_back(0);
    }
}

void unknown::DealingCards(){
    shuffleDeck(deck);
    cardIndex = 0;

    handDeck.assign(playerNum, {});
    for(int i = 0; i < playerNum; i++){
        for(int j = 0; j < 5; j++){
            handDeck[i].push_back(deck[cardIndex++]);
            patternOfCards(deck[cardIndex]);
        }
        cout << endl;
    }
///
}

void unknown::patternOfCards(int cardNum){
    cout << "-|" << ranks[cardNum % 13] << suits[cardNum / 13] << "|-";
}

void unknown::WinningCondition(){
    if(handDeck.size() == 0 && midPoint < 100){
        InOrOut[currentPlayer] = false;
        winningNum++;
        playerPoint[currentPlayer] += (playerNum - winningNum) + 1;
    }
}
bool unknown::LossingCondition(){
    bool haveCardToPlayOrNot = false;
    for(int i = 0; i < 5; i++){
        if(!haveCardToPlayOrNot){
            haveCardToPlayOrNot = canPlayOrNot(handDeck[currentPlayer][i]);
        }
    }
    return !haveCardToPlayOrNot;
}

void unknown::announcement(){
    cout << "Ur player1." << endl;
    cout << "This is Game of Ninenie made of Loserwin." << endl;
}

void unknown::PROCESS(){

    //先宣告一些玩家該知道的事項
    announcement();
    
    //開始一些整局遊戲都固定的資訊
    basicSetting();

    for(gameNum = 0; gameNum < totalGameNum; gameNum++){
        //接著設定那些每局都會變動的資訊
        eachGameSetting();
        while(remainingPlayerNum > 0){
            
            if(InOrOut[currentPlayer]){

                if(remainingPlayerNum == 1){
                    playerPoint[currentPlayer] += (playerNum - winningNum);
                    break;
                }
                //showMidPoint
                cout << "There is " <<  midPoint << " on the Table." << endl;
                //showCurrentPlayer
                cout << "Now is Player" << currentPlayer + 1 << " turn." << endl; 
                //showHandCard
                cout << "Player" << currentPlayer + 1 << "have  "; 
                for(int i = 0; i < 5; i++){patternOfCards(handDeck[currentPlayer][i]);}
                cout << "   ." << endl;

                if(LossingCondition){
                    cout << "Ur lost! " << endl;
                    InOrOut[currentPlayer] = false;
                    lossingNum++;   
                    playerPoint[currentPlayer] += lossingNum;
                    remainingPlayerNum--;
                    findNextPlayer();
                    continue;
                }
                else{
                    if(currentPlayer == 0){
                        cout << "Print 1 to choose to play first card, 2 to second and so on." << endl;
                        int choose; cin >> choose;//這裡做一個防呆可是我懶惰
                        int choosenCard = handDeck[currentPlayer][choose - 1];
                        playCards(choosenCard);                  
                    }
                    else{
                        int choosenCard = playWhichCard();
                        playCards(choosenCard);//這個是錯的 電腦不需要問加或減
                    }
                }
            }
        }
        //可以做一個結束後cout些什麼
        WinningCondition();
        findNextPlayer();
    }
    /*
    while(currentGame <= GameNum) game++{
        if(remainingPlayer = 0) >> END;
        
        PLAY{
            if(!playerisaLive){find nextperson; continue;}
            showMidpoint;
            showcurrentPLayer;
            showhandcard;
            
            if(lossingCondition){find nextperson; continue};

            if(player == 0){leyhimchoose;}
            else(chooseplaywhichCard);
            displaywhichcard;
            play; draw;

            winnigCondition(???)
            find nextperson;
            winingCondition(???)

            showMidpoint;(?)

        }

    }
    */
}