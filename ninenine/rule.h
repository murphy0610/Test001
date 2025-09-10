#ifndef RULE_H
#define RULE_H

#include<iostream>
#include<windows.h>
#include<algorithm>
#include<vector>
#include<random>
#include<string>
#include<chrono> //system clock

using namespace std;

class unknown{

    public:

    //void YELLING();
    void shuffleDeck(vector<int>& deck); //done
    void decidePlayerOrder();//done
    void showcaseGameNumANDEachPlayerPoint();//done
    void askingPlayerNumANDTotalGameNum();//done
    void patternOfCards(int);//done
    void announceMidPoint();//done
    void announcement();
    void basicSetting();// Never gonna END.
    void eachGameSetting();// Never gonna END.
    vector<int> deck; //done


    void DealingCards();
    vector<vector<int>> handDeck; //四個人的手牌
    
    void playCards(int);
    bool canPlayOrNot(int);
    int playWhichCard();
    void drawACard(int);

    void WinningCondition();//done 
    bool LossingCondition();//done 記得這裡還是用currentplayer算

    void findNextPlayer();//done

    void PROCESS();


    private:

    int gameNum; //第幾局
    int totalGameNum; //總共幾局
    vector<int> playerPoint; //目前積分
    int playerNum; //玩家人數
    int midPoint; //牌堆中央點數
    int currentPlayer; //目前玩家
    int count; //計數器
    int cardIndex; //牌的索引拿到哪裡
    //int playerOrder[5] = { 1, 2, 3, 4}; //順序 e.g. 4 2 1 3
    vector<bool> InOrOut;
    vector<string> suits = { "♣", "♦", "♥", "♠"}; //花色
    vector<string> ranks = {"A", "2", "3", "4", "5", "6", "7", 
                            "8", "9", "10", "J", "Q", "K"};
    bool direction; //true 為小到大 false 為大到小
    int remainingPlayerNum;
    int lossingNum;
    int winningNum;

}; 

#endif

/*
每局記得 currentPlayer %= playerNum;
*/