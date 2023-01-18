#include <bits/stdc++.h>
#include <math.h>
#include "game.h"
#include "maths.h"
using namespace std;
extern int SCREEN_HEIGHT;
extern int SCREEN_WIDTH;
extern unsigned long long int woods, goldCoins, bread, fish, stone, wheat;
extern int totalTownHouses;
extern int totalForestersHut, totalmines, totalbakeries, totalfarms, totalfisheries, totalBarracks;
extern int timer;
int getgcd(){
    return __gcd(SCREEN_HEIGHT, SCREEN_WIDTH);
}

unsigned long long int calculateResources(){
    return bread*4 + woods*10 + goldCoins + fish*5 + stone*15 + wheat*2;
}

void calcraid(){
    int res = calculateResources();
    if(res > 6000) setRaid(5);
    else if(res > 5000) setRaid(4);
    else if(res > 4000) setRaid(3);
    else if(res > 3000) setRaid(2);
    else if(res > 2000) setRaid(1);
}

void timeAndResourceManagement(){
    if(timer % 31 == 0) {
        woods += totalForestersHut*2;
    }
    if(timer %= 47){
        stone += totalmines*2;
    }
    if(timer%37 == 0){
        wheat += totalfarms*4;
    }
    if(timer % 41 == 0){
        fish += totalfisheries*2;
    }
    if(timer % 59 == 0) {
        bread -= totalTownHouses*2;
        fish -= 1;
        if(wheat < totalbakeries*5) {
            bread += wheat;
            wheat = 0;
        }
        else{
            bread += totalbakeries*5;
            wheat -= totalbakeries*5;
        }
    }
    if(timer % 120 == 0){
        goldCoins += (woods/2)*10;
        woods -= woods/2;
        goldCoins += (fish/3)*5;
        fish -= fish/3;
        goldCoins += (bread/4)*3;
        bread -= bread/4;
        goldCoins += (stone/4)*15;
        stone -= stone/4;
        goldCoins += wheat*0.75*2;
        wheat -= wheat*0.75;
    }
    if(timer % 100 == 0){
        bread -= 20*totalBarracks;
        stone -= 20*totalBarracks;
        fish -= 20*totalBarracks;
        goldCoins -= 150*totalBarracks;
    }
}