#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

class Soldier{
    private:
    uint  health_points;
    uint  max_health_points;
    uint damage;
    uint num_player;

    public:
    Soldier(int max_health,int damage , int num_player) :
       max_health_points(max_health), health_points(max_health) , damage(damage) , num_player(num_player)
    {} 
    virtual ~Soldier(){};
    virtual void attack(vector<vector<Soldier *>> &board, pair<int, int> location) = 0;
    int getNum(){
        return this->num_player;
    }
    int getHealth(){
        return this->health_points;
    }
    void setHealth(uint  health_points1){
        this->health_points=health_points1;   
    }
    int getMaxHealth(){
        return this->max_health_points;
    }
    int getDamge(){
        return this->damage;
    }

};
